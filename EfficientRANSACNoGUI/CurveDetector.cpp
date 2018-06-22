#include "CurveDetector.h"
#include <iostream>

void CurveDetector::detect(std::vector<Point>& polygon, int num_iter, int min_points, float max_error_ratio_to_radius, float cluster_epsilon, float min_angle, float min_radius, float max_radius, std::vector<Circle>& circles) {
	circles.clear();

	int N = polygon.size();
	if (N < min_points) return;

	int N2 = N;
	while (N2 < cluster_epsilon) N2 += N;

	// initialize the unused list
	std::vector<int> unused_list;
	for (int i = 0; i < N; i++) {
		if (!polygon[i].used) unused_list.push_back(i);
	}

	while (true) {
		int max_num_points = 0;
		Circle best_circle;
		int best_index1;

		for (int iter = 0; iter < num_iter; iter++) {
			// randomly sample index1 as a first point, and then, sample two other points that are close to the first one
			int index1 = -1;
			int index2 = -1;
			int index3 = -1;
			for (int iter2 = 0; iter2 < num_iter; iter2++) {
				index1 = unused_list[rand() % unused_list.size()];
				index2 = (int)(index1 + rand() % (int)(cluster_epsilon * 2 + 1) - cluster_epsilon + N2) % N;
				if (polygon[index2].used) continue;
				index3 = (int)(index1 + rand() % (int)(cluster_epsilon * 2 + 1) - cluster_epsilon + N2) % N;
				if (polygon[index3].used) continue;
				break;
			}

			if (index1 == -1 || index2 == -1 || index3 == -1) continue;

			// if three points are collinear, reject this candidate.
			if (std::abs(crossProduct(polygon[index2].pos - polygon[index1].pos, polygon[index3].pos - polygon[index1].pos)) < 0.001) continue;

			// calculate the circle center from three points
			Circle circle = circleFromPoints(polygon[index1].pos, polygon[index2].pos, polygon[index3].pos);
			if (circle.radius < min_radius || circle.radius > max_radius) continue;

			// check whether the points are supporting this circle
			std::vector<float> angles;
			angles.push_back(std::atan2(polygon[index1].pos.y - circle.center.y, polygon[index1].pos.x - circle.center.x));
			int num_points = 0;
			int prev = 0;
			for (int i = 0; i < N && i - prev < cluster_epsilon; i++) {
				int idx = (index1 + i) % N;
				if (polygon[idx].used) break;
				if (circle.distance(polygon[idx].pos) < circle.radius * max_error_ratio_to_radius) {
					num_points++;
					prev = i;
					angles.push_back(std::atan2(polygon[idx].pos.y - circle.center.y, polygon[idx].pos.x - circle.center.x));
				}
			}
			prev = 0;
			for (int i = 1; i < N && i - prev < cluster_epsilon; i++) {
				int idx = (index1 - i + N) % N;
				if (polygon[idx].used) break;
				if (circle.distance(polygon[idx].pos) < circle.radius * max_error_ratio_to_radius) {
					num_points++;
					prev = i;
					angles.push_back(std::atan2(polygon[idx].pos.y - circle.center.y, polygon[idx].pos.x - circle.center.x));
				}
			}

			// calculate angle range
			circle.setMinMaxAngles(angles);
			if (circle.angle_range < min_angle) continue;

			if (num_points > max_num_points) {
				max_num_points = num_points;
				best_circle = circle;
				best_index1 = index1;
			}
		}

		// if the best detected curve does not have enough supporing points, terminate the algorithm.
		if (max_num_points < min_points) break;

		// update used flag
		int prev = 0;
		std::vector<int> potentially_used;
		for (int i = 0; i < N && i - prev < cluster_epsilon; i++) {
			int idx = (best_index1 + i) % N;
			if (polygon[idx].used) break;
			potentially_used.push_back(idx);
			if (best_circle.distance(polygon[idx].pos) < best_circle.radius * max_error_ratio_to_radius) {
				best_circle.points.push_back(polygon[idx].pos);
				prev = i;
				for (auto& pu : potentially_used) polygon[pu].used = true;
			}
		}
		prev = 0;
		potentially_used.clear();
		for (int i = 1; i < N && i - prev < cluster_epsilon; i++) {
			int idx = (best_index1 - i + N) % N;
			if (polygon[idx].used) break;
			potentially_used.push_back(idx);
			if (best_circle.distance(polygon[idx].pos) < best_circle.radius * max_error_ratio_to_radius) {
				best_circle.points.push_back(polygon[idx].pos);
				prev = i;
				for (auto& pu : potentially_used) polygon[pu].used = true;
			}
		}

		// update used list
		for (int i = unused_list.size() - 1; i >= 0; i--) {
			if (polygon[unused_list[i]].used) unused_list.erase(unused_list.begin() + i);
		}

		circles.push_back(best_circle);
	}
}

Circle CurveDetector::circleFromPoints(const cv::Point2f& p1, const cv::Point2f& p2, const cv::Point2f& p3) {
	float offset = p2.x * p2.x + p2.y * p2.y;
	float bc = (p1.x * p1.x + p1.y * p1.y - offset) / 2.0;
	float cd = (offset - p3.x * p3.x - p3.y * p3.y) / 2.0;
	float det = (p1.x - p2.x) * (p2.y - p3.y) - (p2.x - p3.x)* (p1.y - p2.y);
	
	if (std::abs(det) < 0.0000001) throw "Three points are collinear.";
	 
	float idet = 1 / det;
	
	float centerx = (bc * (p2.y - p3.y) - cd * (p1.y - p2.y)) * idet;
	float centery = (cd * (p1.x - p2.x) - bc * (p2.x - p3.x)) * idet;
	float radius = std::sqrt((p2.x - centerx) * (p2.x - centerx) + (p2.y - centery) * (p2.y - centery));
	
	return Circle(cv::Point2f(centerx, centery), radius);
}

float CurveDetector::crossProduct(const cv::Point2f& a, const cv::Point2f& b) {
	return a.x * b.y - a.y * b.x;
}

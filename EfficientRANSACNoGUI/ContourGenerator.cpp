#include "ContourGenerator.h"
#include "CurveDetector.h"
#include "LineDetector.h"

ContourGenerator::ContourGenerator() {
}

ContourGenerator::~ContourGenerator() {
}

void ContourGenerator::generate(const Polygon& polygon, const std::vector<std::pair<int, std::shared_ptr<PrimitiveShape>>>& shapes, std::vector<cv::Point2f>& contour, float max_error, float angle_threshold) {
	for (int j = 0; j < shapes.size(); j++) {
		if (Circle* circle = dynamic_cast<Circle*>(shapes[j].second.get())) {
			int num = circle->angle_range / CV_PI * 180 / 10;
			contour.push_back(circle->start_point);
			for (int k = 1; k < num; k++) {
				float angle = circle->start_angle + circle->signed_angle_range / num * k;
				contour.push_back(circle->center + circle->radius * cv::Point2f(std::cos(angle), std::sin(angle)));
			}
			contour.push_back(circle->end_point);

			int j2 = (j + 1) % shapes.size();
			contour.push_back(shapes[j2].second->start_point);
		}
		else if (Line* line = dynamic_cast<Line*>(shapes[j].second.get())) {
			int j2 = (j + 1) % shapes.size();
			if (Circle* circle2 = dynamic_cast<Circle*>(shapes[j2].second.get())) {
				contour.push_back(line->end_point);
				continue;
			}
			else if (Line* line2 = dynamic_cast<Line*>(shapes[j2].second.get())) {
				// check if two adjacent shapes are almost collinear
				cv::Point2f dir1 = shapes[j].second->end_point - shapes[j].second->start_point;
				cv::Point2f dir2 = shapes[j2].second->end_point - shapes[j2].second->start_point;
				if (std::abs(dir1.dot(dir2) / cv::norm(dir1) / cv::norm(dir2)) >= std::cos(angle_threshold)) {
					// if two shapes are close enough, merge them
					if (line->distance(line2->start_point) < max_error) continue;
					else {
						// simpliy connect two shapes
						contour.push_back(line->end_point);
						contour.push_back(line2->start_point);
					}
				}

				// calculate the intersection between the current shape and the next one
				cv::Point2f int_pt;
				double tab, tcd;
				if (lineLineIntersection(shapes[j].second->start_point, shapes[j].second->end_point, shapes[j2].second->end_point, shapes[j2].second->start_point, &tab, &tcd, false, int_pt)) {
					bool valid = false;
					int start_index = shapes[j].second->start_index;
					int end_index = shapes[j2].second->end_index;
					if (start_index > end_index) end_index += polygon.contour.size();
					for (int k = start_index; k <= end_index; k++) {
						int index = (k + polygon.contour.size()) % polygon.contour.size();
						if (cv::norm(polygon.contour[index].pos - int_pt) < max_error) {
							valid = true;
							break;
						}
					}

					if (valid) {
						contour.push_back(int_pt);
						continue;
					}
				}

				// simpliy connect two shapes
				contour.push_back(line->end_point);
				contour.push_back(line2->start_point);
			}
		}
	}

}
#pragma once

#include <vector>
#include "Util.h"

class Circle {
public:
	cv::Point2f center;
	float radius;
	std::vector<cv::Point2f> points;
	float start_angle;
	float end_angle;
	float angle_range;

public:
	Circle() : center(0, 0), radius(0) {}
	Circle(const cv::Point2f& center, float radius) : center(center), radius(radius) {}

	float distance(const cv::Point2f& p) {
		return std::abs(cv::norm(p - center) - radius);
	}

	void setMinMaxAngles(std::vector<float>& angles) {
		if (angles.size() == 0) return;
		else if (angles.size() == 1) {
			start_angle = angles[0];
			end_angle = angles[0];
			angle_range = 0;
			return;
		}

		std::sort(angles.begin(), angles.end());

		start_angle = angles[0];
		end_angle = angles.back();
		float max_gap = angles[0] + CV_PI * 2 - angles.back();
		angle_range = end_angle - start_angle;

		std::sort(angles.begin(), angles.end());
		for (int i = 1; i < angles.size(); i++) {
			if (angles[i] - angles[i - 1] > max_gap) {
				max_gap = angles[i] - angles[i - 1];
				start_angle = angles[i];
				end_angle = angles[i - 1] + CV_PI * 2;
				angle_range = end_angle - start_angle;
			}
		}

		// if the arc is almost a complete circle, make it a circle
		if (angle_range > CV_PI * 1.9) {
			end_angle = start_angle + CV_PI * 2;
			angle_range = CV_PI * 2;
		}
	}
};

class CurveDetector {
protected:
	CurveDetector() {}

public:
	static void detect(std::vector<Point>& polygon, int num_iter, int min_points, float max_error_ratio_to_radius, float cluster_epsilon, float min_angle, float min_radius, float max_radius, std::vector<Circle>& circles);
	static Circle circleFromPoints(const cv::Point2f& p1, const cv::Point2f& p2, const cv::Point2f& p3);
	static float crossProduct(const cv::Point2f& a, const cv::Point2f& b);
};


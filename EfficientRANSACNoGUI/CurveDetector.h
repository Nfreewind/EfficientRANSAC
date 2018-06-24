#pragma once

#include <vector>
#include <memory>
#include "PrimitiveShape.h"
#include "Util.h"

class Circle : public PrimitiveShape {
public:
	/** Center of the circle */
	cv::Point2f center;

	/** Radius of the circle */
	float radius;

	/** Start angle */
	float start_angle;

	/** End angle */
	float end_angle;

	/** Angle range */
	float angle_range;

	/** Signed angle range */
	float signed_angle_range;

public:
	Circle();
	Circle(int index, const cv::Point2f& point, const cv::Point2f& center, float radius);
	~Circle() {}

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

		// swap start_angle and end_angle accroding to the start_point and end_point
		cv::Point2f p1 = center + radius * cv::Point2f(std::cos(start_angle), std::sin(start_angle));
		cv::Point2f p2 = center + radius * cv::Point2f(std::cos(end_angle), std::sin(end_angle));
		if (cv::norm(start_point - p1) > cv::norm(start_point - p2)) {
			std::swap(start_angle, end_angle);
		}

		if (start_angle < end_angle) {
			signed_angle_range = angle_range;
		}
		else {
			signed_angle_range = -angle_range;
		}
	}
};

class CurveDetector {
protected:
	CurveDetector() {}
	
public:
	static void detect(std::vector<Point>& polygon, int num_iter, int min_points, float max_error_ratio_to_radius, float cluster_epsilon, float min_angle, float min_radius, float max_radius, std::vector<std::pair<int, std::shared_ptr<PrimitiveShape>>>& circles);
	static std::shared_ptr<Circle> circleFromPoints(int index, const cv::Point2f& p1, const cv::Point2f& p2, const cv::Point2f& p3);
	static float crossProduct(const cv::Point2f& a, const cv::Point2f& b);
};


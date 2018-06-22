#pragma once

#include <vector>
#include "Util.h"

class Line {
public:
	cv::Point2f point;
	cv::Point2f dir;
	std::vector<cv::Point2f> points;
	float start_pos;
	float end_pos;
	float length;

public:
	Line() {}
	Line(const cv::Point2f& point, const cv::Point2f& dir) : point(point), dir(dir / cv::norm(dir)) {}

	float distance(const cv::Point2f& p) {
		return std::abs((p - point).dot(cv::Point2f(dir.y, -dir.x)));
	}

	void setEndPositions(std::vector<float>& positions) {
		if (positions.size() == 0) return;

		std::sort(positions.begin(), positions.end());

		start_pos = positions[0];
		end_pos = positions.back();
		length = end_pos - start_pos;
	}
};

class LineDetector {
protected:
	LineDetector() {}

public:
	static void detect(std::vector<Point>& polygon, int num_iter, int min_points, float max_error, float cluster_epsilon, float min_length, std::vector<float>& principal_angles, float angle_threshold, std::vector<Line>& lines);
};


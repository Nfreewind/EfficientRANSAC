#pragma once

#include <vector>
#include <memory>
#include "PrimitiveShape.h"
#include "Util.h"

class Line : public PrimitiveShape {
public:
	/** One point on the line */
	cv::Point2f point;

	/** Orientation vector of the line */
	cv::Point2f dir;

	/** Start position of the line segment */
	float start_pos;

	/** End position of the line segment */
	float end_pos;

	/** Length of the line segment */
	float length;

public:
	Line();
	Line(int index, const cv::Point2f& point, const cv::Point2f& dir);
	~Line() {}

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
	static void detect(std::vector<Point>& polygon, int num_iter, int min_points, float max_error, float cluster_epsilon, float min_length, std::vector<float>& principal_angles, float angle_threshold, std::vector<std::pair<int, std::shared_ptr<PrimitiveShape>>>& lines);
};


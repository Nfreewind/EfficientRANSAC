#pragma once

#include <vector>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class PrimitiveShape {
public:
	/** Supporting points */
	std::vector<cv::Point2f> points;

	/** Start point index */
	int start_index;

	/** Start point */
	cv::Point2f start_point;

	/** End point index */
	int end_index;

	/** End point */
	cv::Point2f end_point;

public:
	PrimitiveShape() {}
	virtual ~PrimitiveShape() {}

	virtual float distance(const cv::Point2f& p) = 0;
};


#pragma once

#include <vector>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class PrimitiveShape {
public:
	/** Supporting points */
	std::vector<cv::Point2f> points;

	/** Start index point */
	int start_index;

public:
	PrimitiveShape() {}
	virtual ~PrimitiveShape() {}

	virtual float distance(const cv::Point2f& p) = 0;
};


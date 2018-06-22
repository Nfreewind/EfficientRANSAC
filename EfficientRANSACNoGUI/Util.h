#pragma once

#include <vector>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class Point {
public:
	cv::Point2f pos;
	cv::Point2f normal;
	bool used;

public:
	Point() : used(false) {}
	Point(float x, float y) : pos(x, y), used(false) {}
	Point(float x, float y, float nx, float ny) : pos(x, y), normal(nx, ny), used(false) {}
};

class Polygon {
public:
	std::vector<Point> contour;
	std::vector<std::vector<Point>> holes;

public:
	Polygon() {}

	void clearUsedFlag() {
		for (auto& pt : contour) pt.used = false;
		for (auto& hole : holes) {
			for (auto& pt : hole) pt.used = false;
		}
	}
};

std::vector<Polygon> findContours(const cv::Mat& image);

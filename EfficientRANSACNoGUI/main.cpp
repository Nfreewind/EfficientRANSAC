#include <iostream>
#include "CurveDetector.h"
#include "PrimitiveShape.h"

int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " <input image file> <output image file>" << std::endl;
		return -1;
	}

	// load image
	cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

	// find contours
	std::vector<Polygon> polygons = findContours(image);

	// detect circles
	std::vector<std::vector<std::pair<int, std::shared_ptr<PrimitiveShape>>>> shapes;
	for (int i = 0; i < polygons.size(); i++) {
		std::vector<std::pair<int, std::shared_ptr<PrimitiveShape>>> results;
		if (polygons[i].contour.size() >= 100) {
			CurveDetector::detect(polygons[i].contour, 200000, 200, 0.02, 30, 90 / 180.0 * CV_PI, 80, 400, results);
		}
		shapes.push_back(results);
	}

	if (shapes.size() > 0) {
		// generate output image
		cv::Mat result(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
		for (auto& polygon : polygons) {
			std::vector<cv::Point> pol;
			for (auto& pt : polygon.contour) pol.push_back(pt.pos);
			cv::polylines(result, pol, true, cv::Scalar(0, 0, 0), 1);
			for (auto& hole : polygon.holes) {
				std::vector<cv::Point> pol;
				for (auto& pt : hole) pol.push_back(pt.pos);
				cv::polylines(result, pol, true, cv::Scalar(0, 0, 0), 1);
			}
		}
		for (auto& list : shapes) {
			for (auto& shape : list) {
				if (Circle* circle = dynamic_cast<Circle*>(shape.second.get())) {
					cv::ellipse(result, cv::Point(circle->center.x, circle->center.y), cv::Size(circle->radius, circle->radius), 0, circle->start_angle / CV_PI * 180, circle->end_angle / CV_PI * 180, cv::Scalar(255, 0, 0), 3);
				}
			}
		}

		cv::imwrite(argv[2], result);
	}

	return 0;
}
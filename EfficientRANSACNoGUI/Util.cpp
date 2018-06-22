#include "Util.h"

std::vector<Polygon> findContours(const cv::Mat& image) {
	std::vector<Polygon> polygons;

	cv::Mat mat = image.clone();
	cv::threshold(mat, mat, 40, 255, cv::THRESH_BINARY);

	// extract contours
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	//cv::findContours(mat, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	cv::findContours(mat, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_NONE, cv::Point(0, 0));

	for (int i = 0; i < hierarchy.size(); i++) {
		if (hierarchy[i][3] != -1) continue;
		if (contours[i].size() < 3) continue;

		Polygon polygon;
		polygon.contour.resize(contours[i].size());
		for (int j = 0; j < contours[i].size(); j++) {
			polygon.contour[j] = Point(contours[i][j].x, contours[i][j].y);
		}

		if (polygon.contour.size() >= 3) {
			// obtain all the holes inside this contour
			int hole_id = hierarchy[i][2];
			while (hole_id != -1) {
				std::vector<Point> hole;
				hole.resize(contours[hole_id].size());
				for (int j = 0; j < contours[hole_id].size(); j++) {
					hole[j] = Point(contours[hole_id][j].x, contours[hole_id][j].y);
				}
				polygon.holes.push_back(hole);
				hole_id = hierarchy[hole_id][0];
			}

			polygons.push_back(polygon);
		}
	}

	return polygons;
}

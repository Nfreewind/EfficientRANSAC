#include "Canvas.h"
#include <QPainter>
#include <iostream>
#include <QFileInfoList>
#include <QDir>
#include <QMessageBox>
#include <QTextStream>
#include <QResizeEvent>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
	ctrlPressed = false;
	shiftPressed = false;
}

void Canvas::loadImage(const QString& filename) {
	orig_image = QImage(filename).convertToFormat(QImage::Format_Grayscale8);
	image_scale = std::min((float)width() / orig_image.width(), (float)height() / orig_image.height());
	image = orig_image.scaled(orig_image.width() * image_scale, orig_image.height() * image_scale);

	polygons.clear();
	shapes.clear();
	contours.clear();

	update();
}

void Canvas::saveImage(const QString& filename) {
	grab().save(filename);
}

void Canvas::detectContours() {
	polygons.clear();
	shapes.clear();
	contours.clear();

	if (orig_image.isNull()) return;

	cv::Mat mat = cv::Mat(orig_image.height(), orig_image.width(), CV_8UC1, orig_image.bits(), orig_image.bytesPerLine()).clone();
	polygons = findContours(mat);
}

void Canvas::detectCurves(int num_iterations, int min_points, float max_error_ratio_to_radius, float cluster_epsilon, float min_angle, float min_radius, float max_radius) {
	detectContours();

	// detect circles
	shapes.resize(polygons.size());
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() >= 100) {
			CurveDetector::detect(polygons[i].contour, num_iterations, min_points, max_error_ratio_to_radius, cluster_epsilon, min_angle, min_radius, max_radius, shapes[i]);
		}
	}
}

void Canvas::detectLines(int num_iterations, int min_points, float max_error, float cluster_epsilon, float min_length, float angle_threshold) {
	detectContours();

	std::vector<std::vector<cv::Point2f>> pgons;
	for (auto& polygon : polygons) {
		if (polygon.contour.size() < 100) continue;

		std::vector<cv::Point2f> pgon;
		for (auto& pt : polygon.contour) pgon.push_back(pt.pos);
		pgons.push_back(pgon);
	}
	float principal_orientation = OrientationEstimator::estimate(pgons);

	// use the principal orientation, +45, +90, +135 degrees as principal orientations
	std::vector<float> principal_orientations;
	for (int i = 0; i < 4; i++) {
		principal_orientations.push_back(principal_orientation + CV_PI * i / 4);
	}

	// detect lines based on the principal orientations
	shapes.resize(polygons.size());
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() >= 100) {
			LineDetector::detect(polygons[i].contour, num_iterations, min_points, max_error, cluster_epsilon, min_length, principal_orientations, angle_threshold, shapes[i]);
		}
	}
}

void Canvas::detectCurvesLines(int curve_num_iterations, int curve_min_points, float curve_max_error_ratio_to_radius, float curve_cluster_epsilon, float curve_min_angle, float curve_min_radius, float curve_max_radius, int line_num_iterations, int line_min_points, float line_max_error, float line_cluster_epsilon, float line_min_length, float line_angle_threshold) {
	detectContours();

	// detect circles
	shapes.resize(polygons.size());
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() >= 100) {
			CurveDetector::detect(polygons[i].contour, curve_num_iterations, curve_min_points, curve_max_error_ratio_to_radius, curve_cluster_epsilon, curve_min_angle, curve_min_radius, curve_max_radius, shapes[i]);
		}
	}

	// detect principal orientation
	std::vector<std::vector<cv::Point2f>> pgons;
	for (auto& polygon : polygons) {
		if (polygon.contour.size() < 100) continue;

		std::vector<cv::Point2f> pgon;
		for (auto& pt : polygon.contour) pgon.push_back(pt.pos);
		pgons.push_back(pgon);
	}
	float principal_orientation = OrientationEstimator::estimate(pgons);

	// use the principal orientation, +45, +90, +135 degrees as principal orientations
	std::vector<float> principal_orientations;
	for (int i = 0; i < 4; i++) {
		principal_orientations.push_back(principal_orientation + CV_PI * i / 4);
	}

	// detect lines based on the principal orientations
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() >= 100) {
			std::vector<std::pair<int, std::shared_ptr<PrimitiveShape>>> results;
			LineDetector::detect(polygons[i].contour, line_num_iterations, line_min_points, line_max_error, line_cluster_epsilon, line_min_length, principal_orientations, line_angle_threshold, results);
			shapes[i].insert(shapes[i].end(), results.begin(), results.end());
		}
	}
}

void Canvas::generateContours(int curve_num_iterations, int curve_min_points, float curve_max_error_ratio_to_radius, float curve_cluster_epsilon, float curve_min_angle, float curve_min_radius, float curve_max_radius, int line_num_iterations, int line_min_points, float line_max_error, float line_cluster_epsilon, float line_min_length, float line_angle_threshold, float contour_max_error, float contour_angle_threshold) {
	detectContours();

	// detect circles
	shapes.resize(polygons.size());
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() >= 100) {
			CurveDetector::detect(polygons[i].contour, curve_num_iterations, curve_min_points, curve_max_error_ratio_to_radius, curve_cluster_epsilon, curve_min_angle, curve_min_radius, curve_max_radius, shapes[i]);
		}
	}

	// detect principal orientation
	std::vector<std::vector<cv::Point2f>> pgons;
	for (auto& polygon : polygons) {
		if (polygon.contour.size() < 100) continue;

		std::vector<cv::Point2f> pgon;
		for (auto& pt : polygon.contour) pgon.push_back(pt.pos);
		pgons.push_back(pgon);
	}
	float principal_orientation = OrientationEstimator::estimate(pgons);

	// use the principal orientation, +45, +90, +135 degrees as principal orientations
	std::vector<float> principal_orientations;
	for (int i = 0; i < 4; i++) {
		principal_orientations.push_back(principal_orientation + CV_PI * i / 4);
	}

	// detect lines based on the principal orientations
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() >= 100) {
			std::vector<std::pair<int, std::shared_ptr<PrimitiveShape>>> results;
			LineDetector::detect(polygons[i].contour, line_num_iterations, line_min_points, line_max_error, line_cluster_epsilon, line_min_length, principal_orientations, line_angle_threshold, results);
			shapes[i].insert(shapes[i].end(), results.begin(), results.end());
		}
	}

	// generate contours
	contours.resize(shapes.size());
	for (int i = 0; i < shapes.size(); i++) {
		std::sort(shapes[i].begin(), shapes[i].end());
		ContourGenerator::generate(polygons[i], shapes[i], contours[i], contour_max_error, contour_angle_threshold);
	}
}

void Canvas::keyPressEvent(QKeyEvent* e) {
	ctrlPressed = false;
	shiftPressed = false;

	if (e->modifiers() & Qt::ControlModifier) {
		ctrlPressed = true;
	}
	if (e->modifiers() & Qt::ShiftModifier) {
		shiftPressed = true;
	}

	switch (e->key()) {
	case Qt::Key_Space:
		break;
	}

	update();
}

void Canvas::keyReleaseEvent(QKeyEvent* e) {
	switch (e->key()) {
	case Qt::Key_Control:
		ctrlPressed = false;
		break;
	case Qt::Key_Shift:
		shiftPressed = false;
		break;
	default:
		break;
	}
}

void Canvas::paintEvent(QPaintEvent *event) {
	if (!image.isNull()) {
		QPainter painter(this);

		if (polygons.size() == 0) {
			painter.drawImage(0, 0, image);
		}
		else if (contours.size() == 0) {
			painter.fillRect(0, 0, width(), height(), QColor(255, 255, 255));

			painter.setPen(QPen(QColor(0, 0, 0), 1));
			for (auto& polygon : polygons) {
				QPolygon pgon;
				for (auto& p : polygon.contour) {
					pgon.push_back(QPoint(p.pos.x * image_scale, p.pos.y * image_scale));
				}
				painter.drawPolygon(pgon);
				for (auto& hole : polygon.holes) {
					QPolygon pgon;
					for (auto& p : hole) {
						pgon.push_back(QPoint(p.pos.x * image_scale, p.pos.y * image_scale));
					}
					painter.drawPolygon(pgon);
				}
			}

			for (auto& list : shapes) {
				for (auto& shape : list) {
					if (Circle* circle = dynamic_cast<Circle*>(shape.second.get())) {
						painter.setPen(QPen(QColor(255, 192, 192), 1));
						for (int i = 0; i < circle->points.size(); i++) {
							painter.drawRect(circle->points[i].x * image_scale - 1, circle->points[i].y * image_scale - 1, 2, 2);
						}

						painter.setPen(QPen(QColor(255, 0, 0), 3));
						float start_angle = std::min(circle->start_angle, circle->end_angle);
						painter.drawArc((circle->center.x - circle->radius) * image_scale, (circle->center.y - circle->radius) * image_scale, circle->radius * 2 * image_scale, circle->radius * 2 * image_scale, -start_angle / CV_PI * 180 * 16, -circle->angle_range / CV_PI * 180 * 16);
					}
					else if (Line* line = dynamic_cast<Line*>(shape.second.get())) {
						painter.setPen(QPen(QColor(192, 192, 255), 1));
						for (int i = 0; i < line->points.size(); i++) {
							painter.drawRect(line->points[i].x * image_scale - 1, line->points[i].y * image_scale - 1, 2, 2);
						}

						painter.setPen(QPen(QColor(0, 0, 255), 3));
						cv::Point2f p1 = line->point + line->dir * line->start_pos;
						cv::Point2f p2 = line->point + line->dir * line->end_pos;
						painter.drawLine(p1.x * image_scale, p1.y * image_scale, p2.x * image_scale, p2.y * image_scale);
					}
				}
			}
		}
		else {
			painter.fillRect(0, 0, width(), height(), QColor(255, 255, 255));

			painter.setPen(QPen(QColor(0, 0, 0), 1));
			for (auto& polygon : polygons) {
				QPolygon pgon;
				for (auto& p : polygon.contour) {
					pgon.push_back(QPoint(p.pos.x * image_scale, p.pos.y * image_scale));
				}
				painter.drawPolygon(pgon);
				for (auto& hole : polygon.holes) {
					QPolygon pgon;
					for (auto& p : hole) {
						pgon.push_back(QPoint(p.pos.x * image_scale, p.pos.y * image_scale));
					}
					painter.drawPolygon(pgon);
				}
			}

			for (auto& contour : contours) {
				painter.setPen(QPen(QColor(0, 0, 255), 3));
				QPolygon pol;
				for (int i = 0; i < contour.size(); i++) {
					pol.push_back(QPoint(contour[i].x * image_scale, contour[i].y * image_scale));
				}
				painter.drawPolygon(pol);
			}
		}
	}
}

void Canvas::mousePressEvent(QMouseEvent* e) {
	update();
}

void Canvas::resizeEvent(QResizeEvent *e) {
	if (!orig_image.isNull()) {
		image_scale = std::min((float)width() / orig_image.width(), (float)height() / orig_image.height());
		image = orig_image.scaled(orig_image.width() * image_scale, orig_image.height() * image_scale);
	}
}


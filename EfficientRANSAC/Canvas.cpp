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
	circles.clear();
	lines.clear();

	update();
}

void Canvas::saveImage(const QString& filename) {
	grab().save(filename);
}

void Canvas::detectContours() {
	if (orig_image.isNull()) return;

	polygons.clear();
	circles.clear();
	lines.clear();

	cv::Mat mat = cv::Mat(orig_image.height(), orig_image.width(), CV_8UC1, orig_image.bits(), orig_image.bytesPerLine()).clone();
	polygons = findContours(mat);
}

void Canvas::detectCurves(int num_iterations, int min_points, float max_error_ratio_to_radius, float cluster_epsilon, float min_angle, float min_radius, float max_radius) {
	circles.clear();
	lines.clear();

	detectContours();

	// initialize the used flag
	/*for (auto& polygon : polygons) {
		for (auto& pt : polygon.contour) {
			pt.used = false;
		}
	}*/

	// detect circles
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() < 100) continue;

		std::vector<Circle> results;
		CurveDetector::detect(polygons[i].contour, num_iterations, min_points, max_error_ratio_to_radius, cluster_epsilon, min_angle, min_radius, max_radius, results);
		circles.insert(circles.end(), results.begin(), results.end());
	}
}

void Canvas::detectLines(int num_iterations, int min_points, float max_error, float cluster_epsilon, float min_length, float angle_threshold) {
	circles.clear();
	lines.clear();

	detectContours();

	// initialize the used flag
	/*
	for (auto& polygon : polygons) {
		for (auto& pt : polygon.contour) {
			pt.used = false;
		}
	}
	*/

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
	lines.clear();
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() < 100) continue;

		std::vector<Line> results;
		LineDetector::detect(polygons[i].contour, num_iterations, min_points, max_error, cluster_epsilon, min_length, principal_orientations, angle_threshold, results);
		lines.insert(lines.end(), results.begin(), results.end());
	}
}

void Canvas::detectCurvesLines(int curve_num_iterations, int curve_min_points, float curve_max_error_ratio_to_radius, float curve_cluster_epsilon, float curve_min_angle, float curve_min_radius, float curve_max_radius, int line_num_iterations, int line_min_points, float line_max_error, float line_cluster_epsilon, float line_min_length, float line_angle_threshold) {
	circles.clear();
	lines.clear();

	detectContours();

	// initialize the used flag
	/*for (auto& polygon : polygons) {
		for (auto& pt : polygon.contour) {
			pt.used = false;
		}
	}*/

	// detect circles
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() < 100) continue;

		std::vector<Circle> results;
		CurveDetector::detect(polygons[i].contour, curve_num_iterations, curve_min_points, curve_max_error_ratio_to_radius, curve_cluster_epsilon, curve_min_angle, curve_min_radius, curve_max_radius, results);
		circles.insert(circles.end(), results.begin(), results.end());
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
	lines.clear();
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i].contour.size() < 100) continue;

		std::vector<Line> results;
		LineDetector::detect(polygons[i].contour, line_num_iterations, line_min_points, line_max_error, line_cluster_epsilon, line_min_length, principal_orientations, line_angle_threshold, results);
		lines.insert(lines.end(), results.begin(), results.end());
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

			for (auto& circle : circles) {
				painter.setPen(QPen(QColor(255, 192, 192), 1));
				for (int i = 0; i < circle.points.size(); i++) {
					painter.drawRect(circle.points[i].x * image_scale - 1, circle.points[i].y * image_scale - 1, 2, 2);
				}

				painter.setPen(QPen(QColor(255, 0, 0), 3));
				painter.drawArc((circle.center.x - circle.radius) * image_scale, (circle.center.y - circle.radius) * image_scale, circle.radius * 2 * image_scale, circle.radius * 2 * image_scale, -circle.start_angle / CV_PI * 180 * 16, -circle.angle_range / CV_PI * 180 * 16);
			}

			for (auto& line : lines) {
				painter.setPen(QPen(QColor(192, 192, 255), 1));
				for (int i = 0; i < line.points.size(); i++) {
					painter.drawRect(line.points[i].x * image_scale - 1, line.points[i].y * image_scale - 1, 2, 2);
				}

				painter.setPen(QPen(QColor(0, 0, 255), 3));
				cv::Point2f p1 = line.point + line.dir * line.start_pos;
				cv::Point2f p2 = line.point + line.dir * line.end_pos;
				painter.drawLine(p1.x * image_scale, p1.y * image_scale, p2.x * image_scale, p2.y * image_scale);
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


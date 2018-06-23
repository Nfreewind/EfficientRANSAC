#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <QWidget>
#include <QKeyEvent>
#include "../EfficientRANSACNoGUI/CurveDetector.h"
#include "../EfficientRANSACNoGUI/LineDetector.h"
#include "../EfficientRANSACNoGUI/MeanShift.h"
#include "../EfficientRANSACNoGUI/OrientationEstimator.h"
#include "../EfficientRANSACNoGUI/PrimitiveShape.h"

class Canvas : public QWidget {
private:
	static enum { TOP_LEFT = 0, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT };

private:
	QImage orig_image;
	QImage image;
	float image_scale;
	std::vector<Polygon> polygons;
	std::vector<std::vector<std::shared_ptr<PrimitiveShape>>> shapes;

	bool ctrlPressed;
	bool shiftPressed;
	
public:
	Canvas(QWidget *parent = NULL);

	void loadImage(const QString& filename);
	void saveImage(const QString& filename);
	void detectContours();
	void detectCurves(int num_iterations, int min_points, float max_error_ratio_to_radius, float cluster_epsilon, float min_angle, float min_radius, float max_radius);
	void detectLines(int num_iterations, int min_points, float max_error, float cluster_epsilon, float min_length, float angle_threshold);
	void detectCurvesLines(int curve_num_iterations, int curve_min_points, float curve_max_error_ratio_to_radius, float curve_cluster_epsilon, float curve_min_angle, float curve_min_radius, float curve_max_radius, int line_num_iterations, int line_min_points, float line_max_error, float line_cluster_epsilon, float line_min_length, float line_angle_threshold);
	void generateContours();
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);

protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent* e);
	void resizeEvent(QResizeEvent *e);
};

#endif // CANVAS_H

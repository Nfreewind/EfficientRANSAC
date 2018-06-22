#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	//std::vector<float> angles = { 0.0f, 0.05f, 1.5f, 1.6f, 3.1f, 0.7f };
	std::vector<float> angles = { 0.05f, 0.8f, 1.5f, 1.6f, 2.3f, 3.1f, 5.4f, 5.5f, 6.2f };
	std::vector<float> ret = MeanShift::cluster(angles, 0.2, 0.2, 5, 0.2);

	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}

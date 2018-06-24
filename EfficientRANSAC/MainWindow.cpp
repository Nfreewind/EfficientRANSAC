#include "MainWindow.h"
#include <QFileDialog>
#include "CurveOptionDialog.h"
#include "LineOptionDialog.h"
#include "CurveLineOptionDialog.h"
#include "ContourOptionDialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	setCentralWidget(&canvas);
	
	// create tool bar for file menu
	ui.mainToolBar->addAction(ui.actionOpen);
	ui.mainToolBar->addAction(ui.actionSave);

	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(onSave()));
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.actionDetectCurves, SIGNAL(triggered()), this, SLOT(onDetectCurves()));
	connect(ui.actionDetectLines, SIGNAL(triggered()), this, SLOT(onDetectLines()));
	connect(ui.actionDetectCurvesLines, SIGNAL(triggered()), this, SLOT(onDetectCurvesLines()));
	connect(ui.actionGenerateContours, SIGNAL(triggered()), this, SLOT(onGenerateContours()));
}

void MainWindow::onOpen() {
	QString filename = QFileDialog::getOpenFileName(this, tr("Load image..."), "", tr("Image files (*.png *.jpg *.bmp)"));
	if (filename.isEmpty()) return;

	setWindowTitle("Efficient RANSAC - " + filename);
	
	canvas.loadImage(filename);
	canvas.update();
}

void MainWindow::onSave() {
	QString filename = QFileDialog::getSaveFileName(this, tr("Save image..."), "", tr("Image files (*.png *.jpg *.bmp)"));
	if (filename.isEmpty()) return;

	canvas.saveImage(filename);
	canvas.update();
}

void MainWindow::onDetectCurves() {
	CurveOptionDialog dlg;
	if (dlg.exec()) {
		canvas.detectCurves(dlg.getNumIterations(), dlg.getMinPoints(), dlg.getMaxErrorRatioToRadius(), dlg.getClusterEpsilon(), dlg.getMinAngle() / 180.0 * CV_PI, dlg.getMinRadius(), dlg.getMaxRadius());
		canvas.update();
	}
}

void MainWindow::onDetectLines() {
	LineOptionDialog dlg;
	if (dlg.exec()) {
		canvas.detectLines(dlg.getNumIterations(), dlg.getMinPoints(), dlg.getMaxError(), dlg.getClusterEpsilon(), dlg.getMinLength(), dlg.getAngleThreshold() / 180.0 * CV_PI);
		canvas.update();
	}
}

void MainWindow::onDetectCurvesLines() {
	CurveLineOptionDialog dlg;
	if (dlg.exec()) {
		canvas.detectCurvesLines(dlg.getCurveNumIterations(), dlg.getCurveMinPoints(), dlg.getCurveMaxErrorRatioToRadius(), dlg.getCurveClusterEpsilon(), dlg.getCurveMinAngle() / 180.0 * CV_PI, dlg.getCurveMinRadius(), dlg.getCurveMaxRadius(), dlg.getLineNumIterations(), dlg.getLineMinPoints(), dlg.getLineMaxError(), dlg.getLineClusterEpsilon(), dlg.getLineMinLength(), dlg.getAngleThreshold() / 180.0 * CV_PI);
		canvas.update();
	}
}

void MainWindow::onGenerateContours() {
	ContourOptionDialog dlg;
	if (dlg.exec()) {
		canvas.generateContours(dlg.getCurveNumIterations(), dlg.getCurveMinPoints(), dlg.getCurveMaxErrorRatioToRadius(), dlg.getCurveClusterEpsilon(), dlg.getCurveMinAngle() / 180.0 * CV_PI, dlg.getCurveMinRadius(), dlg.getCurveMaxRadius(), dlg.getLineNumIterations(), dlg.getLineMinPoints(), dlg.getLineMaxError(), dlg.getLineClusterEpsilon(), dlg.getLineMinLength(), dlg.getAngleThreshold() / 180.0 * CV_PI, dlg.getContourMaxError(), dlg.getContourAngleThreshold() / 180.0 * CV_PI);
		canvas.update();
	}
}

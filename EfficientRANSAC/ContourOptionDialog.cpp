#include "ContourOptionDialog.h"

ContourOptionDialog::ContourOptionDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	ui.lineEditCurveNumIterations->setText("200000");
	ui.lineEditCurveMinPoints->setText("200");
	ui.lineEditCurveMaxErrorRatioToRadius->setText("0.02");
	ui.lineEditCurveClusterEpsilon->setText("30");
	ui.lineEditCurveMinAngle->setText("90");
	ui.lineEditCurveMinRadius->setText("80");
	ui.lineEditCurveMaxRadius->setText("400");

	ui.lineEditLineNumIterations->setText("20000");
	ui.lineEditLineMinPoints->setText("30");
	ui.lineEditLineMaxError->setText("5");
	ui.lineEditLineClusterEpsilon->setText("20");
	ui.lineEditLineMinLength->setText("30");
	ui.lineEditAngleThreshold->setText("15");

	ui.lineEditContourMaxError->setText("20");
	ui.lineEditContourAngleThreshold->setText("10");

	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(onOK()));
	connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(onCancel()));
}

ContourOptionDialog::~ContourOptionDialog() {
}

int ContourOptionDialog::getCurveNumIterations() {
	return ui.lineEditCurveNumIterations->text().toInt();
}

int ContourOptionDialog::getCurveMinPoints() {
	return ui.lineEditCurveMinPoints->text().toInt();
}

float ContourOptionDialog::getCurveMaxErrorRatioToRadius() {
	return ui.lineEditCurveMaxErrorRatioToRadius->text().toFloat();
}

float ContourOptionDialog::getCurveClusterEpsilon() {
	return ui.lineEditCurveClusterEpsilon->text().toFloat();
}

float ContourOptionDialog::getCurveMinAngle() {
	return ui.lineEditCurveMinAngle->text().toFloat();
}

float ContourOptionDialog::getCurveMinRadius() {
	return ui.lineEditCurveMinRadius->text().toFloat();
}

float ContourOptionDialog::getCurveMaxRadius() {
	return ui.lineEditCurveMaxRadius->text().toFloat();
}

int ContourOptionDialog::getLineNumIterations() {
	return ui.lineEditLineNumIterations->text().toInt();
}

int ContourOptionDialog::getLineMinPoints() {
	return ui.lineEditLineMinPoints->text().toInt();
}

float ContourOptionDialog::getLineMaxError() {
	return ui.lineEditLineMaxError->text().toFloat();
}

float ContourOptionDialog::getLineClusterEpsilon() {
	return ui.lineEditLineClusterEpsilon->text().toFloat();
}

float ContourOptionDialog::getLineMinLength() {
	return ui.lineEditLineMinLength->text().toFloat();
}

float ContourOptionDialog::getAngleThreshold() {
	return ui.lineEditAngleThreshold->text().toFloat();
}

float ContourOptionDialog::getContourMaxError() {
	return ui.lineEditContourMaxError->text().toFloat();
}

float ContourOptionDialog::getContourAngleThreshold() {
	return ui.lineEditContourAngleThreshold->text().toFloat();
}

void ContourOptionDialog::onOK() {
	accept();
}

void ContourOptionDialog::onCancel() {
	reject();
}

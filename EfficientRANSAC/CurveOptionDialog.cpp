#include "CurveOptionDialog.h"

CurveOptionDialog::CurveOptionDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	ui.lineEditNumIterations->setText("200000");
	ui.lineEditMinPoints->setText("200");
	ui.lineEditMaxErrorRatioToRadius->setText("0.02");
	ui.lineEditClusterEpsilon->setText("30");
	ui.lineEditMinAngle->setText("90");
	ui.lineEditMinRadius->setText("80");
	ui.lineEditMaxRadius->setText("400");

	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(onOK()));
	connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(onCancel()));
}

CurveOptionDialog::~CurveOptionDialog() {
}

int CurveOptionDialog::getNumIterations() {
	return ui.lineEditNumIterations->text().toInt();
}

int CurveOptionDialog::getMinPoints() {
	return ui.lineEditMinPoints->text().toInt();
}

float CurveOptionDialog::getMaxErrorRatioToRadius() {
	return ui.lineEditMaxErrorRatioToRadius->text().toFloat();
}

float CurveOptionDialog::getClusterEpsilon() {
	return ui.lineEditClusterEpsilon->text().toFloat();
}

float CurveOptionDialog::getMinAngle() {
	return ui.lineEditMinAngle->text().toFloat();
}

float CurveOptionDialog::getMinRadius() {
	return ui.lineEditMinRadius->text().toFloat();
}

float CurveOptionDialog::getMaxRadius() {
	return ui.lineEditMaxRadius->text().toFloat();
}

void CurveOptionDialog::onOK() {
	accept();
}

void CurveOptionDialog::onCancel() {
	reject();
}

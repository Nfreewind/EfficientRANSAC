#include "LineOptionDialog.h"

LineOptionDialog::LineOptionDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	ui.lineEditNumIterations->setText("20000");
	ui.lineEditMinPoints->setText("30");
	ui.lineEditMaxError->setText("5");
	ui.lineEditClusterEpsilon->setText("20");
	ui.lineEditMinLength->setText("30");
	ui.lineEditAngleThreshold->setText("15");

	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(onOK()));
	connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(onCancel()));
}

LineOptionDialog::~LineOptionDialog() {
}

int LineOptionDialog::getNumIterations() {
	return ui.lineEditNumIterations->text().toInt();
}

int LineOptionDialog::getMinPoints() {
	return ui.lineEditMinPoints->text().toInt();
}

float LineOptionDialog::getMaxError() {
	return ui.lineEditMaxError->text().toFloat();
}

float LineOptionDialog::getClusterEpsilon() {
	return ui.lineEditClusterEpsilon->text().toFloat();
}

float LineOptionDialog::getMinLength() {
	return ui.lineEditMinLength->text().toFloat();
}

float LineOptionDialog::getAngleThreshold() {
	return ui.lineEditAngleThreshold->text().toFloat();
}

void LineOptionDialog::onOK() {
	accept();
}

void LineOptionDialog::onCancel() {
	reject();
}

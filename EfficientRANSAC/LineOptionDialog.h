#pragma once

#include <QDialog>
#include "ui_LineOptionDialog.h"

class LineOptionDialog : public QDialog {
	Q_OBJECT

private:
	Ui::LineOptionDialog ui;

public:
	LineOptionDialog(QWidget *parent = Q_NULLPTR);
	~LineOptionDialog();

	int getNumIterations();
	int getMinPoints();
	float getMaxError();
	float getClusterEpsilon();
	float getMinLength();
	float getAngleThreshold();

public slots:
	void onOK();
	void onCancel();
};

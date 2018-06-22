#pragma once

#include <QDialog>
#include "ui_CurveOptionDialog.h"

class CurveOptionDialog : public QDialog {
	Q_OBJECT

private:
	Ui::CurveOptionDialog ui;

public:
	CurveOptionDialog(QWidget *parent = Q_NULLPTR);
	~CurveOptionDialog();
	
	int getNumIterations();
	int getMinPoints();
	float getMaxErrorRatioToRadius();
	float getClusterEpsilon();
	float getMinAngle();
	float getMinRadius();
	float getMaxRadius();

public slots:
	void onOK();
	void onCancel();
};

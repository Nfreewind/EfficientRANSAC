#pragma once

#include <QDialog>
#include "ui_CurveLineOptionDialog.h"

class CurveLineOptionDialog : public QDialog {
	Q_OBJECT

private:
	Ui::CurveLineOptionDialog ui;

public:
	CurveLineOptionDialog(QWidget *parent = Q_NULLPTR);
	~CurveLineOptionDialog();

	int getCurveNumIterations();
	int getCurveMinPoints();
	float getCurveMaxErrorRatioToRadius();
	float getCurveClusterEpsilon();
	float getCurveMinAngle();
	float getCurveMinRadius();
	float getCurveMaxRadius();

	int getLineNumIterations();
	int getLineMinPoints();
	float getLineMaxError();
	float getLineClusterEpsilon();
	float getLineMinLength();
	float getAngleThreshold();

public slots:
	void onOK();
	void onCancel();
};

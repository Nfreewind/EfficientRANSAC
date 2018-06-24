/********************************************************************************
** Form generated from reading UI file 'ContourOptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTOUROPTIONDIALOG_H
#define UI_CONTOUROPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ContourOptionDialog
{
public:
    QPushButton *pushButtonOK;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEditCurveMinAngle;
    QLineEdit *lineEditCurveNumIterations;
    QLabel *label_5;
    QLineEdit *lineEditCurveMaxRadius;
    QLineEdit *lineEditCurveMinRadius;
    QLineEdit *lineEditCurveMaxErrorRatioToRadius;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *lineEditCurveMinPoints;
    QLineEdit *lineEditCurveClusterEpsilon;
    QLabel *label_14;
    QPushButton *pushButtonCancel;
    QGroupBox *groupBox_2;
    QLineEdit *lineEditLineMinLength;
    QLineEdit *lineEditLineClusterEpsilon;
    QLineEdit *lineEditLineMinPoints;
    QLineEdit *lineEditLineMaxError;
    QLineEdit *lineEditLineNumIterations;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEditAngleThreshold;
    QLabel *label_13;
    QLabel *label_15;
    QGroupBox *groupBox_3;
    QLabel *label_16;
    QLineEdit *lineEditContourMaxError;
    QLineEdit *lineEditContourAngleThreshold;
    QLabel *label_17;
    QLabel *label_18;

    void setupUi(QDialog *ContourOptionDialog)
    {
        if (ContourOptionDialog->objectName().isEmpty())
            ContourOptionDialog->setObjectName(QStringLiteral("ContourOptionDialog"));
        ContourOptionDialog->resize(301, 483);
        pushButtonOK = new QPushButton(ContourOptionDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(40, 440, 91, 31));
        groupBox = new QGroupBox(ContourOptionDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 171));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 81, 16));
        lineEditCurveMinAngle = new QLineEdit(groupBox);
        lineEditCurveMinAngle->setObjectName(QStringLiteral("lineEditCurveMinAngle"));
        lineEditCurveMinAngle->setGeometry(QRect(140, 100, 101, 20));
        lineEditCurveNumIterations = new QLineEdit(groupBox);
        lineEditCurveNumIterations->setObjectName(QStringLiteral("lineEditCurveNumIterations"));
        lineEditCurveNumIterations->setGeometry(QRect(140, 20, 101, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 131, 16));
        lineEditCurveMaxRadius = new QLineEdit(groupBox);
        lineEditCurveMaxRadius->setObjectName(QStringLiteral("lineEditCurveMaxRadius"));
        lineEditCurveMaxRadius->setGeometry(QRect(140, 140, 101, 20));
        lineEditCurveMinRadius = new QLineEdit(groupBox);
        lineEditCurveMinRadius->setObjectName(QStringLiteral("lineEditCurveMinRadius"));
        lineEditCurveMinRadius->setGeometry(QRect(140, 120, 101, 20));
        lineEditCurveMaxErrorRatioToRadius = new QLineEdit(groupBox);
        lineEditCurveMaxErrorRatioToRadius->setObjectName(QStringLiteral("lineEditCurveMaxErrorRatioToRadius"));
        lineEditCurveMaxErrorRatioToRadius->setGeometry(QRect(140, 60, 101, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 131, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 131, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 131, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 131, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 20, 81, 16));
        lineEditCurveMinPoints = new QLineEdit(groupBox);
        lineEditCurveMinPoints->setObjectName(QStringLiteral("lineEditCurveMinPoints"));
        lineEditCurveMinPoints->setGeometry(QRect(140, 40, 101, 20));
        lineEditCurveClusterEpsilon = new QLineEdit(groupBox);
        lineEditCurveClusterEpsilon->setObjectName(QStringLiteral("lineEditCurveClusterEpsilon"));
        lineEditCurveClusterEpsilon->setGeometry(QRect(140, 80, 101, 20));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(250, 100, 31, 16));
        pushButtonCancel = new QPushButton(ContourOptionDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(170, 440, 91, 31));
        groupBox_2 = new QGroupBox(ContourOptionDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 190, 281, 151));
        lineEditLineMinLength = new QLineEdit(groupBox_2);
        lineEditLineMinLength->setObjectName(QStringLiteral("lineEditLineMinLength"));
        lineEditLineMinLength->setGeometry(QRect(140, 100, 101, 20));
        lineEditLineClusterEpsilon = new QLineEdit(groupBox_2);
        lineEditLineClusterEpsilon->setObjectName(QStringLiteral("lineEditLineClusterEpsilon"));
        lineEditLineClusterEpsilon->setGeometry(QRect(140, 80, 101, 20));
        lineEditLineMinPoints = new QLineEdit(groupBox_2);
        lineEditLineMinPoints->setObjectName(QStringLiteral("lineEditLineMinPoints"));
        lineEditLineMinPoints->setGeometry(QRect(140, 40, 101, 20));
        lineEditLineMaxError = new QLineEdit(groupBox_2);
        lineEditLineMaxError->setObjectName(QStringLiteral("lineEditLineMaxError"));
        lineEditLineMaxError->setGeometry(QRect(140, 60, 101, 20));
        lineEditLineNumIterations = new QLineEdit(groupBox_2);
        lineEditLineNumIterations->setObjectName(QStringLiteral("lineEditLineNumIterations"));
        lineEditLineNumIterations->setGeometry(QRect(140, 20, 101, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 80, 131, 16));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 20, 81, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 40, 81, 16));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 100, 131, 16));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 60, 131, 16));
        lineEditAngleThreshold = new QLineEdit(groupBox_2);
        lineEditAngleThreshold->setObjectName(QStringLiteral("lineEditAngleThreshold"));
        lineEditAngleThreshold->setGeometry(QRect(140, 120, 101, 20));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 120, 131, 16));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(250, 120, 31, 16));
        groupBox_3 = new QGroupBox(ContourOptionDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 350, 281, 71));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 20, 91, 16));
        lineEditContourMaxError = new QLineEdit(groupBox_3);
        lineEditContourMaxError->setObjectName(QStringLiteral("lineEditContourMaxError"));
        lineEditContourMaxError->setGeometry(QRect(140, 20, 101, 20));
        lineEditContourAngleThreshold = new QLineEdit(groupBox_3);
        lineEditContourAngleThreshold->setObjectName(QStringLiteral("lineEditContourAngleThreshold"));
        lineEditContourAngleThreshold->setGeometry(QRect(140, 40, 101, 20));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 40, 91, 16));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(250, 40, 31, 16));

        retranslateUi(ContourOptionDialog);

        QMetaObject::connectSlotsByName(ContourOptionDialog);
    } // setupUi

    void retranslateUi(QDialog *ContourOptionDialog)
    {
        ContourOptionDialog->setWindowTitle(QApplication::translate("ContourOptionDialog", "ContourOptionDialog", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("ContourOptionDialog", "OK", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ContourOptionDialog", "Curve", Q_NULLPTR));
        label->setText(QApplication::translate("ContourOptionDialog", "Min points:", Q_NULLPTR));
        label_5->setText(QApplication::translate("ContourOptionDialog", "Min radius:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ContourOptionDialog", "Max error ratio to radius:", Q_NULLPTR));
        label_6->setText(QApplication::translate("ContourOptionDialog", "Max radius:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ContourOptionDialog", "Cluster epsilon:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ContourOptionDialog", "Min angle:", Q_NULLPTR));
        label_7->setText(QApplication::translate("ContourOptionDialog", "# iterations:", Q_NULLPTR));
        label_14->setText(QApplication::translate("ContourOptionDialog", "[deg]", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("ContourOptionDialog", "Cancel", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("ContourOptionDialog", "Line", Q_NULLPTR));
        label_8->setText(QApplication::translate("ContourOptionDialog", "Cluster epsilon:", Q_NULLPTR));
        label_9->setText(QApplication::translate("ContourOptionDialog", "# iterations:", Q_NULLPTR));
        label_10->setText(QApplication::translate("ContourOptionDialog", "Min points:", Q_NULLPTR));
        label_11->setText(QApplication::translate("ContourOptionDialog", "Min length:", Q_NULLPTR));
        label_12->setText(QApplication::translate("ContourOptionDialog", "Max error:", Q_NULLPTR));
        label_13->setText(QApplication::translate("ContourOptionDialog", "Angle threshold:", Q_NULLPTR));
        label_15->setText(QApplication::translate("ContourOptionDialog", "[deg]", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ContourOptionDialog", "Contour", Q_NULLPTR));
        label_16->setText(QApplication::translate("ContourOptionDialog", "Max error:", Q_NULLPTR));
        label_17->setText(QApplication::translate("ContourOptionDialog", "Angle threshold:", Q_NULLPTR));
        label_18->setText(QApplication::translate("ContourOptionDialog", "[deg]", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContourOptionDialog: public Ui_ContourOptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTOUROPTIONDIALOG_H

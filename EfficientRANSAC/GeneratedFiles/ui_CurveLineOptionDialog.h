/********************************************************************************
** Form generated from reading UI file 'CurveLineOptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVELINEOPTIONDIALOG_H
#define UI_CURVELINEOPTIONDIALOG_H

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

class Ui_CurveLineOptionDialog
{
public:
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
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *CurveLineOptionDialog)
    {
        if (CurveLineOptionDialog->objectName().isEmpty())
            CurveLineOptionDialog->setObjectName(QStringLiteral("CurveLineOptionDialog"));
        CurveLineOptionDialog->resize(302, 403);
        groupBox = new QGroupBox(CurveLineOptionDialog);
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
        groupBox_2 = new QGroupBox(CurveLineOptionDialog);
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
        pushButtonCancel = new QPushButton(CurveLineOptionDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(170, 360, 91, 31));
        pushButtonOK = new QPushButton(CurveLineOptionDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(40, 360, 91, 31));
        QWidget::setTabOrder(pushButtonOK, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, lineEditCurveNumIterations);
        QWidget::setTabOrder(lineEditCurveNumIterations, lineEditCurveMinPoints);
        QWidget::setTabOrder(lineEditCurveMinPoints, lineEditCurveMaxErrorRatioToRadius);
        QWidget::setTabOrder(lineEditCurveMaxErrorRatioToRadius, lineEditCurveClusterEpsilon);
        QWidget::setTabOrder(lineEditCurveClusterEpsilon, lineEditCurveMinAngle);
        QWidget::setTabOrder(lineEditCurveMinAngle, lineEditCurveMinRadius);
        QWidget::setTabOrder(lineEditCurveMinRadius, lineEditCurveMaxRadius);
        QWidget::setTabOrder(lineEditCurveMaxRadius, lineEditLineNumIterations);
        QWidget::setTabOrder(lineEditLineNumIterations, lineEditLineMinPoints);
        QWidget::setTabOrder(lineEditLineMinPoints, lineEditLineMaxError);
        QWidget::setTabOrder(lineEditLineMaxError, lineEditLineClusterEpsilon);
        QWidget::setTabOrder(lineEditLineClusterEpsilon, lineEditLineMinLength);

        retranslateUi(CurveLineOptionDialog);

        QMetaObject::connectSlotsByName(CurveLineOptionDialog);
    } // setupUi

    void retranslateUi(QDialog *CurveLineOptionDialog)
    {
        CurveLineOptionDialog->setWindowTitle(QApplication::translate("CurveLineOptionDialog", "CurveLineOptionDialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CurveLineOptionDialog", "Curve", Q_NULLPTR));
        label->setText(QApplication::translate("CurveLineOptionDialog", "Min points:", Q_NULLPTR));
        label_5->setText(QApplication::translate("CurveLineOptionDialog", "Min radius:", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurveLineOptionDialog", "Max error ratio to radius:", Q_NULLPTR));
        label_6->setText(QApplication::translate("CurveLineOptionDialog", "Max radius:", Q_NULLPTR));
        label_3->setText(QApplication::translate("CurveLineOptionDialog", "Cluster epsilon:", Q_NULLPTR));
        label_4->setText(QApplication::translate("CurveLineOptionDialog", "Min angle:", Q_NULLPTR));
        label_7->setText(QApplication::translate("CurveLineOptionDialog", "# iterations:", Q_NULLPTR));
        label_14->setText(QApplication::translate("CurveLineOptionDialog", "[deg]", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CurveLineOptionDialog", "Line", Q_NULLPTR));
        label_8->setText(QApplication::translate("CurveLineOptionDialog", "Cluster epsilon:", Q_NULLPTR));
        label_9->setText(QApplication::translate("CurveLineOptionDialog", "# iterations:", Q_NULLPTR));
        label_10->setText(QApplication::translate("CurveLineOptionDialog", "Min points:", Q_NULLPTR));
        label_11->setText(QApplication::translate("CurveLineOptionDialog", "Min length:", Q_NULLPTR));
        label_12->setText(QApplication::translate("CurveLineOptionDialog", "Max error:", Q_NULLPTR));
        label_13->setText(QApplication::translate("CurveLineOptionDialog", "Angle threshold:", Q_NULLPTR));
        label_15->setText(QApplication::translate("CurveLineOptionDialog", "[deg]", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("CurveLineOptionDialog", "Cancel", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("CurveLineOptionDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveLineOptionDialog: public Ui_CurveLineOptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVELINEOPTIONDIALOG_H

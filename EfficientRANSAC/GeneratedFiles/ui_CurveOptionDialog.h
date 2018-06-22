/********************************************************************************
** Form generated from reading UI file 'CurveOptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEOPTIONDIALOG_H
#define UI_CURVEOPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CurveOptionDialog
{
public:
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QLineEdit *lineEditMinPoints;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditMaxErrorRatioToRadius;
    QLabel *label_3;
    QLineEdit *lineEditClusterEpsilon;
    QLabel *label_4;
    QLineEdit *lineEditMinAngle;
    QLabel *label_5;
    QLineEdit *lineEditMinRadius;
    QLabel *label_6;
    QLineEdit *lineEditMaxRadius;
    QLabel *label_7;
    QLineEdit *lineEditNumIterations;
    QLabel *label_8;

    void setupUi(QDialog *CurveOptionDialog)
    {
        if (CurveOptionDialog->objectName().isEmpty())
            CurveOptionDialog->setObjectName(QStringLiteral("CurveOptionDialog"));
        CurveOptionDialog->resize(301, 224);
        pushButtonOK = new QPushButton(CurveOptionDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(40, 180, 91, 31));
        pushButtonCancel = new QPushButton(CurveOptionDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(170, 180, 91, 31));
        lineEditMinPoints = new QLineEdit(CurveOptionDialog);
        lineEditMinPoints->setObjectName(QStringLiteral("lineEditMinPoints"));
        lineEditMinPoints->setGeometry(QRect(150, 40, 101, 20));
        label = new QLabel(CurveOptionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 81, 16));
        label_2 = new QLabel(CurveOptionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 131, 16));
        lineEditMaxErrorRatioToRadius = new QLineEdit(CurveOptionDialog);
        lineEditMaxErrorRatioToRadius->setObjectName(QStringLiteral("lineEditMaxErrorRatioToRadius"));
        lineEditMaxErrorRatioToRadius->setGeometry(QRect(150, 60, 101, 20));
        label_3 = new QLabel(CurveOptionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 131, 16));
        lineEditClusterEpsilon = new QLineEdit(CurveOptionDialog);
        lineEditClusterEpsilon->setObjectName(QStringLiteral("lineEditClusterEpsilon"));
        lineEditClusterEpsilon->setGeometry(QRect(150, 80, 101, 20));
        label_4 = new QLabel(CurveOptionDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 131, 16));
        lineEditMinAngle = new QLineEdit(CurveOptionDialog);
        lineEditMinAngle->setObjectName(QStringLiteral("lineEditMinAngle"));
        lineEditMinAngle->setGeometry(QRect(150, 100, 101, 20));
        label_5 = new QLabel(CurveOptionDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 120, 131, 16));
        lineEditMinRadius = new QLineEdit(CurveOptionDialog);
        lineEditMinRadius->setObjectName(QStringLiteral("lineEditMinRadius"));
        lineEditMinRadius->setGeometry(QRect(150, 120, 101, 20));
        label_6 = new QLabel(CurveOptionDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 140, 131, 16));
        lineEditMaxRadius = new QLineEdit(CurveOptionDialog);
        lineEditMaxRadius->setObjectName(QStringLiteral("lineEditMaxRadius"));
        lineEditMaxRadius->setGeometry(QRect(150, 140, 101, 20));
        label_7 = new QLabel(CurveOptionDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 81, 16));
        lineEditNumIterations = new QLineEdit(CurveOptionDialog);
        lineEditNumIterations->setObjectName(QStringLiteral("lineEditNumIterations"));
        lineEditNumIterations->setGeometry(QRect(150, 20, 101, 20));
        label_8 = new QLabel(CurveOptionDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(260, 100, 31, 16));
        QWidget::setTabOrder(pushButtonOK, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, lineEditNumIterations);
        QWidget::setTabOrder(lineEditNumIterations, lineEditMinPoints);
        QWidget::setTabOrder(lineEditMinPoints, lineEditMaxErrorRatioToRadius);
        QWidget::setTabOrder(lineEditMaxErrorRatioToRadius, lineEditClusterEpsilon);
        QWidget::setTabOrder(lineEditClusterEpsilon, lineEditMinAngle);
        QWidget::setTabOrder(lineEditMinAngle, lineEditMinRadius);
        QWidget::setTabOrder(lineEditMinRadius, lineEditMaxRadius);

        retranslateUi(CurveOptionDialog);

        QMetaObject::connectSlotsByName(CurveOptionDialog);
    } // setupUi

    void retranslateUi(QDialog *CurveOptionDialog)
    {
        CurveOptionDialog->setWindowTitle(QApplication::translate("CurveOptionDialog", "Curve Option Dialog", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("CurveOptionDialog", "OK", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("CurveOptionDialog", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("CurveOptionDialog", "Min points:", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurveOptionDialog", "Max error ratio to radius:", Q_NULLPTR));
        label_3->setText(QApplication::translate("CurveOptionDialog", "Cluster epsilon:", Q_NULLPTR));
        label_4->setText(QApplication::translate("CurveOptionDialog", "Min angle:", Q_NULLPTR));
        label_5->setText(QApplication::translate("CurveOptionDialog", "Min radius:", Q_NULLPTR));
        label_6->setText(QApplication::translate("CurveOptionDialog", "Max radius:", Q_NULLPTR));
        label_7->setText(QApplication::translate("CurveOptionDialog", "# iterations:", Q_NULLPTR));
        label_8->setText(QApplication::translate("CurveOptionDialog", "[deg]", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveOptionDialog: public Ui_CurveOptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEOPTIONDIALOG_H

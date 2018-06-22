/********************************************************************************
** Form generated from reading UI file 'OptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

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

class Ui_OptionDialog
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

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QStringLiteral("OptionDialog"));
        OptionDialog->resize(301, 224);
        pushButtonOK = new QPushButton(OptionDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(40, 180, 91, 31));
        pushButtonCancel = new QPushButton(OptionDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(170, 180, 91, 31));
        lineEditMinPoints = new QLineEdit(OptionDialog);
        lineEditMinPoints->setObjectName(QStringLiteral("lineEditMinPoints"));
        lineEditMinPoints->setGeometry(QRect(170, 40, 113, 20));
        label = new QLabel(OptionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 81, 16));
        label_2 = new QLabel(OptionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 131, 16));
        lineEditMaxErrorRatioToRadius = new QLineEdit(OptionDialog);
        lineEditMaxErrorRatioToRadius->setObjectName(QStringLiteral("lineEditMaxErrorRatioToRadius"));
        lineEditMaxErrorRatioToRadius->setGeometry(QRect(170, 60, 113, 20));
        label_3 = new QLabel(OptionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 131, 16));
        lineEditClusterEpsilon = new QLineEdit(OptionDialog);
        lineEditClusterEpsilon->setObjectName(QStringLiteral("lineEditClusterEpsilon"));
        lineEditClusterEpsilon->setGeometry(QRect(170, 80, 113, 20));
        label_4 = new QLabel(OptionDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 131, 16));
        lineEditMinAngle = new QLineEdit(OptionDialog);
        lineEditMinAngle->setObjectName(QStringLiteral("lineEditMinAngle"));
        lineEditMinAngle->setGeometry(QRect(170, 100, 113, 20));
        label_5 = new QLabel(OptionDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 120, 131, 16));
        lineEditMinRadius = new QLineEdit(OptionDialog);
        lineEditMinRadius->setObjectName(QStringLiteral("lineEditMinRadius"));
        lineEditMinRadius->setGeometry(QRect(170, 120, 113, 20));
        label_6 = new QLabel(OptionDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 140, 131, 16));
        lineEditMaxRadius = new QLineEdit(OptionDialog);
        lineEditMaxRadius->setObjectName(QStringLiteral("lineEditMaxRadius"));
        lineEditMaxRadius->setGeometry(QRect(170, 140, 113, 20));
        label_7 = new QLabel(OptionDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 81, 16));
        lineEditNumIterations = new QLineEdit(OptionDialog);
        lineEditNumIterations->setObjectName(QStringLiteral("lineEditNumIterations"));
        lineEditNumIterations->setGeometry(QRect(170, 20, 113, 20));

        retranslateUi(OptionDialog);

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QApplication::translate("OptionDialog", "OptionDialog", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("OptionDialog", "OK", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("OptionDialog", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("OptionDialog", "min points:", Q_NULLPTR));
        label_2->setText(QApplication::translate("OptionDialog", "Max error ratio to radius:", Q_NULLPTR));
        label_3->setText(QApplication::translate("OptionDialog", "Cluster epsilon:", Q_NULLPTR));
        label_4->setText(QApplication::translate("OptionDialog", "Min angle:", Q_NULLPTR));
        label_5->setText(QApplication::translate("OptionDialog", "Min radius:", Q_NULLPTR));
        label_6->setText(QApplication::translate("OptionDialog", "Max radius:", Q_NULLPTR));
        label_7->setText(QApplication::translate("OptionDialog", "# iterations:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'LineOptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEOPTIONDIALOG_H
#define UI_LINEOPTIONDIALOG_H

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

class Ui_LineOptionDialog
{
public:
    QLabel *label;
    QLineEdit *lineEditMaxError;
    QLineEdit *lineEditNumIterations;
    QLabel *label_3;
    QLineEdit *lineEditMinLength;
    QLineEdit *lineEditMinPoints;
    QLineEdit *lineEditClusterEpsilon;
    QLabel *label_4;
    QLabel *label_7;
    QPushButton *pushButtonCancel;
    QLabel *label_2;
    QPushButton *pushButtonOK;
    QLabel *label_5;
    QLineEdit *lineEditAngleThreshold;
    QLabel *label_6;

    void setupUi(QDialog *LineOptionDialog)
    {
        if (LineOptionDialog->objectName().isEmpty())
            LineOptionDialog->setObjectName(QStringLiteral("LineOptionDialog"));
        LineOptionDialog->resize(302, 204);
        label = new QLabel(LineOptionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 81, 16));
        lineEditMaxError = new QLineEdit(LineOptionDialog);
        lineEditMaxError->setObjectName(QStringLiteral("lineEditMaxError"));
        lineEditMaxError->setGeometry(QRect(150, 60, 101, 20));
        lineEditNumIterations = new QLineEdit(LineOptionDialog);
        lineEditNumIterations->setObjectName(QStringLiteral("lineEditNumIterations"));
        lineEditNumIterations->setGeometry(QRect(150, 20, 101, 20));
        label_3 = new QLabel(LineOptionDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 131, 16));
        lineEditMinLength = new QLineEdit(LineOptionDialog);
        lineEditMinLength->setObjectName(QStringLiteral("lineEditMinLength"));
        lineEditMinLength->setGeometry(QRect(150, 100, 101, 20));
        lineEditMinPoints = new QLineEdit(LineOptionDialog);
        lineEditMinPoints->setObjectName(QStringLiteral("lineEditMinPoints"));
        lineEditMinPoints->setGeometry(QRect(150, 40, 101, 20));
        lineEditClusterEpsilon = new QLineEdit(LineOptionDialog);
        lineEditClusterEpsilon->setObjectName(QStringLiteral("lineEditClusterEpsilon"));
        lineEditClusterEpsilon->setGeometry(QRect(150, 80, 101, 20));
        label_4 = new QLabel(LineOptionDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 131, 16));
        label_7 = new QLabel(LineOptionDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 20, 81, 16));
        pushButtonCancel = new QPushButton(LineOptionDialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(170, 160, 91, 31));
        label_2 = new QLabel(LineOptionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 131, 16));
        pushButtonOK = new QPushButton(LineOptionDialog);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(40, 160, 91, 31));
        label_5 = new QLabel(LineOptionDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 120, 131, 16));
        lineEditAngleThreshold = new QLineEdit(LineOptionDialog);
        lineEditAngleThreshold->setObjectName(QStringLiteral("lineEditAngleThreshold"));
        lineEditAngleThreshold->setGeometry(QRect(150, 120, 101, 20));
        label_6 = new QLabel(LineOptionDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 120, 31, 16));
        QWidget::setTabOrder(pushButtonOK, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, lineEditNumIterations);
        QWidget::setTabOrder(lineEditNumIterations, lineEditMinPoints);
        QWidget::setTabOrder(lineEditMinPoints, lineEditMaxError);
        QWidget::setTabOrder(lineEditMaxError, lineEditClusterEpsilon);
        QWidget::setTabOrder(lineEditClusterEpsilon, lineEditMinLength);

        retranslateUi(LineOptionDialog);

        QMetaObject::connectSlotsByName(LineOptionDialog);
    } // setupUi

    void retranslateUi(QDialog *LineOptionDialog)
    {
        LineOptionDialog->setWindowTitle(QApplication::translate("LineOptionDialog", "Line Option Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("LineOptionDialog", "Min points:", Q_NULLPTR));
        label_3->setText(QApplication::translate("LineOptionDialog", "Cluster epsilon:", Q_NULLPTR));
        label_4->setText(QApplication::translate("LineOptionDialog", "Min length:", Q_NULLPTR));
        label_7->setText(QApplication::translate("LineOptionDialog", "# iterations:", Q_NULLPTR));
        pushButtonCancel->setText(QApplication::translate("LineOptionDialog", "Cancel", Q_NULLPTR));
        label_2->setText(QApplication::translate("LineOptionDialog", "Max error:", Q_NULLPTR));
        pushButtonOK->setText(QApplication::translate("LineOptionDialog", "OK", Q_NULLPTR));
        label_5->setText(QApplication::translate("LineOptionDialog", "Angle threshold:", Q_NULLPTR));
        label_6->setText(QApplication::translate("LineOptionDialog", "[deg]", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LineOptionDialog: public Ui_LineOptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEOPTIONDIALOG_H

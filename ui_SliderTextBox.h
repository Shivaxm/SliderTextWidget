/********************************************************************************
** Form generated from reading UI file 'SliderTextBox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDERTEXTBOX_H
#define UI_SLIDERTEXTBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "SliderTextBox.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    SliderTextBox *widget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        widget = new SliderTextBox(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 50, 120, 80));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDERTEXTBOX_H

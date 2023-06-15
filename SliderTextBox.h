#ifndef SLIDERTEXTBOX_H
#define SLIDERTEXTBOX_H

#endif // SLIDERTEXTBOX_H
#pragma once

#include <QHBoxLayout>
#include <QLineEdit>
#include <QSlider>
#include <QIntValidator>
#include <QPalette>
#include "DelayedInitializationWidget.h"


class SliderTextBox : public DelayedInitializationWidget<QWidget>
{
    Q_OBJECT

public:
    SliderTextBox(QWidget *parent = nullptr);

protected:
    void initialize() override;

private:
    QLineEdit m_lineEdit;
    QSlider m_slider{Qt::Horizontal};

private slots:
    void onSliderValueChanged(int value);
    void onLineEditTextChanged(const QString &text);
};

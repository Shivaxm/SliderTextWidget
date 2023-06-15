#include "SliderTextBox.h"


SliderTextBox::SliderTextBox(QWidget *parent)
    : DelayedInitializationWidget(parent)
{
    // Set up a validator to limit input to numbers between 0 and 100
    m_lineEdit.setValidator(new QIntValidator(0, 100, this));

    // Connect signals and slots for the slider and line edit
    connect(&m_slider, &QSlider::valueChanged, this, &SliderTextBox::onSliderValueChanged);
    connect(&m_lineEdit, &QLineEdit::textChanged, this, &SliderTextBox::onLineEditTextChanged);

    // Set the initial slider value
    m_slider.setValue(0);
}

void SliderTextBox::initialize()
{
    auto layout = new QHBoxLayout(this);
    layout->addWidget(&m_lineEdit);
    layout->addWidget(&m_slider);
}

void SliderTextBox::onSliderValueChanged(int value)
{
    m_lineEdit.setText(QString::number(value));
}

void SliderTextBox::onLineEditTextChanged(const QString &text)
{
    bool ok;
    int value = text.toInt(&ok);

    // if the text in the QLineEdit can be converted to an int (ok == true),
    // set the slider value to this int
    if (ok)
        m_slider.setValue(value);

    QPalette palette = m_lineEdit.palette();
    if (value > 100 || value <0 ||!ok ) {
        palette.setColor(QPalette::Text, Qt::red);
        m_lineEdit.setPalette(palette);
    } else {
        palette.setColor(QPalette::Text, Qt::black);
        m_lineEdit.setPalette(palette);
    }
}

#include "SliderTextWidgetPlugin.h"
#include "SliderTextBox.h"
#include <QtPlugin>

SliderTextWidgetPlugin::SliderTextWidgetPlugin(QObject *parent)
    : QObject(parent), m_initialized(false)
{
    m_maxValue = 100;
}

QWidget *SliderTextWidgetPlugin::createWidget(QWidget *parent)
{
    return new SliderTextBox(parent);
}

void SliderTextWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    m_initialized = true;
}

bool SliderTextWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QString SliderTextWidgetPlugin::name() const
{
    return QLatin1String("SliderTextBox");
}

QString SliderTextWidgetPlugin::group() const
{
    return QLatin1String("Custom Widgets");
}

QIcon SliderTextWidgetPlugin::icon() const
{
    return QIcon();
}

QString SliderTextWidgetPlugin::toolTip() const
{
    return QLatin1String("A custom Slider TextBox widget");
}

QString SliderTextWidgetPlugin::whatsThis() const
{
    return QLatin1String("This is a custom widget that provides a slider with an accompanying text box");
}

bool SliderTextWidgetPlugin::isContainer() const
{
    return false;
}

QString SliderTextWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"SliderTextBox\" name=\"sliderTextBox\">\n</widget>\n");
}

QString SliderTextWidgetPlugin::includeFile() const
{
    return QLatin1String("SliderTextBox.h");
}

Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")

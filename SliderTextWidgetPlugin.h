#ifndef SLIDERTEXTWIDGETPLUGIN_H
#define SLIDERTEXTWIDGETPLUGIN_H

#include <QObject>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <QDesignerFormEditorInterface>
#include <QWidget>
#include <QLineEdit>
#include <QSlider>
#include <QVBoxLayout>
#include <QIntValidator>


    class SliderTextWidgetPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
#endif // QT_VERSION >= 0x050000

public:
    explicit SliderTextWidgetPlugin(QObject *parent = nullptr);
    ~SliderTextWidgetPlugin() = default;
    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);
    void setMaxValue(int maxValue);



private:
    int m_maxValue;
    bool m_initialized;
};

#endif // SLIDERTEXTBOX_H


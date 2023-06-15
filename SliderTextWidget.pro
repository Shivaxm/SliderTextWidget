CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(SliderTextWidgetPlugin)
TEMPLATE    = lib

HEADERS     = SliderTextWidgetPlugin.h \
    DelayedInitializationWidget.h \
    ImageViewer.h \
    SliderTextBox.h
SOURCES     = SliderTextWidgetPlugin.cpp \
    ImageViewer.cpp \
    SliderTextBox.cpp \
    main.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(SliderTextWidget.pri)

DISTFILES += \
    CMakeLists.txt

FORMS += \
    ImageViewer.ui

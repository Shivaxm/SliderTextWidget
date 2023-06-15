#pragma once

#include "slidertextboxlib_export.h"
#include <QWidget>

namespace Ui {
class ImageViewer;
}

class SLIDERTEXTBOXLIB_EXPORT ImageViewer : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

private:
    Ui::ImageViewer *ui;
};

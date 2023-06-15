#include "ImageViewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewer viewer;
    viewer.show();
    return a.exec();
}

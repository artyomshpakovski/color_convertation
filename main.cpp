#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget app;
    app.setWindowTitle("Color converter");
    app.show();
    return a.exec();
}

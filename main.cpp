#include "widget.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QPalette Pal;


    Pal.setColor(QPalette::Background, Qt::black);
    w.setAutoFillBackground(true);
    w.setPalette(Pal);
    w.show();
    return a.exec();
}

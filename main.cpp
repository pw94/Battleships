#include "boardwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BoardWidget w;
    w.show();

    return a.exec();
}

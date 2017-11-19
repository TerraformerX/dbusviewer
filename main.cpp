#include "dbusviewer.h"
#include <QApplication>
//#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBusViewer w;
    w.show();

    return a.exec();
}

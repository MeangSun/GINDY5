#include <QtGui/QApplication>
#include "mainpage.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Mainpage w(a.applicationDirPath());
    //qDebug()<<w.appdir;
    w.show();
    
    return a.exec();
}

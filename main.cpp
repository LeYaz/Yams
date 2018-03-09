#include "mainwindow.h"
#include "pageacceuil.hpp"
#include <QApplication>
#include "pagenouvellepartie.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    PageAcceuil p1;



    p1.show();
    //p.show();







    return a.exec();
}

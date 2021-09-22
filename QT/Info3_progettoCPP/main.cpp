#include "Carfleetmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarFleetManager w;
    w.show();
    return a.exec();
}

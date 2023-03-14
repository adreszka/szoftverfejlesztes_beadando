#include "adatbazis.h"
#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Adatbazis::getObjektum().csatlakozas("autokereskedes.sqlite");
    Adatbazis::getObjektum().autokBeolvas();
    Adatbazis::getObjektum().felhasznaloBeolvas("teszt");
    Adatbazis::getObjektum().markaBeolvasas();

    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}

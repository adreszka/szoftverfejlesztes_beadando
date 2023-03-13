#include "adatbazis.h"
#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Adatbazis adatb;
    adatb.csatlakozas("autokereskedes.sqlite");
    adatb.autokBeolvas();
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}

#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //nagy a faszom
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //ablak beállítások
    setWindowTitle("Autó kereskedés");
    setWindowIcon(QIcon(":kepek/appIcon.png"));

    setFixedSize(800, 600);

    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
    ui->stackedWidgetUnregistered->setCurrentWidget(ui->purchasePageUnregistered);

    //alap listázás
    QWidget *elemek = new QWidget();
    ui->listaUnregistered->setWidget(elemek);
    QVBoxLayout *elemTarolo = new QVBoxLayout(elemek);

    for(int i = 0; i < 20; ++i)
    {
        QHBoxLayout *rekord = new QHBoxLayout();
        elemTarolo->addLayout(rekord);
        for(int i = 0; i < 2; ++i)
        {
            QPushButton *button = new QPushButton();
            rekord->addWidget(button);
        }
    }
}

Dialog::~Dialog()
{
    delete ui;
}


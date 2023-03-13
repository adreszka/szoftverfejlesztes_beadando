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

    setFixedSize(800, 800);

    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
    ui->stackedWidgetUnregistered->setCurrentWidget(ui->purchasePageUnregistered);

    //alap listázás
    ui->listUnregistered->setWidget(elemek);

//    for(int i = 0; i < 30; ++i)
//    {
//        QHBoxLayout *rekord = new QHBoxLayout();
//        elemTarolo->addLayout(rekord);
//        for(int i = 0; i < 2; ++i)
//        {
//            QPushButton *button = new QPushButton();
//            rekord->addWidget(button);
//        }
//    }
    listazas(Tarolo::getObjektum());

    //unregistered feltöltés
    ui->brandComboBoxUnregistered->addItem("Válasszon");
    ui->typeComboBoxUnregistered->addItem("Válasszon");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::listazas(list<Auto> autok)
{
//    for(int i = 0; i < 10; ++i)
//    {
//        QHBoxLayout *rekord = new QHBoxLayout();
//        elemTarolo->addLayout(rekord);
//        QPushButton *button = new QPushButton();
//        rekord->addWidget(button);
//    }
}

//unregistered page
void Dialog::on_loginButtonUnregistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->authenticationPage);
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->loginPage);
}

//authentication page
void Dialog::on_backButtonAuthentication_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
}

//login page
void Dialog::on_registrationButtonLogin_clicked()
{
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->registrationPage);
}

void Dialog::on_loginButtonLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
}

//registration page
void Dialog::on_registrationButtonRegistration_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
}


void Dialog::on_loginButtonRegistration_clicked()
{
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->loginPage);
}


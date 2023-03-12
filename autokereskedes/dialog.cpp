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

    //unregistered feltöltés
    ui->brandComboBoxUnregistered->addItem("Válasszon");
    ui->typeComboBoxUnregistered->addItem("Válasszon");
    ui->fromPurchaseSpinBoxUnregistered->setMinimum(0);
    ui->toPurchaseSpinBoxUnregistered->setMinimum(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_loginButtonUnregistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->authenticationPage);
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->loginPage);
}

void Dialog::on_registrationButtonLogin_clicked()
{
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->registrationPage);
}

void Dialog::on_pushButton_clicked()
{
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->loginPage);
}

void Dialog::on_backButtonAuthentication_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
}


void Dialog::on_loginButtonLogin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
}


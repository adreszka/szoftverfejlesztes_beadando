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

    listazas(Tarolo::getObjektum().getAutok());

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
    for(auto i : autok)
    {
        QHBoxLayout *rekord = new QHBoxLayout();
        elemTarolo->addLayout(rekord);

        QPushButton *button = new QPushButton();
        button->setText(QString::fromStdString(i.getMarka() + " " + i.getTipus()));
        rekord->addWidget(button);

        QLabel *ar = new QLabel();
        ar->setText(QString::fromStdString(to_string(i.getAr())));
        rekord->addWidget(ar);
    }
}

//unregistered page
void Dialog::on_loginButtonUnregistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->authenticationPage);
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->loginPage);
}

void Dialog::on_filerButtonUnregistered_clicked()
{
    while(elemTarolo->count() != 0)
    {
        QLayoutItem *i = elemTarolo->takeAt(0);
        delete i->widget();
        delete i;
    }

//    QLayoutItem *item;
//    QLayout *sublayout;
//    QWidget *widget;
//    while(item = elemTarolo->takeAt(0))
//    {
//        if((sublayout = item->layout()) != 0)
//        {

//        }else if((widget = item->widget()) != 0)
//        {
//            widget->hide();
//            delete widget;
//        }else{
//            delete item;
//        }
//    }

    string uzemanyag[3] = {ui->gasCheckBoxUnregistered->isChecked()?ui->gasCheckBoxUnregistered->text().toStdString():"",
                           ui->electronicCheckBoxUnregistered->isChecked()?ui->electronicCheckBoxUnregistered->text().toStdString():"",
                      ui->dieselCheckBoxUnregistered->isChecked()?ui->dieselCheckBoxUnregistered->text().toStdString():""};
    string meghajtas[3] = {ui->fwdCheckBoxUnregistered->isChecked()?"FWD":"",
                           ui->rwdCheckBoxUnregistered->isChecked()?"RWD":"",
                           ui->awdCheckBoxUnregistered->isChecked()?"AWD":""};
    string kialakitas[3] = {ui->hatchbackCheckBoxUnregistered->isChecked()?"Ferde_hátú":"",
                            ui->sedanCheckBoxUnregistered->isChecked()?"Sedan":"",
                            ui->suvCheckBoxUnregistered->isChecked()?"SUV":""};
    string sebvalto[2] = {ui->manualCheckBoxUnregistered->isChecked()?"Manuális":"",
                          ui->automaticCheckBoxUnregistered->isChecked()?"Automata":""};
    string felszereltseg[6] = {ui->gpsCheckBoxUnregistered->isChecked()?"GPS":"",
                            ui->acCheckBoxUnregistered->isChecked()?"Klíma":"",
                            ui->rocketCheckBoxUnregistered->isChecked()?"Rakéta":"",
                            ui->absCheckBoxUnregistered->isChecked()?"ABS":"",
                            ui->espCheckBoxUnregistered->isChecked()?"ESP":"",
                            ui->radarCheckBoxUnregistered->isChecked()?"Tolatóradar":""};

    listazas(kereses(ui->brandComboBoxUnregistered->currentText().toStdString(),
                    ui->typeComboBoxUnregistered->currentText().toStdString(),
                    pair<int,int>(ui->fromPriceSpinBoxUnregistered->value(), ui->toPriceSpinBoxUnregistered->value()),
                    pair<int,int>(ui->FromRentSpinBoxUnregistered->value(), ui->toRentSpinBoxUnregistered->value()),
                    pair<int,int>(ui->fromYearSpinBoxUnregistered->value(), ui->toYearSpinBoxUnregistered->value()),
                    uzemanyag,
                    meghajtas,
                    kialakitas,
                    pair<int,int>(ui->fromPowerSpinBoxUnregistered->value(), ui->toPowerSpinBoxUnregistered->value()),
                    pair<int,int>(ui->fromSizeSpinBoxUnregistered->value(), ui->toSizeSpinBoxUnregistered->value()),
                    sebvalto,
                    felszereltseg));
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

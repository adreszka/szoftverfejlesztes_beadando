#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //window settings
    setWindowTitle("Autó kereskedés");
    setWindowIcon(QIcon(":kepek/appIcon.png"));

    setFixedSize(800, 800);

    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
    ui->stackedWidgetUnregistered->setCurrentWidget(ui->purchasePageUnregistered);

    //listing on unregistered page
    ui->listUnregistered->setWidget(itemsUnregistered);

    listUnregistered(Tarolo::getObjektum().getAutok());

    //listing on registered page
    ui->listRegistered->setWidget(itemsRegistered);

    listRegistered(Tarolo::getObjektum().getAutok());

    //unregistered comboBox
    ui->brandComboBoxUnregistered->addItem("Válasszon");
    ui->typeComboBoxUnregistered->addItem("Válasszon");

    map<string, list<string>> brandsUnregisterered = Tarolo::getObjektum().getMarkak();
    for(auto i : brandsUnregisterered)
    {
        ui->brandComboBoxUnregistered->addItem(QString::fromStdString(i.first));
    }

    //registered comboBox
    ui->brandComboBoxRegistered->addItem("Válasszon");
    ui->typeComboBoxRegistered->addItem("Válasszon");

    map<string, list<string>> brandsRegistered = Tarolo::getObjektum().getMarkak();
    for(auto i : brandsRegistered)
    {
        ui->brandComboBoxRegistered->addItem(QString::fromStdString(i.first));
    }

    //unregistered car equipments
    ui->gpsCheckBoxCarUnregistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->gpsCheckBoxCarUnregistered->setFocusPolicy(Qt::NoFocus);

    ui->acCheckBoxCarUnregistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->acCheckBoxCarUnregistered->setFocusPolicy(Qt::NoFocus);

    ui->rocketCheckBoxCarUnregistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->rocketCheckBoxCarUnregistered->setFocusPolicy(Qt::NoFocus);

    ui->absCheckBoxCarUnregistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->absCheckBoxCarUnregistered->setFocusPolicy(Qt::NoFocus);

    ui->espCheckBoxCarUnregistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->espCheckBoxCarUnregistered->setFocusPolicy(Qt::NoFocus);

    ui->radarCheckBoxCarUnregistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->radarCheckBoxCarUnregistered->setFocusPolicy(Qt::NoFocus);

    //registered car equipments
    ui->gpsCheckBoxCarRegistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->gpsCheckBoxCarRegistered->setFocusPolicy(Qt::NoFocus);

    ui->acCheckBoxCarRegistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->acCheckBoxCarRegistered->setFocusPolicy(Qt::NoFocus);

    ui->rocketCheckBoxCarRegistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->rocketCheckBoxCarRegistered->setFocusPolicy(Qt::NoFocus);

    ui->absCheckBoxCarRegistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->absCheckBoxCarRegistered->setFocusPolicy(Qt::NoFocus);

    ui->espCheckBoxCarRegistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->espCheckBoxCarRegistered->setFocusPolicy(Qt::NoFocus);

    ui->radarCheckBoxCarRegistered->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->radarCheckBoxCarRegistered->setFocusPolicy(Qt::NoFocus);
}

Dialog::~Dialog()
{
    delete ui;
}

//unregistered page
void Dialog::showCarUnregisteredPage(Auto car)
{
    ui->stackedWidget->setCurrentWidget(ui->carUnregisteredPage);

    //clear equipments
    ui->gpsCheckBoxCarUnregistered->setChecked(false);
    ui->acCheckBoxCarUnregistered->setChecked(false);
    ui->rocketCheckBoxCarUnregistered->setChecked(false);
    ui->absCheckBoxCarUnregistered->setChecked(false);
    ui->espCheckBoxCarUnregistered->setChecked(false);
    ui->radarCheckBoxCarUnregistered->setChecked(false);

    //set values
    ui->nameLabelCarUnregistered->setText(QString::fromStdString(car.getMarka() + " " + car.getTipus()));
    ui->yearValueLabelCarUnregistered->setText(QString::fromStdString(to_string(car.getEvjarat())));
    ui->fuelValueLabelCarUnregistered->setText(QString::fromStdString(car.getUzemanyag()));
    ui->powerValueLabelCarUnregistered->setText(QString::fromStdString(to_string(car.getMotor_teljesitmeny()) + " LE"));
    ui->sizeValueLabelCarUnregistered->setText(QString::fromStdString(to_string(car.getHengerutartalom())));
    ui->driveValueLabelCarUnregistered->setText(QString::fromStdString(car.getHajtas()));
    ui->gearValueLabelCarUnregistered->setText(QString::fromStdString(car.getSebessegvalto()));
    ui->designValueLabelCarUnregistered->setText(QString::fromStdString(car.getKialakitas()));
    ui->trunkValueLabelCarUnregistered->setText(QString::fromStdString(to_string(car.getCsomagtarto_meret())));
    ui->priceValueLabelCarUnregistered->setText(QString::fromStdString(to_string(car.getAr())));
    ui->rentValueLabelCarUnregistered->setText(QString::fromStdString(to_string(car.getNapidij())));

    for(string i : car.getFelszerelesek())
    {
        if(i == "GPS")
            ui->gpsCheckBoxCarUnregistered->setChecked(true);
        if(i == "Klíma")
            ui->acCheckBoxCarUnregistered->setChecked(true);
        if(i == "Rakéta")
            ui->rocketCheckBoxCarUnregistered->setChecked(true);
        if(i == "ABS")
            ui->absCheckBoxCarUnregistered->setChecked(true);
        if(i == "ESP")
            ui->espCheckBoxCarUnregistered->setChecked(true);
        if(i == "Tolatóradar")
            ui->radarCheckBoxCarUnregistered->setChecked(true);
    }
}

void Dialog::listUnregistered(list<Auto> cars)
{
    //delete records
    for(auto i : itemListUnregistered)
    {
        for(auto j : i.second.second)
        {
            j->deleteLater();
        }

        i.second.first->deleteLater();
        i.first->deleteLater();
    }
    itemListUnregistered.clear();

    //add records
    for(auto i : cars)
    {
        QHBoxLayout *record = new QHBoxLayout();
        itemContainerUnregistered->addLayout(record);
        itemListUnregistered.insert(pair<QHBoxLayout*, pair<QPushButton*, list<QLabel*>>>(record, pair<QPushButton*, list<QLabel*>>()));

        QPushButton *button = new QPushButton();
        button->setText(QString::fromStdString(i.getMarka() + " " + i.getTipus()));
        connect(button, &QPushButton::clicked, [=]{showCarUnregisteredPage(i);});
        record->addWidget(button);
        itemListUnregistered[record] = pair<QPushButton*, list<QLabel*>>(button, list<QLabel*>());

        QLabel *price = new QLabel();
        price->setText(QString::fromStdString(to_string(i.getAr())));
        record->addWidget(price);
        itemListUnregistered[record].second.push_back(price);

        QLabel *rentPrice = new QLabel();
        rentPrice->setText(QString::fromStdString(to_string(i.getNapidij())));
        record->addWidget(rentPrice);
        itemListUnregistered[record].second.push_back(rentPrice);
    }
}

void Dialog::on_loginButtonUnregistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->authenticationPage);
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->loginPage);
}

void Dialog::on_filerButtonUnregistered_clicked()
{
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

    listUnregistered(kereses(ui->brandComboBoxUnregistered->currentText().toStdString(),
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

void Dialog::on_brandComboBoxUnregistered_currentIndexChanged(int index)
{
    ui->typeComboBoxUnregistered->clear();

    ui->typeComboBoxUnregistered->addItem("Válasszon");

    map<string, list<string>> temp = Tarolo::getObjektum().getMarkak();
    for(auto i : temp)
    {
        if(i.first == ui->brandComboBoxUnregistered->currentText().toStdString())
        {
            for(auto j : i.second)
            {
                ui->typeComboBoxUnregistered->addItem(QString::fromStdString(j));
            }
            break;
        }
    }
}

//registered page
void Dialog::showCarRegisteredPage(Auto car)
{
    ui->stackedWidget->setCurrentWidget(ui->carRegisteredPage);

    //clear equipments
    ui->gpsCheckBoxCarRegistered->setChecked(false);
    ui->acCheckBoxCarRegistered->setChecked(false);
    ui->rocketCheckBoxCarRegistered->setChecked(false);
    ui->absCheckBoxCarRegistered->setChecked(false);
    ui->espCheckBoxCarRegistered->setChecked(false);
    ui->radarCheckBoxCarRegistered->setChecked(false);

    //set values
    ui->licenceValueCarRegistered->setText(QString::fromStdString(car.getRendszam()));
    ui->nameLabelCarRegistered->setText(QString::fromStdString(car.getMarka() + " " + car.getTipus()));
    ui->yearValueLabelCarRegistered->setText(QString::fromStdString(to_string(car.getEvjarat())));
    ui->fuelValueLabelCarRegistered->setText(QString::fromStdString(car.getUzemanyag()));
    ui->powerValueLabelCarRegistered->setText(QString::fromStdString(to_string(car.getMotor_teljesitmeny()) + " LE"));
    ui->sizeValueLabelCarRegistered->setText(QString::fromStdString(to_string(car.getHengerutartalom())));
    ui->driveValueLabelCarRegistered->setText(QString::fromStdString(car.getHajtas()));
    ui->gearValueLabelCarRegistered->setText(QString::fromStdString(car.getSebessegvalto()));
    ui->designValueLabelCarRegistered->setText(QString::fromStdString(car.getKialakitas()));
    ui->trunkValueLabelCarRegistered->setText(QString::fromStdString(to_string(car.getCsomagtarto_meret())));
    ui->priceValueLabelCarRegistered->setText(QString::fromStdString(to_string(car.getAr())));
    ui->rentValueLabelCarRegistered->setText(QString::fromStdString(to_string(car.getNapidij())));

    for(string i : car.getFelszerelesek())
    {
        if(i == "GPS")
            ui->gpsCheckBoxCarRegistered->setChecked(true);
        if(i == "Klíma")
            ui->acCheckBoxCarRegistered->setChecked(true);
        if(i == "Rakéta")
            ui->rocketCheckBoxCarRegistered->setChecked(true);
        if(i == "ABS")
            ui->absCheckBoxCarRegistered->setChecked(true);
        if(i == "ESP")
            ui->espCheckBoxCarRegistered->setChecked(true);
        if(i == "Tolatóradar")
            ui->radarCheckBoxCarRegistered->setChecked(true);
    }
}

void Dialog::listRegistered(list<Auto> cars)
{
    //delete records
    for(auto i : itemListRegistered)
    {
        for(auto j : i.second.second)
        {
            j->deleteLater();
        }

        i.second.first->deleteLater();
        i.first->deleteLater();
    }
    itemListRegistered.clear();

    //add records
    for(auto i : cars)
    {
        QHBoxLayout *record = new QHBoxLayout();
        itemContainerRegistered->addLayout(record);
        itemListRegistered.insert(pair<QHBoxLayout*, pair<QPushButton*, list<QLabel*>>>(record, pair<QPushButton*, list<QLabel*>>()));

        QPushButton *button = new QPushButton();
        button->setText(QString::fromStdString(i.getMarka() + " " + i.getTipus()));
        connect(button, &QPushButton::clicked, [=]{showCarRegisteredPage(i);});
        record->addWidget(button);
        itemListRegistered[record] = pair<QPushButton*, list<QLabel*>>(button, list<QLabel*>());

        QLabel *price = new QLabel();
        price->setText(QString::fromStdString(to_string(i.getAr())));
        record->addWidget(price);
        itemListRegistered[record].second.push_back(price);

        QLabel *rentPrice = new QLabel();
        rentPrice->setText(QString::fromStdString(to_string(i.getNapidij())));
        record->addWidget(rentPrice);
        itemListRegistered[record].second.push_back(rentPrice);
    }
}

void Dialog::on_profileButtonRegistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->profilePage);
}

void Dialog::on_filerButtonRegistered_clicked()
{
    string uzemanyag[3] = {ui->gasCheckBoxRegistered->isChecked()?ui->gasCheckBoxRegistered->text().toStdString():"",
                           ui->electronicCheckBoxRegistered->isChecked()?ui->electronicCheckBoxRegistered->text().toStdString():"",
                      ui->dieselCheckBoxRegistered->isChecked()?ui->dieselCheckBoxRegistered->text().toStdString():""};
    string meghajtas[3] = {ui->fwdCheckBoxRegistered->isChecked()?"FWD":"",
                           ui->rwdCheckBoxRegistered->isChecked()?"RWD":"",
                           ui->awdCheckBoxRegistered->isChecked()?"AWD":""};
    string kialakitas[3] = {ui->hatchbackCheckBoxRegistered->isChecked()?"Ferde_hátú":"",
                            ui->sedanCheckBoxRegistered->isChecked()?"Sedan":"",
                            ui->suvCheckBoxRegistered->isChecked()?"SUV":""};
    string sebvalto[2] = {ui->manualCheckBoxRegistered->isChecked()?"Manuális":"",
                          ui->automaticCheckBoxRegistered->isChecked()?"Automata":""};
    string felszereltseg[6] = {ui->gpsCheckBoxRegistered->isChecked()?"GPS":"",
                            ui->acCheckBoxRegistered->isChecked()?"Klíma":"",
                            ui->rocketCheckBoxRegistered->isChecked()?"Rakéta":"",
                            ui->absCheckBoxRegistered->isChecked()?"ABS":"",
                            ui->espCheckBoxRegistered->isChecked()?"ESP":"",
                            ui->radarCheckBoxRegistered->isChecked()?"Tolatóradar":""};

    listRegistered(kereses(ui->brandComboBoxRegistered->currentText().toStdString(),
                    ui->typeComboBoxRegistered->currentText().toStdString(),
                    pair<int,int>(ui->fromPriceSpinBoxRegistered->value(), ui->toPriceSpinBoxRegistered->value()),
                    pair<int,int>(ui->FromRentSpinBoxRegistered->value(), ui->toRentSpinBoxRegistered->value()),
                    pair<int,int>(ui->fromYearSpinBoxRegistered->value(), ui->toYearSpinBoxRegistered->value()),
                    uzemanyag,
                    meghajtas,
                    kialakitas,
                    pair<int,int>(ui->fromPowerSpinBoxRegistered->value(), ui->toPowerSpinBoxRegistered->value()),
                    pair<int,int>(ui->fromSizeSpinBoxRegistered->value(), ui->toSizeSpinBoxRegistered->value()),
                    sebvalto,
                    felszereltseg));
}

void Dialog::on_brandComboBoxRegistered_currentIndexChanged(int index)
{
    ui->typeComboBoxRegistered->clear();

    ui->typeComboBoxRegistered->addItem("Válasszon");

    map<string, list<string>> temp = Tarolo::getObjektum().getMarkak();
    for(auto i : temp)
    {
        if(i.first == ui->brandComboBoxRegistered->currentText().toStdString())
        {
            for(auto j : i.second)
            {
                ui->typeComboBoxRegistered->addItem(QString::fromStdString(j));
            }
            break;
        }
    }
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
    if(!Autentikacio::getObjektum().bejelentkezes(ui->usernameFieldLogin->text().toStdString(), ui->passwordFieldLogin->text().toStdString()))
    {
        QMessageBox::warning(this, "Sikertelen bejelentkezés!", "Hibás a beírt felhasználónév vagy jelszó!");
    }else{
        switch(Autentikacio::getObjektum().getTipus())
        {
        case felhasznalo_tipus::felhasznalo :
            ui->stackedWidget->setCurrentWidget(ui->registeredPage);
            break;

        case felhasznalo_tipus::admin :
            break;

        case felhasznalo_tipus::kereskedo :
            break;
        default:
            break;
        }
    }
}

//registration page
void Dialog::on_registrationButtonRegistration_clicked()
{
    if(Autentikacio::getObjektum().regisztracio(ui->usernameFieldRegistration->text().toStdString(), ui->emailFieldRegistration->text().toStdString(), ui->passwordFieldRegistration->text().toStdString(), ui->nameFieldRegistration->text().toStdString(), ui->birthFieldRegistration->text().toInt(), ui->phoneFieldRegistration->text().toStdString(), ui->postcodeFieldRegistration->text().toInt(), ui->maleRadioRegistration->isChecked()?false:true))
    {
        QMessageBox::warning(this, "Hibás felhasználó név!", "Ez a felhasználónév már foglalt!");
    }else{
        ui->stackedWidget->setCurrentWidget(ui->registeredPage);
    }
}


void Dialog::on_loginButtonRegistration_clicked()
{
    ui->stackedWidgetAuthentication->setCurrentWidget(ui->loginPage);
}

//unregispered car page

void Dialog::on_backButtonCarUnregistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
}

//registered car page

void Dialog::on_backButtonCarRegistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
}

void Dialog::on_buyButtonCarRegistered_clicked()
{
    Adatbazis::getObjektum().autoVasarlas(ui->licenceValueCarRegistered->text().toStdString());

    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
    listRegistered(Tarolo::getObjektum().getAutok());
//    ui->filerButtonRegistered->animateClick();
}

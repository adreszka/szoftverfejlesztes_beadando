#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //button hide
    ui->bidButtonRegisteredPurchase->hide();
    ui->bidButtonUnregisteredPurchase->hide();
    ui->purchaseLabelRegisteredPurchase->hide();
    ui->purchaseLabelUnregisteredPurchase->hide();

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

    map<string, list<string>> brandsUnregisterered = Tarolo::getObjektum().getMarkak();
    for(auto i : brandsUnregisterered)
    {
        ui->brandComboBoxUnregistered->addItem(QString::fromStdString(i.first));
    }

    //registered comboBox
    ui->brandComboBoxRegistered->addItem("Válasszon");

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

    //request equipments
    ui->gpsCheckBoxSalesmanRequest->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->gpsCheckBoxSalesmanRequest->setFocusPolicy(Qt::NoFocus);

    ui->acCheckBoxSalesmanRequest->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->acCheckBoxSalesmanRequest->setFocusPolicy(Qt::NoFocus);

    ui->rocketCheckBoxSalesmanRequest->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->rocketCheckBoxSalesmanRequest->setFocusPolicy(Qt::NoFocus);

    ui->absCheckBoxSalesmanRequest->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->absCheckBoxSalesmanRequest->setFocusPolicy(Qt::NoFocus);

    ui->espCheckBoxSalesmanRequest->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->espCheckBoxSalesmanRequest->setFocusPolicy(Qt::NoFocus);

    ui->radarCheckBoxSalesmanRequest->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->radarCheckBoxSalesmanRequest->setFocusPolicy(Qt::NoFocus);

    //admin list
    ui->profileListAdmin->setWidget(itemsAdmin);

    listAdmin(Adatbazis::getObjektum().fiokokListazasa(true, true));

    //salesman page
    ui->warehouseListSalesman->setWidget(itemsWarehouse);
    ui->rentedListSalesman->setWidget(itemsRented);
    ui->requestListSalesman->setWidget(itemsRequest);

    listWarehouse(Tarolo::getObjektum().getAutok());
    listRented(Tarolo::getObjektum().getAutok());
    listRequest(Adatbazis::getObjektum().kervenyekListazasa());
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
    ui->licenceValueCarUnregistered->setText(QString::fromStdString(car.getRendszam()));
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
        if(i.getRaktaron())
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
        if(i.getRaktaron())
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
}

void Dialog::on_profileButtonRegistered_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->profilePage);

    //get values
    ui->usernameValueLabelProfile->setText(QString::fromStdString(Tarolo::getObjektum().getFelhasznalo().getFelhasznalo_nev()));
    ui->nameValueLabelProfile->setText(QString::fromStdString(Tarolo::getObjektum().getFelhasznalo().getTeljes_nev()));
    ui->emailValueLabelProfile->setText(QString::fromStdString(Tarolo::getObjektum().getFelhasznalo().getEmail()));
    ui->phoneValueLabelProfile->setText(QString::fromStdString(Tarolo::getObjektum().getFelhasznalo().getTelefonszam()));
    ui->birthValueLabelProfile->setText(QString::fromStdString(to_string(Tarolo::getObjektum().getFelhasznalo().getSzul_dat())));
    if(Tarolo::getObjektum().getFelhasznalo().getNem())
    {
        ui->genderValueLabelProfile->setText("férfi");
    }else{
        ui->genderValueLabelProfile->setText("nő");
    }
    ui->postcodeValueLabelProfile->setText(QString::fromStdString(to_string(Tarolo::getObjektum().getFelhasznalo().getIranyitoszam())));
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
            ui->stackedWidget->setCurrentWidget(ui->adminPage);
            ui->stackedWidgetAdmin->setCurrentWidget(ui->profileListPageAdmin);
            break;

        case felhasznalo_tipus::kereskedo :
            ui->stackedWidget->setCurrentWidget(ui->salemanPage);
            break;
        default:
            break;
        }

        ui->usernameFieldLogin->setText("");
        ui->passwordFieldLogin->setText("");
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

        ui->usernameFieldRegistration->setText("");
        ui->emailFieldRegistration->setText("");
        ui->passwordFieldRegistration->setText("");
        ui->nameFieldRegistration->setText("");
        ui->birthFieldRegistration->setText("");
        ui->phoneFieldRegistration->setText("");
        ui->postcodeFieldRegistration->setText("");
        ui->maleRadioRegistration->setChecked(true);
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
    ui->filerButtonRegistered->animateClick();
}

void Dialog::on_rentButtonCarRegistered_clicked()
{
    Adatbazis::getObjektum().autoBerles(ui->licenceValueCarRegistered->text().toStdString(), Tarolo::getObjektum().getFelhasznalo().getFelhasznalo_nev());

    QMessageBox::information(this, "Bérlés:", "A bérlés sikeresen megtörtént!");

    listRegistered(Tarolo::getObjektum().getAutok());
    listUnregistered(Tarolo::getObjektum().getAutok());
    listWarehouse(Tarolo::getObjektum().getAutok());
    listRented(Tarolo::getObjektum().getAutok());

    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
}


//admin pag
void Dialog::on_logoutButtonAdmin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
}

void Dialog::showSalesmanAdmin(Kereskedo salesman)
{
    ui->stackedWidget->setCurrentWidget(ui->salesmanProfilePageAdmin);

    //get values
    ui->usernameValueLabelSalesmanProfileAdmin->setText(QString::fromStdString(salesman.getFelhasznalo_nev()));
    ui->nameValueLabelSalesmanProfileAdmin->setText(QString::fromStdString(salesman.getTeljes_nev()));
    ui->emailValueLabelSalesmanProfileAdmin->setText(QString::fromStdString(salesman.getEmail()));
    ui->phoneValueLabelSalesmanProfileAdmin->setText(QString::fromStdString(salesman.getTelefonszam()));
}

void Dialog::showUserAdmin(RegisztraltFelhasznalo user)
{
    ui->stackedWidget->setCurrentWidget(ui->userProfilePageAdmin);

    //get values
    ui->usernameValueLabelUserProfileAdmin->setText(QString::fromStdString(user.getFelhasznalo_nev()));
    ui->nameValueLabelUserProfileAdmin->setText(QString::fromStdString(user.getTeljes_nev()));
    ui->emailValueLabelUserProfileAdmin->setText(QString::fromStdString(user.getEmail()));
    ui->phoneValueLabelUserProfileAdmin->setText(QString::fromStdString(user.getTelefonszam()));
    ui->birthValueLabelUserProfileAdmin->setText(QString::fromStdString(to_string(user.getSzul_dat())));
    if(user.getNem())
    {
        ui->genderValueLabelUserProfileAdmin->setText("férfi");
    }else{
        ui->genderValueLabelUserProfileAdmin->setText("nő");
    }
    ui->postcodeValueLabelUserProfileAdmin->setText(QString::fromStdString(to_string(user.getIranyitoszam())));
}

void Dialog::listAdmin(pair<list<Kereskedo>, list<RegisztraltFelhasznalo>> lists)
{
    //delete records
    for(auto i : itemListAdmin)
    {
        i.second.second->deleteLater();

        i.second.first->deleteLater();
        i.first->deleteLater();
    }
    itemListAdmin.clear();

    //add records
    for(auto salesman : lists.first)
    {
        QHBoxLayout *record = new QHBoxLayout();
        itemContainerAdmin->addLayout(record);
        itemListAdmin.insert(pair<QHBoxLayout*, pair<QPushButton*, QLabel*>>(record, pair<QPushButton*, QLabel*>()));

        QPushButton *button = new QPushButton();
        button->setText(QString::fromStdString(salesman.getFelhasznalo_nev()));
        connect(button, &QPushButton::clicked, [=]{showSalesmanAdmin(salesman);});
        record->addWidget(button);

        QLabel *type = new QLabel();
        type->setText(QString::fromStdString("Kereskedő"));
        record->addWidget(type);
        itemListAdmin[record] = pair<QPushButton*, QLabel*>(button, type);

    }

    for(auto user : lists.second)
    {
        QHBoxLayout *record = new QHBoxLayout();
        itemContainerAdmin->addLayout(record);
        itemListAdmin.insert(pair<QHBoxLayout*, pair<QPushButton*, QLabel*>>(record, pair<QPushButton*, QLabel*>()));

        QPushButton *button = new QPushButton();
        button->setText(QString::fromStdString(user.getFelhasznalo_nev()));
        connect(button, &QPushButton::clicked, [=]{showUserAdmin(user);});
        record->addWidget(button);

        QLabel *type = new QLabel();
        type->setText(QString::fromStdString("Felhasználó"));
        record->addWidget(type);
        itemListAdmin[record] = pair<QPushButton*, QLabel*>(button, type);
    }
}

void Dialog::on_salesmanButtonListAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentWidget(ui->salesmanPageAdmin);
}


void Dialog::on_listButtonSalesmanAdmin_clicked()
{
    ui->stackedWidgetAdmin->setCurrentWidget(ui->profileListPageAdmin);
}


void Dialog::on_salesmanCheckBoxAdmin_stateChanged(int arg1)
{
    listAdmin(Adatbazis::getObjektum().fiokokListazasa(ui->salesmanCheckBoxAdmin->isChecked(), ui->userCheckBoxAdmin->isChecked()));
}


void Dialog::on_userCheckBoxAdmin_stateChanged(int arg1)
{
    listAdmin(Adatbazis::getObjektum().fiokokListazasa(ui->salesmanCheckBoxAdmin->isChecked(), ui->userCheckBoxAdmin->isChecked()));
}


void Dialog::on_salesmanRegistrationButtonAdmin_clicked()
{
    Adatbazis::getObjektum().kereskedoHozzaadasa(
        ui->usernameFieldAdmin->text().toStdString(),
        ui->passwordFieldAdmin->text().toStdString(),
        ui->nameFieldAdmin->text().toStdString(),
        ui->phoneFieldAdmin->text().toStdString(),
        ui->emailFieldAdmin->text().toStdString()
    );

    QMessageBox::information(this, "", "A kereskedő regisztrálása sikeres volt!");

    ui->usernameFieldAdmin->setText("");
    ui->passwordFieldAdmin->setText("");
    ui->nameFieldAdmin->setText("");
    ui->phoneFieldAdmin->setText("");
    ui->emailFieldAdmin->setText("");

    listAdmin(Adatbazis::getObjektum().fiokokListazasa(ui->salesmanCheckBoxAdmin->isChecked(), ui->userCheckBoxAdmin->isChecked()));
}


//salesman admin page
void Dialog::on_backButtonSalemanProfileAdmin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminPage);
}

void Dialog::on_deleteButtonSalesmanProfileAdmin_clicked()
{
    Adatbazis::getObjektum().fiokTorles(ui->usernameValueLabelSalesmanProfileAdmin->text().toStdString());

    QMessageBox::information(this, "Fiók törlése:", "Sikeresen törölte a kereskedő fiókját.");

    listAdmin(Adatbazis::getObjektum().fiokokListazasa(ui->salesmanCheckBoxAdmin->isChecked(), ui->userCheckBoxAdmin->isChecked()));

    ui->stackedWidget->setCurrentWidget(ui->adminPage);
}


//user admin page
void Dialog::on_backButtonUserProfileAdmin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminPage);
}

void Dialog::on_deleteButtonUserProfileAdmin_clicked()
{
    Adatbazis::getObjektum().fiokTorles(ui->usernameValueLabelUserProfileAdmin->text().toStdString());

    QMessageBox::information(this, "Fiók törlése:", "Sikeresen törölte a felhasználó fiókját.");

    listAdmin(Adatbazis::getObjektum().fiokokListazasa(ui->salesmanCheckBoxAdmin->isChecked(), ui->userCheckBoxAdmin->isChecked()));

    ui->stackedWidget->setCurrentWidget(ui->adminPage);
}


//profile page
void Dialog::on_backButtonProfile_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->registeredPage);
}

void Dialog::on_sellButtonProfile_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->requestPage);
}

void Dialog::on_logoutButtonProfile_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
}

//salesman page
void Dialog::on_logoutButtonSalesman_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->unregisteredPage);
}

void Dialog::showWarehouse(Auto car)
{
    ui->stackedWidget->setCurrentWidget(ui->warehousePage);

    //clear equipments
    ui->gpsCheckBoxWarehouse->setChecked(false);
    ui->acCheckBoxWarehouse->setChecked(false);
    ui->rocketCheckBoxWarehouse->setChecked(false);
    ui->absCheckBoxWarehouse->setChecked(false);
    ui->espCheckBoxWarehouse->setChecked(false);
    ui->radarCheckBoxWarehouse->setChecked(false);

    //set values
    ui->licenceValueWarehouse->setText(QString::fromStdString(car.getRendszam()));
    ui->nameLabelWarehouse->setText(QString::fromStdString(car.getMarka() + " " + car.getTipus()));
    ui->yearValueLabelWarehouse->setText(QString::fromStdString(to_string(car.getEvjarat())));
    ui->fuelValueLabelWarehouse->setText(QString::fromStdString(car.getUzemanyag()));
    ui->powerValueLabelWarehouse->setText(QString::fromStdString(to_string(car.getMotor_teljesitmeny()) + " LE"));
    ui->sizeValueLabelWarehouse->setText(QString::fromStdString(to_string(car.getHengerutartalom())));
    ui->driveValueLabelWarehouse->setText(QString::fromStdString(car.getHajtas()));
    ui->gearValueLabelWarehouse->setText(QString::fromStdString(car.getSebessegvalto()));
    ui->designValueLabelWarehouse->setText(QString::fromStdString(car.getKialakitas()));
    ui->trunkValueLabelWarehouse->setText(QString::fromStdString(to_string(car.getCsomagtarto_meret())));
    ui->priceValueLabelWarehouse->setText(QString::fromStdString(to_string(car.getAr())));
    ui->rentValueLabelWarehouse->setText(QString::fromStdString(to_string(car.getNapidij())));

    for(string i : car.getFelszerelesek())
    {
        if(i == "GPS")
            ui->gpsCheckBoxWarehouse->setChecked(true);
        if(i == "Klíma")
            ui->acCheckBoxWarehouse->setChecked(true);
        if(i == "Rakéta")
            ui->rocketCheckBoxWarehouse->setChecked(true);
        if(i == "ABS")
            ui->absCheckBoxWarehouse->setChecked(true);
        if(i == "ESP")
            ui->espCheckBoxWarehouse->setChecked(true);
        if(i == "Tolatóradar")
            ui->radarCheckBoxWarehouse->setChecked(true);
    }
}

void Dialog::listWarehouse(list<Auto> list)
{
    //delete records
    for(auto i : itemListWarehouse)
    {
        i.second.second->deleteLater();

        i.second.first->deleteLater();
        i.first->deleteLater();
    }
    itemListWarehouse.clear();

    //add records
    for(auto i : list)
    {
        if(i.getRaktaron())
        {
            QHBoxLayout *record = new QHBoxLayout();
            itemContainerWarehouse->addLayout(record);
            itemListWarehouse.insert(pair<QHBoxLayout*, pair<QPushButton*, QLabel*>>(record, pair<QPushButton*, QLabel*>()));

            QPushButton *button = new QPushButton();
            button->setText(QString::fromStdString(i.getMarka() + " " + i.getTipus()));
            connect(button, &QPushButton::clicked, [=]{showWarehouse(i);});
            record->addWidget(button);

            QLabel *licence = new QLabel();
            licence->setText(QString::fromStdString(i.getRendszam()));
            record->addWidget(licence);
            itemListWarehouse[record] = pair<QPushButton*, QLabel*>(button, licence);
        }
    }
}

void Dialog::showRented(Auto car)
{

    ui->stackedWidget->setCurrentWidget(ui->rentedPage);

    //clear equipments
    ui->gpsCheckBoxRented->setChecked(false);
    ui->acCheckBoxRented->setChecked(false);
    ui->rocketCheckBoxRented->setChecked(false);
    ui->absCheckBoxRented->setChecked(false);
    ui->espCheckBoxRented->setChecked(false);
    ui->radarCheckBoxRented->setChecked(false);

    //set values
    ui->licenceValueRented->setText(QString::fromStdString(car.getRendszam()));
    ui->nameLabelRented->setText(QString::fromStdString(car.getMarka() + " " + car.getTipus()));
    ui->yearValueLabelRented->setText(QString::fromStdString(to_string(car.getEvjarat())));
    ui->fuelValueLabelRented->setText(QString::fromStdString(car.getUzemanyag()));
    ui->powerValueLabelRented->setText(QString::fromStdString(to_string(car.getMotor_teljesitmeny()) + " LE"));
    ui->sizeValueLabelRented->setText(QString::fromStdString(to_string(car.getHengerutartalom())));
    ui->driveValueLabelRented->setText(QString::fromStdString(car.getHajtas()));
    ui->gearValueLabelRented->setText(QString::fromStdString(car.getSebessegvalto()));
    ui->designValueLabelRented->setText(QString::fromStdString(car.getKialakitas()));
    ui->trunkValueLabelRented->setText(QString::fromStdString(to_string(car.getCsomagtarto_meret())));
    ui->priceValueLabelRented->setText(QString::fromStdString(to_string(car.getAr())));
    ui->rentValueLabelRented->setText(QString::fromStdString(to_string(car.getNapidij())));

    for(string i : car.getFelszerelesek())
    {
        if(i == "GPS")
            ui->gpsCheckBoxRented->setChecked(true);
        if(i == "Klíma")
            ui->acCheckBoxRented->setChecked(true);
        if(i == "Rakéta")
            ui->rocketCheckBoxRented->setChecked(true);
        if(i == "ABS")
            ui->absCheckBoxRented->setChecked(true);
        if(i == "ESP")
            ui->espCheckBoxRented->setChecked(true);
        if(i == "Tolatóradar")
            ui->radarCheckBoxRented->setChecked(true);
    }
}

void Dialog::listRented(list<Auto> list)
{
    //delete records
    for(auto i : itemListRented)
    {

        i.second.second->deleteLater();

        i.second.first->deleteLater();
        i.first->deleteLater();
    }
    itemListRented.clear();

    //add records
    for(auto i : list)
    {
        if(!i.getRaktaron())
        {
            QHBoxLayout *record = new QHBoxLayout();
            itemContainerRented->addLayout(record);
            itemListRented.insert(pair<QHBoxLayout*, pair<QPushButton*, QLabel*>>(record, pair<QPushButton*, QLabel*>()));

            QPushButton *button = new QPushButton();
            button->setText(QString::fromStdString(i.getMarka() + " " + i.getTipus()));
            connect(button, &QPushButton::clicked, [=]{showRented(i);});
            record->addWidget(button);

            QLabel *licence = new QLabel();
            licence->setText(QString::fromStdString(i.getRendszam()));
            record->addWidget(licence);
            itemListRented[record] = pair<QPushButton*, QLabel*>(button, licence);
        }
    }
}

void Dialog::showRequest(Auto car)
{
    ui->stackedWidget->setCurrentWidget(ui->salesmanRequestPage);

    //clear equipments
    ui->gpsCheckBoxSalesmanRequest->setChecked(false);
    ui->acCheckBoxSalesmanRequest->setChecked(false);
    ui->rocketCheckBoxSalesmanRequest->setChecked(false);
    ui->absCheckBoxSalesmanRequest->setChecked(false);
    ui->espCheckBoxSalesmanRequest->setChecked(false);
    ui->radarCheckBoxSalesmanRequest->setChecked(false);

    //set values
    ui->licenceValueSalesmanRequest->setText(QString::fromStdString(car.getRendszam()));
    ui->nameLabelSalesmanRequest->setText(QString::fromStdString(car.getMarka() + " " + car.getTipus()));
    ui->yearValueLabelSalesmanRequest->setText(QString::fromStdString(to_string(car.getEvjarat())));
    ui->fuelValueLabelSalesmanRequest->setText(QString::fromStdString(car.getUzemanyag()));
    ui->powerValueLabelSalesmanRequest->setText(QString::fromStdString(to_string(car.getMotor_teljesitmeny()) + " LE"));
    ui->sizeValueLabelSalesmanRequest->setText(QString::fromStdString(to_string(car.getHengerutartalom())));
    ui->driveValueLabelSalesmanRequest->setText(QString::fromStdString(car.getHajtas()));
    ui->gearValueLabelSalesmanRequest->setText(QString::fromStdString(car.getSebessegvalto()));
    ui->designValueLabelSalesmanRequest->setText(QString::fromStdString(car.getKialakitas()));
    ui->trunkValueLabelSalesmanRequest->setText(QString::fromStdString(to_string(car.getCsomagtarto_meret())));
    ui->priceValueLabelSalesmanRequest->setText(QString::fromStdString(to_string(car.getAr())));

    for(string i : car.getFelszerelesek())
    {
        if(i == "GPS")
            ui->gpsCheckBoxSalesmanRequest->setChecked(true);
        if(i == "Klíma")
            ui->acCheckBoxSalesmanRequest->setChecked(true);
        if(i == "Rakéta")
            ui->rocketCheckBoxSalesmanRequest->setChecked(true);
        if(i == "ABS")
            ui->absCheckBoxSalesmanRequest->setChecked(true);
        if(i == "ESP")
            ui->espCheckBoxSalesmanRequest->setChecked(true);
        if(i == "Tolatóradar")
            ui->radarCheckBoxSalesmanRequest->setChecked(true);
    }
}

void Dialog::listRequest(list<Auto> list)
{
    //delete records
    for(auto i : itemListRequest)
    {

        i.second.second->deleteLater();

        i.second.first->deleteLater();
        i.first->deleteLater();
    }
    itemListRequest.clear();

    //add records
    for(auto i : list)
    {
        if(!i.getRaktaron())
        {
            QHBoxLayout *record = new QHBoxLayout();
            itemContainerRequest->addLayout(record);
            itemListRequest.insert(pair<QHBoxLayout*, pair<QPushButton*, QLabel*>>(record, pair<QPushButton*, QLabel*>()));

            QPushButton *button = new QPushButton();
            button->setText(QString::fromStdString(i.getMarka() + " " + i.getTipus()));
            connect(button, &QPushButton::clicked, [=]{showRequest(i);});
            record->addWidget(button);

            QLabel *licence = new QLabel();
            licence->setText(QString::fromStdString(i.getRendszam()));
            record->addWidget(licence);
            itemListRequest[record] = pair<QPushButton*, QLabel*>(button, licence);
        }
    }
}


//warehouse page
void Dialog::on_backButtonWarehouse_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->salemanPage);
}

void Dialog::on_deleteButtonWarehouse_clicked()
{
    Adatbazis::getObjektum().autoTorles(ui->licenceValueWarehouse->text().toStdString());

    listWarehouse(Tarolo::getObjektum().getAutok());

    ui->stackedWidget->setCurrentWidget(ui->salemanPage);
}


//rented page

void Dialog::on_backButtonRented_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->salemanPage);
}


void Dialog::on_placeBackButtonRented_clicked()
{
    Adatbazis::getObjektum().autoBerlesbolVisszahozva(ui->licenceValueRented->text().toStdString());
    Tarolo::getObjektum().raktarbaBevitel(ui->licenceValueRented->text().toStdString());

    listWarehouse(Tarolo::getObjektum().getAutok());
    listRented(Tarolo::getObjektum().getAutok());

    ui->stackedWidget->setCurrentWidget(ui->salemanPage);
}


//request page
void Dialog::on_submitButtonRequest_clicked()
{
    //fill up the equipment list
    list<string> equipment;
    if(ui->gpsCheckBoxRequest->isChecked())
        equipment.push_back("GPS");
    if(ui->acCheckBoxRequest->isChecked())
        equipment.push_back("Klíma");
    if(ui->rocketCheckBoxRequest->isChecked())
        equipment.push_back("Rakéta");
    if(ui->absCheckBoxRequest->isChecked())
        equipment.push_back("ABS");
    if(ui->espCheckBoxRequest->isChecked())
        equipment.push_back("ESP");
    if(ui->radarCheckBoxRequest->isChecked())
        equipment.push_back("Tolatóradar");

    //create the request
    Adatbazis::getObjektum().ujKervenyTarolasa(ui->licenceFieldRequest->text().toStdString(), ui->brandFieldRequest->text().toStdString(), ui->typeFieldRequest->text().toStdString(), ui->designComboBoxRequest->currentText().toStdString()=="Ferde hátú"?"Ferde_hátú":ui->designComboBoxRequest->currentText().toStdString(), ui->priceSpinBoxRequest->value(), "fekete", ui->trunkSpinBoxRequest->value(), ui->fuelComboBoxRequest->currentText().toStdString(), ui->yearSpinBoxRequest->value(), ui->powerSpinBoxRequest->value(), ui->sizeSpinBoxRequest->value(), ui->gearComboBoxRequest->currentText().toStdString()=="Automata"?1:0, ui->driveComboBoxRequest->currentText().toStdString()=="Hátsó kerék"?"RWD":ui->driveComboBoxRequest->currentText().toStdString()=="Első kerék"?"FWD":"AWD", equipment);

    //clear the page
    ui->brandFieldRequest->setText("");
    ui->typeFieldRequest->setText("");
    ui->licenceFieldRequest->setText("");
    ui->yearSpinBoxRequest->setValue(ui->yearSpinBoxRequest->minimum());
    ui->fuelComboBoxRequest->setCurrentIndex(0);
    ui->powerSpinBoxRequest->setValue(ui->powerSpinBoxRequest->minimum());
    ui->sizeSpinBoxRequest->setValue(ui->sizeSpinBoxRequest->minimum());
    ui->driveComboBoxRequest->setCurrentIndex(0);
    ui->gearComboBoxRequest->setCurrentIndex(0);
    ui->designComboBoxRequest->setCurrentIndex(0);
    ui->trunkSpinBoxRequest->setValue(ui->trunkSpinBoxRequest->minimum());
    ui->gpsCheckBoxRequest->setChecked(false);
    ui->acCheckBoxRequest->setChecked(false);
    ui->rocketCheckBoxRequest->setChecked(false);
    ui->absCheckBoxRequest->setChecked(false);
    ui->espCheckBoxRequest->setChecked(false);
    ui->radarCheckBoxRequest->setChecked(false);
    ui->priceSpinBoxRequest->setValue(ui->priceSpinBoxRequest->minimum());

    ui->stackedWidget->setCurrentWidget(ui->profilePage);
}

void Dialog::on_backButtonRequest_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->profilePage);
}


//salesman request page

void Dialog::on_backButtonSalesmanRequest_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->salemanPage);
}


void Dialog::on_acceptButtonSalesmanRequest_clicked()
{
    Adatbazis::getObjektum().autoEladasraKinalasa(ui->licenceValueSalesmanRequest->text().toStdString(), QInputDialog::getInt(this,"Új eladási ár", "Az autó eladási ára:"), QInputDialog::getInt(this, "Új napi díj", "Az autó bérlési díja:"), 1);

    listRequest(Adatbazis::getObjektum().kervenyekListazasa());

    ui->stackedWidget->setCurrentWidget(ui->salemanPage);
}

void Dialog::on_denyButtonSalesmanRequest_clicked()
{
    Adatbazis::getObjektum().autoEladasraKinalasa(ui->licenceValueSalesmanRequest->text().toStdString(), 0, 0, 0);

    listRequest(Adatbazis::getObjektum().kervenyekListazasa());

    ui->stackedWidget->setCurrentWidget(ui->salemanPage);
}

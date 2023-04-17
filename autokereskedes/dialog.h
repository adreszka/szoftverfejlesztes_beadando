#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSignalMapper>
#include <QInputDialog>
#include <list>
#include <map>

#include "auto.h"
#include "tarolo.h"
#include "rendszerfuggvenyek.h"
#include "autentikacio.h"
#include "kereskedo.h"
#include "regisztraltfelhasznalo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void listUnregistered(list<Auto> cars);
    void listRegistered(list<Auto> cars);

private slots:
    void showCarUnregisteredPage(Auto car);
    void showCarRegisteredPage(Auto car);

    void on_loginButtonUnregistered_clicked();

    void on_registrationButtonLogin_clicked();

    void on_backButtonAuthentication_clicked();

    void on_loginButtonLogin_clicked();

    void on_registrationButtonRegistration_clicked();

    void on_loginButtonRegistration_clicked();

    void on_filerButtonUnregistered_clicked();

    void on_brandComboBoxUnregistered_currentIndexChanged(int index);

    void on_filerButtonRegistered_clicked();

    void on_profileButtonRegistered_clicked();

    void on_brandComboBoxRegistered_currentIndexChanged(int index);

    void on_backButtonCarUnregistered_clicked();

    void on_backButtonCarRegistered_clicked();

    void on_buyButtonCarRegistered_clicked();

    void on_salesmanButtonListAdmin_clicked();

    void on_listButtonSalesmanAdmin_clicked();

    void on_salesmanCheckBoxAdmin_stateChanged(int arg1);

    void on_userCheckBoxAdmin_stateChanged(int arg1);

    void on_salesmanRegistrationButtonAdmin_clicked();

    void listAdmin(pair<list<Kereskedo>, list<RegisztraltFelhasznalo>>);

    void showSalesmanAdmin(Kereskedo salesman);

    void showUserAdmin(RegisztraltFelhasznalo user);

    void on_backButtonSalemanProfileAdmin_clicked();

    void on_backButtonUserProfileAdmin_clicked();

    void on_deleteButtonSalesmanProfileAdmin_clicked();

    void on_deleteButtonUserProfileAdmin_clicked();

    void on_rentButtonCarRegistered_clicked();

    void on_backButtonProfile_clicked();

    void listWarehouse(list<Auto> list);

    void listRented(list<Auto> list);

    void showWarehouse(Auto car);

    void showRented(Auto car);

    void on_backButtonWarehouse_clicked();

    void on_deleteButtonWarehouse_clicked();

    void on_backButtonRented_clicked();

    void on_placeBackButtonRented_clicked();

private:
    Ui::Dialog *ui;

    //container of the listed items
    map<QHBoxLayout*, pair<QPushButton*, list<QLabel*>>> itemListUnregistered;
    map<QHBoxLayout*, pair<QPushButton*, list<QLabel*>>> itemListRegistered;
    map<QHBoxLayout*, pair<QPushButton*, QLabel*>> itemListAdmin;
    map<QHBoxLayout*, pair<QPushButton*, QLabel*>> itemListWarehouse;
    map<QHBoxLayout*, pair<QPushButton*, QLabel*>> itemListRented;

    //unregistered listed cars
    QWidget *itemsUnregistered = new QWidget();
    QVBoxLayout *itemContainerUnregistered = new QVBoxLayout(itemsUnregistered);

    //registered listed cars
    QWidget *itemsRegistered = new QWidget();
    QVBoxLayout *itemContainerRegistered = new QVBoxLayout(itemsRegistered);

    //admin list
    QWidget *itemsAdmin = new QWidget();
    QVBoxLayout *itemContainerAdmin = new QVBoxLayout(itemsAdmin);

    //salesman warehouse list
    QWidget *itemsWarehouse = new QWidget();
    QVBoxLayout *itemContainerWarehouse = new QVBoxLayout(itemsWarehouse);

    //salesman rented list
    QWidget *itemsRented = new QWidget();
    QVBoxLayout *itemContainerRented = new QVBoxLayout(itemsRented);
};
#endif // DIALOG_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <list>
#include <QMessageBox>
#include <QSignalMapper>

#include "auto.h"
#include "tarolo.h"
#include "rendszerfuggvenyek.h"
#include "autentikacio.h"

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

private:
    Ui::Dialog *ui;

    //unregistered listed cars
    QWidget *itemsUnregistered = new QWidget();
    QVBoxLayout *itemContainerUnregistered = new QVBoxLayout(itemsUnregistered);

    //registered listed cars
    QWidget *itemsRegistered = new QWidget();
    QVBoxLayout *itemContainerRegistered = new QVBoxLayout(itemsRegistered);
};
#endif // DIALOG_H

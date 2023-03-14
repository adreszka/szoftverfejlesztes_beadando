#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <list>
#include <QMessageBox>

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

    void listazas(list<Auto> autok);

private slots:
    void on_loginButtonUnregistered_clicked();

    void on_registrationButtonLogin_clicked();

    void on_backButtonAuthentication_clicked();

    void on_loginButtonLogin_clicked();

    void on_registrationButtonRegistration_clicked();

    void on_loginButtonRegistration_clicked();

    void on_filerButtonUnregistered_clicked();

    void on_brandComboBoxUnregistered_currentIndexChanged(int index);

private:
    Ui::Dialog *ui;

    QWidget *elemek = new QWidget();
    QVBoxLayout *elemTarolo = new QVBoxLayout(elemek);
};
#endif // DIALOG_H

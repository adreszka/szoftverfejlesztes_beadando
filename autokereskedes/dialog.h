#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_loginButtonUnregistered_clicked();

    void on_registrationButtonLogin_clicked();

    void on_pushButton_clicked();

    void on_backButtonAuthentication_clicked();

    void on_loginButtonLogin_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H

#include "autentikacio.h"

Autentikacio &Autentikacio::getObjektum()
{
    static Autentikacio autentikacio;
    return autentikacio;
}

void Autentikacio::bejelentkezes()
{
    /*SAConnection dbcon;
    //boolean adatbazisbanTalalhato = false;
    dbcon.Connect("autokereskedes.sqlite","","",SA_SQLite_Client);*/
    string username;
    string password;
    cout << "Kerem adja meg a felhasznalonevet!" << endl;
    cin >> username;
    cout << "Kerem adja meg a jelszavát!" << endl;
    cin >> password;
    /*SACommand select(&dbcon, "SELECT * FROM Bejelentkezesi_adatok");
    select.Execute();
    while(select.FetchNext()) {
        string usernamedb = (string)select[1].asString();
        string passworddb = (string)select[3].asString();
        if (username == usernamedb && password == passworddb) {
            cout << "Sikeresen bejelentkezett!" << endl;
            adatbazisbanTalalhato = true;
            break;
        }
    }
    if (adatbazisbanTalalhato == false) {
        cout << "Nem található az adatbázisban!" << endl;
    }*/
}

void Autentikacio::regisztracio()
{
    /*SAConnection dbcon;
    dbcon.Connect("autokereskedes.sqlite","","",SA_SQLite_Client);*/
    string username;
    string password;
    int a = 3;
    bool adatbazisbanTalalhato = false;
    cout << "Kerem adja meg a felhasznalonevet!" << endl;
    cin >> username;
    cout << "Kerem adja meg a jelszavat!" << endl;
    cin >> password;
    /*SACommand select(&dbcon, "SELECT * FROM Bejelentkezesi_adatok");
    select.Execute();
    while(select.FetchNext()) {
        string usernamedb = (string)select[1].asString();
        string passworddb = (string)select[3].asString();
        if (username == usernamedb && password == passworddb) {
            adatbazisbanTalalhato = true;
            break;
        }
    }
    SACommand add(&dbcon,
                  "INSERT INTO Bejelentkezesi_adatok(Felhasznalo_nev, "
                  "Felhasznalo_Id, Jelszo) VALUES(:1, :2, :3)");
    if (adatbazisbanTalalhato == false) {
        add << username.c_str();
        add << (long)a;
        add << password.c_str();
        add.Execute();
    }*/

    // adatbázisba felhasználó mentése és ellenőrzése, hogy szerepel-e ilyen felhasználó
    // az adatbázisba
    // cout << "Sikeres regisztracio" << endl;
    // valami oknál fogva nem sikerült az adatbázisba menteni; cout << "Sikertelen regisztracio" << endl;
}

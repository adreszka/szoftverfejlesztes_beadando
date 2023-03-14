#include "autentikacio.h"

Autentikacio &Autentikacio::getObjektum()
{
    static Autentikacio autentikacio;
    return autentikacio;
}

bool Autentikacio::bejelentkezes(const string &felhasznalo_nev, const string &jelszo)
{
    return Adatbazis::getObjektum().bejelentkezesEllenorzes(felhasznalo_nev, jelszo);
}

bool Autentikacio::regisztracio(const string &felhasznaloNev, const string &email, const string &jelszo, const string &teljesNev, const int &szulEv, const int &telefonSzam, const int&iranyitoSzam, const bool &nem)
{
    return Adatbazis::getObjektum().regisztracioElmentese(felhasznaloNev,email,jelszo,teljesNev,szulEv,telefonSzam,nem,iranyitoSzam);
    /*SAConnection dbcon;
    dbcon.Connect("autokereskedes.sqlite","","",SA_SQLite_Client);*/
//    string username;
//    string password;
//    int a = 3;
//    bool adatbazisbanTalalhato = false;
//    cout << "Kerem adja meg a felhasznalonevet!" << endl;
//    cin >> username;
//    cout << "Kerem adja meg a jelszavat!" << endl;
//    cin >> password;
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

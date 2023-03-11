#include "autentikacio.h"

Autentikacio &Autentikacio::getObjektum()
{
    static Autentikacio autentikacio;
    return autentikacio;
}

void Autentikacio::bejelentkezes()
{
    string username;
    string password;
    cout << "Kerem adja meg a felhasznalonevet!" << endl;
    cin >> username;
    cout << "Kerem adja meg a jelszavát!" << endl;
    cin >> password;
    //if (username == //adatbázisba ellenőrzés, hogy szerepel-e benne)
        //if (password == ////adatbázisba ellenőrzés, hogy szerepel-e benne)
            // cout << "Sikeresen bejelentkezett!" << endl;
    //cout << "Sikertelen bejelentkezes!" << endl;
}

void Autentikacio::regisztracio()
{
    string username;
    string password;
    cout << "Kerem adja meg a felhasznalonevet!" << endl;
    cin >> username;
    cout << "Kerem adja meg a jelszavat!" << endl;
    cin >> password;
    // adatbázisba felhasználó mentése és ellenőrzése, hogy szerepel-e ilyen felhasználó
    // az adatbázisba
    // cout << "Sikeres regisztracio" << endl;
    // valami oknál fogva nem sikerült az adatbázisba menteni; cout << "Sikertelen regisztracio" << endl;
}

#include "regisztracio.h"

Regisztracio &Regisztracio::getObjektum()
{
    static Regisztracio regisztracio;
    return regisztracio;
}

void Regisztracio::regisztracio()
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

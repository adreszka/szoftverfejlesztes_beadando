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
    return Adatbazis::getObjektum().regisztracioElmentese(felhasznaloNev,email,jelszo,teljesNev,szulEv,telefonSzam,iranyitoSzam, nem);
}

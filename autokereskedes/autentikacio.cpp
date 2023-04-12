#include "autentikacio.h"

Autentikacio &Autentikacio::getObjektum()
{
    static Autentikacio autentikacio;
    return autentikacio;
}

bool Autentikacio::bejelentkezes(const string &felhasznalo_nev, const string &jelszo)
{
    string hozzaferes = Adatbazis::getObjektum().bejelentkezesEllenorzes(felhasznalo_nev, jelszo);
    if (!hozzaferes.empty())
    {
        Adatbazis::getObjektum().felhasznaloBeolvas(felhasznalo_nev);
        if (hozzaferes == "admin") tipus = admin;
        else if (hozzaferes == "kereskedo") tipus = kereskedo;
        else tipus = felhasznalo;
        return true;
    }
    return false;
}

bool Autentikacio::regisztracio(const string &felhasznaloNev, const string &email, const string &jelszo, const string &teljesNev, const int &szulEv, const string &telefonSzam, const int&iranyitoSzam, const bool &nem)
{
    return Adatbazis::getObjektum().regisztracioElmentese(felhasznaloNev,email,jelszo,teljesNev,szulEv,telefonSzam,iranyitoSzam, nem);
}

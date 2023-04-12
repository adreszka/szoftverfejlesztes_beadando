#ifndef AUTENTIKACIO_H
#define AUTENTIKACIO_H

#include <iostream>
#include <string>

#include "adatbazis.h"

enum felhasznalo_tipus
{
    admin,
    kereskedo,
    felhasznalo
};

using namespace std;

class Autentikacio
{
    felhasznalo_tipus tipus;
    Autentikacio()=default;
    Autentikacio(const Autentikacio& other)=default;
public:
    static Autentikacio& getObjektum();
    bool bejelentkezes(const string &felhasznalo_nev, const string &jelszo);
    bool regisztracio(const string &felhasznaloNev, const string &email, const string &jelszo, const string &teljesNev, const int &szulEv, const string &telefonSzam, const int&iranyitoSzam, const bool &nem);
    felhasznalo_tipus getTipus() const;
};

#endif // AUTENTIKACIO_H

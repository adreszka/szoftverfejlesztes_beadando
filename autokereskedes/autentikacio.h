#ifndef AUTENTIKACIO_H
#define AUTENTIKACIO_H

#include <iostream>
#include <string>

#include "adatbazis.h"

using namespace std;

class Autentikacio
{
    Autentikacio()=default;
    Autentikacio(const Autentikacio& other)=default;
public:
    static Autentikacio& getObjektum();
    bool bejelentkezes(const string &felhasznalo_nev, const string &jelszo);
    bool regisztracio(const string &felhasznaloNev, const string &email, const string &jelszo, const string &teljesNev, const int &szulEv, const int &telefonSzam, const int&iranyitoSzam, const bool &nem);
};

#endif // AUTENTIKACIO_H

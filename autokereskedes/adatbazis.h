#ifndef ADATBAZIS_H
#define ADATBAZIS_H

#ifdef _W64 || _WIN32
#define WIN32_LEAN_AND_MEAN
#endif // _W64 || _WIN32

#include <iostream>
#include <functional>
#include <SQLAPI.h>
#include <string>
#include <list>

#include "tarolo.h"
#include "auto.h"
#include "regisztraltfelhasznalo.h"


// adatbázis kapcsolatát, lekérdezéseket végzi

class Adatbazis
{
    SAConnection dbcon;
    Adatbazis()=default;
    Adatbazis(const Adatbazis &adatbazis)=default;
public:
    static Adatbazis& getObjektum();

    void csatlakozas (const string& sqlite_fajl);
    void teszt ();
    void autokBeolvas();
    bool bejelentkezesEllenorzes(const string& felhasznalo_nev, const string& jelszo);
    void felhasznaloBeolvas(const string& felhasznalo_nev);
    void autoVasarlas(const string& rendszam);
    void markaBeolvasas();
    bool regisztracioElmentese(const string &felhasznaloNev, const string &email, const string &jelszo, const string &teljesNev, const int &szulEv, const int &telefonSzam, const int&iranyitoSzam, const bool &nem);
};


//Adatbazis adatbazis;
//adatbazis.csatlakozas("autokereskedes.sqlite");
//adatbazis.teszt();
//adatbazis.autokBeolvas();
//adatbazis.felhasznaloBeolvas("teszt");
//Tarolo::getObjektum().kiirTeszt();
//adatbazis.autoVasarlas("FOS123");

#endif // ADATBAZIS_H

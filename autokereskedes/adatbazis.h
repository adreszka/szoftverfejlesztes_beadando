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
#include "felhasznalo.h"


// adatbázis kapcsolatát, lekérdezéseket végzi

class Adatbazis
{
    SAConnection dbcon;
public:
    Adatbazis()=default;
    void csatlakozas (const string& sqlite_fajl);
    void teszt ();
    void autokBeolvas();
    void bejelentkezesEllenorzes(const string& felhasznalo_nev, const string& jelszo);
    void felhasznaloBeolvas(const string& felhasznalo_nev);
    void autoVasarlas(const string& rendszam);
};


//Adatbazis adatbazis;
//adatbazis.csatlakozas("autokereskedes.sqlite");
//adatbazis.teszt();
//adatbazis.autokBeolvas();
//adatbazis.felhasznaloBeolvas("teszt");
//Tarolo::getObjektum().kiirTeszt();
//adatbazis.autoVasarlas("FOS123");

#endif // ADATBAZIS_H

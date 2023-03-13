#ifndef ADATBAZIS_H
#define ADATBAZIS_H

#include <iostream>
#include <functional>
#include <SQLAPI.h>
#include <string>
#include <list>

#include "tarolo.h"
#include "auto.h"

#ifdef _W64 || _WIN32
#define WIN32_LEAN_AND_MEAN
#endif // _W64 || _WIN32

using namespace std;

// adatbázis kapcsolatát, lekérdezéseket végzi

class Adatbazis
{
    SAConnection dbcon;
public:
    Adatbazis()=default;
    void csatlakozas (const string& sqlite_fajl);
    void teszt ();
    void autokBeolvas();
    //void felhaszlnaoBeolvas();
};

#endif // ADATBAZIS_H

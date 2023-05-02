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
#include "kereskedo.h"


// adatbázis kapcsolatát, lekérdezéseket végzi

class Adatbazis
{
    SAConnection dbcon;
    Adatbazis()=default;
    Adatbazis(const Adatbazis &adatbazis)=default;
public:
    static Adatbazis& getObjektum();

    void csatlakozas (const string& sqlite_fajl);
    void autokBeolvas();
    string bejelentkezesEllenorzes(const string& felhasznalo_nev, const string& jelszo);
    void felhasznaloBeolvas(const string& felhasznalo_nev);
    void autoVasarlas(const string& rendszam);
    void markaBeolvasas();
    bool regisztracioElmentese(const string &felhasznaloNev, const string &email, const string &jelszo, const string &teljesNev, const int &szulEv, const string &telefonSzam, const int&iranyitoSzam, const bool &nem);
    void autoBerles(const string &rendszam, const string &felhasznalo_nev);
    void autoEladasraKinalasa(const string& rendszam, int ar, int napi_dij, const string& szin,
                              int csomagtarto_meret, const string& uzemanyag, int evjarat, int motor_teljesitmeny,
                              int hengerutartalom, bool sebessegvalto, const string& hajtas, const string& tipus,
                              const string& marka, const string& kialakitas, list<string> felszerelesek);
    void autoTorles(const string& rendszam);
    void fiokTorles(const string& felhasznalo_nev);
    void kereskedoHozzaadasa(const string& felhasznalo_nev, const string& jelszo,const string& teljes_nev, const string& telefonszam, const string& email);
    void autoBerlesbolVisszahozva(const string& rendszam, int elteltnapok);
    pair<list<Kereskedo>,list<RegisztraltFelhasznalo>> fiokokListazasa(const bool kereskedo, const bool felhasznalo);
    void ujKervenyTarolasa(const string& rendszam, const string& marka, const string& tipus, const string& kialakitas, int ar, int napi_dij,
                              const string& szin, int csomagtarto_meret, const string& uzemanyag, int evjarat, int motor_teljesitmeny,
                              int hengerutartalom, bool sebessegvalto, const string& hajtas, list<string> felszerelesek, bool biralas);
    list<Auto> kervenyekListazasa();
};
#endif // ADATBAZIS_H

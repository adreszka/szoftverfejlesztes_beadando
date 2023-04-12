#ifndef TAROLO_H
#define TAROLO_H

#include <list>
#include <map>
#include <iostream>
#include <algorithm>

#include "auto.h"
#include "regisztraltfelhasznalo.h"

using namespace std;

class Tarolo
{
    list<Auto> autok;
    map<string, list<string>> markak;
    RegisztraltFelhasznalo felhasznalo;
    Tarolo()=default;
    Tarolo(const Tarolo& other)=default;
public:
    static Tarolo& getObjektum();
    void hozzaAd(const Auto& a);
    void kiirTeszt();
    list<Auto> getAutok() const;
    RegisztraltFelhasznalo getFelhasznalo() const;
    void setFelhasznalo(const RegisztraltFelhasznalo &newFelhasznalo);
    map<string, list<string>> getMarkak() const;
    void setMarkak(const map<string, list<string> > &newMarkak);
    void torolAuto(const string& rendszam);
};

#endif // TAROLO_H

#include "tarolo.h"

list<Auto> Tarolo::getAutok() const
{
    return autok;
}

RegisztraltFelhasznalo Tarolo::getFelhasznalo() const
{
    return felhasznalo;
}

void Tarolo::setFelhasznalo(const RegisztraltFelhasznalo &newFelhasznalo)
{
    felhasznalo = newFelhasznalo;
}

map<string, list<string> > Tarolo::getMarkak() const
{
    return markak;
}

void Tarolo::setMarkak(const map<string, list<string> > &newMarkak)
{
    markak = newMarkak;
}

void Tarolo::torolAuto(const string &rendszam)
{
    Tarolo::getObjektum().autok.remove_if([rendszam](Auto temp){
        return temp.getRendszam() == rendszam;
    });
}

Tarolo &Tarolo::getObjektum()
{
    static Tarolo tarolo;
    return tarolo;
}

void Tarolo::hozzaAd(const Auto &a)
{
    autok.push_back(a);
}

void Tarolo::kiirTeszt()
{
    for(auto &i : this->getObjektum().autok){
        cout << i.getRendszam()<< endl;
        for (auto &j : i.getFelszerelesek()){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << this->getObjektum().getFelhasznalo().getTeljes_nev() << endl;
}

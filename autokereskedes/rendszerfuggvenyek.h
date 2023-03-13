#include "SQLAPI.h"
#include "tarolo.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>

#ifndef RENDSZERFUGGVENYEK_H
#define RENDSZERFUGGVENYEK_H

using namespace std;

list<Auto> keresesAr(string marka, string tipus, pair<int,int> ar, pair<int,int> berlet, pair<int,int> ev, string uzemanyag[], string meghajtas[], string kivitel[], pair<int,int> teljesitmeny, pair<int,int> urtartalom, string valto[], string felszereltseg[])
{
    list<Auto> autok = Tarolo::getObjektum().getAutok();
    list<Auto> ki_autok;
    copy_if(autok.begin(), autok.end(), back_inserter(ki_autok), [&](const Auto* kocsi){
        return (marka != "Válasszon:" && kocsi->getMarka() == marka)
                && (tipus != "Válasszon:" && kocsi->getTipus() == tipus)
                && ((kocsi->getAr() >= ar.first && kocsi->getAr() <= ar.second) || (ar.first == 0 && ar.second == 0) || (kocsi->getAr() >= ar.first && ar.second == 0))
                && ((kocsi->getNapidij() >= berlet.first && kocsi->getNapidij() <= berlet.second) || (berlet.first == 0 && berlet.second == 0) || (kocsi->getNapidij() >= berlet.first && berlet.second == 0))
                && ((kocsi->getEvjarat() >= ev.first && kocsi->getEvjarat() <= ev.second) || (ev.first == 0 && ev.second == 0) || (kocsi->getEvjarat() >= ev.first && ev.second == 0))
                && (find(uzemanyag, uzemanyag+3, kocsi->getUzemanyag()) != uzemanyag+3)
                && (find(meghajtas, meghajtas+3, kocsi->getHajtas()) != meghajtas+3)
                && (find(kivitel, kivitel+3, kocsi->getKialakitas()) != kivitel+3)
                && ((kocsi->getMotor_teljesitmeny() >= teljesitmeny.first && kocsi->getMotor_teljesitmeny() <= teljesitmeny.second) || (teljesitmeny.first == 0 && teljesitmeny.second == 0) || (kocsi->getMotor_teljesitmeny() >= teljesitmeny.first && teljesitmeny.second == 0))
                && ((kocsi->getHengerutartalom() >= urtartalom.first && kocsi->getHengerutartalom() <= urtartalom.second) || (urtartalom.first == 0 && urtartalom.second == 0) || (kocsi->getHengerutartalom() >= urtartalom.first && urtartalom.second == 0))
                && (find(valto, valto+2, kocsi->getSebessegvalto()) != valto+2)
                && kocsi->getFelszerelesek().end() != find_if(kocsi->getFelszerelesek().begin(), kocsi->getFelszerelesek().end(), [&](string felszereles){
            return find(felszereltseg, felszereltseg+3, felszereles) != felszereltseg+6;
    });
    });
    return ki_autok;
}

#endif // RENDSZERFUGGVENYEK_H

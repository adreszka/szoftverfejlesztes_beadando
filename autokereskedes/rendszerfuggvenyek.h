#include "SQLAPI.h"
#include "tarolo.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>

#ifndef RENDSZERFUGGVENYEK_H
#define RENDSZERFUGGVENYEK_H

using namespace std;

template <typename T> list<Auto> keresesiParameter(int parameter, T x)
{
    list<Auto> autok = Tarolo::getObjektum().getAutok();
    list<Auto> ki_autok;
    copy_if(autok.begin(), autok.end(), back_inserter(ki_autok), [&](const Auto* kocsi){
        switch(parameter){
            case 0:
            return kocsi->getAr() == x;
            break;
            case 1:
            return kocsi->getCsomagtarto_meret() == x;
            break;
            case 2:
            return kocsi->getEvjarat() == x;
            break;
            case 3:
            return kocsi->getHajtas() == x;
            break;
            case 4:
            return kocsi->getHengerutartalom() == x;
            break;
            case 5:
            return kocsi->getKialakitas() == x;
            break;
            case 6:
            return kocsi->getMarka() == x;
            break;
            case 7:
            return kocsi->getMotor_teljesitmeny() == x;
            break;
            case 8:
            return kocsi->getNapidij() == x;
            break;
            case 9:
            return kocsi->getRaktaron() == x;
            break;
            case 10:
            return kocsi->getSebessegvalto() == x;
            break;
            case 11:
            return kocsi->getSzin() == x;
            break;
            case 12:
            return kocsi->getTipus() == x;
            break;
            case 13:
            return kocsi->getUzemanyag() == x;
            break;
        }
    });
    return ki_autok;
}

#endif // RENDSZERFUGGVENYEK_H

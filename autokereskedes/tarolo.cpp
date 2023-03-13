#include "tarolo.h"

Tarolo &Tarolo::getObjektum()
{
    static Tarolo tarolo;
    return tarolo;
}

void Tarolo::hozzaAd(const Auto &a)
{
    autok.push_back(a);
}

//void Tarolo::kiirTeszt()
//{
//    for(auto &i : this->getObjektum().autok){
//        cout << i.getRendszam()<< endl;
//        for (auto &j : i.getFelszerelesek()){
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//}

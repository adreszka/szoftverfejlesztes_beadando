#include "auto.h"


Auto::Auto(const string &_rendszam, const string &_marka, const string &_tipus,
           list<string> _felszerelesek, const string &_kialakitas, int _ar,
           int _napidij, const string &_szin, int _csomagtarto_meret,
           const string &_uzemanyag, int _evjarat, int _motor_teljesitmeny,
           int _hengerutartalom, const string &_sebessegvalto, const string &_hajtas):
    rendszam(_rendszam),
    marka(_marka),
    tipus(_tipus),
    felszerelesek(_felszerelesek),
    kialakitas(_kialakitas),
    ar(_ar),
    napidij(_napidij),
    szin(_szin),
    csomagtarto_meret(_csomagtarto_meret),
    uzemanyag(_uzemanyag),
    evjarat(_evjarat),
    motor_teljesitmeny(_motor_teljesitmeny),
    hengerutartalom(_hengerutartalom),
    sebessegvalto(_sebessegvalto),
    hajtas(_hajtas)
{

}

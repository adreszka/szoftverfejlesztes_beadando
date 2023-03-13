#include "auto.h"


string Auto::getRendszam() const
{
    return rendszam;
}

list<string> Auto::getFelszerelesek() const
{
    return felszerelesek;
}



Auto::Auto(const string& _rendszam, int _ar, int _napidij, const string& _szin, int _csomagtarto_meret,
            const string& _uzemanyag, int _evjarat, int _motor_teljesitmeny, int _hengerutartalom,
            const string& _sebessegvalto, const string& _hajtas,
            const string& _marka, const string& _tipus, bool _raktaron,
            const string& _kialakitas, list<string> _felszerelesek):
    rendszam(_rendszam),
    ar(_ar),
    napidij(_napidij),
    szin(_szin),
    csomagtarto_meret(_csomagtarto_meret),
    uzemanyag(_uzemanyag),
    evjarat(_evjarat),
    motor_teljesitmeny(_motor_teljesitmeny),
    hengerutartalom(_hengerutartalom),
    sebessegvalto(_sebessegvalto),
    hajtas(_hajtas),
    marka(_marka),
    tipus(_tipus),
    raktaron(_raktaron),
    kialakitas(_kialakitas),
    felszerelesek(_felszerelesek)
{

}

#include "auto.h"


string Auto::getRendszam() const
{
    return rendszam;
}

list<string> Auto::getFelszerelesek() const
{
    return felszerelesek;
}



int Auto::getAr() const
{
    return ar;
}

int Auto::getNapidij() const
{
    return napidij;
}

string Auto::getSzin() const
{
    return szin;
}

int Auto::getCsomagtarto_meret() const
{
    return csomagtarto_meret;
}

string Auto::getUzemanyag() const
{
    return uzemanyag;
}

int Auto::getEvjarat() const
{
    return evjarat;
}

int Auto::getMotor_teljesitmeny() const
{
    return motor_teljesitmeny;
}

int Auto::getHengerutartalom() const
{
    return hengerutartalom;
}

string Auto::getSebessegvalto() const
{
    return sebessegvalto;
}

string Auto::getHajtas() const
{
    return hajtas;
}

string Auto::getMarka() const
{
    return marka;
}

string Auto::getTipus() const
{
    return tipus;
}

bool Auto::getRaktaron() const
{
    return raktaron;
}

string Auto::getKialakitas() const
{
    return kialakitas;
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

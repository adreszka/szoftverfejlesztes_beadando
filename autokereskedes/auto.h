#ifndef AUTO_H
#define AUTO_H

#include <string>
#include <list>

using namespace std;

class Auto
{
    string rendszam;
    string marka;
    string tipus;
    list<string> felszerelesek;
    string kialakitas;
    int ar;
    int napidij;
    string szin;
    int csomagtarto_meret;
    string uzemanyag;
    int evjarat;
    int motor_teljesitmeny;
    int hengerutartalom;
    string sebessegvalto;
    string hajtas;
public:
    Auto(const string& _rendszam, const string& _marka, const string& _tipus,
         list<string> _felszerelesek, const string& _kialakitas, int _ar, int _napidij,
         const string& _szin, int _csomagtarto_meret, const string& _uzemanyag,
         int _evjarat, int _motor_teljesitmeny, int _hengerutartalom,
         const string& _sebessegvalto, const string& _hajtas
         );
    // leírásokat tárol az autóról
};

#endif // AUTO_H

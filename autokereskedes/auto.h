#ifndef AUTO_H
#define AUTO_H

#include <string>

using namespace std;

class Auto
{
    string rendszam;
    string marka;
    string tipus;
    string *felszerelesek; // tömb
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
    Auto(const string& rendszam, const string& marka, const string& tipus,
         string& felszerelesek, const string& kialakitas, int ar, int napidij,
         const string& szin, int csomagtarto_meret, const string& uzemanyag,
         int evjarat, int motor_teljesitmeny, int hengerutartalom,
         const string& sebessegvalto, const string& hajtas
         );
    // leírásokat tárol az autóról
};

#endif // AUTO_H

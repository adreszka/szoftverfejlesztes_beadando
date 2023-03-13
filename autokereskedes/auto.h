#ifndef AUTO_H
#define AUTO_H

#include <string>
#include <list>

using namespace std;

class Auto
{
    string rendszam;
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
    string marka;
    string tipus;
    bool raktaron;             //0 nincs itt/1 itt van
    string kialakitas;
    list<string> felszerelesek;
public:
    Auto(const string& _rendszam, int _ar, int _napidij, const string& _szin, int _csomagtarto_meret,
         const string& _uzemanyag, int _evjarat, int _motor_teljesitmeny, int _hengerutartalom,
         const string& _sebessegvalto, const string& _hajtas,
         const string& _marka, const string& _tipus, bool _raktaron,
         const string& _kialakitas, list<string> _felszerelesek);
    // leírásokat tárol az autóról
    string getRendszam() const;
    list<string> getFelszerelesek() const;
    int getAr() const;
    int getNapidij() const;
    string getSzin() const;
    int getCsomagtarto_meret() const;
    string getUzemanyag() const;
    int getEvjarat() const;
    int getMotor_teljesitmeny() const;
    int getHengerutartalom() const;
    string getSebessegvalto() const;
    string getHajtas() const;
    string getMarka() const;
    string getTipus() const;
    bool getRaktaron() const;
    string getKialakitas() const;
};

#endif // AUTO_H

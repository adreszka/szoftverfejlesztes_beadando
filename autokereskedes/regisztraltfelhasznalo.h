#ifndef REGISZTRALTFELHASZNALO_H
#define REGISZTRALTFELHASZNALO_H

#include <string>
#include <list>

using namespace std;

class RegisztraltFelhasznalo
{
    string felhasznalo_nev;
    string teljes_nev;
    string szul_dat;
    int telefonszam;
    string email;
    bool nem;                //0 férfi 1 nő
    int iranyitoszam;
    int hozzaferes;
    public:
    RegisztraltFelhasznalo(const string& _felhasznalo_nev, const string& _teljes_nev, const string _szul_dat,
    int _telefonszam, const string& _email, bool _nem, int _iranyitoszam, int _hozzaferes);
    // tud keresni, szűrni, vásárolni...
};

#endif // REGISZTRALTFELHASZNALO_H

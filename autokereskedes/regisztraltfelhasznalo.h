#ifndef REGISZTRALT_FELHASZNALO_H
#define REGISZTRALT_FELHASZNALO_H

#include <string>
#include <list>

using namespace std;

class RegisztraltFelhasznalo
{
    int felhasznalo_id;
    string teljes_nev;
    string szul_dat;
    int telefonszam;
    string email;
    bool nem;                //0 férfi 1 nő
    int iranyitoszam;
    public:
    RegisztraltFelhasznalo(int felhasznalo_id, const string& _teljes_nev, const string _szul_dat,
    int _telefonszam, const string& _email, bool _nem, int _iranyitoszam);
    RegisztraltFelhasznalo();
    string getTeljes_nev() const;
    int getFelhasznalo_id() const;
};

#endif // REGISZTRALT_FELHASZNALO_H

#ifndef FELHASZNALO_H
#define FELHASZNALO_H

#include <string>
#include <list>

using namespace std;

class Felhasznalo
{
    int felhasznalo_id;
    string teljes_nev;
    string szul_dat;
    int telefonszam;
    string email;
    bool nem;                //0 férfi 1 nő
    int iranyitoszam;
    public:
    Felhasznalo(int felhasznalo_id, const string& _teljes_nev, const string _szul_dat,
    int _telefonszam, const string& _email, bool _nem, int _iranyitoszam);
};

#endif // FELHASZNALO_H

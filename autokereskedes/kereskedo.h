#ifndef KERESKEDO_H
#define KERESKEDO_H

#include <string>

using namespace std;

class Kereskedo
{
    // autókereskedőnek a tulaja, végzi az autók eladását és kérvények kezelését
    int felhasznalo_id;
    string teljes_nev;
    string telefonszam;
    string email;
public:
    Kereskedo();
    Kereskedo(int felhasznalo_id, const string &teljes_nev, const string &telefonszam, const string &email);
    int getFelhasznalo_id() const;
    const string &getTeljes_nev() const;
    const string &getTelefonszam() const;
    const string &getEmail() const;
};

#endif // KERESKEDO_H

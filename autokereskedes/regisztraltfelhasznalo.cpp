#include "regisztraltfelhasznalo.h"

string RegisztraltFelhasznalo::getTeljes_nev() const
{
    return teljes_nev;
}

int RegisztraltFelhasznalo::getFelhasznalo_id() const
{
    return felhasznalo_id;
}

RegisztraltFelhasznalo::RegisztraltFelhasznalo(int _felhasznalo_id, const string& _teljes_nev, const int _szul_dat,
                         const string& _telefonszam, const string& _email, bool _nem, int _iranyitoszam):
    felhasznalo_id(_felhasznalo_id),
    teljes_nev(_teljes_nev),
    szul_dat(_szul_dat),
    telefonszam(_telefonszam),
    email(_email),
    nem(_nem),
    iranyitoszam(_iranyitoszam)
{

}

RegisztraltFelhasznalo::RegisztraltFelhasznalo()
{

}

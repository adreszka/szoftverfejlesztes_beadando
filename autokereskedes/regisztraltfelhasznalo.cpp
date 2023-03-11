#include "regisztraltfelhasznalo.h"

RegisztraltFelhasznalo::RegisztraltFelhasznalo(const string& _felhasznalo_nev, const string& _teljes_nev, const string _szul_dat,
                                               int _telefonszam, const string& _email, bool _nem, int _iranyitoszam, int _hozzaferes):
    felhasznalo_nev(_felhasznalo_nev),
    teljes_nev(_teljes_nev),
    szul_dat(_szul_dat),
    telefonszam(_telefonszam),
    email(_email),
    nem(_nem),
    iranyitoszam(_iranyitoszam),
    hozzaferes(_hozzaferes)
{

}

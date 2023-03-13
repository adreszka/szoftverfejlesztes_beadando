#include "felhasznalo.h"

Felhasznalo::Felhasznalo(int felhasznalo_id, const string& _teljes_nev, const string _szul_dat,
                         int _telefonszam, const string& _email, bool _nem, int _iranyitoszam):
    teljes_nev(_teljes_nev),
    szul_dat(_szul_dat),
    telefonszam(_telefonszam),
    email(_email),
    nem(_nem),
    iranyitoszam(_iranyitoszam)
{

}

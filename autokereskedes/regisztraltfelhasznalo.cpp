#include "regisztraltfelhasznalo.h"

string RegisztraltFelhasznalo::getTeljes_nev() const
{
    return teljes_nev;
}

int RegisztraltFelhasznalo::getFelhasznalo_id() const
{
    return felhasznalo_id;
}

int RegisztraltFelhasznalo::getSzul_dat() const
{
    return szul_dat;
}

const string &RegisztraltFelhasznalo::getTelefonszam() const
{
    return telefonszam;
}

const string &RegisztraltFelhasznalo::getEmail() const
{
    return email;
}

bool RegisztraltFelhasznalo::getNem() const
{
    return nem;
}

int RegisztraltFelhasznalo::getIranyitoszam() const
{
    return iranyitoszam;
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

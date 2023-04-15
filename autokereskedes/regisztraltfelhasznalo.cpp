#include "regisztraltfelhasznalo.h"

string RegisztraltFelhasznalo::getTeljes_nev() const
{
    return teljes_nev;
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

const string &RegisztraltFelhasznalo::getFelhasznalo_nev() const
{
    return felhasznalo_nev;
}

RegisztraltFelhasznalo::RegisztraltFelhasznalo(const string& _teljes_nev, const int _szul_dat,
                         const string& _telefonszam, const string& _email, bool _nem, int _iranyitoszam, const string &_felhasznalo_nev):
    teljes_nev(_teljes_nev),
    szul_dat(_szul_dat),
    telefonszam(_telefonszam),
    email(_email),
    nem(_nem),
    iranyitoszam(_iranyitoszam),
    felhasznalo_nev(_felhasznalo_nev)
{

}

RegisztraltFelhasznalo::RegisztraltFelhasznalo()
{

}

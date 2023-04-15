#include "kereskedo.h"

int Kereskedo::getFelhasznalo_id() const
{
    return felhasznalo_id;
}

const string &Kereskedo::getTeljes_nev() const
{
    return teljes_nev;
}

const string &Kereskedo::getTelefonszam() const
{
    return telefonszam;
}

const string &Kereskedo::getEmail() const
{
    return email;
}

Kereskedo::Kereskedo()
{

}

Kereskedo::Kereskedo(int felhasznalo_id, const string &teljes_nev, const string &telefonszam, const string &email) : felhasznalo_id(felhasznalo_id),
    teljes_nev(teljes_nev),
    telefonszam(telefonszam),
    email(email)
{}

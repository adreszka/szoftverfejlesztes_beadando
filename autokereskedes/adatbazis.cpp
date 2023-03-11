#include "adatbazis.h"

void Adatbazis::csatlakozas(const string &fajl)
{
    dbcon.Connect(fajl.c_str(),"","",SA_SQLite_Client);
    cout << "Sikeres csatlakozas!" << endl;
}

void Adatbazis::teszt()
{
    SACommand szamol(&dbcon,"SELECT count(Rendszam) FROM Auto");
    szamol.Execute();
    szamol.FetchNext();
    int cnt = szamol[1].asLong();
    cout << "Rekordok szama: " << cnt << endl;
    cout << "Jo munkat!" << endl << endl;
}

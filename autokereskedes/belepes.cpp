#include "belepes.h"

Belepes &Belepes::getObjektum()
{
    static Belepes belepes;
    return belepes;
}

void Belepes::bejelentkezes()
{
    string username;
    string password;
    cout << "Kerem adja meg a felhasznalonevet!" << endl;
    cin >> username;
    cout << "Kerem adja meg a jelszavát!" << endl;
    cin >> password;
    //if (username == //adatbázisba ellenőrzés, hogy szerepel-e benne)
        //if (password == ////adatbázisba ellenőrzés, hogy szerepel-e benne)
            // cout << "Sikeresen bejelentkezett!" << endl;
    //cout << "Sikertelen bejelentkezes!" << endl;
}

#include "adatbazis.h"

#include <chrono>
#include <iomanip>

Adatbazis &Adatbazis::getObjektum()
{
    static Adatbazis adatbazis;
    return adatbazis;
}

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

void Adatbazis::autokBeolvas()
{
    SACommand selectauto(&dbcon,"SELECT a.Rendszam, Ar, Napidij, Szin, Csomagtarto_merete, Uzemanyag, Evjarat, Motor_teljesitmenye, Hengerurtartalom, Sebessegvalto, Hajtas, m.Marka, t.Tipus, Raktaron, k.Kialakitas_nev"
                            " FROM Auto a JOIN Kialakitas k ON a.Kialakitas_Id = k.Kialakitas_Id JOIN Tipus t ON a.Tipus_Id = t.Tipus_Id JOIN Marka m ON m.Marka_Id = t.Marka_Id");
    SACommand selectfelszereltseg(&dbcon, "SELECT felsz"
                      " FROM Felszereltseg_seged fs JOIN Felszereltseg f ON fs.Felsz_Id = f.Felsz_Id"
                      " WHERE fs.Rendszam = :1");
    selectauto.Execute();
    while (selectauto.FetchNext()){
        string rendszam = (string)selectauto[1].asString();
        int ar = selectauto[2].asLong();
        int napidij = selectauto[3].asLong();
        string szin = (string)selectauto[4].asString();
        int csomagtarto_meret = selectauto[5].asLong();
        string uzemanyag = (string)selectauto[6].asString();
        int evjarat = selectauto[7].asLong();
        int motor_teljesitmeny = selectauto[8].asLong();
        int hengerurtartalom = selectauto[9].asLong();
        string sebessegvalto;
        if (selectauto[10].asLong()==0){
            sebessegvalto = "Manuális";
        }else{
            sebessegvalto = "Automata";
        }
        string hajtas = (string)selectauto[11].asString();
        string marka = (string)selectauto[12].asString();
        string tipus = (string)selectauto[13].asString();
        bool raktaron = selectauto[14].asBool();
        string kialakitas = (string)selectauto[15].asString();
        selectfelszereltseg << rendszam.c_str();
        selectfelszereltseg.Execute();
        list<string> felszerelesek;
        while(selectfelszereltseg.FetchNext()){
            string felszereles = (string)selectfelszereltseg[1].asString();
            felszerelesek.push_back(felszereles);
        }
        Auto a(rendszam, ar, napidij, szin, csomagtarto_meret, uzemanyag, evjarat,
               motor_teljesitmeny, hengerurtartalom, sebessegvalto, hajtas,
               marka, tipus, raktaron, kialakitas, felszerelesek);
        Tarolo::getObjektum().hozzaAd(a);
    }
}

bool Adatbazis::bejelentkezesEllenorzes(const string& felhasznalo_nev, const string& jelszo)
{
    boolean adatbazisbanTalalhato = false;
    SACommand select(&dbcon, "SELECT * FROM Bejelentkezesi_adatok");
        select.Execute();
        while(select.FetchNext()) {
            string felhasznalo_nevdb = (string)select[2].asString();
            string jelszodb = (string)select[3].asString();
            if (felhasznalo_nev == felhasznalo_nevdb && jelszo == jelszodb) {
                adatbazisbanTalalhato = true;
                break;
            }
        }

    return adatbazisbanTalalhato;
}

void Adatbazis::felhasznaloBeolvas(const string& felhasznalo_nev)
{
    SACommand selectfelhasznalo(&dbcon,"SELECT f.Felhasznalo_Id, Teljes_nev, Szul_dat, Telefonszam, Email, Nem, Iranyitoszam, Felhasznalo_nev"
                                " FROM Felhasznalo f JOIN Bejelentkezesi_adatok b ON f.Felhasznalo_Id = b.Felhasznalo_Id"
                                " WHERE felhasznalo_nev = :1");
    selectfelhasznalo << felhasznalo_nev.c_str();
    selectfelhasznalo.Execute();
    while (selectfelhasznalo.FetchNext()){
        int felhasznalo_id = selectfelhasznalo[1].asLong();
        string teljes_nev = (string)selectfelhasznalo[2].asString();
        int szul_dat = selectfelhasznalo[3].asLong();
        string telefonszam = (string)selectfelhasznalo[4].asString();
        string email = (string)selectfelhasznalo[5].asString();
        bool nem = selectfelhasznalo[6].asBool();
        int iranyitoszam = selectfelhasznalo[7].asLong();
        RegisztraltFelhasznalo f(felhasznalo_id, teljes_nev, szul_dat, telefonszam,
                      email, nem, iranyitoszam);
        Tarolo::getObjektum().setFelhasznalo(f);
    }
}

void Adatbazis::autoVasarlas(const string& rendszam)
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();
    int felhasznalo_id = Tarolo::getObjektum().getFelhasznalo().getFelhasznalo_id();
    SACommand addTranzakcio(&dbcon,"INSERT INTO Tranzakcio(Rendszam, Datum, Szerep, Felhasznalo_Id) VALUES (:1, :2, 0, :3)");
    SACommand deleteAutoFelszereles(&dbcon, "DELETE FROM Felszereltseg_seged WHERE Rendszam = :1");
    SACommand deleteAuto(&dbcon, "DELETE FROM Auto WHERE Rendszam = :1");
    addTranzakcio << rendszam.c_str();
    addTranzakcio << str.c_str();
    addTranzakcio << (long)felhasznalo_id;
    addTranzakcio.Execute();
    deleteAutoFelszereles << rendszam.c_str();
    deleteAutoFelszereles.Execute();
    deleteAuto << rendszam.c_str();
    deleteAuto.Execute();
}

void Adatbazis::markaBeolvasas()
{
    SACommand markaSelect(&dbcon, "SELECT Marka, Tipus FROM Marka JOIN Tipus ON Marka.Marka_Id = Tipus.Marka_Id");
    markaSelect.Execute();

    map<string, list<string>> markak;
    while(markaSelect.FetchNext())
    {
        markak[(string)markaSelect[1].asString()].push_back((string)markaSelect[2].asString());
    }
    Tarolo::getObjektum().setMarkak(markak);
}

bool Adatbazis::regisztracioElmentese(const string &felhasznaloNev, const string &email, const string &jelszo, const string &teljesNev, const int &szulEv, const string &telefonSzam, const int &iranyitoSzam, const bool &nem)
{
    boolean adatbazisbanTalalhato = false;
    int felhasznalo_id;
    SACommand select(&dbcon, "SELECT * FROM Bejelentkezesi_adatok");
    select.Execute();
    while(select.FetchNext()) {
        string usernamedb = (string)select[2].asString();
        if (felhasznaloNev == usernamedb) {
            boolean adatbazisbanTalalhato = true;
            return adatbazisbanTalalhato;
        }
    }
    SACommand add(&dbcon,
                  "INSERT INTO Bejelentkezesi_adatok(Felhasznalo_nev,"
                  " Jelszo, Hozzaferes) VALUES(:1, :2, :3)");
    add << felhasznaloNev.c_str();
    add << jelszo.c_str();
    add << "felhasznalo";
    add.Execute();
    SACommand selectFelhasznalo(&dbcon, "SELECT * FROM Bejelentkezesi_adatok WHERE Felhasznalo_nev = :1");
    selectFelhasznalo << felhasznaloNev.c_str();
    selectFelhasznalo.Execute();
    while (selectFelhasznalo.FetchNext()) {
        felhasznalo_id = selectFelhasznalo[1].asLong();
    }
    SACommand addAdatok(&dbcon, "INSERT INTO Felhasznalo VALUES (:1,:2,:3,:4,:5,:6,:7)");
    addAdatok << (long)felhasznalo_id;
    addAdatok << teljesNev.c_str();
    addAdatok << (long)szulEv;
    addAdatok << telefonSzam.c_str();
    addAdatok << email.c_str();
    addAdatok << (bool)nem;
    addAdatok << (long)iranyitoSzam;
    addAdatok.Execute();
    return adatbazisbanTalalhato;
}

void Adatbazis::autoBerles(const string &rendszam, const int &felhasznalo_id)
{
    SACommand updateraktaron(&dbcon, "UPDATE Auto SET Raktaron = 0 WHERE Rendszam = :1");
    SACommand addKolcsonzes(&dbcon, "INSERT INTO Kolcsonzes(Rendszam, Felhasznalo_Id) VALUES (:1, :2)");
    updateraktaron << rendszam.c_str();
    updateraktaron.Execute();
    addKolcsonzes << rendszam.c_str();
    addKolcsonzes << (long)felhasznalo_id;
    addKolcsonzes.Execute();
}




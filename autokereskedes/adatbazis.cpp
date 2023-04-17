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

void Adatbazis::autokBeolvas()
{
    SACommand selectauto(&dbcon,"SELECT a.Rendszam, Ar, Napidij, Szin, Csomagtarto_merete, Uzemanyag, Evjarat, Motor_teljesitmenye, Hengerurtartalom, Sebessegvalto, Hajtas, m.Marka_nev, t.Tipus_nev, Raktaron, k.Kialakitas_nev"
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

string Adatbazis::bejelentkezesEllenorzes(const string& felhasznalo_nev, const string& jelszo)
{
    SACommand select(&dbcon, "SELECT * FROM Bejelentkezesi_adatok");
        select.Execute();
        while(select.FetchNext()) {
            string felhasznalo_nevdb = (string)select[2].asString();
            string jelszodb = (string)select[3].asString();
            string hozzaferes = (string)select[4].asString();
            if (felhasznalo_nev == felhasznalo_nevdb && jelszo == jelszodb) {
                return hozzaferes;
            }
        }
    return "";
}

void Adatbazis::felhasznaloBeolvas(const string& felhasznalo_nev)
{
    SACommand selectfelhasznalo(&dbcon,"SELECT Teljes_nev, Szul_dat, Telefonszam, Email, Nem, Iranyitoszam, Felhasznalo_nev"
                                " FROM Felhasznalo f JOIN Bejelentkezesi_adatok b ON f.Felhasznalo_Id = b.Felhasznalo_Id"
                                " WHERE felhasznalo_nev = :1");
    selectfelhasznalo << felhasznalo_nev.c_str();
    selectfelhasznalo.Execute();
    while (selectfelhasznalo.FetchNext()){
        string teljes_nev = (string)selectfelhasznalo[1].asString();
        int szul_dat = selectfelhasznalo[2].asLong();
        string telefonszam = (string)selectfelhasznalo[3].asString();
        string email = (string)selectfelhasznalo[4].asString();
        bool nem = selectfelhasznalo[5].asBool();
        int iranyitoszam = selectfelhasznalo[6].asLong();
        string felhasznalo_nev = (string)selectfelhasznalo[7].asString();
        RegisztraltFelhasznalo f(teljes_nev, szul_dat, telefonszam,
                      email, nem, iranyitoszam, felhasznalo_nev);
        Tarolo::getObjektum().setFelhasznalo(f);
    }
}

void Adatbazis::autoVasarlas(const string& rendszam)
{
    int felhasznalo_id;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    auto str = oss.str();
    SACommand selectFelhasznalo_id(&dbcon, "SELECT Felhasznalo_Id FROM Bejelentkezesi_adatok WHERE Felhasznalo_nev LIKE :1");
    SACommand addTranzakcio(&dbcon,"INSERT INTO Tranzakcio(Rendszam, Datum, Szerep, Felhasznalo_Id) VALUES (:1, :2, 0, :3)");
    SACommand deleteAutoFelszereles(&dbcon, "DELETE FROM Felszereltseg_seged WHERE Rendszam = :1");
    SACommand deleteAuto(&dbcon, "DELETE FROM Auto WHERE Rendszam = :1");
    selectFelhasznalo_id << Tarolo::getObjektum().getFelhasznalo().getFelhasznalo_nev().c_str();
    selectFelhasznalo_id.Execute();
    while(selectFelhasznalo_id.FetchNext()){
        felhasznalo_id = selectFelhasznalo_id[1].asLong();
    }
    addTranzakcio << rendszam.c_str();
    addTranzakcio << str.c_str();
    addTranzakcio << (long)felhasznalo_id;
    addTranzakcio.Execute();
    deleteAutoFelszereles << rendszam.c_str();
    deleteAutoFelszereles.Execute();
    deleteAuto << rendszam.c_str();
    deleteAuto.Execute();
    Tarolo::getObjektum().torolAuto(rendszam);
}

void Adatbazis::markaBeolvasas()
{
    SACommand markaSelect(&dbcon, "SELECT Marka_nev, Tipus_nev FROM Marka JOIN Tipus ON Marka.Marka_Id = Tipus.Marka_Id");
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

void Adatbazis::autoBerles(const string &rendszam, const string &felhasznalo_nev)
{
    int felhasznalo_id;
    SACommand updateraktaron(&dbcon, "UPDATE Auto SET Raktaron = 0 WHERE Rendszam = :1");
    SACommand addKolcsonzes(&dbcon, "INSERT INTO Kolcsonzes(Rendszam, Felhasznalo_Id) VALUES (:1, :2)");
    SACommand selectFelhasznalo_id(&dbcon, "SELECT Felhasznalo_Id FROM Bejelentkezesi_adatok WHERE Felhasznalo_nev LIKE :1");
    selectFelhasznalo_id << felhasznalo_nev.c_str();
    selectFelhasznalo_id.Execute();
    while (selectFelhasznalo_id.FetchNext()){
        felhasznalo_id = selectFelhasznalo_id[1].asLong();
    }
    updateraktaron << rendszam.c_str();
    updateraktaron.Execute();
    addKolcsonzes << rendszam.c_str();
    addKolcsonzes << (long)felhasznalo_id;
    addKolcsonzes.Execute();

    Tarolo::getObjektum().raktarbolKivetel(rendszam);
}

void Adatbazis::autoEladasraKinalasa(const string& rendszam, int ar, int napi_dij, const string& szin,
                          int csomagtarto_meret, const string& uzemanyag, int evjarat, int motor_teljesitmeny,
                          int hengerutartalom, bool sebessegvalto, const string& hajtas, const string& tipus,
                          const string& marka, const string& kialakitas, list<string> felszerelesek)
{
    list<int> felsz_id;
    int marka_id, tipus_id, kialakitas_id, szamlalo = 0;
    SACommand selectMarkak(&dbcon, "SELECT * FROM Marka WHERE Marka_nev = :1");
    SACommand selectTipusok(&dbcon, "SELECT * FROM Tipus WHERE Tipus_nev = :1");
    SACommand selectKialakitas(&dbcon, "SELECT * FROM Kialakitas WHERE Kialakitas_nev = :1");
    SACommand selectFelszerelesek(&dbcon, "SELECT * FROM Felszereltseg");
    SACommand insertFelszereles(&dbcon, "INSERT INTO Felszereltseg_seged VALUES (:1,:2)");
    SACommand insertAuto(&dbcon, "INSERT INTO Auto VALUES (:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12,:13,:14)");
    selectKialakitas << kialakitas.c_str();
    selectKialakitas.Execute();
    while (selectKialakitas.FetchNext())
    {
        kialakitas_id = selectKialakitas[1].asLong();
    }
    selectMarkak << marka.c_str();
    selectMarkak.Execute();
    while (selectMarkak.FetchNext())
    {
        szamlalo++;
    }
    if (szamlalo == 0)
    {
        SACommand insertMarka(&dbcon, "INSERT INTO Marka(Marka_nev) VALUES (:1)");
        insertMarka << marka.c_str();
        insertMarka.Execute();
    }
    szamlalo = 0;
    selectMarkak.Execute();
    while (selectMarkak.FetchNext())
    {
        marka_id = selectMarkak[1].asLong();
    }
    selectTipusok << tipus.c_str();
    selectTipusok.Execute();
    while (selectTipusok.FetchNext())
    {
        szamlalo++;
    }
    if (szamlalo == 0)
    {
        SACommand insertTipus(&dbcon, "INSERT INTO Tipus(Tipus_nev, Marka_Id) VALUES(:1,:2)");
        insertTipus << tipus.c_str();
        insertTipus << (long)marka_id;
        insertTipus.Execute();
    }
    selectTipusok.Execute();
    while (selectTipusok.FetchNext())
    {
        tipus_id = selectTipusok[1].asLong();
    }
    insertAuto << rendszam.c_str();
    insertAuto << (long)ar;
    insertAuto << (long)napi_dij;
    insertAuto << szin.c_str();
    insertAuto << (long)csomagtarto_meret;
    insertAuto << uzemanyag.c_str();
    insertAuto << (long)evjarat;
    insertAuto << (long)motor_teljesitmeny;
    insertAuto << (long)hengerutartalom;
    insertAuto << (bool)sebessegvalto;
    insertAuto << hajtas.c_str();
    insertAuto << (long)tipus_id;
    insertAuto << (long)kialakitas_id;
    insertAuto << (long)1;
    insertAuto.Execute();
    selectFelszerelesek.Execute();
    while (selectFelszerelesek.FetchNext()) {
        string felszereles = (string)selectFelszerelesek[2].asString();
        for (auto& felsz : felszerelesek) {
            if (felszereles == felsz) {
                int id = selectFelszerelesek[1].asLong();
                felsz_id.push_back(id);
            }
        }
    }
    if (!felsz_id.empty()) {
        for (auto& id : felsz_id) {
            insertFelszereles << rendszam.c_str();
            insertFelszereles << (long)id;
            insertFelszereles.Execute();
        }
    }
}

void Adatbazis::autoTorles(const string &rendszam)
{
    Tarolo::getObjektum().torolAuto(rendszam);
    SACommand deleteFelszerelesek(&dbcon, "DELETE FROM Felszereltseg_seged WHERE Rendszam = :1");
    SACommand deleteAuto(&dbcon, "DELETE FROM Auto WHERE Rendszam = :1");
    deleteFelszerelesek << rendszam.c_str();
    deleteFelszerelesek.Execute();
    deleteAuto << rendszam.c_str();
    deleteAuto.Execute();
}

void Adatbazis::fiokTorles(const string &felhasznalo_nev)
{
    int felhaszn_id;
    SACommand selectFelhasznalo(&dbcon, "SELECT * FROM Bejelentkezesi_adatok WHERE Felhasznalo_nev = :1");
    SACommand deleteFelhasznaloAdatok(&dbcon, "DELETE FROM Felhasznalo WHERE Felhasznalo_Id = :1");
    SACommand deleteFelhasznaloBejelentkezesiAdatok(&dbcon, "DELETE FROM "
                                                            "Bejelentkezesi_adatok WHERE Felhasznalo_Id = :1");
    selectFelhasznalo << felhasznalo_nev.c_str();
    selectFelhasznalo.Execute();
    while (selectFelhasznalo.FetchNext())
    {
        felhaszn_id = selectFelhasznalo[1].asLong();
    }
    deleteFelhasznaloAdatok << (long)felhaszn_id;
    deleteFelhasznaloAdatok.Execute();
    deleteFelhasznaloBejelentkezesiAdatok << (long)felhaszn_id;
    deleteFelhasznaloBejelentkezesiAdatok.Execute();
}

void Adatbazis::kereskedoHozzaadasa(const string &felhasznalo_nev, const string &jelszo,const string &teljes_nev, const string &telefonszam, const string &email)
{
    int felhasznalo_id;
    SACommand insertBejelentkezesiAdatok(&dbcon, "INSERT INTO Bejelentkezesi_adatok (Felhasznalo_nev, Jelszo, Hozzaferes) VALUES (:1, :2, 'kereskedo')");
    insertBejelentkezesiAdatok << felhasznalo_nev.c_str();
    insertBejelentkezesiAdatok << jelszo.c_str();
    insertBejelentkezesiAdatok.Execute();
    SACommand selectFelhasznalo_id(&dbcon, "SELECT Felhasznalo_Id FROM Bejelentkezesi_adatok WHERE Felhasznalo_nev LIKE :1");
    selectFelhasznalo_id << felhasznalo_nev.c_str();
    selectFelhasznalo_id.Execute();
    while (selectFelhasznalo_id.FetchNext()){
        felhasznalo_id = selectFelhasznalo_id[1].asLong();
    }
    SACommand insertFelhasznalo(&dbcon, "INSERT INTO Felhasznalo (Felhasznalo_Id ,Teljes_nev, Telefonszam, Email) VALUES (:1, :2, :3, :4)");
    insertFelhasznalo << (long)felhasznalo_id;
    insertFelhasznalo << teljes_nev.c_str();
    insertFelhasznalo << telefonszam.c_str();
    insertFelhasznalo << email.c_str();
    insertFelhasznalo.Execute();
}

void Adatbazis::autoBerlesbolVisszahozva(const string &rendszam, int elteltnapok)
{
    int napidij = 0, kolcsdij = 0;
    SACommand selectAuto(&dbcon, "SELECT * FROM Auto WHERE Rendszam = :1");
    SACommand updateAuto(&dbcon, "UPDATE Auto SET Raktaron = 1 WHERE Rendszam = :1");
    SACommand updateKolcsonzottAuto(&dbcon, "UPDATE Kolcsonzes SET elteltnapok = :2, Kolcsdij = :3 "
                                            "WHERE Rendszam = :1 AND elteltnapok ISNULL");
    selectAuto << rendszam.c_str();
    selectAuto.Execute();
    while (selectAuto.FetchNext())
    {
        napidij = selectAuto[3].asLong();
    }
    kolcsdij = elteltnapok * napidij;
    updateKolcsonzottAuto << rendszam.c_str();
    updateKolcsonzottAuto << (long)elteltnapok;
    updateKolcsonzottAuto << (long)kolcsdij;
    updateKolcsonzottAuto.Execute();
    updateAuto << rendszam.c_str();
    updateAuto.Execute();
}

pair<list<Kereskedo>,list<RegisztraltFelhasznalo>> Adatbazis::fiokokListazasa(const bool kereskedo, const bool felhasznalo)
{
    list<Kereskedo> kereskedoL;
    list<RegisztraltFelhasznalo> felhasznaloL;
    pair<list<Kereskedo>,list<RegisztraltFelhasznalo>> lista;
    if((kereskedo && felhasznalo) || (!kereskedo && !felhasznalo)){
        SACommand felhasznalokLekerese(&dbcon, "SELECT Felhasznalo_nev, Teljes_nev, Szul_dat, Telefonszam, Email, Nem, Iranyitoszam, Hozzaferes "
                          "FROM Bejelentkezesi_adatok b JOIN Felhasznalo f ON b.Felhasznalo_Id = f.Felhasznalo_Id ");
        felhasznalokLekerese.Execute();
        while (felhasznalokLekerese.FetchNext()){
            if((string)felhasznalokLekerese[8].asString() == "kereskedo"){
                string felhasznalo_nev = (string)felhasznalokLekerese[1].asString();
                string teljes_nev = (string)felhasznalokLekerese[2].asString();
                string telefonszam = (string)felhasznalokLekerese[4].asString();
                string email = (string)felhasznalokLekerese[5].asString();
                Kereskedo k(teljes_nev, telefonszam, email, felhasznalo_nev);
                kereskedoL.push_back(k);
            }else if((string)felhasznalokLekerese[8].asString() == "felhasznalo"){
                string felhasznalo_nev = (string)felhasznalokLekerese[1].asString();
                string teljes_nev = (string)felhasznalokLekerese[2].asString();
                int szul_dat = felhasznalokLekerese[3].asLong();
                string telefonszam = (string)felhasznalokLekerese[4].asString();
                string email = (string)felhasznalokLekerese[5].asString();
                bool nem = felhasznalokLekerese[6].asBool();
                int iranyitoszam = felhasznalokLekerese[7].asLong();
                RegisztraltFelhasznalo rf(teljes_nev, szul_dat, telefonszam, email, nem, iranyitoszam, felhasznalo_nev);
                felhasznaloL.push_back(rf);
            }
        }
        lista.first = kereskedoL;
        lista.second = felhasznaloL;
    }
    else if(kereskedo && !felhasznalo){
        SACommand felhasznalokLekerese(&dbcon, "SELECT Felhasznalo_nev, Teljes_nev, Telefonszam, Email, Hozzaferes "
                          "FROM Bejelentkezesi_adatok b JOIN Felhasznalo f ON b.Felhasznalo_Id = f.Felhasznalo_Id ");
        felhasznalokLekerese.Execute();
        while (felhasznalokLekerese.FetchNext()){
            if((string)felhasznalokLekerese[5].asString() == "kereskedo"){
            string felhasznalo_nev = (string)felhasznalokLekerese[1].asString();
            string teljes_nev = (string)felhasznalokLekerese[2].asString();
            string telefonszam = (string)felhasznalokLekerese[3].asString();
            string email = (string)felhasznalokLekerese[4].asString();
            Kereskedo k(teljes_nev, telefonszam, email, felhasznalo_nev);
            kereskedoL.push_back(k);
            }
        }
        lista.first = kereskedoL;
    }
    else if(!kereskedo && felhasznalo){
        SACommand felhasznalokLekerese(&dbcon, "SELECT Felhasznalo_nev, Teljes_nev, Szul_dat, Telefonszam, Email, Nem, Iranyitoszam, Hozzaferes "
                          "FROM Bejelentkezesi_adatok b JOIN Felhasznalo f ON b.Felhasznalo_Id = f.Felhasznalo_Id ");
        felhasznalokLekerese.Execute();
        while (felhasznalokLekerese.FetchNext()){
            if((string)felhasznalokLekerese[8].asString() == "felhasznalo"){
                string felhasznalo_nev = (string)felhasznalokLekerese[1].asString();
                string teljes_nev = (string)felhasznalokLekerese[2].asString();
                int szul_dat = felhasznalokLekerese[3].asLong();
                string telefonszam = (string)felhasznalokLekerese[4].asString();
                string email = (string)felhasznalokLekerese[5].asString();
                bool nem = felhasznalokLekerese[6].asBool();
                int iranyitoszam = felhasznalokLekerese[7].asLong();
                RegisztraltFelhasznalo rf(teljes_nev, szul_dat, telefonszam, email, nem, iranyitoszam, felhasznalo_nev);
                felhasznaloL.push_back(rf);
            }
        }
        lista.first = kereskedoL;
        lista.second = felhasznaloL;
    }
    return lista;
}

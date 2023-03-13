#include "adatbazis.h"

void Adatbazis::csatlakozas(const string &fajl)
{
    dbcon.Connect(fajl.c_str(),"","",SA_SQLite_Client);
}

void Adatbazis::teszt()
{
    SACommand szamol(&dbcon,"SELECT count(Rendszam) FROM Auto");
    szamol.Execute();
    szamol.FetchNext();
    int cnt = szamol[1].asLong();
}

void Adatbazis::autokBeolvas()
{
    SACommand selectauto(&dbcon,"SELECT a.Rendszam, Ar, Napidij, Szin, Csomagtarto_merete, Uzemanyag, Evjarat, Motor_teljesitmenye, Hengerurtartalom, Sebessegvalto, Hajtas, m.Marka, t.Tipus, Raktaron, k.Kialakitas"
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

//void Adatbazis::felhaszlnaoBeolvas()
//{
//    SACommand selectfelhasznalo(&dbcon,"SELECT *"
//                         " FROM Felhasznalo");
//    selectfelhasznalo.Execute();
//    while (selectfelhasznalo.FetchNext()){
//        int ar = selectfelhasznalo[1].asLong();
//    }
//}

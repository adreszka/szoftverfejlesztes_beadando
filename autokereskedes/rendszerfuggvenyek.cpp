#include "rendszerfuggvenyek.h"
list<Auto> kereses(string marka,
                   string tipus,
                   pair<int,int> ar,
                   pair<int,int> berlet,
                   pair<int,int> ev,
                   string uzemanyag[],
                   string meghajtas[],
                   string kivitel[],
                   pair<int,int> teljesitmeny,
                   pair<int,int> urtartalom,
                   string valto[],
                   string felszereltseg[])
{
    list<Auto> autok = Tarolo::getObjektum().getAutok();
    list<Auto> ki_autok;
    copy_if(autok.begin(), autok.end(), back_inserter(ki_autok), [&](Auto temp){
        list<string> felsz = temp.getFelszerelesek();
        return (temp.getMarka() == marka || marka == "Válasszon") &&
                (temp.getTipus() == tipus || tipus == "Válasszon") &&
                ((temp.getAr() >= ar.first && temp.getAr() <= ar.second) || (temp.getAr() >= ar.first && ar.second == 0) || (ar.first == 0 && ar.second == 0)) &&
                ((temp.getNapidij() >= berlet.first && temp.getNapidij() <= berlet.second) || (temp.getNapidij() >= berlet.first && berlet.second == 0) || (berlet.first == 0 && berlet.second == 0)) &&
                ((temp.getEvjarat() >= ev.first && temp.getEvjarat() <= ev.second) || (temp.getEvjarat() >= ev.first && ev.second == 0) || (ev.first == 0 && ev.second == 0)) &&
                ((find(uzemanyag, uzemanyag+3, temp.getUzemanyag()) != uzemanyag+3) || (all_of(uzemanyag, uzemanyag+3, [](string temp){return temp == "";}))) &&
                ((find(meghajtas, meghajtas+3, temp.getHajtas()) != meghajtas+3) || (all_of(meghajtas, meghajtas+3, [](string temp){return temp == "";}))) &&
                ((find(kivitel, kivitel+3, temp.getKialakitas()) != kivitel+3) || (all_of(kivitel, kivitel+3, [](string temp){return temp == "";}))) &&
                ((temp.getMotor_teljesitmeny() >= teljesitmeny.first && temp.getMotor_teljesitmeny() <= teljesitmeny.second) || (temp.getMotor_teljesitmeny() >= teljesitmeny.first && teljesitmeny.second == 0) || (teljesitmeny.first == 0 && teljesitmeny.second == 0)) &&
                ((temp.getHengerutartalom() >= urtartalom.first && temp.getHengerutartalom() <= urtartalom.second) || (temp.getHengerutartalom() >= urtartalom.first && urtartalom.second == 0) || (urtartalom.first == 0 && urtartalom.second == 0)) &&
                ((find(valto, valto+2, temp.getSebessegvalto()) != valto+2) || (all_of(valto, valto+2, [](string temp){return temp == "";}))) &&
                (any_of(felsz.begin(), felsz.end(), [&](string innerTemp){return (find(felszereltseg, felszereltseg+6, innerTemp) != felszereltseg+6);}))
                || (all_of(felszereltseg, felszereltseg+6, [](string temp) {return temp == "";}));
    });
    return ki_autok;
}

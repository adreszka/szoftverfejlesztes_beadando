#ifdef _W64 || _WIN32
#define WIN32_LEAN_AND_MEAN
#endif // _W64 || _WIN32
#include "SQLAPI.h"
#include "tarolo.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>

#ifndef RENDSZERFUGGVENYEK_H
#define RENDSZERFUGGVENYEK_H

using namespace std;

list<Auto> kereses(string marka, string tipus, pair<int,int> ar, pair<int,int> berlet, pair<int,int> ev, string uzemanyag[], string meghajtas[], string kivitel[], pair<int,int> teljesitmeny, pair<int,int> urtartalom, string valto[], string felszereltseg[]);

#endif // RENDSZERFUGGVENYEK_H

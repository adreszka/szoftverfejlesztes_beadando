#include "SQLAPI.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>

#ifndef RENDSZERFUGGVENYEK_H
#define RENDSZERFUGGVENYEK_H

using namespace std;

template <typename T> bool keresesiParameter(T x)
{
    return (x == "" || x == 0) ? true : false;
}

bool arIntervallum (int x, int y, int ar)
{
    if(x == 0 && y == 0)
        return false;
    else
        return (y<ar && ar<x) ? true : false;
}

bool felszereles (vector<int> felszerelesek, int felszereles)
{
    for(int x : felszerelesek)
    {
        if(felszereles == x)
            return true;
    }
    return false;
}

#endif // RENDSZERFUGGVENYEK_H

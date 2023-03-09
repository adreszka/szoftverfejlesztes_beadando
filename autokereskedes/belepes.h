#ifndef BELEPES_H
#define BELEPES_H

#include <string>
#include <iostream>

using namespace std;

class Belepes
{
    Belepes()=default;
    Belepes(const Belepes& other)=default;
public:
    static Belepes& getObjektum();
    void bejelentkezes();
};

#endif // BELEPES_H

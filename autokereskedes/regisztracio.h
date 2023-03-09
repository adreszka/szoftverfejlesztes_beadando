#ifndef REGISZTRACIO_H
#define REGISZTRACIO_H

#include <string>
#include <iostream>

using namespace std;

class Regisztracio
{
    Regisztracio()=default;
    Regisztracio(const Regisztracio& other)=default;
public:
    static Regisztracio& getObjektum();
    void regisztracio();
};

#endif // REGISZTRACIO_H

#ifndef AUTENTIKACIO_H
#define AUTENTIKACIO_H

#include <iostream>
#include <string>

using namespace std;

class Autentikacio
{
    Autentikacio()=default;
    Autentikacio(const Autentikacio& other)=default;
public:
    static Autentikacio& getObjektum();
    void bejelentkezes();
    void regisztracio();
};

#endif // AUTENTIKACIO_H

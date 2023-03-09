#include "tarolo.h"

Tarolo &Tarolo::getObjektum()
{
    static Tarolo tarolo;
    return tarolo;
}

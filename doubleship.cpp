#include "doubleship.h"

const int DoubleShip::getSize()
{
    return 2;
}

void DoubleShip::sink()
{
    if (firstFloated) {
        firstFloated = false;
    } else {
        floated = false;
    }
}

DoubleShip::~DoubleShip() {
}

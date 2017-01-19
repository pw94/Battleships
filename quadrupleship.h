#ifndef QUADRUPLESHIP_H
#define QUADRUPLESHIP_H

#include "ship.h"

class QuadrupleShip : public Ship
{
    bool floatedParts[3];
public:
    QuadrupleShip();
    virtual const int getSize();
    void sink();
    virtual ~QuadrupleShip();
};

#endif // QUADRUPLESHIP_H

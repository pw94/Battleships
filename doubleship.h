#ifndef DOUBLESHIP_H
#define DOUBLESHIP_H

#include "ship.h"

class DoubleShip : public Ship
{
protected:
    bool firstFloated = true;
public:
    virtual const int getSize();
    void sink();
    virtual ~DoubleShip();
};

#endif // DOUBLESHIP_H

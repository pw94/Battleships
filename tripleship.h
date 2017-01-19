#ifndef TRIPLESHIP_H
#define TRIPLESHIP_H

#include "ship.h"

class TripleShip : public Ship
{
    bool floatedParts[2];
public:
    TripleShip();
    virtual const int getSize();
    void sink();
    virtual ~TripleShip();
};

#endif // TRIPLESHIP_H

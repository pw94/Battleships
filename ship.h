#ifndef SHIP_H
#define SHIP_H

#include "sinkable.h"

class Ship : public Sinkable
{
public:
    Ship();
    bool isFloated();
    virtual void sink();
    virtual const int getSize();
    virtual ~Ship();
protected:
    bool floated;
};

#endif // SHIP_H

#include "quadrupleship.h"

QuadrupleShip::QuadrupleShip()
{
    for (int i = 0; i < 3; ++i)
        floatedParts[i] = true;
}

const int QuadrupleShip::getSize()
{
    return 4;
}

void QuadrupleShip::sink()
{
    if(floatedParts[0])
        floatedParts[0] = false;
    else if(floatedParts[1])
        floatedParts[1] = false;
    else if(floatedParts[2])
        floatedParts[2] = false;
    else
        floated = false;
}

QuadrupleShip::~QuadrupleShip()
{
}

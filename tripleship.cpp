#include "tripleship.h"

TripleShip::TripleShip()
{
    for (int i = 0; i < 2; ++i)
        floatedParts[i] = true;
}

const int TripleShip::getSize()
{
    return 3;
}

void TripleShip::sink()
{
    if(floatedParts[0])
        floatedParts[0] = false;
    else if(floatedParts[1])
        floatedParts[1] = false;
    else
        floated = false;
}

TripleShip::~TripleShip()
{
}

#include "ship.h"

Ship::Ship()
{
    floated = true;
}

bool Ship::isFloated()
{
    return floated;
}

const int Ship::getSize()
{
    return 1;
}

void Ship::sink()
{
    floated = false;
}

Ship::~Ship()
{

}

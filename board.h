#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "sinkable.h"
#include "ship.h"

template <class T, unsigned int N = 10U>
class Board
{
    std::vector<Sinkable *> ships;
    Sinkable* table[N][N];
    void fillOutWithShips();
    void putOnBoard();
    int getRandom(unsigned int n = N);
    bool doesNotFit(int size, int row, int col);
    void clearTable();
    void fillOutBoard();
    void removeShips();
public:
    Board();
    bool hit(int row, int col);
    bool areFloated();
    void reset();
};

#endif // BOARD_H

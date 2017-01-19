#include "board.h"
#include "doubleship.h"
#include "tripleship.h"
#include "quadrupleship.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

template<class T, unsigned int N>
Board<T, N>::Board()
{
    this->clearTable();
    this->fillOutBoard();
}

template<class T, unsigned int N>
void Board<T, N>::fillOutBoard() {
    srand((unsigned int)time(NULL));
    this->fillOutWithShips();
    std::random_shuffle (ships.begin(), ships.end());
    this->putOnBoard();
}

template<class T, unsigned int N>
void Board<T, N>::clearTable() {
    for (int r = 0; r < N; ++r)
        for (int cc = 0; cc < N; ++cc)
            table[r][cc] = NULL;
}

template<class T, unsigned int N>
int Board<T, N>::getRandom(unsigned int n)
{
    return rand()%n;
}

template<class T, unsigned int N>
void Board<T, N>::putOnBoard()
{
    for(auto const& ship: ships) {
        int row = getRandom();
        int col = getRandom();
        while(table[row][col] != NULL) {
            row = getRandom();
            col = getRandom();
        }
        table[row][col] = ship;
    }
}

template<>
void Board<Ship, 10U>::putOnBoard()
{
    for(auto const& ship: ships) {
        auto size = ((Ship *) ship)->getSize();
        int row = getRandom();
        int col = getRandom(10+1-size);
        while(this->doesNotFit(size,row,col)) {
            row = getRandom();
            col = getRandom();
        }

        for (int i = 0; i < size; ++i)
            table[row][col++] = ship;
    }
}

template<class T, unsigned int N>
bool Board<T,N>::doesNotFit(int size, int row, int col)
{
    bool wrong = false;
    for (int c = 0; c < size; ++c) {
        if(table[row][col++]!=NULL) {
            wrong = true;
            break;
        }
    }
    return wrong;
}

template<class T, unsigned int N>
void Board<T, N>::fillOutWithShips()
{
    ships.push_back(new T());
    ships.push_back(new T());
    ships.push_back(new T());
}

template<>
void Board<Ship, 10U>::fillOutWithShips()
{
    ships.push_back(new QuadrupleShip());
    ships.push_back(new TripleShip());
    ships.push_back(new TripleShip());
    ships.push_back(new DoubleShip());
    ships.push_back(new DoubleShip());
    ships.push_back(new DoubleShip());
    ships.push_back(new Ship());
    ships.push_back(new Ship());
    ships.push_back(new Ship());
    ships.push_back(new Ship());
}

template<class T, unsigned int N>
bool Board<T, N>::hit(int row, int col)
{
    Sinkable *sinkable = table[row][col];
    if (sinkable != NULL) {
        sinkable->sink();
        return true;
    } else {
        return false;
    }
}

template<class T, unsigned int N>
bool Board<T, N>::areFloated()
{
    bool are = false;
    for(auto const& ship: ships) {
        if (ship->isFloated()) {
            are = true;
            break;
        }
    }
    return are;
}

template<class T, unsigned int N>
void Board<T, N>::removeShips()
{
    ships.clear();
}

template<class T, unsigned int N>
void Board<T, N>::reset()
{
    this->clearTable();
    this->removeShips();
    this->fillOutBoard();
}

template class Board<Ship>;

#include "boardfield.h"

BoardField::BoardField(int row, int column, const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    pos.row = row;
    pos.column = column;
}

int BoardField::getRow()
{
    return pos.row;
}

int BoardField::getColumn()
{
    return pos.column;
}

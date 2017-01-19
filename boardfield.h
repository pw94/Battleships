#ifndef BOARDFIELD_H
#define BOARDFIELD_H

#include "position.h"
#include <QString>
#include <QWidget>
#include <QPushButton>


class BoardField : public QPushButton
{
    Q_OBJECT

    Position pos;
public:
    BoardField(int row, int column, const QString &text, QWidget *parent = Q_NULLPTR);
    int getRow();
    int getColumn();
};

#endif // BOARDFIELD_H

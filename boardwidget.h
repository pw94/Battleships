#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include "boardfield.h"
#include "ship.h"
#include "board.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    BoardWidget(QWidget *parent = 0);
    ~BoardWidget();

private:
    QGridLayout* layout;
    QPushButton* startButton;
    QLabel* statusLabel;

    const static uint SIZE = 10U;

    BoardField* cells[SIZE][SIZE];
    Board<Ship> board;

    void setField(bool hit, BoardField *field);

    uint points = 0;
    uint pointsToGain = 0;

private slots:
    void handleField();
    void handleReset();
};

#endif // BOARDWIDGET_H

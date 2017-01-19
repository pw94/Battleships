#include "boardwidget.h"
#include <QMessageBox>

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    startButton = new QPushButton("RESET", this);
    connect(startButton, SIGNAL(released()), this, SLOT(handleReset()));
    layout->addWidget(startButton,0,1,1,SIZE-2);

    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            cells[row][column] = new BoardField(row, column,"?", this);
            connect(cells[row][column], SIGNAL(released()), this, SLOT(handleField()));
            layout->addWidget(cells[row][column],row+1,column,1,1);
        }
    }
    statusLabel = new QLabel("Points: 0", this);
    layout->addWidget(statusLabel,SIZE+1,0,1,SIZE);
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
}

BoardWidget::~BoardWidget()
{

}

void BoardWidget::setField(bool hit, BoardField *field)
{
    QString text(hit ? "+" : "-");
    field->setText(text);
    field->setEnabled(false);
    QPalette palette;
    palette.setColor(QPalette::ButtonText, hit ? Qt::blue : Qt::red);
    field->setPalette(palette);
}

void BoardWidget::handleField()
{
    BoardField *field = (BoardField *) sender();
    bool hit = board.hit(field->getRow(), field->getColumn());
    setField(hit, field);

    if(hit) {
        points += ++pointsToGain;
        QString formattedMsg = QString("Points: %1").arg(QString::number(points));
        statusLabel->setText(formattedMsg);
    }
    else
        pointsToGain = 0;

    if(!board.areFloated()) {
        QMessageBox msgBox(this);
        QString formattedMsg = QString("Congratulations!!! You gained %1 points!").arg(QString::number(points));
        QString str(formattedMsg);
        msgBox.setText(str);
        msgBox.exec();
        this->handleReset();
    }
}

void BoardWidget::handleReset()
{
    QPalette palette;
    palette.setColor(QPalette::ButtonText, Qt::black);
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            cells[row][column]->setText("?");
            cells[row][column]->setEnabled(true);
            cells[row][column]->setPalette(palette);
        }
    }
    board.reset();
    points = 0;
    pointsToGain = 0;
    statusLabel->setText("Points: 0");
}

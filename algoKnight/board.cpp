#include "board.h"
#include"wholeboard.h" //

int board::count = 1;

board::board()
{
    pieceColor = true;
    setFlag(QGraphicsItem::ItemIsSelectable);

}

QRectF board::boundingRect() const
{
    return QRectF(eleSize * positionX, eleSize * positionY, eleSize, eleSize);
}

void board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::white);

    //drawing the rectangle black/white alternatively
    if(pieceColor)
        brush.setColor(Qt::white);
    else
        brush.setColor(Qt::gray);

    //yellow if selected
    if(selected)
        brush.setColor(Qt::yellow);

    //if square is available show green
    if(available)
        brush.setColor(Qt::green);

    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}


void board::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //only one of the box can be selected
    //deselect the selected box and only then you can select another box

    //wholeBoard::availSpots();

    if(!selected)
    {
        if(count>1)
            return;
        else
        {
            count++;
            selected = true;
            wholeBoard::availSpots();
        }

    }
    else
    {

        selected = false;
        count--;
        wholeBoard::availSpots();
    }


    update();
    QGraphicsItem::mousePressEvent(event);
}




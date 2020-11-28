#include "board.h"
#include"wholeboard.h" //
#include<QDebug>
#include<QCursor>
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
    QImage *knight1 = new QImage(":/img/image/knight.png");


    //drawing the rectangle black/white alternatively
    if(pieceColor)
        brush.setColor(Qt::white);
    else
        brush.setColor(Qt::gray);

    //if square is available show green
    if(available)
        brush.setColor(Qt::green);
    //yellow if selected

    if(visited)
        brush.setColor(Qt::blue);

    painter->fillRect(rec,brush);
    painter->drawRect(rec);

    if(selected){
        brush.setColor(Qt::yellow);
        painter->drawImage(rec,*knight1);
        painter->drawRect(rec);


}
}


void board::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //only one of the box can be selected
    //deselect the selected box and only then you can select another box

    //wholeBoard::availSpots();

    //if knight is to move to an available spot...//logic here

    if(!selected && !visited)
    {

        if(available)
        {
            count--;

        }

        if(count>1)
            return;

        count++;
        wholeBoard::renewAvail();
        visited = true;
        selected = true;
        wholeBoard::score++;
        wholeBoard::availSpots();//make spots available

    }

    else if(selected && wholeBoard::score <= 1) //cannot unselect once selected
    {
        visited = false;
        selected = false;
        count--;
        wholeBoard::score--;
        wholeBoard::unavailSpots();   //make spots unavailable
    }




    update();
    QGraphicsItem::mousePressEvent(event);
}



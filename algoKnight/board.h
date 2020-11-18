#ifndef BOARD_H
#define BOARD_H

#define DIMENSION 8
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QPainter>
#include<QPointF>

class board : public QGraphicsItem
{
public:
    board();
    const int eleSize = 50;
    bool pieceColor;
    int positionX, positionY;
    bool selected = false;
    static int count;
    bool available = false;
    bool visited = false;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // BOARD_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =  new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    Board.setupBoard(scene);
}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_placeKnight_clicked()
{
    //place knight function
    //get positionX and positionY for the image to be place
//    int posX, posY;
//    Board.placeKnight(&posX,&posY);
    //std::cout<<posX;
//    QGraphicsPixmapItem *knight = new QGraphicsPixmapItem(QPixmap("knight.png"));
//    scene->addItem(knight);
//    knight->setPos(0,0);
//    knight->setScale(2.0);
//    knight->setZValue(0.1);

}



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
//    ui->scoreLabel->setText("Score: " + QString::number(Board.score));


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_placeKnight_clicked()
{
    //place knight function
    //get positionX and positionY for the image to be place
   int posX, posY;
//    Board.placeKnight(&posX,&posY);
    //std::cout<<posX;
    QGraphicsPixmapItem *knight = new QGraphicsPixmapItem(QPixmap(":/img/image/knight.png"));
    scene->addItem(knight);
   knight->setPos(0,-10);
   knight->setZValue(0.1);

}



void MainWindow::on_resetAll_clicked()
{
    Board.resetBoard();
}


void MainWindow::on_autoSolve_clicked()
{
    path.showSolution();
}

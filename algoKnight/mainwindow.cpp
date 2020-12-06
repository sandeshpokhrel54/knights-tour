#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include"wholeboard.h"
#include<QDebug>
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



void MainWindow::on_resetAll_clicked()
{
    Board.resetBoard();
    path.resetPath();
}


void MainWindow::on_autoSolve_clicked()
{
    path.findKnightPath();
}

void MainWindow::on_recap_clicked()
{
    //call function to traverse tree from wholeboard.cpp
    Board.traverseTree();
}

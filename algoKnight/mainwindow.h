#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DIMENSION 8
#include <QMainWindow>
#include<QGraphicsScene>
#include<iostream>
#include "wholeboard.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_placeKnight_clicked();



    void on_resetAll_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    wholeBoard Board;

};
#endif // MAINWINDOW_H

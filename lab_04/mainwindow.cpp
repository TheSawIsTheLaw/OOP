#include "mainwindow.h"

#include <QDebug>

#include "defines.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    qDebug(
        "Lift is on %d floor, doors are closed.\nWe are waiting for your "
        "commands!",
        START_FLOOR);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CabinButtonFloor1_clicked()
{
    qDebug("Was clicked Button 1 on lift controller.");
    lift.call(1);
}

void MainWindow::on_CabinButtonFloor2_clicked()
{
    qDebug("Was clicked Button 2 on lift controller.");
    lift.call(2);
}

void MainWindow::on_CabinButtonFloor3_clicked()
{
    qDebug("Was clicked Button 3 on lift controller.");
    lift.call(3);
}

void MainWindow::on_CabinButtonFloor4_clicked()
{
    qDebug("Was clicked Button 4 on lift controller.");
    lift.call(4);
}

void MainWindow::on_CabinButtonFloor5_clicked()
{
    qDebug("Was clicked Button 5 on lift controller.");
    lift.call(5);
}

void MainWindow::on_CabinButtonFloor6_clicked()
{
    qDebug("Was clicked Button 6 on lift controller.");
    lift.call(6);
}

void MainWindow::on_CabinButtonFloor7_clicked()
{
    qDebug("Was clicked Button 7 on lift controller.");
    lift.call(7);
}

void MainWindow::on_CabinButtonFloor8_clicked()
{
    qDebug("Was clicked Button 8 on lift controller.");
    lift.call(8);
}

void MainWindow::on_CabinButtonFloor9_clicked()
{
    qDebug("Was clicked Button 9 on lift controller.");
    lift.call(9);
}

void MainWindow::on_CabinButtonFloor10_clicked()
{
    qDebug("Was clicked Button 10 on lift controller.");
    lift.call(10);
}

void MainWindow::on_CabinButtonFloor11_clicked()
{
    qDebug("Was clicked Button 11 on lift controller.");
    lift.call(11);
}

void MainWindow::on_CabinButtonFloor12_clicked()
{
    qDebug("Was clicked Button 12 on lift controller.");
    lift.call(12);
}

void MainWindow::on_CabinButtonFloor13_clicked()
{
    qDebug("Was clicked Button 13 on lift controller.");
    lift.call(13);
}

void MainWindow::on_CabinButtonFloor14_clicked()
{
    qDebug("Was clicked Button 14 on lift controller.");
    lift.call(14);
}

void MainWindow::on_CabinButtonFloor15_clicked()
{
    qDebug("Was clicked Button 15 on lift controller.");
    lift.call(15);
}

void MainWindow::on_CabinButtonFloor16_clicked()
{
    qDebug("Was clicked Button 16 on lift controller.");
    lift.call(16);
}

void MainWindow::on_FloorButton1_clicked()
{
    qDebug() << "Lift was called on 1 floor.";
    lift.call(1);
}

void MainWindow::on_FloorButton2_clicked()
{
    qDebug() << "Lift was called on 2 floor.";
    lift.call(2);
}

void MainWindow::on_FloorButton3_clicked()
{
    qDebug() << "Lift was called on 3 floor.";
    lift.call(3);
}

void MainWindow::on_FloorButton4_clicked()
{
    qDebug() << "Lift was called on 4 floor.";
    lift.call(4);
}

void MainWindow::on_FloorButton5_clicked()
{
    qDebug() << "Lift was called on 5 floor.";
    lift.call(5);
}

void MainWindow::on_FloorButton6_clicked()
{
    qDebug() << "Lift was called on 6 floor.";
    lift.call(6);
}

void MainWindow::on_FloorButton7_clicked()
{
    qDebug() << "Lift was called on 7 floor.";
    lift.call(7);
}

void MainWindow::on_FloorButton8_clicked()
{
    qDebug() << "Lift was called on 8 floor.";
    lift.call(8);
}

void MainWindow::on_FloorButton9_clicked()
{
    qDebug() << "Lift was called on 9 floor.";
    lift.call(9);
}

void MainWindow::on_FloorButton10_clicked()
{
    qDebug() << "Lift was called on 10 floor.";
    lift.call(10);
}

void MainWindow::on_FloorButton11_clicked()
{
    qDebug() << "Lift was called on 11 floor.";
    lift.call(11);
}

void MainWindow::on_FloorButton12_clicked()
{
    qDebug() << "Lift was called on 12 floor.";
    lift.call(12);
}

void MainWindow::on_FloorButton13_clicked()
{
    qDebug() << "Lift was called on 13 floor.";
    lift.call(13);
}

void MainWindow::on_FloorButton14_clicked()
{
    qDebug() << "Lift was called on 14 floor.";
    lift.call(14);
}

void MainWindow::on_FloorButton15_clicked()
{
    qDebug() << "Lift was called on 15 floor.";
    lift.call(15);
}

void MainWindow::on_FloorButton16_clicked()
{
    qDebug() << "Lift was called on 16 floor.";
    lift.call(16);
}

#include "mainwindow.h"

#include <QDebug>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    qDebug() << "Лифт находится на этаже 1, двери закрыты.\n"
                "Лифт находится в режиме ожидания.";
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_CabinButtonFloor1_clicked() {
    qDebug() << "В лифте нажали кнопку 1.";
    lift.click(1);
}

void MainWindow::on_CabinButtonFloor2_clicked() {
    qDebug() << "В лифте нажали кнопку 2.";
    lift.click(2);
}

void MainWindow::on_CabinButtonFloor3_clicked() {
    qDebug() << "В лифте нажали кнопку 3.";
    lift.click(3);
}

void MainWindow::on_CabinButtonFloor4_clicked() {
    qDebug() << "В лифте нажали кнопку 4.";
    lift.click(4);
}

void MainWindow::on_CabinButtonFloor5_clicked() {
    qDebug() << "В лифте нажали кнопку 5.";
    lift.click(5);
}

void MainWindow::on_CabinButtonFloor6_clicked() {
    qDebug() << "В лифте нажали кнопку 6.";
    lift.click(6);
}

void MainWindow::on_CabinButtonFloor7_clicked() {
    qDebug() << "В лифте нажали кнопку 7.";
    lift.click(7);
}

void MainWindow::on_CabinButtonFloor8_clicked() {
    qDebug() << "В лифте нажали кнопку 8.";
    lift.click(8);
}

void MainWindow::on_CabinButtonFloor9_clicked() {
    qDebug() << "В лифте нажали кнопку 9.";
    lift.click(9);
}

void MainWindow::on_CabinButtonFloor10_clicked() {
    qDebug() << "В лифте нажали кнопку 11.";
    lift.click(11);
}

void MainWindow::on_CabinButtonFloor11_clicked() {
    qDebug() << "В лифте нажали кнопку 12.";
    lift.click(12);
}

void MainWindow::on_CabinButtonFloor12_clicked() {
    qDebug() << "В лифте нажали кнопку 13.";
    lift.click(13);
}

void MainWindow::on_CabinButtonFloor13_clicked() {
    qDebug() << "В лифте нажали кнопку 14.";
    lift.click(14);
}

void MainWindow::on_CabinButtonFloor14_clicked() {
    qDebug() << "В лифте нажали кнопку 14.";
    lift.click(14);
}

void MainWindow::on_CabinButtonFloor15_clicked() {
    qDebug() << "В лифте нажали кнопку 15.";
    lift.click(15);
}

void MainWindow::on_CabinButtonFloor16_clicked() {
    qDebug() << "В лифте нажали кнопку 16.";
    lift.click(16);
}

void MainWindow::on_FloorButton1_clicked() {
    qDebug() << "Вызов лифта на 1 этаже.";
    lift.click(1);
}

void MainWindow::on_FloorButton2_clicked() {
    qDebug() << "Вызов лифта на 2 этаже.";
    lift.click(2);
}

void MainWindow::on_FloorButton3_clicked() {
    qDebug() << "Вызов лифта на 3 этаже.";
    lift.click(3);
}

void MainWindow::on_FloorButton4_clicked() {
    qDebug() << "Вызов лифта на 4 этаже.";
    lift.click(4);
}

void MainWindow::on_FloorButton5_clicked() {
    qDebug() << "Вызов лифта на 5 этаже.";
    lift.click(5);
}

void MainWindow::on_FloorButton6_clicked() {
    qDebug() << "Вызов лифта на 6 этаже.";
    lift.click(6);
}

void MainWindow::on_FloorButton7_clicked() {
    qDebug() << "Вызов лифта на 7 этаже.";
    lift.click(7);
}

void MainWindow::on_FloorButton8_clicked() {
    qDebug() << "Вызов лифта на 8 этаже.";
    lift.click(8);
}

void MainWindow::on_FloorButton9_clicked() {
    qDebug() << "Вызов лифта на 9 этаже.";
    lift.click(9);
}

void MainWindow::on_FloorButton10_clicked() {
    qDebug() << "Вызов лифта на 10 этаже.";
    lift.click(10);
}

void MainWindow::on_FloorButton11_clicked() {
    qDebug() << "Вызов лифта на 11 этаже.";
    lift.click(11);
}

void MainWindow::on_FloorButton12_clicked() {
    qDebug() << "Вызов лифта на 12 этаже.";
    lift.click(12);
}

void MainWindow::on_FloorButton13_clicked() {
    qDebug() << "Вызов лифта на 13 этаже.";
    lift.click(13);
}

void MainWindow::on_FloorButton14_clicked() {
    qDebug() << "Вызов лифта на 14 этаже.";
    lift.click(14);
}

void MainWindow::on_FloorButton15_clicked() {
    qDebug() << "Вызов лифта на 15 этаже.";
    lift.click(15);
}

void MainWindow::on_FloorButton16_clicked() {
    qDebug() << "Вызов лифта на 16 этаже.";
    lift.click(16);
}

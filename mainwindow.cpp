#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_chooseModelButton_clicked()
{

}

void MainWindow::on_goLeftButton_clicked()
{

}

void MainWindow::on_goDownButton_clicked()
{

}

void MainWindow::on_goUpButton_clicked()
{

}

void MainWindow::on_goRightButton_clicked()
{

}

void MainWindow::on_rotateZRightButton_clicked()
{

}

void MainWindow::on_toratateZLeftButton_clicked()
{

}

void MainWindow::on_rotateYdownButton_clicked()
{

}

void MainWindow::on_rotateYupButton_clicked()
{

}

void MainWindow::on_rotateXRightButton_clicked()
{

}

void MainWindow::on_rotateXLeftButton_clicked()
{

}

void MainWindow::on_plusMasstButton_clicked()
{

}

void MainWindow::on_minusMasstButton_clicked()
{

}

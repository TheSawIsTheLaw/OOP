#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userDomain.h"
#include "modelDomain.h"
#include <string.h>

#include "defines.h"

static model_t model;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_chooseModelButton_clicked(){
    QString qFileName = QFileDialog::getOpenFileName(this, tr("Open Model"), "../startModels", tr("Model Files (*.txt)"));
    qDebug("%s", qUtf8Printable(qFileName));
    setModel(qFileName);
}

void MainWindow::on_goLeftButton_clicked(){
    taskManager(GO_LEFT);
}

void MainWindow::on_goDownButton_clicked(){
    taskManager(GO_DOWN);
}

void MainWindow::on_goUpButton_clicked(){
    taskManager(GO_UP);
}

void MainWindow::on_goRightButton_clicked(){
    taskManager(GO_RIGHT);
}

void MainWindow::on_rotateZRightButton_clicked(){
    taskManager(ROTATE_Z_R);
}

void MainWindow::on_toratateZLeftButton_clicked(){
    taskManager(ROTATE_Z_L);
}

void MainWindow::on_rotateYdownButton_clicked(){
    taskManager(ROTATE_Y_D);
}

void MainWindow::on_rotateYupButton_clicked(){
    taskManager(ROTATE_Y_U);
}

void MainWindow::on_rotateXRightButton_clicked(){
    taskManager(ROTATE_X_R);
}

void MainWindow::on_rotateXLeftButton_clicked(){
    taskManager(ROTATE_X_L);
}

void MainWindow::on_plusMasstButton_clicked(){
    taskManager(SCALE_PLUS);
}

void MainWindow::on_minusMasstButton_clicked(){
    taskManager(SCALE_MINUS);
}

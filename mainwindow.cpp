#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userDomain.h"
#include "modelDomain.h"

#include "defines.h"

static modelT model;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showAll(modelT &model){
    isModelInited(model);

    QPen whitePen(Qt::white);
    nodeT firstNode, secondNode;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 980, 400);

    if (line.length() != 0) {
        line.clear();
    }

    for (int i = 0; i < model.numOfEdges; i++) {
        firstNode = model.nodes[model.edges[i].firstNode];
        secondNode = model.nodes[model.edges[i].secondNode];
        line.append(scene->addLine(firstNode.xCoord,
                                   firstNode.yCoord,
                                   secondNode.xCoord ,
                                   secondNode.yCoord,
                                   whitePen));
    }

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_showModel_clicked()
{
    showAll(model);
}

void MainWindow::on_chooseModelButton_clicked(){
    QString qFileName = QFileDialog::getOpenFileName(this, tr("Open Model"), "../startModels", tr("Model Files (*.txt)"));
    qDebug("%s", qUtf8Printable(qFileName));
    int check = setModel(qFileName, model);
    qDebug("%d", check);
    if (check == FILE_ERROR)
        QMessageBox::critical(this, "Ошибка!", "Произошла ошибка при открытии файла.");
    else if (check == MEMORY_ALLOCATION_ERROR)
        QMessageBox::critical(this, "Ошибка!", "Произошла ошибка при вылении памяти под данные.");
    else if (check == FILE_STRUCTURE_ERROR)
        QMessageBox::critical(this, "Ошибка!", "Переданный файл обладает нарушенной структурой и не может быть обработан.");
    else if (check == MODEL_IS_NOT_INITED_ERROR)
        QMessageBox::critical(this, "Ошибка!", "Переданная модель не инициализированна. Код программы был изменён. Не в лучшую сторону.");
    else if (check == MODEL_IS_NOT_READY_ERROR)
        QMessageBox::critical(this, "Ошибка!", "Ошибка формата файла.");
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


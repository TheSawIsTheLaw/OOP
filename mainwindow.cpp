#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "userDomain.h"

#include "modelDomain.h"

#include "defines.h"

static modelT model;

MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showAll(modelT &model) {
    int check;
    check = isModelInited(model);
    if (check)
        return;

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

        line.append(scene->addLine(firstNode.xCoord, firstNode.yCoord,
            secondNode.xCoord, secondNode.yCoord, whitePen));
    }

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_chooseModelButton_clicked() {
    QString qFileName = QFileDialog::getOpenFileName(
        this, tr("Open Model"), "../startModels", tr("Model Files (*.txt)"));
    qDebug("%s", qUtf8Printable(qFileName));
    int check = setModel(qFileName, model);
    qDebug("%d", check);
    if (check == FILE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Файл не был выбран, либо файл недоступен.");
    else if (check == MEMORY_ALLOCATION_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Произошла ошибка при выделении памяти под данные.");
    else if (check == FILE_STRUCTURE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Переданный файл обладает нарушенной структурой и неМожет "
            "быть обработан.");
    else if (check == MODEL_IS_NOT_INITED_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована. Код программы "
            "был изменён. Не в лучшую сторону.");
    else if (check == MODEL_IS_NOT_READY_ERROR)
        QMessageBox::critical(this, "Ошибка!", "Ошибка формата файла.");
    else
        showAll(model);
}

void MainWindow::on_goLeftButton_clicked() {
    int check;

    check = taskManager(GO_LEFT, model);
    qDebug("left");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_goDownButton_clicked() {
    int check;

    check = taskManager(GO_DOWN, model);
    qDebug("down");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_goUpButton_clicked() {
    int check;

    check = taskManager(GO_UP, model);
    qDebug("up");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_goRightButton_clicked() {
    int check;

    check = taskManager(GO_RIGHT, model);
    qDebug("down");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateZRightButton_clicked() {
    int check;

    check = taskManager(ROTATE_Z_R, model);
    qDebug("zR");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_toratateZLeftButton_clicked() {
    int check;

    check = taskManager(ROTATE_Z_L, model);
    qDebug("zL");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateYdownButton_clicked() {

    int check;

    check = taskManager(ROTATE_Y_R, model);
    qDebug("yR");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateYupButton_clicked() {
    int check;

    check = taskManager(ROTATE_Y_L, model);
    qDebug("yL");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateXRightButton_clicked() {

    int check;

    check = taskManager(ROTATE_X_R, model);
    qDebug("xR");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateXLeftButton_clicked() {
    int check;

    check = taskManager(ROTATE_X_L, model);
    qDebug("xL");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_plusMasstButton_clicked() {
    int check;

    check = taskManager(SCALE_PLUS, model);
    qDebug("sP");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_minusMasstButton_clicked() {
    int check;

    check = taskManager(SCALE_MINUS, model);
    qDebug("sM");

    if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

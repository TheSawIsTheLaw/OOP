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

    QPen whitePen(Qt::black);
    nodeT firstNode, secondNode;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(X_RECT_START, Y_RECT_START, X_RECT_END, Y_RECT_END);

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
    QDEB(qUtf8Printable(qFileName));
    int check = setModel(qFileName, model);
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
    QDEB("left");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_goDownButton_clicked() {
    int check;

    check = taskManager(GO_DOWN, model);
    QDEB("down");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_goUpButton_clicked() {
    int check;

    check = taskManager(GO_UP, model);
    QDEB("up");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_goRightButton_clicked() {
    int check;

    check = taskManager(GO_RIGHT, model);
    QDEB("right");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateZRightButton_clicked() {
    int check;

    check = taskManager(ROTATE_Z_R, model);
    QDEB("zR");
    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_toratateZLeftButton_clicked() {
    int check;

    check = taskManager(ROTATE_Z_L, model);
    QDEB("zL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateYdownButton_clicked() {

    int check;

    check = taskManager(ROTATE_Y_R, model);
    QDEB("yR");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateYupButton_clicked() {
    int check;

    check = taskManager(ROTATE_Y_L, model);
    QDEB("yL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateXRightButton_clicked() {

    int check;

    check = taskManager(ROTATE_X_R, model);
    QDEB("xR");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_rotateXLeftButton_clicked() {
    int check;

    check = taskManager(ROTATE_X_L, model);
    QDEB("xL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_plusMasstButton_clicked() {
    int check;

    check = taskManager(SCALE_PLUS, model);
    QDEB("sP");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

void MainWindow::on_minusMasstButton_clicked() {
    int check;

    check = taskManager(SCALE_MINUS, model);
    QDEB("sM");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");

    showAll(model);
}

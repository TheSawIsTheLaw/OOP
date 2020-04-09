#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "userDomain.h"

#include "modelDomain.h"

#include "defines.h"


MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void showAll(modelT &model, Ui::MainWindow *ui) {
    int check;
    check = isModelInited(model);
    if (check)
        return;

    QPen whitePen(Qt::black);
    nodeT firstNode, secondNode;

    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(X_RECT_START, Y_RECT_START, X_RECT_END, Y_RECT_END);

    QVector<QGraphicsLineItem *> line;
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
        this, tr("Open Model"), "../OOP/startModels", tr("Model Files (*.txt)"));
    QDEB(qUtf8Printable(qFileName));
    int check = taskManager(SET_MODEL, ui, qFileName);
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
}

void MainWindow::on_goLeftButton_clicked() {
    int check;

    check = taskManager(GO_LEFT, ui);
    QDEB("left");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_goDownButton_clicked() {
    int check;

    check = taskManager(GO_DOWN, ui);
    QDEB("down");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_goUpButton_clicked() {
    int check;

    check = taskManager(GO_UP, ui);
    QDEB("up");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_goRightButton_clicked() {
    int check;

    check = taskManager(GO_RIGHT, ui);
    QDEB("right");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_rotateZRightButton_clicked() {
    int check;

    check = taskManager(ROTATE_Z_R, ui);
    QDEB("zR");
    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_toratateZLeftButton_clicked() {
    int check;

    check = taskManager(ROTATE_Z_L, ui);
    QDEB("zL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_rotateYdownButton_clicked() {

    int check;

    check = taskManager(ROTATE_Y_R, ui);
    QDEB("yR");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_rotateYupButton_clicked() {
    int check;

    check = taskManager(ROTATE_Y_L, ui);
    QDEB("yL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_rotateXRightButton_clicked() {

    int check;

    check = taskManager(ROTATE_X_R, ui);
    QDEB("xR");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_rotateXLeftButton_clicked() {
    int check;

    check = taskManager(ROTATE_X_L, ui);
    QDEB("xL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_plusMasstButton_clicked() {
    int check;

    check = taskManager(SCALE_PLUS, ui);
    QDEB("sP");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

void MainWindow::on_minusMasstButton_clicked() {
    int check;

    check = taskManager(SCALE_MINUS, ui);
    QDEB("sM");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
}

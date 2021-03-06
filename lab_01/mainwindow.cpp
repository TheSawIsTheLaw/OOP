#include "mainwindow.h"

#include "ui_mainwindow.h"

#include "defines.h"

#include "nodeLevel.h"

#include "userDomain.h"

#include "drawLevel.h"


MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void viewScene(Ui::MainWindow *const ui, QGraphicsScene *const scene) {
    ui->graphicsView->setScene(scene);
}

void drawModel(const modelT model, const drawRequestT drawRequest) {
    // FIXED: Отдельная функция рисования

    for (int i = 0; i < model.numOfEdges; i++)
        appendEdgeToScene(drawRequest.scene, drawRequest.line,
                          drawRequest.blackPen, model.nodes,
                          model.edges[i]);

    viewScene(drawRequest.ui, drawRequest.scene);

}

QString getFileWay(QWidget *const parent, const QString startLocation,
                   const QString fileFormat) {
    return QFileDialog::getOpenFileName(
                parent, "Open Model", startLocation, fileFormat);
}

void MainWindow::on_chooseModelButton_clicked() {
    QString qFileName = getFileWay(this, "../OOP/startModels", "*.txt");

    requestT request;

    setLoadRequest(request, qUtf8Printable(qFileName));

    if (!request.fileName) {
        QMessageBox::critical(this, "Ошибка!",
            "Ошибка выделения памяти.");
        return ;
    }

    int check = taskManager(request);
    if (check == FILE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Файл не был выбран, либо файл недоступен.");
    else if (check == MEMORY_ALLOCATION_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Произошла ошибка при выделении памяти под данные.");
    else if (check == FILE_STRUCTURE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Переданный файл обладает нарушенной структурой и не "
            "может быть обработан.");
    else if (check == FILE_FORMAT_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "В переданном файле содержатся некорректные значения, вследствие чего он не "
            "может быть обработан.");
    else if (check == MODEL_IS_NOT_INITED_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована. Код программы "
            "был изменён. Не в лучшую сторону.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    freeFileNameRequest(request);
    resetRequest(request);
}

void MainWindow::on_goLeftButton_clicked() {
    requestT request;

    setMoveChoice(request, GO_X, -MOVE_UNIT);

    int check = taskManager(request);
    QDEB("left");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_goDownButton_clicked() {
    requestT request;

    setMoveChoice(request, GO_Y, MOVE_UNIT);

    int check = taskManager(request);
    QDEB("down");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_goUpButton_clicked() {
    requestT request;

    setMoveChoice(request, GO_Y, -MOVE_UNIT);

    int check = taskManager(request);
    QDEB("up");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_goRightButton_clicked() {
    requestT request;

    setMoveChoice(request, GO_X, MOVE_UNIT);

    int  check = taskManager(request);
    QDEB("right");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_rotateZRightButton_clicked() {
    requestT request;

    setRotateChoiceZ(request, X_CENTER_SCENE,
                     Y_CENTER_SCENE, ROTATION_UNIT);

    int check = taskManager(request);
    QDEB("zR");
    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_toratateZLeftButton_clicked() {
    requestT request;

    setRotateChoiceZ(request, X_CENTER_SCENE,
                     Y_CENTER_SCENE, -ROTATION_UNIT);

    int check = taskManager(request);
    QDEB("zL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_rotateYdownButton_clicked() {
    requestT request;

    setRotateChoiceY(request, X_CENTER_SCENE,
                     Z_CENTER_SCENE, -ROTATION_UNIT);

    int check = taskManager(request);
    QDEB("yR");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_rotateYupButton_clicked() {
    requestT request;

    setRotateChoiceY(request, X_CENTER_SCENE,
                     Z_CENTER_SCENE, ROTATION_UNIT);

    int check = taskManager(request);
    QDEB("yL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_rotateXRightButton_clicked() {
    requestT request;

    setRotateChoiceX(request, Y_CENTER_SCENE,
                     Z_CENTER_SCENE, -ROTATION_UNIT);

    int check = taskManager(request);
    QDEB("xR");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_rotateXLeftButton_clicked() {
    requestT request;

    setRotateChoiceX(request, Y_CENTER_SCENE,
                     Z_CENTER_SCENE, ROTATION_UNIT);

    int check = taskManager(request);
    QDEB("xL");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_plusMasstButton_clicked() {
    requestT request;

    setScaleChoice(request, SCALE_UNIT_PLUS, X_CENTER_SCENE,
                   Y_CENTER_SCENE, Z_CENTER_SCENE);

    int check = taskManager(request);
    QDEB("sP");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

void MainWindow::on_minusMasstButton_clicked() {
    requestT request;

    setScaleChoice(request, SCALE_UNIT_MINUS, X_CENTER_SCENE,
                   Y_CENTER_SCENE, Z_CENTER_SCENE);

    int check = taskManager(request);
    QDEB("sM");

    if (check == OUT_OF_CHOICE_ERROR)
        QMessageBox::critical(this, "Ошибка!",
            "Был передан неверный параметр выбора действия. Обратитесь в поддержку.");
    else if (check)
        QMessageBox::critical(this, "Ошибка!",
            "Модель не инициализирована.");
    if (!check) {
        resetRequest(request);
        setDrawRequest(request, X_RECT_START,
                       Y_RECT_START, X_RECT_END,
                       Y_RECT_END, ui);
        check = taskManager(request);
        if (check == MODEL_IS_NOT_INITED_ERROR)
                QMessageBox::critical(this, "Ошибка!",
                    "Модель не инициализирована. Код программы "
                    "был изменён. Не в лучшую сторону.");
    }
    resetRequest(request);
}

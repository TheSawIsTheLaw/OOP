#include "mainwindow.h"

#include "Commands/commands.hpp"
#include "QFileDialog"
#include "QMessageBox"
#include "defines.hpp"
#include "string.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    facade = Facade();
    scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString getFileWay(QWidget *const parent, const QString startLocation, const QString fileFormat)
{
    return QFileDialog::getOpenFileName(parent, "Upload Scene", startLocation, fileFormat);
}

void MainWindow::on_pushButton_clicked()
{
    qDebug("Upload");
    QString qFileName = getFileWay(this, "../lab_03",
                                   "");

    if (qFileName == "")
    {
        QMessageBox::critical(this, "Ошибка!", "Не был выбран файл.");
        return;
    }

    UploadCommand command(qUtf8Printable(qFileName));
    if (command.getFileName()[0] == '\0')
    {
        QMessageBox::critical(this,
                              "Ошибка!",
                              "Размер пути к файлу превышает заданное "
                              "максимальное количество символов.");
        return;
    }

    qDebug("FileName in command: %s\n", command.getFileName());

    facade.execute(command);

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    scene->clear();
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);

    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->radioButton_3->setEnabled(true);
    ui->radioButton->setChecked(true);
}

void MainWindow::on_goLeftButton_clicked()
{
    TransformMoveCommand command;
    command.setDX(-MOVE_MEASURE);
    command.setDY(0);
    command.setDZ(0);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_goRightButton_clicked()
{
    TransformMoveCommand command;
    command.setDX(MOVE_MEASURE);
    command.setDY(0);
    command.setDZ(0);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_goDownButton_clicked()
{
    TransformMoveCommand command;
    command.setDX(0);
    command.setDY(MOVE_MEASURE);
    command.setDZ(0);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_goUpButton_clicked()
{
    TransformMoveCommand command;
    command.setDX(0);
    command.setDY(-MOVE_MEASURE);
    command.setDZ(0);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateYupButton_clicked()
{
    TransformRotateCommand command;
    command.setAngle(ROTATE_ANGLE);
    command.setAxis(Y);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateYdownButton_clicked()
{
    TransformRotateCommand command;
    command.setAngle(-ROTATE_ANGLE);
    command.setAxis(Y);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateXLeftButton_clicked()
{
    TransformRotateCommand command;
    command.setAngle(-ROTATE_ANGLE);
    command.setAxis(X);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateXRightButton_clicked()
{
    TransformRotateCommand command;
    command.setAngle(ROTATE_ANGLE);
    command.setAxis(X);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_toratateZLeftButton_clicked()
{
    TransformRotateCommand command;
    command.setAngle(-ROTATE_ANGLE);
    command.setAxis(Z);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateZRightButton_clicked()
{
    TransformRotateCommand command;
    command.setAngle(ROTATE_ANGLE);
    command.setAxis(Z);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_plusMasstButton_clicked()
{
    TransformScaleCommand command;
    command.setCoef(SCALE_COEF_PLUS);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_minusMasstButton_clicked()
{
    TransformScaleCommand command;
    command.setCoef(SCALE_COEF_MINUS);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else
        return;

    std::shared_ptr<DrawingFactoryBase> factoryPtr;
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(0, 0, 980, 400);
    factoryPtr.reset(new QTDrawingFactory(scene));
    DrawCommand comm = DrawCommand(factoryPtr);
    facade.execute(comm);
    ui->graphicsView->setScene(scene);
}

void MainWindow::on_NextButton_clicked()
{
    ChangeCurComponentCommand command;
    command.setDirection(ChangeCurComponentCommand::NEXT);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else if (ui->radioButton_3->isChecked())
    {
        facade.execute(command, SCENE);
        std::shared_ptr<DrawingFactoryBase> factoryPtr;
        QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
        scene->setSceneRect(0, 0, 980, 400);
        factoryPtr.reset(new QTDrawingFactory(scene));
        DrawCommand comm = DrawCommand(factoryPtr);
        facade.execute(comm);
        ui->graphicsView->setScene(scene);
    }
}

void MainWindow::on_PreviousButton_clicked()
{
    ChangeCurComponentCommand command;
    command.setDirection(ChangeCurComponentCommand::PREV);

    if (ui->radioButton->isChecked())
        facade.execute(command, CAMERA);
    else if (ui->radioButton_2->isChecked())
        facade.execute(command, MODEL);
    else if (ui->radioButton_3->isChecked())
    {
        facade.execute(command, SCENE);
        std::shared_ptr<DrawingFactoryBase> factoryPtr;
        QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
        scene->setSceneRect(0, 0, 980, 400);
        factoryPtr.reset(new QTDrawingFactory(scene));
        DrawCommand comm = DrawCommand(factoryPtr);
        facade.execute(comm);
        ui->graphicsView->setScene(scene);
    }
}

void MainWindow::on_radioButton_3_clicked()
{
}

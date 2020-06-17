#include "mainwindow.h"

#include "Commands/commands.h"
#include "QFileDialog"
#include "QMessageBox"
#include "defines.h"
#include "string.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    facade = Facade();
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

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_goLeftButton_clicked()
{
    TransformModelMoveCommand command;
    command.setDX(-10);
    command.setDY(0);
    command.setDZ(0);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_goRightButton_clicked()
{
    TransformModelMoveCommand command;
    command.setDX(10);
    command.setDY(0);
    command.setDZ(0);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_goDownButton_clicked()
{
    TransformModelMoveCommand command;
    command.setDX(0);
    command.setDY(10);
    command.setDZ(0);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_goUpButton_clicked()
{
    TransformModelMoveCommand command;
    command.setDX(0);
    command.setDY(-10);
    command.setDZ(0);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateYupButton_clicked()
{
    TransformModelRotateCommand command;
    command.setAngle(0.174533);
    command.setAxis(Y);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateYdownButton_clicked()
{
    TransformModelRotateCommand command;
    command.setAngle(-0.174533);
    command.setAxis(Y);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateXLeftButton_clicked()
{
    TransformModelRotateCommand command;
    command.setAngle(-0.174533);
    command.setAxis(X);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateXRightButton_clicked()
{
    TransformModelRotateCommand command;
    command.setAngle(0.174533);
    command.setAxis(X);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_toratateZLeftButton_clicked()
{
    TransformModelRotateCommand command;
    command.setAngle(-0.174533);
    command.setAxis(Z);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_rotateZRightButton_clicked()
{
    TransformModelRotateCommand command;
    command.setAngle(0.174533);
    command.setAxis(Z);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_plusMasstButton_clicked()
{
    TransformModelScaleCommand command;
    command.setCoef(1.1);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_minusMasstButton_clicked()
{
    TransformModelScaleCommand command;
    command.setCoef(0.9);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

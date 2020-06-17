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
    TransformModelCommand command;
    command.setDX(-1);
    command.setDY(0);
    command.setDZ(0);

    QGraphicsScene *scene = facade.execute(command);

    ui->graphicsView->setScene(scene);
}

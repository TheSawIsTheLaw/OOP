#include "mainwindow.h"

#include "Commands/uploadcommand.h"
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
    QString qFileName = getFileWay(this, ".", "");

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

    facade.execute(command);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QFileDialog"
#include "QMessageBox"

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


QString getFileWay(QWidget *const parent, const QString startLocation,
                   const QString fileFormat) {
    return QFileDialog::getOpenFileName(
                parent, "Upload Scene", startLocation, fileFormat);
}


void MainWindow::on_pushButton_clicked()
{
    qDebug("Upload");
    QString qFileName = getFileWay(this, ".", "");
    qDebug("%s", qUtf8Printable(qFileName));

    if (qFileName == "") {
        QMessageBox::critical(this, "Ошибка!",
            "Не был выбран файл.");
        return ;
    }
}

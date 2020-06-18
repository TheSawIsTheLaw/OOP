#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "facade.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_goLeftButton_clicked();

    void on_goRightButton_clicked();

    void on_goDownButton_clicked();

    void on_goUpButton_clicked();

    void on_rotateYupButton_clicked();

    void on_rotateYdownButton_clicked();

    void on_rotateXLeftButton_clicked();

    void on_rotateXRightButton_clicked();

    void on_toratateZLeftButton_clicked();

    void on_rotateZRightButton_clicked();

    void on_plusMasstButton_clicked();

    void on_minusMasstButton_clicked();

    void on_NextButton_clicked();

    void on_PreviousButton_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Facade facade;
    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H

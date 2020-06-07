#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "lift.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private slots:
    void on_CabinButtonFloor1_clicked();

    void on_CabinButtonFloor2_clicked();

    void on_CabinButtonFloor3_clicked();

    void on_CabinButtonFloor4_clicked();

    void on_CabinButtonFloor5_clicked();

    void on_CabinButtonFloor6_clicked();

    void on_CabinButtonFloor7_clicked();

    void on_CabinButtonFloor8_clicked();

    void on_CabinButtonFloor9_clicked();

    void on_CabinButtonFloor10_clicked();

    void on_CabinButtonFloor11_clicked();

    void on_CabinButtonFloor12_clicked();

    void on_CabinButtonFloor13_clicked();

    void on_CabinButtonFloor14_clicked();

    void on_CabinButtonFloor15_clicked();

    void on_CabinButtonFloor16_clicked();

    void on_FloorButton1_clicked();

    void on_FloorButton2_clicked();

    void on_FloorButton3_clicked();

    void on_FloorButton4_clicked();

    void on_FloorButton5_clicked();

    void on_FloorButton6_clicked();

    void on_FloorButton7_clicked();

    void on_FloorButton8_clicked();

    void on_FloorButton9_clicked();

    void on_FloorButton10_clicked();

    void on_FloorButton11_clicked();

    void on_FloorButton12_clicked();

    void on_FloorButton13_clicked();

    void on_FloorButton14_clicked();

    void on_FloorButton15_clicked();

    void on_FloorButton16_clicked();

   private:
    Ui::MainWindow *ui;
    Lift lift;
};
#endif // MAINWINDOW_H

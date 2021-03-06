#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>

#include <QMessageBox>

#include <QGraphicsScene>

#include "modelDomain.h"


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

    void on_chooseModelButton_clicked();

    void on_goLeftButton_clicked();

    void on_goDownButton_clicked();

    void on_goUpButton_clicked();

    void on_goRightButton_clicked();

    void on_rotateZRightButton_clicked();

    void on_toratateZLeftButton_clicked();

    void on_rotateYdownButton_clicked();

    void on_rotateYupButton_clicked();

    void on_rotateXRightButton_clicked();

    void on_rotateXLeftButton_clicked();

    void on_plusMasstButton_clicked();

    void on_minusMasstButton_clicked();

 private:
  Ui::MainWindow *ui;
};

typedef struct {
    int xRectStart;
    int yRectStart;
    int xRectEnd;
    int yRectEnd;
    QPen blackPen;
    QGraphicsScene *scene;
    QVector<QGraphicsLineItem *> line;
    Ui::MainWindow *ui;
}drawRequestT; // Draw request

//! Draw function
void drawModel(const modelT model, const drawRequestT drawRequest);
//< End

#endif  // MAINWINDOW_H

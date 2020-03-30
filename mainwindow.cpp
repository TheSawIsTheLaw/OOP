#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userDomain.h"
#include "modelDomain.h"

#include "defines.h"

static modelT model;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::showAll(modelT& model) {
  int check;
  check = isModelInited(model);
  if (check) return;

  QPen whitePen(Qt::white);
  nodeT firstNode, secondNode;

  scene = new QGraphicsScene(this);
  scene->setSceneRect(0, 0, 980, 400);

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
      this, tr("Open Model"), "../startModels", tr("Model Files (*.txt)"));
  qDebug("%s", qUtf8Printable(qFileName));
  int check = setModel(qFileName, model);
  qDebug("%d", check);
  if (check == FILE_ERROR)
    QMessageBox::critical(
        this, "Ошибка!",
        "Возможно, что не был выбран файл, либо файл недоступен.");
  else if (check == MEMORY_ALLOCATION_ERROR)
    QMessageBox::critical(this, "Ошибка!",
                          "Произошла ошибка при выделении памяти под данные.");
  else if (check == FILE_STRUCTURE_ERROR)
    QMessageBox::critical(this, "Ошибка!",
                          "Переданный файл обладает нарушенной структурой и не может "
                          "быть обработан.");
  else if (check == MODEL_IS_NOT_INITED_ERROR)
    QMessageBox::critical(this, "Ошибка!",
                          "Переданная модель не инициализирована. Код программы "
                          "был изменён. Не в лучшую сторону.");
  else if (check == MODEL_IS_NOT_READY_ERROR)
    QMessageBox::critical(this, "Ошибка!", "Ошибка формата файла.");
  else
    showAll(model);
}

void MainWindow::on_goLeftButton_clicked() {
  taskManager(GO_LEFT, model);
  qDebug("left");
  showAll(model);
}

void MainWindow::on_goDownButton_clicked() {
  taskManager(GO_DOWN, model);
  qDebug("down");
  showAll(model);
}

void MainWindow::on_goUpButton_clicked() {
  taskManager(GO_UP, model);
  qDebug("up");
  showAll(model);
}

void MainWindow::on_goRightButton_clicked() {
  taskManager(GO_RIGHT, model);
  qDebug("down");
  showAll(model);
}

void MainWindow::on_rotateZRightButton_clicked() {
  taskManager(ROTATE_Z_R, model);
  qDebug("zR");
  showAll(model);
}

void MainWindow::on_toratateZLeftButton_clicked() {
  taskManager(ROTATE_Z_L, model);
  qDebug("zL");
  showAll(model);
}

void MainWindow::on_rotateYdownButton_clicked() {
  taskManager(ROTATE_Y_R, model);
  qDebug("yR");
  showAll(model);
}

void MainWindow::on_rotateYupButton_clicked() {
  taskManager(ROTATE_Y_L, model);
  qDebug("yL");
  showAll(model);
}

void MainWindow::on_rotateXRightButton_clicked() {
  taskManager(ROTATE_X_R, model);
  qDebug("xR");
  showAll(model);
}

void MainWindow::on_rotateXLeftButton_clicked() {
  taskManager(ROTATE_X_L, model);
  qDebug("xL");
  showAll(model);
}

void MainWindow::on_plusMasstButton_clicked() {
  taskManager(SCALE_PLUS, model);
  qDebug("sP");
  showAll(model);
}

void MainWindow::on_minusMasstButton_clicked() {
  taskManager(SCALE_MINUS, model);
  qDebug("sM");
  showAll(model);
}

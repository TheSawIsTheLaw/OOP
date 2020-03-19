#include "choosemodelselection.h"
#include "ui_choosemodelselection.h"
#include "defines.h"

ChooseModelSelection::ChooseModelSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseModelSelection){
    ui->setupUi(this);
}

ChooseModelSelection::~ChooseModelSelection(){
    delete ui;
}

#ifndef CHOOSEMODELSELECTION_H
#define CHOOSEMODELSELECTION_H

#include <QWidget>


namespace Ui {
class ChooseModelSelection;
}

class ChooseModelSelection : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseModelSelection(QWidget *parent = nullptr);
    ~ChooseModelSelection();

private:
    Ui::ChooseModelSelection *ui;
};

#endif // CHOOSEMODELSELECTION_H

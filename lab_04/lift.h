#ifndef LIFT_H
#define LIFT_H

#include <QObject>

#include "cabine.h"
#include "controller.h"

class Lift : public QObject {
    Q_OBJECT
   public:
    Lift();
    void clickButton(short floorNumber);

   private:
    Controller controller;
    Cabine cabine;
};

#endif // LIFT_H

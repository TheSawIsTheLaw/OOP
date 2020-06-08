#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>

#include "cabine.h"
#include "controller.h"
#include "defines.h"

class Lift : public QObject {
    Q_OBJECT

   public:
    Lift();
    void call(short floor);

   private:
    Controller controller;
    Cabine cabine;
};

#endif // LIFT_H

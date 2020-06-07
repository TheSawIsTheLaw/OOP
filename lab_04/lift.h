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
    void click(short floor);

   private:
    Controller control_panel;
    Cabine lift_cabin;
};

#endif // LIFT_H

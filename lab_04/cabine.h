#ifndef CABINE_H
#define CABINE_H

#include <QObject>

#include "controller.h"
#include "defines.h"
#include "door.h"

class Cabine : public QObject {
    Q_OBJECT
    enum cabineState { MOVE, WAIT, STOP };

   public:
    explicit Cabine(QObject *parent = nullptr);

   signals:
    void cabineIsCalled();
    void cabinePassingFloor(short floor, direction d);
    void cabineReachedDestanationFloor(short floor);
    void cabin_stopped(short floor);

   public slots:
    void cabin_move();
    void cabin_stopping();
    void cabin_call(short floor, direction dir);

   private:
    int current_floor;
    int target;
    bool new_target;
    cabineState current_state;
    direction current_direction;
    Door door;
    QTimer crossing_floor_timer;
};

#endif // CABINE_H

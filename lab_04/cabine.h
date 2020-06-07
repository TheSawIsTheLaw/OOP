#ifndef CABINE_H
#define CABINE_H

#include <QObject>

#include "controller.h"
#include "defines.h"
#include "door.h"

class Cabine : public QObject {
    Q_OBJECT
   public slots:
    void cabineMovesBetweenFloors();
    void cabineStartMoving();
    void cabineStand();
    void cabineCall(short floor, direction dir);

   signals:
    void cabineIsCalled();
    void cabinePassingFloor(short floor, direction dir);
    void cabineReachedDestinationFloor(short floor);
    void cabineStopped(short floor);

   public:
    explicit Cabine(QObject *parent = nullptr);


   private:
    enum cabineState { MOVES, ISWAITINGFOREVENT, STANDING };

    Door door;
    short currentFloor;
    short destinationFloor;
    bool hasNewDestinationFloor;
    QTimer passFloorTimer;
    cabineState currentState;
    direction currentMovementDirection;
};

#endif // CABINE_H

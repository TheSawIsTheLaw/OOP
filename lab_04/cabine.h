#ifndef CABINE_H
#define CABINE_H

#include <QObject>

#include "controller.h"
#include "defines.h"
#include "door.h"

class Cabine : public QObject {
    Q_OBJECT
    enum cabineState { MOVES, ISWAITINGFOREVENT, STANDING };

   public:
    explicit Cabine(QObject *parent = nullptr);

   signals:
    void cabineIsCalled();
    void cabinePassingFloor(short floor, direction dir);
    void cabineReachedDestinationFloor(short floor);
    void cabineStopped(short floor);

   public slots:
    void cabineMoves();
    void cabineStopping();
    void cabineCall(short floor, direction dir);

   private:
    short currentFloor;
    short destinationFloor;
    bool hasNewDestinationFloor;
    cabineState currentState;
    direction currentMovementDirection;
    Door door;
    QTimer passFloorTimer;
};

#endif // CABINE_H

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>

#include "defines.h"

class Controller : public QObject {
    Q_OBJECT

   public slots:
    void onFloor(short floor);
    void passedFloor(short floor);

   public:
    explicit Controller(QObject *parent = nullptr);
    void setNewDestinationFloor(short floor);

   signals:
    void setDestinationFloor(short floor);

   private:
    enum controllerState { FREE, BUSY };

    short currentFloor;
    short currentDestinationFloor = NO_DESTINATION_FLOOR;

    QVector<bool> isCommonDestination;
    controllerState currentState;
    direction currentMovementDirection;
};

#endif // CONTROLLER_H

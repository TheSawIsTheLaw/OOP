#ifndef CABINE_H
#define CABINE_H

#include <QObject>

class Cabine : public QObject {
    Q_OBJECT
    enum state { MOVE, WAIT, STOP };

   public:
    Cabine() {}
    virtual ~Cabine() {}
};

#endif // CABINE_H

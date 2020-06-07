#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>

#include "defines.h"

class Controller : public QObject {
    Q_OBJECT
    enum panel_state { FREE, BUSY };

   public:
    explicit Controller(QObject *parent = nullptr);
    void set_new_target(short floor);

   signals:
    void set_target(short floor, direction dir);

   public slots:
    void achieved_floor(short floor);
    void passed_floor(short floor);

   private:
    int cur_floor;
    int cur_target = -1;

    QVector<bool> is_target;
    panel_state current_state;
    direction cur_direction;
    bool next_target(short &floor);
    void find_new_target();
};

#endif // CONTROLLER_H

#ifndef FATIGUEALARM_H
#define FATIGUEALARM_H

#include<QObject>

class FatigueAlarm : public QObject{
    Q_OBJECT
public:
    FatigueAlarm();

signals:
    void fatigueAlarm();

};

#endif // FATIGUEALARM_H

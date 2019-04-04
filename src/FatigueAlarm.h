#ifndef FATIGUEALARM_H
#define FATIGUEALARM_H

#include<QObject>

class FatigueAlarm : public QObject{
    Q_OBJECT
public:
    FatigueAlarm();

signals:
    void fatigueAlarm();
    void progressStart();

public slots:
    void progressBar(float);
};

#endif // FATIGUEALARM_H

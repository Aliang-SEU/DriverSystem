#include "FatigueAlarm.h"
#include <QDebug>
FatigueAlarm::FatigueAlarm(){
}

void FatigueAlarm::progressBar(float percent){
    emit progressStart();
}

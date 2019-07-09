#include "human.h"
#include <QDebug>

Human::Human(){

}

Human::~Human(){

}

int Human::getShotRange(){
    return _range;
}

void Human::setAngle(int angle){
    _angle = angle;
}

void Human::setShotRange(int range){
    _range = range;
}

void Human::setAttackMode(bool attackMode){
    _attackMode = attackMode;
}

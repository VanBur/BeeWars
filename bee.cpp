#include "bee.h"
#include <gamemodel.h>
#include <cmath>
#include <QDebug>

Bee::Bee(){
    _distance   = GameModel::MAX_RANGE;
    _speed      = MIN_SPEED + rand() % MAX_SPEED;
    int direction = rand() % 2;
    if (direction == 1)
        _speed *= -1;
    _attackDelta = M_PI / ATTACK_FRAMES;
    _currentAttackPosition = 0;
}

Bee::~Bee(){

}

int Bee::getDistance(){
    return _distance;
}

void Bee::updatePosition(){
    if (!isAlive())
        return;
    if (isAlive() && _isActive)
        getAngry();
    if (_attackMode)
        newDistance();

    _angle += _speed;

    if (_angle > 360 || _angle < -360)
        _angle = _angle % 360;
}

void Bee::newDistance(){
    _distance = abs(GameModel::MAX_RANGE * cos(_attackDelta * _currentAttackPosition));
    if (_distance == 0)
        this->setDamage(_damage);
    _currentAttackPosition = _currentAttackPosition + 1;
    if (_currentAttackPosition == ATTACK_FRAMES){
        _currentAttackPosition = 0;
        _attackMode = false;
    }
}

void Bee::getAngry(){
    if (rand() % ATTACK_CHANSE == 0)
        _attackMode = true;
}

#include "unitbase.h"
#include <cmath>
#include <QDebug>

UnitBase::UnitBase(){
    _isActive       = true;
    _attackMode     = false;
    _angle          = rand() % 360;
}

UnitBase::~UnitBase(){

}

void UnitBase::setupParams(UnitParams params){
    _hp = params.hp;
    _damage = params.damage;
    _type = params.type;
}

int UnitBase::getHP(){
    return _hp;
}

int UnitBase::getDamage(){
    return _damage;
}

QString UnitBase::getType(){
    return _type;
}

int UnitBase::getAngle(){
    return _angle;
}

void UnitBase::setDamage(int damage){
    _hp -= damage;
}

bool UnitBase::isAttacking(){
    return _attackMode;
}

bool UnitBase::isActive(){
    return _isActive;
}

bool UnitBase::isAlive(){
    return (_hp > 0);
}

void UnitBase::isActive(bool active){
    _isActive = active;
}

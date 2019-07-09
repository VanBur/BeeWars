#ifndef UNITBASE_H
#define UNITBASE_H

#include <QString>

struct UnitParams{
    QString type;
    int damage;
    int hp;
};

class UnitBase
{
protected:
    bool    _attackMode;
    bool    _isActive;
    int     _hp;
    int     _damage;
    int     _angle;
    QString _type;

public:
    UnitBase();
    ~UnitBase();

    QString getType();
    int getHP();
    int getDamage();
    int getAngle();
    bool isAttacking();
    bool isActive();
    bool isAlive();

    void setDamage(int);
    void isActive(bool);
    void setupParams(UnitParams);
};

#endif // UNITBASE_H

#ifndef BEEBASE_H
#define BEEBASE_H

#include <unitbase.h>

class Bee : public UnitBase
{
private:
    static const int MAX_SPEED      = 3;
    static const int MIN_SPEED      = 1;
    static const int ATTACK_FRAMES  = 30;
    static const int ATTACK_CHANSE  = 1000;

    int _distance;
    int _speed;
    int _currentAttackPosition;
    double _attackDelta;

    void newDistance();

public:
    Bee();
    ~Bee();

    int getDistance();
    void getAngry();

    void updatePosition();
};

#endif // BEEBASE_H

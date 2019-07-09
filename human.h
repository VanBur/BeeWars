#ifndef HUMAN_H
#define HUMAN_H

#include <unitbase.h>

class Human : public UnitBase
{
private:
    int _range;

public:
    Human();
    ~Human();

    void setAngle(int angle);
    void setShotRange(int range);
    void setAttackMode(bool);

    int getShotRange();
};

#endif // HUMAN_H

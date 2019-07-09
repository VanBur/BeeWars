#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <human.h>
#include <bee.h>

using namespace std;

struct DeathAnimation {
    QString type;
    int angle;
    int distance;
    int currentFrame = 0;
};

class GameModel: public QObject
{
    Q_OBJECT
public:
    enum GAME_STATUS {IN_GAME, WIN, LOSE, DRAW};

    static const int MAX_RANGE      = 200;

    static const int TOTAL_QUEEN    = 1;
    static const int TOTAL_WORKER   = 5;
    static const int TOTAL_DRONE    = 8;

    const UnitParams PLAYER = UnitParams{"player", 10, 200};
    const UnitParams QUEEN  = UnitParams{"queen", 12, 100};
    const UnitParams WORKER = UnitParams{"worker", 10, 75};
    const UnitParams DRONE  = UnitParams{"drone", 8, 50};

    GameModel();
    ~GameModel();

    int getStatus();
    Human* getPlayer();
    vector<Bee>* getBees();
    vector<DeathAnimation>* getDeadBees();

    void hitPlayer(int damage);
    void removeDeadBee(int index);

public slots:
    void shot();
    void restart();

private:
    int _gameStatus;
    Human _player;
    vector<Bee> _bees;
    vector<DeathAnimation> _deadBees;

    void generateBees();
    void generatePlayer();
    void killAllBees();
};

#endif // GAMEMODEL_H

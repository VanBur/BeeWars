#include "gamemodel.h"
#include <QDebug>

GameModel::GameModel(){
    _gameStatus = GAME_STATUS::IN_GAME;
    generatePlayer();
    generateBees();
}

GameModel::~GameModel(){
    _bees.clear();
    _deadBees.clear();
}

void GameModel::generateBees(){
    int i;
    for (i = 0; i < TOTAL_QUEEN; ++i){
        Bee queen = Bee();
        queen.setupParams(QUEEN);
        _bees.push_back(queen);
    }
    for (i = 0; i < TOTAL_WORKER; i++){
        Bee worker = Bee();
        worker.setupParams(WORKER);
        _bees.push_back(worker);
    }
    for (i = 0; i < TOTAL_DRONE; i++){
        Bee worker = Bee();
        worker.setupParams(DRONE);
        _bees.push_back(worker);
    }
}

void GameModel::generatePlayer(){
    _player.setupParams(PLAYER);
}

int GameModel::getStatus(){
    return _gameStatus;
}

vector<Bee>* GameModel::getBees(){
    return &_bees;
}

Human* GameModel::getPlayer(){
    return &_player;
}

void GameModel::shot(){
    if (!_player.isAlive() || _bees.size() == 0)
        return;
    _player.setAttackMode(true);
    int beeIndex = rand() % _bees.size();
    Bee *selectedBee = &_bees[beeIndex];

    selectedBee->setDamage(_player.getDamage());
    _player.setAngle(selectedBee->getAngle());
    _player.setShotRange(selectedBee->getDistance());

    if (!selectedBee->isAlive()){
        DeathAnimation da = DeathAnimation();
        da.type = selectedBee->getType();
        da.distance = selectedBee->getDistance();
        da.angle = selectedBee->getAngle();
        _deadBees.push_back(da);
        if (selectedBee->getType() == QUEEN.type)
            killAllBees();
        else
            _bees.erase(_bees.begin() + beeIndex);
    }

    if (_bees.size() == 0){
        if (_player.isAlive())
            _gameStatus = GameModel::GAME_STATUS::WIN;
        else
            _gameStatus = GameModel::GAME_STATUS::DRAW;
    }
}

void GameModel::hitPlayer(int damage){
    _player.setDamage(damage);
    if (!_player.isAlive()){
        if (_bees.size() == 0){
            _gameStatus = GameModel::GAME_STATUS::DRAW;
        } else {
            _gameStatus = GameModel::GAME_STATUS::LOSE;
            for (int i = 0; i < _bees.size(); ++i) {
                _bees[i].isActive(false);
            }
        }
    }
}

void GameModel::killAllBees(){
    for (int i = 0; i < _bees.size(); ++i) {
        DeathAnimation da = DeathAnimation();
        da.type = _bees[i].getType();
        da.distance = _bees[i].getDistance();
        da.angle = _bees[i].getAngle();
        _deadBees.push_back(da);
    }
    _bees.clear();
}

void GameModel::removeDeadBee(int index){
    _deadBees.erase(_deadBees.begin() + index);
}

vector<DeathAnimation>* GameModel::getDeadBees(){
    return &_deadBees;
}

void GameModel::restart(){
    if (_gameStatus == GAME_STATUS::IN_GAME)
        return;
    _bees.clear();
    _deadBees.clear();
    _gameStatus = GAME_STATUS::IN_GAME;
    generatePlayer();
    generateBees();
}

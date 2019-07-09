#include "renderwidget.h"
#include "iostream"
#include <glwidget.h>

RenderWidget::RenderWidget(){
    _background = QBrush(BACKGROUND_COLOR);
}

RenderWidget::~RenderWidget(){

}

void RenderWidget::setModel(GameModel *model){
    _model = model;
}

void RenderWidget::paint(QPainter *painter, QPaintEvent *event){
    painter->fillRect(event->rect(), _background);
    painter->translate(GLWidget::GL_WINDOW_SIZE/2, GLWidget::GL_WINDOW_SIZE/2);
    painter->save();

    drawPlayer(painter);
    drawBullet(painter);

    for (int i = 0; i < _model->getBees()->size(); ++i)
        drawBee(painter, &_model->getBees()->at(i));

    for (int i = 0; i < _model->getDeadBees()->size(); i++)
        drawDeathAnim(painter, &_model->getDeadBees()->at(i), i);

    drawResult(painter);
    painter->restore();
}

void RenderWidget::drawDeathAnim(QPainter *painter, DeathAnimation *da, int index){
    QPixmap pixmap;
    pixmap.load(generateDeathPath(da->type, da->currentFrame));
    if (pixmap.isNull()){
        _model->removeDeadBee(index);
        return;
    }
    painter->rotate(da->angle);
    painter->drawPixmap(da->distance, 0,
                        BEE_PIXMAP_SIZE, BEE_PIXMAP_SIZE, pixmap);
    painter->rotate(-da->angle);
    da->currentFrame += 1;
}

void RenderWidget::drawPlayer(QPainter *painter){
    QPixmap pixmap;

    if (_model->getPlayer()->isAlive()) {
        pixmap.load(generateSkinPath(_model->getPlayer()->getType()));
        painter->rotate(_model->getPlayer()->getAngle());
        painter->drawPixmap(-PLAYER_PIXMAP_SIZE/2, -PLAYER_PIXMAP_SIZE/2,
                            PLAYER_PIXMAP_SIZE, PLAYER_PIXMAP_SIZE, pixmap);
        painter->rotate(-_model->getPlayer()->getAngle());
    } else {
        pixmap.load(generateDeathPath(_model->getPlayer()->getType(), 0));
        painter->drawPixmap(-PLAYER_PIXMAP_SIZE/2, -PLAYER_PIXMAP_SIZE/2,
                            PLAYER_PIXMAP_SIZE, PLAYER_PIXMAP_SIZE, pixmap);
    }
}

void RenderWidget::drawBee(QPainter *painter, Bee *bee){
    QPixmap pixmap;
    pixmap.load(generateSkinPath(bee->getType()));
    painter->rotate(bee->getAngle());
    painter->drawPixmap(bee->getDistance(), 0,
                        BEE_PIXMAP_SIZE, BEE_PIXMAP_SIZE, pixmap);
    painter->rotate(-bee->getAngle());

    if(bee->getDistance() == 0 && _model->getStatus() == GameModel::GAME_STATUS::IN_GAME)
        _model->hitPlayer(bee->getDamage());

    bee->updatePosition();
}

void RenderWidget::drawBullet(QPainter *painter){
    if (!_model->getPlayer()->isAttacking())
        return;

    _model->getPlayer()->setAttackMode(false);
    painter->setPen(QPen(Qt::yellow, 1));
    painter->rotate(_model->getPlayer()->getAngle());
    painter->drawLine(0, 0, int(_model->getPlayer()->getShotRange()), 0);
    painter->rotate(-_model->getPlayer()->getAngle());
}

void RenderWidget::drawResult(QPainter *painter){
    QString finalText;
    switch (_model->getStatus()) {
    case GameModel::GAME_STATUS::WIN:
        finalText = "YOU WIN";
        painter->setPen(QPen(Qt::green));
        break;
    case GameModel::GAME_STATUS::LOSE:
        finalText = "YOU LOSE";
        painter->setPen(QPen(Qt::red));
        break;
    case GameModel::GAME_STATUS::DRAW:
        finalText = "DRAW";
        painter->setPen(QPen(Qt::yellow));
        break;
    default:
        return;
    }

    painter->drawText(FINAL_BANNER, Qt::AlignCenter, finalText);
    painter->drawRect(FINAL_BANNER);
}

QString RenderWidget::generateSkinPath(QString type){
    return QString(BASE_SKIN_PIXMAP_URL + type);
}

QString RenderWidget::generateDeathPath(QString type, int currentFrame){
    return QString(BASE_DEATH_PIXMAP_URL + type + BASE_FRAME_NAME + QString::number(currentFrame));
}

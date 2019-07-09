#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QPainter>
#include <QPaintEvent>
#include <gamemodel.h>

class RenderWidget
{
    const int PLAYER_PIXMAP_SIZE = 40;
    const int BEE_PIXMAP_SIZE = 40;
    const QRect FINAL_BANNER = QRect(-90, -150, 180, 30);
    const QColor BACKGROUND_COLOR = QColor(168, 168, 168);

    const QString BASE_SKIN_PIXMAP_URL   = ":/img/sprites/skins/";
    const QString BASE_DEATH_PIXMAP_URL  = ":/anim/sprites/death/";
    const QString BASE_FRAME_NAME        = "/frame_";

public:
    RenderWidget();
    ~RenderWidget();

    void paint(QPainter *painter, QPaintEvent *event);
    void setModel(GameModel *model);
    void resetPainter();

private:
    GameModel *_model;
    QBrush _background;
    void drawPlayer(QPainter *painter);
    void drawBee(QPainter *painter, Bee *bee);
    void drawBullet(QPainter *painter);
    void drawResult(QPainter *painter);
    void drawDeathAnim(QPainter *painter, DeathAnimation *da, int index);

    QString generateSkinPath(QString type);
    QString generateDeathPath(QString type, int currentFrame);
};

#endif

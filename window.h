#ifndef WINDOW_H
#define WINDOW_H

#include "renderwidget.h"

#include <QWidget>
#include <QPushButton>
#include <gamemodel.h>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private:
    const int FPS = 25;

    RenderWidget _renderWidget;
    GameModel _model;
};

#endif

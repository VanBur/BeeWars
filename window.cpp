#include "glwidget.h"
#include "window.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QPushButton>

Window::Window(){
    setWindowTitle(tr("BeeWars"));

    GLWidget *openGL = new GLWidget(&_renderWidget, this, &_model);

    QPushButton *hitButton      = new QPushButton(tr("HIT"));
    QPushButton *restartButton  = new QPushButton(tr("RESTART"));
    QHBoxLayout *buttonsLayout  = new QHBoxLayout;
    QVBoxLayout *mainLayout     = new QVBoxLayout;

    buttonsLayout->addWidget(restartButton);
    buttonsLayout->addWidget(hitButton);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(openGL);
    setLayout(mainLayout);

    connect(hitButton, &QPushButton::clicked, &_model, &GameModel::shot);
    connect(restartButton, &QPushButton::clicked, &_model, &GameModel::restart);

    // render timer
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, openGL, &GLWidget::animate);
    timer->start(1000/FPS);
}

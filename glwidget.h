#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <gamemodel.h>

class RenderWidget;

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    static const int GL_WINDOW_SIZE = 500;

    GLWidget(RenderWidget *renderWidget, QWidget *parent, GameModel *model);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    RenderWidget *helper;
};

#endif

#include "glwidget.h"
#include "renderwidget.h"
#include <QPainter>

GLWidget::GLWidget(RenderWidget *renderWidget, QWidget *parent, GameModel *model)
    : QOpenGLWidget(parent), helper(renderWidget)
{
    renderWidget->setModel(model);
    setFixedSize(GL_WINDOW_SIZE, GL_WINDOW_SIZE);
    setAutoFillBackground(false);
}

void GLWidget::animate(){
    update();
}

void GLWidget::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event);
    painter.end();
}

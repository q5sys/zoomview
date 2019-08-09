#ifndef ZOOMGVIEW_H
#define ZOOMGVIEW_H

#include <QGraphicsView>

class QWidget;
class QGraphicsScene;

class zoomGView : public QGraphicsView { Q_OBJECT

public:
    zoomGView(QGraphicsScene*, QWidget* = NULL);
    ~zoomGView();

private:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    bool move;
    int moveStartX, moveStartY;
};


#endif // ZOOMGVIEW_H



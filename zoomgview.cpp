#include "zoomgview.h"
#include <QtGui>

zoomGView::zoomGView(QGraphicsScene *scene, QWidget* parent) :QGraphicsView(scene, parent){

void zoomGView::wheelEvent(QWheelEvent *event){
  if (event->modifiers() & Qt::ControlModifier){
    const ViewportAnchor zoomAnchor = transformationAnchor();
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    int angle = event->angleDelta().y();
    qreal zoomFactor;

    if (angle > 0) { zoomFactor = 1.1; }
    else { zoomFactor = 0.9; }
    scale(zoomFactor, zoomFactor);
    setTransformationAnchor(zoomAnchor);
  }
  else { QGraphicsView::wheelEvent(event); }
}

void zoomGView::mousePressEvent(QMouseEvent *event){
  if (event->button() == Qt::RightButton)
    {
      move = true;
      moveStartX = event->x();
      moveStartY = event->y();
      setCursor(Qt::ClosedHandCursor);
      event->accept();
      return;
  }
  event->ignore();
}

void zoomGView::mouseReleaseEvent(QMouseEvent *event){
  if (event->button() == Qt::RightButton)
    {
    move = false;
    setCursor(Qt::ArrowCursor);
    event->accept();
    return;
  }
  event->ignore();
}

void zoomGView::mouseMoveEvent(QMouseEvent *event){
  if (move)
    {
    horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - moveStartX));
    verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - moveStartY));
    moveStartX = event->x();
    moveStartY = event->y();
    event->accept();
    return;
  }
  event->ignore();

}
}

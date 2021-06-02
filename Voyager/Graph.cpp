#include "Graph.h"

Otrisov::Otrisov(QObject *parent) : QGraphicsScene(parent){
is_picked_planets = false;
myPen = new QPen(Qt::red);
myBrush = new QBrush(Qt::red);
}

void Otrisov::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
QGraphicsScene::update();
QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void Otrisov::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
QGraphicsScene::mousePressEvent(mouseEvent);
if (is_picked_planets && QGraphicsScene::focusItem()) {
QGraphicsItem* item = QGraphicsScene::focusItem();
planet* PlThis = static_cast<planet*>(item);
if (PlThis) {
emit HoldDownPlanet(PlThis);
}
}
QGraphicsScene::update();
}

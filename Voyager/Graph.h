#ifndef GRAPH_H
#define GRAPH_H

#include "Planets.h"
#include <QColor>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class QGraphicsSceneMouseEvent;

class Otrisov :  public QGraphicsScene {
Q_OBJECT
private:
QPen* myPen;
QBrush* myBrush;
public:
explicit Otrisov(QObject *parent = 0);
bool is_picked_planets;

public slots:
signals: void HoldDownPlanet(planet*);

protected:
void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

};

class QPointF;
class QColor;

#endif // GRAPH_H

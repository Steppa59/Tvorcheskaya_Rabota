#include "Planets.h"


planet::planet(int Xcoor, int Ycoor, QString str, QGraphicsItem* parent) : QGraphicsItem(parent) {
oX = Xcoor;
oY = Ycoor;
NamePlanet = str;
PlanetColor = QColor(221, 160, 221);
setFlag(QGraphicsItem::ItemIsMovable);
}

planet::planet(const planet& PlThis){
oX = PlThis.oX;
oY = PlThis.oY;
NamePlanet = PlThis.NamePlanet;
setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF planet::boundingRect() const {
return QRectF(oX,oY,xB,xB);
}

bool operator== (const planet &PlF, const planet &PlS) {
return (PlF.NamePlanet == PlS.NamePlanet);
}

void planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
painter->setBrush(PlanetColor);
int size = xB - 5;
painter->drawEllipse(oX,oY,size,size);
painter->drawText(oX+xB/3,oY+xB-20,NamePlanet);
}

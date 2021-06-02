#ifndef planets_H
#define planets_H

#include <QGraphicsItem>
#include <QPainter>
#include <QFontMetrics>
const int expp = 23;
const int Razbr_diap = 100;
class planet : public QGraphicsItem {
public:
planet(int, int, QString, QGraphicsItem* parent = nullptr);
planet(const planet&);
QString NamePlanet;
friend bool operator== (const planet&, const planet&);
private:
QColor PlanetColor;
int oX, oY;
protected:
QRectF boundingRect() const override;
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};
const int xB = 45;

#endif // planets_H

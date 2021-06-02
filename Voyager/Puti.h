#ifndef Puti_H
#define Puti_H

#include <QGraphicsItem>
#include "Planets.h"
void put_temp(int kol, int index, std::vector<double> &stein_vec);
double alpha_rock(double a, double xC1, double xC2, double yC1, double yC2);
const int bigNumerator = 10000000;
class put : public QGraphicsItem {
public:
put(planet*, planet*, double, QGraphicsItem* parent = nullptr);
friend bool operator== (const put&, const put&);
put(const put&);
double len;
planet* planetPerv;
planet* planetVtor;
protected:
const int zero_holder = 0;
const int viewFlexer = 35;
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
QString ConvertInStr(double);
QRectF boundingRect() const override;

};


#endif // Puti_H

#define _USE_MATH_DEFINES
#include "Puti.h"
#include <cmath>
#include "trigcalcx.h"
#include "Planets.h"

double alpha_rock(double a, double xC1, double xC2, double yC1, double yC2){
    double ans = 0;
    if (xC2-xC1<0) {
    if (yC2-yC1<0) {
    ans = M_PI + a;
    } else {
    ans = M_PI - a;
    }
    } else if (yC2-yC1<0) {
    ans = -a;
    }
    return ans;
}

put::put(planet* plt1, planet* plt2, double l, QGraphicsItem* parent) : QGraphicsItem(parent) {
planetPerv = plt1;
planetVtor = plt2;
len = l;
setFlag(QGraphicsItem::ItemIsFocusable);
}

put::put(const put& pu){
planetPerv = pu.planetPerv;
planetVtor = pu.planetVtor;
len = pu.len;
setFlag(QGraphicsItem::ItemIsFocusable);
}

QString put::ConvertInStr(double db){
QString result = QString::number(db);
return result;
}

void put_temp(int kol, int index, std::vector<double> &stein_vec){
    for (int j = 0; j < kol; j++) {
    if (index == j)
    stein_vec.push_back(-1);
    else {
    int random_number;
    random_number = rand()/bigNumerator + Razbr_diap;
    stein_vec.push_back(random_number);
    }
    }
}


void put::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
qreal x1 = planetPerv->pos().x() + expp;
qreal y1 = planetPerv->pos().y() + expp;
qreal x2 = planetVtor->pos().x() + expp;
qreal y2 = planetVtor->pos().y() + expp;
qreal Alpha = -atan(abs(y2 - y1) / abs(x2 - x1));

Alpha = alpha_rock(Alpha, x1, x2, y1, y2);

TrigCalcx head_trig_craft;

qreal pX,pY;
pX= head_trig_craft.tr_calc.initSinMul * sin(Alpha);
pY = head_trig_craft.tr_calc.initSinMul * cos(Alpha);
QLineF line = QLineF(x1-pX, y1-pY, x2-pX, y2-pY);
QLineF vector = line.unitVector();
QPointF Tochka1 = vector.p2();
vector.setLength(line.length()-head_trig_craft.tr_calc.lengthStep);
QPointF Tochka2 = vector.p2();
painter->drawLine(QLineF(Tochka1, Tochka2));
vector.setLength(line.length() - head_trig_craft.tr_calc.lengthMax);

QLineF strelkaL = QLineF(Tochka2, vector.p2());
QLineF strelkaR = QLineF(Tochka2, vector.p2());
strelkaL.setAngle(strelkaL.angle() - head_trig_craft.tr_calc.anASib);
strelkaR.setAngle(strelkaR.angle() + head_trig_craft.tr_calc.anASib);
painter->drawLine(strelkaL);
painter->drawLine(strelkaR);

QFontMetrics params(painter->font());
QString converted = ConvertInStr(len);
int side = params.horizontalAdvance(converted);
qreal rotate_angle = -line.angle();
QPointF center = line.center();

qreal text_x = center.x() * cos(M_PI * rotate_angle / head_trig_craft.tr_calc.angPropCircle)
        + center.y() * sin(M_PI * rotate_angle / head_trig_craft.tr_calc.angPropCircle);
qreal text_y = -center.x() * sin(M_PI * rotate_angle / head_trig_craft.tr_calc.angPropCircle)
        + center.y() * cos(M_PI * rotate_angle / head_trig_craft.tr_calc.angPropCircle);

painter->rotate(rotate_angle);
painter->drawText(text_x - side/head_trig_craft.tr_calc.lineParam,
                  text_y - head_trig_craft.tr_calc.textCon, converted);
painter->rotate(-rotate_angle);
}

QRectF put::boundingRect() const {
return QRectF(zero_holder, zero_holder, viewFlexer, viewFlexer);
}

bool operator== (const put &plt_station1, const put &plt_station2) {
return plt_station1.planetPerv == plt_station2.planetPerv && plt_station1.planetVtor == plt_station2.planetVtor;
}

#ifndef VOYAGER_H
#define VOYAGER_H

#include <QMainWindow>
#include "Planets.h"
#include <QGraphicsView>
#include <vector>
#include "Puti.h"
#include "Graph.h"
#include <QKeyEvent>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Way {
int otkuda;
int kuda;
};
const int abber = 4;
class MainWindow : public QMainWindow
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();
public slots:
void Reshenie();
void PlanetCreate();
void VblvodP();
void O4ISTKA();
private:
Ui::MainWindow *ui;
planet* v;
public:
Otrisov* Layout;
vector<planet*> planets;
vector<vector<double>> control;
private slots:
void on_pushButton_clicked();
void on_res_clicked();
};

#endif // VOYAGER_H

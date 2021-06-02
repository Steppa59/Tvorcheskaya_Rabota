#include "Voyager.h"
#include "Puti.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
ui->setupUi(this);
Layout = new Otrisov(ui->graphicsView);
ui->graphicsView->setScene(Layout);
connect(ui->O4ISTKA, &QPushButton::released, this, &MainWindow::O4ISTKA);
connect(ui->res,SIGNAL(clicked()),this,SLOT(Reshenie()));
connect(ui->VblvodP,SIGNAL(clicked()),this,SLOT(VblvodP()));
ui->DPut->hide();
ui->Put->hide();
ui->label->hide();
ui->Marshrut->hide();
}

void MainWindow :: VblvodP() {
int n = ui->planet->text().toInt();
if(n>2) {
for (int i = 0; i < n; i++) {
planet *new_planet = new planet(0, i, QString::number(i+1));
vector<planet*>::iterator j = planets.begin();
for (; j != planets.end(); j++) {
    planet* comp = *j;
if (new_planet == comp) {
delete new_planet;
return;
}
}
planets.push_back(new_planet);
Layout->addItem(new_planet);
Layout->QGraphicsScene::update();
vector<double> garb;
put_temp(n, i, garb);
control.push_back(garb);
}

for(int i = 0;i<planets.size();i++) {
planet* k1 =planets[i];
int q1 = (planets[i]->NamePlanet).toInt();
for(int j = 0;j<planets.size();j++) {
if(i!=j) {
planet* kj = planets[j];
int qj = (planets[j]->NamePlanet).toInt();
double sj = control[q1 - 1][qj - 1];
put* new_put = new put(k1, kj, sj);
Layout->addItem(new_put);
Layout->QGraphicsScene::update();
}
}
}
} else
QMessageBox::warning(this, " Ошибка! ", "Вводить можно только числа");
}

void MainWindow::O4ISTKA() {
ui->planet->clear();
Layout -> clear();
ui->label->clear();
ui->Marshrut->clear();
Layout->QGraphicsScene::update();
planets.clear();
control.clear();
ui->DPut->hide();
ui->Put->hide();
ui->label->hide();
ui->Marshrut->hide();
}

void MainWindow::PlanetCreate() {
if(!control.empty()) {
int N = planets.size() - 1;
QString q = QString::number((planets[N]->NamePlanet).toInt() + 1);
planet *new_planet = new planet(0, 0, q);
for (auto i : planets){
if (*new_planet == *i) {
delete new_planet;
return;
}
}
planets.push_back(new_planet);
Layout->addItem(new_planet);
Layout->QGraphicsScene::update();
vector<double>t;
for (int j = 0; j < control.size()+1; j++) {
if (control.size() == j)
t.push_back(-1);
else {
int in;
in = rand()/10000000 + 100;
t.push_back(in);
}
}
control.push_back(t);

for (int j = 0; j < control.size()-1; j++) {
int in;
in = rand()/10000000 + 100;
control[j].push_back(in);
}
N = planets.size() - 1;
planet* k1 =planets[N];
int q1 = (planets[N]->NamePlanet).toInt();
for(int j = 0;j<planets.size();j++) {
if(N!=j) {
planet* kj = planets[j];
int qj = (planets[j]->NamePlanet).toInt();
double sj = control[q1 - 1][qj - 1];
put* new_put = new put(k1, kj, sj);
Layout->addItem(new_put);
Layout->QGraphicsScene::update();
}
}
for(int j = 0;j<planets.size();j++) {
if(N!=j)
{
planet* kj = planets[j];
int qj = (planets[j]->NamePlanet).toInt();
double sj = control[qj - 1][q1 - 1];
put* new_put = new put(kj, k1, sj);
Layout->addItem(new_put);
Layout->QGraphicsScene::update();
}
}
}
}

void SokrCol(vector<vector<double>> & arr) {
int raz =arr.size();
for (int i = 0; i < raz; i++) {
int MIN = 999999;
for (int j = 0; j < raz; j++) {
if (MIN > arr[i][j] && arr[i][j] >= 0)
MIN = arr[i][j];
}

if (MIN != 999999) {
for (int j = 0; j < raz; j++) {
if (arr[i][j] >= 0)
arr[i][j] -= MIN;
}
}

}
}

void SokrRow(vector<vector<double>> & arr) {
for (int i = 0; i < arr.size(); i++) {
int MIN = 999999;
for (int j = 0; j < arr[0].size(); j++) {
if (MIN > arr[j][i] && arr[j][i] >= 0)
MIN = arr[j][i];
}
if (MIN != 999999) {
for (int j = 0; j < arr[0].size(); j++) {
if (arr[j][i] >= 0)
arr[j][i] -= MIN;
}
}
}
}

int poiskMinStolbec(vector<vector<double>>& arr, int i, int j) {
int MIN = 999999;
for (int N=0; N<arr.size(); N++) {
if (MIN > arr[i][N] && arr[i][N]>=0 && N != j) {
MIN=arr[i][N];
}
}
return MIN;
}
int poiskMinStroka(vector<vector<double>>& arr, int i, int j) {
int MIN = 999999;
for (int N=0; N<arr.size(); N++) {
if (MIN > arr[N][j] && arr[N][j] >= 0 && N != i) {
MIN = arr[N][j];
}

}
return MIN;
}



Way poiskWay(vector<vector<double>>& arr) {
int max=-1;
Way way{ 0, 0 };

for (int i = 0; i < arr.size(); i++) {
for (int j = 0; j < arr[0].size(); j++) {
if (arr[i][j] == 0) {
int t = poiskMinStolbec(arr, i,j) + poiskMinStroka(arr, i,j);
if (t > max) {
max = t;
way.otkuda = i;
way.kuda = j;
}
}
}
}
arr[way.kuda][way.otkuda]=-1;
for (int i = 0; i < arr.size(); i++) {
arr[way.otkuda][i] = -1;
arr[i][way.kuda] = -1;
}
return way;
}

int Dlina(vector<vector<double>> matrix, vector<Way> option) {
int dlin = 0;
int Kol = 0;
Way cur = option[0];
while (Kol < option.size()) {
for (int i = 0; i < option.size(); i++) {
Way next = option[i];
if (cur.kuda == next.otkuda) {
Kol++;
dlin += matrix[cur.otkuda][cur.kuda];
cur = next;
break;
}
}
}
  return dlin;
}

QString NaitiPravPut(vector<Way> option) {
QString marsh = "";
Way present = option[0];
marsh += QString::number(present.otkuda + 1) + " ➞ " + QString::number(present.kuda + 1);
int Kol = 0;
while (Kol < option.size()+1) {
for (int i = 0; i < option.size(); i++) {
Way next = option[i];
if (present.kuda == next.otkuda) {
marsh += " ➞ " + QString::number(next.kuda + 1);
present = next;
Kol++;
break;
}

}

}
if(option.size() > abber)
marsh.chop(3);
else {
QString  napr = marsh.right(marsh.size() - 3);
marsh = napr;
  }
 return marsh;
}

void MainWindow :: Reshenie() {
if(!control.empty()) {
int i = 0;
vector<vector<double>> matrix = control;
vector<Way> g_vec;
while (i != matrix.size()) {
SokrCol(matrix);
SokrRow(matrix);
g_vec.push_back(poiskWay(matrix));
i++;
}

int sum = Dlina(control, g_vec);
QString KON = NaitiPravPut(g_vec);
ui->Marshrut->setText(NaitiPravPut(g_vec)+" ➞ "+KON[9]);
ui->label->setText(QString::number(sum));
}
}

MainWindow::~MainWindow()
{
delete ui;
}


void MainWindow::on_pushButton_clicked()
{
int iz = 0;
int v = 0;
QString iz1 = ui->lineEdit_iz->text();
QString v1 = ui->lineEdit_v ->text();
iz=iz1.toInt();
v=v1.toInt();
}

void MainWindow::on_res_clicked() {
ui->DPut->show();
ui->Put->show();
ui->label->show();
ui->Marshrut->show();
}

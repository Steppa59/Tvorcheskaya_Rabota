#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <cmath>
bool znak = false;
bool tochka = false;
bool numX = true;
bool chislo = true;
short int lastClickSkobka = 0; // | "-1" == "(";   "1" == ")";     0!=="(" + ")";
bool lastClickChislo = false;
bool lastClickX = false;
short int ClickPole = 1;
int pos3=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_devide,SIGNAL(clicked()),this,SLOT(on_pushButton_devide_clicked()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(on_pushButton_mult_clicked()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(on_pushButton_plus_clicked()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(on_pushButton_minus_clicked()));
    connect(ui->pushButton_exp,SIGNAL(clicked()),this,SLOT(on_pushButton_exp_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers()
{
 if(chislo==true){
 QPushButton * button = (QPushButton *)sender();
 if (ClickPole==1){
 ui->Result_Show->setText(ui->Result_Show->text() + button->text());
 znak=true;
 tochka=true;
 numX=false;
 chislo=true;
 lastClickSkobka=0;
 lastClickChislo=true;
 lastClickX = false;
 } else ui->vvodX->setText(ui->vvodX->text() + button->text());
}
}

void MainWindow::on_pushButton_dot_clicked()
{
if(tochka==true){
    ui->Result_Show->setText(ui->Result_Show->text()+".");
    znak=false;
    tochka=false;
    numX=false;
    chislo=true;
    lastClickSkobka=0;
    lastClickChislo=false;
    lastClickX = false;
    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    if(znak==true){
    ui->Result_Show->setText(ui->Result_Show->text()+"+");
    znak=false;
    tochka=false;
    numX=true;
    chislo=true;
    lastClickSkobka=0;
    lastClickChislo=false;
    lastClickX = false;
    }
}

void MainWindow::on_pushButton_minus_clicked()
{
    if(znak==true) {
    ui->Result_Show->setText(ui->Result_Show->text()+"-");
    znak=false;
    tochka=false;
    numX=true;
    chislo=true;
    lastClickSkobka=0;
    lastClickChislo=false;
    lastClickX = false;
    }
    if(lastClickSkobka==-1){
        ui->Result_Show->setText(ui->Result_Show->text()+"-1*");
        znak=false;
        tochka=false;
        numX=true;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=false;
        lastClickX = false;
    }
}

void MainWindow::on_pushButton_mult_clicked()
{
    if(znak==true){
    ui->Result_Show->setText(ui->Result_Show->text()+"*");
    znak=false;
    tochka=false;
    numX=true;
    chislo=true;
    lastClickSkobka=0;
    lastClickChislo=false;
    lastClickX = false;
    }
}

void MainWindow::on_pushButton_devide_clicked()
{
    if(znak==true){
    ui->Result_Show->setText(ui->Result_Show->text()+"/");
    znak=false;
    tochka=false;
    numX=true;
    chislo=true;
    lastClickSkobka=0;
    lastClickChislo=false;
    lastClickX = false;
    }
}

void MainWindow::on_pushButton_exp_clicked()
{
    if(znak==true){
    ui->Result_Show->setText(ui->Result_Show->text()+"^");
    znak=false;
    tochka=false;
    numX=false;
    chislo=true;
    lastClickSkobka=0;
    lastClickChislo=false;
    lastClickX = false;
    }
}

void MainWindow::on_pushButton_x_clicked()
{
    if(numX==true){
    ui->Result_Show->setText(ui->Result_Show->text()+"x");
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    }else if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
    ui->Result_Show->setText(ui->Result_Show->text()+"*x");
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    }
}

void MainWindow::on_pushButton_sl_clicked()
{
    if (((lastClickSkobka==1)or(lastClickChislo)or(lastClickX))&&znak){
    ui->Result_Show->setText(ui->Result_Show->text()+"*(");
    lastClickSkobka=-1;
    lastClickChislo=false;
    lastClickX=false;
    numX=true;
    chislo=true;
    znak=false;
    tochka=false;
        } else {
    ui->Result_Show->setText(ui->Result_Show->text()+"(");
    numX=true;
    chislo=true;
    znak=false;
    tochka=false;
    lastClickChislo=false;
    lastClickSkobka=-1;
    lastClickX=false;

    }
}

void MainWindow::on_pushButton_sp_clicked()
{

    lastClickSkobka=1;
    ui->Result_Show->setText(ui->Result_Show->text()+")");
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickChislo=false;
    lastClickX=false;
    lastClickSkobka=1;



}

void MainWindow::on_pushButton_del_clicked()
{
    if(ClickPole==1){
    int siz = ui->Result_Show->text().length();
    QString next="";
    if (siz>1){
    for (int i=0;i<=siz-2;i++){

    next=next+ui->Result_Show->text()[i];
}
    if (next[siz-1].isLetter()){
        znak=true;
        tochka=false;
        numX=false;
        chislo=false;
        lastClickSkobka=0;
        lastClickChislo=true;
        lastClickX = true;
    }
    if ((ui->Result_Show->text()[siz-2]=="0")or
        (ui->Result_Show->text()[siz-2]=="1")or
        (ui->Result_Show->text()[siz-2]=="2")or
        (ui->Result_Show->text()[siz-2]=="3")or
        (ui->Result_Show->text()[siz-2]=="4")or
        (ui->Result_Show->text()[siz-2]=="5")or
        (ui->Result_Show->text()[siz-2]=="6")or
        (ui->Result_Show->text()[siz-2]=="7")or
        (ui->Result_Show->text()[siz-2]=="8")or
        (ui->Result_Show->text()[siz-2]=="9"))
    {
        znak=true;
        tochka=true;
        numX=false;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=true;
        lastClickX = false;
    }
    if (ui->Result_Show->text()[siz-2]=="."){
        znak=false;
        tochka=false;
        numX=false;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=false;
        lastClickX = false;
    }

    if (ui->Result_Show->text()[siz-2]=="+"){
        znak=false;
        tochka=false;
        numX=true;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=false;
        lastClickX = false;
    }
    if (ui->Result_Show->text()[siz-2]=="-"){
        znak=false;
        tochka=false;
        numX=true;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=false;
        lastClickX = false;
    }
    if (ui->Result_Show->text()[siz-2]=="*"){
        znak=false;
        tochka=false;
        numX=true;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=false;
        lastClickX = false;
    }
    if (ui->Result_Show->text()[siz-2]=="/"){
        znak=false;
        tochka=false;
        numX=true;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=false;
        lastClickX = false;
    }
    if (ui->Result_Show->text()[siz-2]=="^"){
        znak=false;
        tochka=false;
        numX=false;
        chislo=true;
        lastClickSkobka=0;
        lastClickChislo=false;
        lastClickX = false;
    }
    if (ui->Result_Show->text()[siz-2]==")"){
        znak=true;
        tochka=false;
        numX=false;
        chislo=false;
        lastClickChislo=false;
        lastClickX=false;
    }
    if (ui->Result_Show->text()[siz-2]=="("){
    lastClickSkobka=-1;
    lastClickChislo=false;
    lastClickX=false;
    numX=true;
    chislo=true;
    znak=false;
    tochka=false;
    }


    }
    if((ui->Result_Show->text().length()>=-5)&&(ui->Result_Show->text().length()<2)) {
    next="";
    }
    ui->Result_Show->setText(next);
    if (ui->Result_Show->text()==""){
    lastClickSkobka=0;
    lastClickChislo=false;
    lastClickX=false;
    numX=true;
    chislo=true;
    znak=false;
    tochka=false;
    }
    }
    if (ClickPole==2){
      int siz2 = ui->vvodX->text().length();
        QString next2="";
        if (siz2>1){
        for (int i=0;i<=siz2-2;i++){
        next2=next2+ui->Result_Show->text()[i];
    }
    }
     ui->vvodX->setText(next2);
}

}
void MainWindow::on_pushButton_Res_clicked()
{
    bool PeremEst = true;
    bool WrongSk = false; // false = всё хорошо
    short int KolSkobokL = 0;
    short int KolSkobokR = 0; // 0 == cкобки расставлены верно
    QString Strok2 = ui->Result_Show->text();
    for (int i=0;i<=Strok2.length();i++){
        if(Strok2[i]=="("){
    KolSkobokL++;
        }

        if(Strok2[i]==")"){
    KolSkobokR++;
        }
        if(KolSkobokL-KolSkobokR<0){
        WrongSk=true;
        }
    }
ui->Result_Show_2->setText("");
QString znachX = ui->vvodX->text();
QString resul = "";
QString Strok = ui->Result_Show->text();

if ((KolSkobokR!=KolSkobokL)or(WrongSk==true)){
ui->LabelWrong->setText("Ошибка! Проверьте правильность расставления скобок !");
} else
if(ui->Result_Show->text().contains("/0")){
ui->LabelWrong->setText("Ошибка! На ноль делить нельзя !");
} else
if (ui->Result_Show->text()==""){
ui->LabelWrong->setText("Ошибка! Введите математическую задачу с;");
} else
if(((znachX=="")&&(ui->Result_Show->text().contains("x")))or
((ui->V1->text()=="")&&(ui->Result_Show->text().contains(ui->P1->text()))&&(ui->P1->text()!=""))or
((ui->V2->text()=="")&&(ui->Result_Show->text().contains(ui->P2->text()))&&(ui->P2->text()!=""))or
((ui->V3->text()=="")&&(ui->Result_Show->text().contains(ui->P3->text()))&&(ui->P3->text()!=""))or
((ui->V4->text()=="")&&(ui->Result_Show->text().contains(ui->P4->text()))&&(ui->P4->text()!=""))or
((ui->V5->text()=="")&&(ui->Result_Show->text().contains(ui->P5->text()))&&(ui->P5->text()!=""))or
((ui->V6->text()=="")&&(ui->Result_Show->text().contains(ui->P6->text()))&&(ui->P6->text()!=""))or
((ui->V7->text()=="")&&(ui->Result_Show->text().contains(ui->P7->text()))&&(ui->P7->text()!="")))
{
ui->LabelWrong->setText("Ошибка! Введите значение введенных переменных !");
} else {
ui->LabelWrong->setText("");
int pos=0;
ui->Result_Show_22->clear();
pos = ui->Result_Show_22->textCursor().selectionStart();
ui->Result_Show_22->textCursor().setPosition(pos);
ui->Result_Show_22->textCursor().insertText("Переписываем изначальное выражение: ");
ui->Result_Show_22->textCursor().insertText('\n'+ui->Result_Show->text()+"="+'\n'+'\n');
bool EstX=false;
if((ui->Result_Show->text().contains("x"))or
((ui->Result_Show->text().contains(ui->P1->text()))&&(ui->P1->text()!=""))or
((ui->Result_Show->text().contains(ui->P2->text()))&&(ui->P2->text()!=""))or
((ui->Result_Show->text().contains(ui->P3->text()))&&(ui->P3->text()!=""))or
((ui->Result_Show->text().contains(ui->P4->text()))&&(ui->P4->text()!=""))or
((ui->Result_Show->text().contains(ui->P5->text()))&&(ui->P5->text()!=""))or
((ui->Result_Show->text().contains(ui->P6->text()))&&(ui->P6->text()!=""))or
((ui->Result_Show->text().contains(ui->P7->text()))&&(ui->P7->text()!="")))
{
EstX=true;
}
if(EstX){
ui->Result_Show_22->textCursor().insertText("Выражение после подстановки переменных: ");
// ////////////////////////////////////////////////////////////////////////////////////////////////////////
for (int i=0;i<=Strok.length();i++){
if ((Strok[i]==ui->P1->text())&&(ui->P1->text()!="")){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V1->text());
} else
if ((Strok[i]==ui->P2->text())&&(ui->P2->text()!="")){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V2->text());
} else
if ((Strok[i]==ui->P3->text())&&(ui->P3->text()!="")){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V3->text());
} else
if ((Strok[i]==ui->P4->text())&&(ui->P4->text()!="")){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V4->text());
} else
if ((Strok[i]==ui->P5->text())&&(ui->P5->text()!="")){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V5->text());
} else
if ((Strok[i]==ui->P6->text())&&(ui->P6->text()!="")){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V6->text());
} else
if ((Strok[i]==ui->P7->text())&&(ui->P7->text()!="")){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V7->text());
} else
if ((Strok[i]=="x")&&(ui->Result_Show->text().contains("x"))){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ znachX);
} else {
ui->Result_Show_2->setText(ui->Result_Show_2->text() + Strok[i]);
}
}
// ///////////////////////////////////////////////////////////////////////////////////////////
ui->Result_Show_22->textCursor().insertText("\n");

ui->Result_Show_22->textCursor().insertText(ui->Result_Show_2->text()+"=");

Strok = ui->Result_Show_2->text();
while (PeremEst==true){
PeremEst=false;
for (int i=0;i<=Strok.length();i++){
if (Strok[i].isLetter()){
PeremEst=true;
}
}
QString ABC=ui->Result_Show_2->text();
ui->Result_Show_2->clear();

for (int i=0;i<=Strok.length()-1;i++){
if ((Strok[i]==ui->P1->text())&&(ui->P1->text()!="")){
if((ui->V1->text().contains("+"))or(ui->V1->text().contains("-"))or
(ui->V1->text().contains("*"))or(ui->V1->text().contains("/"))){
 ui->Result_Show_2->setText(ui->Result_Show_2->text()+"("+ui->V1->text()+")");
} else {
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V1->text());
}
}

else
if ((Strok[i]==ui->P2->text())&&(ui->P2->text()!="")){
//ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V2->text());
    if((ui->V2->text().contains("+"))or(ui->V2->text().contains("-"))or
    (ui->V2->text().contains("*"))or(ui->V2->text().contains("/"))){
     ui->Result_Show_2->setText(ui->Result_Show_2->text()+"("+ui->V2->text()+")");
    } else {
    ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V2->text());
    }
}

else
if ((Strok[i]==ui->P3->text())&&(ui->P3->text()!="")){
//ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V3->text());
    if((ui->V3->text().contains("+"))or(ui->V3->text().contains("-"))or
    (ui->V3->text().contains("*"))or(ui->V3->text().contains("/"))){
     ui->Result_Show_2->setText(ui->Result_Show_2->text()+"("+ui->V3->text()+")");
    } else {
    ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V3->text());
    }
}

else
if ((Strok[i]==ui->P4->text())&&(ui->P4->text()!="")){
//ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V4->text());
    if((ui->V4->text().contains("+"))or(ui->V4->text().contains("-"))or
    (ui->V4->text().contains("*"))or(ui->V4->text().contains("/"))){
     ui->Result_Show_2->setText(ui->Result_Show_2->text()+"("+ui->V4->text()+")");
    } else {
    ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V4->text());
    }
}

else
if ((Strok[i]==ui->P5->text())&&(ui->P5->text()!="")){
//ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V5->text());
    if((ui->V5->text().contains("+"))or(ui->V5->text().contains("-"))or
    (ui->V5->text().contains("*"))or(ui->V5->text().contains("/"))){
     ui->Result_Show_2->setText(ui->Result_Show_2->text()+"("+ui->V5->text()+")");
    } else {
    ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V5->text());
    }
}

else
if ((Strok[i]==ui->P6->text())&&(ui->P6->text()!="")){
//ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V6->text());
    if((ui->V6->text().contains("+"))or(ui->V6->text().contains("-"))or
    (ui->V6->text().contains("*"))or(ui->V6->text().contains("/"))){
     ui->Result_Show_2->setText(ui->Result_Show_2->text()+"("+ui->V6->text()+")");
    } else {
    ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V6->text());
    }
}

else
if ((Strok[i]==ui->P7->text())&&(ui->P7->text()!="")){
//ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V7->text());
    if((ui->V7->text().contains("+"))or(ui->V7->text().contains("-"))or
    (ui->V7->text().contains("*"))or(ui->V7->text().contains("/"))){
        //
     ui->Result_Show_2->setText(ui->Result_Show_2->text()+"("+ui->V7->text()+")");
    } else {
    ui->Result_Show_2->setText(ui->Result_Show_2->text()+ui->V7->text());
    }
}

else
if ((Strok[i]=="x")&&(ui->Result_Show->text().contains("x"))){
ui->Result_Show_2->setText(ui->Result_Show_2->text()+ znachX);
}

else {
ui->Result_Show_2->setText(ui->Result_Show_2->text() + Strok[i]);
}
}
if(PeremEst){
ui->Result_Show_22->textCursor().insertText('\n'+ui->Result_Show_2->text()+"=");
Strok= ui->Result_Show_2->text();
}
}
ui->Result_Show_2->setText(Strok);
ui->Result_Show_22->textCursor().insertText("\n");
ui->Result_Show_22->textCursor().insertText("\n");
}


// /////////////////////////////////////////////////////////////////////////////////////

ui->Result_Show_2->setText(Strok);
if (ui->Result_Show_2->text().contains("(")){
ui->Result_Show_22->textCursor().insertText("Находим значение в скобках, и раскрываем их: ");
ui->Result_Show_22->textCursor().insertText("\n");
ui->Result_Show_22->textCursor().insertText(ui->Result_Show_2->text()+"=");
ui->Result_Show_22->textCursor().insertText("\n");
}
while (ui->Result_Show_2->text().contains("(")){
//15+(4*5-27/3+19)-12
KolSkobokL=0;
for(int i=0;i<=ui->Result_Show_2->text().length()-1;i++){
if(ui->Result_Show_2->text()[i]==("(")) {
KolSkobokL++;
}
}
KolSkobokR=KolSkobokL;
int KolMinus =2;

int xi=0; // место в строке последней "("
int y=0; // кол-во найденных закрывающихся скобок ")"
int yi=0; // место в строке ближайшей ")"
QString RK1=""; // строка символов до последней "("
QString RK2=""; // строка символов в раскрываемых скобках
QString RK3=""; // строка всех символов после нужных скобок
QString STR = ui->Result_Show_2->text();
for(int i = 0;i<=ui->Result_Show_2->text().length();i++){
if(STR[i]=="("){
xi=i;
}
}  // находим положение нужных скобок

for (int i=0;i<xi;i++){
RK1=RK1+STR[i];
}
if (RK1=="("){
RK1="";
}

bool K=false;
for(int i=xi;i<=ui->Result_Show_2->text().length();i++){
if ((STR[i]==")")&&(!K)){
y++;
K=true;
yi=i;
}
}


for(int i=xi+1;i<=yi-1;i++){
RK2=RK2+STR[i];
}
RK2.replace("(","");
RK2.replace(")","");
for(int i=yi;i<=STR.length();i++){
RK3=RK3+STR[i];
}
RK3.replace(" ","");
if (RK3==")"){
RK3="";
} else{
QString RK33;
for(int i=1;i<=RK3.length();i++){
RK33=RK33+RK3[i];
}
RK3=RK33;
RK3.replace(" ","");
}


KolSkobokR--;
KolSkobokL=KolSkobokR;
ui->RK->setText("RK1="+ RK1 + " RK2=" + RK2 +" RK3=" + RK3);
QString REZ=RK2;
ui->Result_Show_2->setText(REZ);



while(REZ.contains("^")){
int I=0;
int p1=0;
bool Zn=false;
for(int p=0;p<REZ.length()-1;p++){
if ((REZ[p]=="^")&&(!Zn)){
Zn=true;
I=p;
}
p1++;
}
QString a2="";
int A2=I;
while(((REZ[A2+1]==".")or(REZ[A2+1].isDigit()))&&(A2<p1)){
A2++;
a2=a2+REZ[A2];
}
QString a1="";
int A1=I;
while((A1-1>=0)&&((REZ[A1-1].isDigit())or(REZ[A1-1]=="."))){
A1--;
a1=REZ[A1]+a1;
}
double b1=a1.toDouble();
double b2=a2.toDouble();
double b3=0;
QString B3="";
if(REZ[I]=="^"){
b3=pow(b1,b2);
}
B3=QString::number(b3);

QString After="";
for(int i=A2+1;i<=p1;i++){
After[i]=REZ[i];
}
After.replace( " ", "" );

QString Before="";
for(int i =0;i<A1;i++){
Before[i]=REZ[i];
}
Before.replace( " ", "" );
B3.replace(" ","");
REZ=Before+B3+After;

ui->RK11->setText("Всего символов в строке " +QString::number(p1) + " | "+a1+
" | " +a2+"="+B3 +"|До: "+Before+ " |После:"+After+"    "+REZ);
}

//


while((REZ.contains("*"))or(REZ.contains("/"))){
int I=0;
int p1=0;
bool Zn=false;
for(int p=0;p<REZ.length()-1;p++){
if (((REZ[p]=="*")or(REZ[p]=="/"))&&(!Zn)){
Zn=true;
I=p;
}
p1++;
}
QString a2="";
int A2=I;
while(((REZ[A2+1].isDigit())&&(A2<p1))or(REZ[A2+1]==".")or((REZ[A2+1]=="-")&&((REZ[A2]=="*")or
(REZ[A2]=="/")))){
A2++;
a2=a2+REZ[A2];
}
QString a1="";
int A1=I;
while((A1-1>=0)&&((REZ[A1-1].isDigit())or(REZ[A1-1]=="."))){
A1--;
a1=REZ[A1]+a1;
}
double b1=a1.toDouble();
double b2=a2.toDouble();
double b3=0;
QString B3="";
if(REZ[I]=="*"){
b3=b1*b2;
}
if(REZ[I]=="/"){
b3=b1/b2;
}
B3=QString::number(b3);

QString After="";
for(int i=A2+1;i<=p1;i++){
After[i]=REZ[i];
}
After.replace( " ", "" );

QString Before="";
for(int i =0;i<A1;i++){
Before[i]=REZ[i];
}
Before.replace( " ", "" );
B3.replace(" ","");
REZ=Before+B3+After;

ui->RK11->setText("Всего символов в строке " +QString::number(p1) + " | "+a1+
" | " +a2+"="+B3 +"|До: "+Before+ " |После:"+After+"    "+REZ);
}

//15+(4*5-27/3+19)-12

KolMinus=0;
for(int i=0;i<=REZ.length();i++){
if(REZ[i]=="-"){
KolMinus++;
}
}

while((REZ.contains("+"))or(KolMinus>0)){
int I=0;
int p1=0;
bool Zn=false;
for(int p=0;p<REZ.length()-1;p++){
if (((REZ[p]=="+")or(REZ[p]=="-"))&&(!Zn)){
Zn=true;
I=p;
}
p1++;
}
QString a2="";
int A2=I;
while(((REZ[A2+1].isDigit())&&(A2<p1))or(REZ[A2+1]==".")or((REZ[A2+1]=="-")&&((REZ[A2]=="-")or
(REZ[A2]=="+")))){
A2++;
a2=a2+REZ[A2];
}
QString a1="";
int A1=I;
while((A1-1>=0)&&((REZ[A1-1].isDigit())or(REZ[A1-1]=="."))){
A1--;
a1=REZ[A1]+a1;
}

double b1=a1.toDouble();
double b2=a2.toDouble();
double b3=0;
QString B3="";
if(REZ[I]=="+"){
b3=b1+b2;
}
if(REZ[I]=="-"){
b3=b1-b2;
}
B3=QString::number(b3);

QString After="";
for(int i=A2+1;i<=p1;i++){
After[i]=REZ[i];
}
After.replace( " ", "" );

QString Before="";
for(int i =0;i<A1;i++){
Before[i]=REZ[i];
}
Before.replace( " ", "" );
B3.replace(" ","");
REZ=Before+B3+After;
REZ.replace("--","-");
REZ.replace("+-","-");
REZ.replace("-+","-");
KolMinus=0;
for(int i=0;i<=REZ.length();i++){
if(REZ[i]=="-"){
KolMinus++;
}
}

ui->RK11->setText("Всего символов в строке " +QString::number(p1) + " | "+a1+
" | " +a2+"="+B3 +"|До: "+Before+ " |После:"+After+"    "+REZ);
}

ui->Result_Show_2->setText(RK1+REZ+RK3);
if ((ui->Result_Show_2->text().contains("*"))or(KolMinus>1)or
(ui->Result_Show_2->text().contains("+"))or(ui->Result_Show_2->text().contains("/")))
{
ui->Result_Show_22->textCursor().insertText(ui->Result_Show_2->text()+"=");
ui->Result_Show_22->textCursor().insertText("\n");
} else {
ui->Result_Show_22->textCursor().insertText(ui->Result_Show_2->text());
ui->Result_Show_22->textCursor().insertText("\n");
ui->Result_Show_22->textCursor().insertText("\n");
//ui->Result_Show_22->textCursor().insertText("Ответ: " +ui->Result_Show_2->text());
}

QString RL=ui->Result_Show_2->text();
RL.replace(" ","") ;
ui->Result_Show_2->setText(RL);
}
//

if (!ui->Result_Show_2->text().contains("(")){
ui->Result_Show_22->textCursor().insertText("\n");
ui->Result_Show_22->textCursor().insertText("Ответ: ");
    QString REZ = ui->Result_Show_2->text();
while(REZ.contains("^")){
int I=0;
int p1=0;
bool Zn=false;
for(int p=0;p<REZ.length()-1;p++){
if ((REZ[p]=="^")&&(!Zn)){
Zn=true;
I=p;
}
p1++;
}
QString a2="";
int A2=I;
while(((REZ[A2+1]==".")or(REZ[A2+1].isDigit()))&&(A2<p1)){
A2++;
a2=a2+REZ[A2];
}
QString a1="";
int A1=I;
while((A1-1>=0)&&((REZ[A1-1].isDigit())or(REZ[A1-1]=="."))){
A1--;
a1=REZ[A1]+a1;
}
double b1=a1.toDouble();
double b2=a2.toDouble();
double b3=0;
QString B3="";
if(REZ[I]=="^"){
b3=pow(b1,b2);
}
B3=QString::number(b3);
QString After="";
for(int i=A2+1;i<=p1;i++){
After[i]=REZ[i];
}
After.replace( " ", "" );
QString Before="";
for(int i =0;i<A1;i++){
Before[i]=REZ[i];
}
Before.replace( " ", "" );
B3.replace(" ","");
REZ=Before+B3+After;
//ui->Result_Show_22->textCursor().insertText(REZ);
}
while((REZ.contains("*"))or(REZ.contains("/"))){
int I=0;
int p1=0;
bool Zn=false;
for(int p=0;p<REZ.length()-1;p++){
if (((REZ[p]=="*")or(REZ[p]=="/"))&&(!Zn)){
Zn=true;
I=p;
}
p1++;
}
QString a2="";
int A2=I;
while(((REZ[A2+1].isDigit())&&(A2<p1))or(REZ[A2+1]==".")or((REZ[A2+1]=="-")&&((REZ[A2]=="*")or
(REZ[A2]=="/")))){
A2++;
a2=a2+REZ[A2];
}
QString a1="";
int A1=I;
while((A1-1>=0)&&((REZ[A1-1].isDigit())or(REZ[A1-1]=="."))){
A1--;
a1=REZ[A1]+a1;
}
double b1=a1.toDouble();
double b2=a2.toDouble();
double b3=0;
QString B3="";
if(REZ[I]=="*"){
b3=b1*b2;
}
if(REZ[I]=="/"){
b3=b1/b2;
}
B3=QString::number(b3);

QString After="";
for(int i=A2+1;i<=p1;i++){
After[i]=REZ[i];
}
After.replace( " ", "" );

QString Before="";
for(int i =0;i<A1;i++){
Before[i]=REZ[i];
}
Before.replace( " ", "" );
B3.replace(" ","");
REZ=Before+B3+After;
}

bool Z = true;
while((REZ.contains("+"))or((REZ.contains("-"))&Z)){
int I=0;
int p1=0;
bool Zn=false;
for(int p=0;p<REZ.length()-1;p++){
if (((REZ[p]=="+")or(REZ[p]=="-"))&&(!Zn)){
Zn=true;
I=p;
}
p1++;
}
QString a2="";
int A2=I;
while(((REZ[A2+1].isDigit())&&(A2<p1))or(REZ[A2+1]==".")or((REZ[A2+1]=="-")&&((REZ[A2]=="-")or
(REZ[A2]=="+")))){
A2++;
a2=a2+REZ[A2];
}
QString a1="";
int A1=I;
while((A1-1>=0)&&((REZ[A1-1].isDigit())or(REZ[A1-1]=="."))){
A1--;
a1=REZ[A1]+a1;
}

double b1=a1.toDouble();
double b2=a2.toDouble();
double b3=0;
QString B3="";
if(REZ[I]=="+"){
b3=b1+b2;
}
if(REZ[I]=="-"){
if (a1==""){
b3=-b2;
Z=false;
} else {
b3=b1-b2;
}
}
B3=QString::number(b3);

QString After="";
for(int i=A2+1;i<=p1;i++){
After[i]=REZ[i];
}
After.replace( " ", "" );

QString Before="";
for(int i =0;i<A1;i++){
Before[i]=REZ[i];
}
Before.replace( " ", "" );
B3.replace(" ","");
REZ=Before+B3+After;
REZ.replace("--","-");
REZ.replace("+-","-");
REZ.replace("-+","-");
}
//
ui->Result_Show_22->textCursor().insertText(REZ);
}
//
}
}

void MainWindow::on_pushButton_clear_clicked()
{
ui->Result_Show->setText("");
ui->Result_Show_2->setText("");
ui->LabelWrong->setText("");
ui->vvodX->setText("");
znak = false;
tochka = false;
numX = true;
chislo = true;
lastClickSkobka = 0;
lastClickChislo = false;
lastClickX=false;
pos3=0;
ui->P1->clear();
ui->P2->clear();
ui->P3->clear();
ui->P4->clear();
ui->P5->clear();
ui->P6->clear();
ui->P7->clear();
ui->V1->clear();
ui->V2->clear();
ui->V3->clear();
ui->V4->clear();
ui->V5->clear();
ui->V6->clear();
ui->V7->clear();
ui->Shtorka->move(560,140);
ui->Shtorka->setFixedHeight(241);
ui->Result_Show_22->clear();
}


void MainWindow::on_pushButton_V_clicked()
{
 QTime time;
pos3++;
if (pos3<=7)
{

if(pos3==1){
time.start();
for(;time.elapsed() < 100;){
                           }
ui->Shtorka->move(560,200);
ui->Shtorka->setFixedHeight(181);


} else{
time.start();
for(;time.elapsed() < 100;){
                           }
ui->Shtorka->move(560,170+pos3*30);
ui->Shtorka->setFixedHeight(211-pos3*30);

     }
}
}



void MainWindow::on_Result_Show_editingFinished()
{
ClickPole=1;
}

void MainWindow::on_vvodX_editingFinished()
{
ClickPole=2;
}

void MainWindow::on_Vv_clicked()
{
if(ui->P1->text()!="")
    if(numX==true){
znak=true;
tochka=false;
numX=false;
chislo=false;
lastClickSkobka=0;
lastClickChislo=true;
lastClickX = true;
ui->Result_Show->setText(ui->Result_Show->text()+ui->P1->text());
    } else {

 if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
ui->Result_Show->setText(ui->Result_Show->text()+"*"+ui->P1->text());
znak=true;
tochka=false;
numX=false;
chislo=false;
lastClickSkobka=0;
lastClickChislo=true;
lastClickX = true;
}
}
}

void MainWindow::on_Vv_2_clicked()
{
if(ui->P2->text()!="")
if(numX==true){
znak=true;
tochka=false;
numX=false;
chislo=false;
lastClickSkobka=0;
lastClickChislo=true;
lastClickX = true;
ui->Result_Show->setText(ui->Result_Show->text()+ui->P2->text());
}else if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
ui->Result_Show->setText(ui->Result_Show->text()+"*"+ui->P2->text());
znak=true;
tochka=false;
numX=false;
chislo=false;
lastClickSkobka=0;
lastClickChislo=true;
lastClickX = true;
}
}
void MainWindow::on_Vv_3_clicked()
{
if(ui->P3->text()!="")
    if(numX==true){
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    ui->Result_Show->setText(ui->Result_Show->text()+ui->P3->text());
    }else if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
    ui->Result_Show->setText(ui->Result_Show->text()+"*"+ui->P3->text());
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    }
}

void MainWindow::on_Vv_4_clicked()
{
if(ui->P4->text()!="")
    if(numX==true){
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    ui->Result_Show->setText(ui->Result_Show->text()+ui->P4->text());
    }else if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
    ui->Result_Show->setText(ui->Result_Show->text()+"*"+ui->P4->text());
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    }
}

void MainWindow::on_Vv_5_clicked()
{
if(ui->P5->text()!="")
    if(numX==true){
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    ui->Result_Show->setText(ui->Result_Show->text()+ui->P5->text());
    }else if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
    ui->Result_Show->setText(ui->Result_Show->text()+"*"+ui->P5->text());
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    }
}

void MainWindow::on_Vv_6_clicked()
{
if(ui->P6->text()!="")
    if(numX==true){
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    ui->Result_Show->setText(ui->Result_Show->text()+ui->P6->text());
    }else if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
    ui->Result_Show->setText(ui->Result_Show->text()+"*"+ui->P6->text());
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    }
}

void MainWindow::on_Vv_7_clicked()
{
if(ui->P7->text()!="")
    if(numX==true){
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    ui->Result_Show->setText(ui->Result_Show->text()+ui->P7->text());
    }else if ((lastClickChislo)or(lastClickSkobka==1)or(lastClickX)){
    ui->Result_Show->setText(ui->Result_Show->text()+"*"+ui->P7->text());
    znak=true;
    tochka=false;
    numX=false;
    chislo=false;
    lastClickSkobka=0;
    lastClickChislo=true;
    lastClickX = true;
    }
}

void MainWindow::on_vvodX_returnPressed()
{
ClickPole=2;
}

void MainWindow::on_Result_Show_returnPressed()
{
ClickPole=1;
}

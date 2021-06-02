#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digits_numbers();

    void on_pushButton_dot_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_mult_clicked();
    void on_pushButton_devide_clicked();
    void on_pushButton_exp_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_sl_clicked();
    void on_pushButton_sp_clicked();
    void on_pushButton_del_clicked();
    void on_pushButton_Res_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_V_clicked();
    void on_Result_Show_editingFinished();
    void on_vvodX_editingFinished();
//    void on_pushButton_clicked();
    void on_Vv_clicked();
    void on_Vv_2_clicked();
    void on_Vv_3_clicked();
    void on_Vv_4_clicked();
    void on_Vv_5_clicked();
    void on_Vv_6_clicked();
    void on_Vv_7_clicked();
    void on_vvodX_returnPressed();
    void on_Result_Show_returnPressed();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *e) override;

private slots:


    /*void slotButton1();
    void slotButton2();
    void slotButton3();
    void slotButton4();
    void slotButton5();
    void slotButton6();
    void slotButton7();
    void slotButton8();
    void slotButton9();
    void slotButton0();
    void slotButton11();
    void slotButton12();
    void slotButton13();
    void slotButton14();
    void slotButton15();
*/



    void on_pushButton_delit_clicked();

    void on_pushButton_umnozhit_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    double Show();

    void on_pushButton_ravno_clicked();

    void on_pushButton_AC_clicked();

    void on_pushButton_plusminus_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_procent_clicked();

    void on_pushButton_log10_clicked();

    void on_pushButton_1delitx_clicked();

    void on_pushButton_kdadrat_clicked();

    void on_pushButton_sqrt_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

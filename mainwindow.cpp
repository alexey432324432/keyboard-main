#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <locale>
#include <math.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}






string str;
bool flag = false;
QString sos;
QString sos_2;
string boom;
double digit = 0;
bool youCan = false;



string* function_for_QT_delenieUmnozhenie(string str)
{
    string* mass = new string[100];
    int j = 0;
    for (int i = 0; i < mass->size() + 1; i++)
    {
        mass[i] = "";
    }
    for (int i = 0; i < str.length() + 1; i++)
    {
        if (str[i] == '+')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else if (str[i] == '-')
        {
            if (i == 0)
            {
                mass[j] = str[i];
            }
            else
            {
                j++;
                mass[j] = str[i];
                j++;
            }

        }
        else if (str[i] == '*')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else if (str[i] == '/')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else if (str[i] == '%')
        {
            j++;
            mass[j] = str[i];
            j++;
        }
        else
        {
            mass[j] = mass[j] + str[i];
        }
    }


link:;
    for (int i = 0; (i < mass->length() + 2); i++)
    {
        if (mass[i] == "*")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) * stod(mass[i + 1]));
                for (int b = i + 2; b < 100; b++)
                                {
                                    mass[b - 2] = mass[b];
                                    mass[b] = "";
                                }
                                goto link;
                }
        if (mass[i] == "/")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) / stod(mass[i + 1]));
            if (i <= mass->length() - 2)
            {
                for (int b = i + 2; b < 100; b++)
                {
                    mass[b - 2] = mass[b];
                    mass[b] = "";
                }
                goto link;
            }
        }
        if (mass[i] == "%")
                {
                    mass[i - 1] = to_string(stoi(mass[i - 1]) % stoi(mass[i + 1]));
                    for (int b = i + 2; b < mass->length(); b++)
                    {
                        mass[b - 2] = mass[b];
                        mass[b] = "";
                    }

                    goto link;
                }
    }
    return mass;
}



double function_for_QT(string str)
{
    string* mass = new string[100];
    mass = function_for_QT_delenieUmnozhenie(str);
    double result = 0;
    int j = 0;
link:;
    if (mass[0] == "-")
    {
        mass[0] = "-" + mass[1];
    }

    for (int i = 0; i < mass->size() + 2; i++)
    {
        if (mass[i] == "+")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) + stod(mass[i + 1]));
            if (i <= mass->length() - 2)
            {
                for (int b = i + 2; b < 100; b++)
                {
                    mass[b - 2] = mass[b];
                    mass[b] = "";
                }
                goto link;
            }
        }
        else if (mass[i] == "-")
        {
            mass[i - 1] = to_string(stod(mass[i - 1]) - stod(mass[i + 1]));

            if (i <= mass->length() - 2)// ???????????? ??????????
            {
                for (int b = i + 2; b < 100; b++)
                {
                    mass[b - 2] = mass[b];
                    mass[b] = "";
                }
                goto link;
            }
        }
    }
    result = stod(mass[0]);
    for (int i = 1; i <= (mass->size() - 2); i = i + 2)
    {
        if (mass[i] == "+")
        {
            result = result + stod(mass[i + 1]);
        }
        if (mass[i] == "-")
        {
            result = result - stod(mass[i + 1]);
        }
    }
    return result;
}




double MainWindow::Show()
{

        digit = function_for_QT(str);
        boom = to_string(digit);
        sos_2 = QString::fromStdString(boom);
        ui->label_2->setText(sos_2);
        return digit;
}

void MainWindow::on_pushButton_delit_clicked()
{
    if (flag == true)
    {
 Show();
        str = str + "/";
        sos = QString::fromStdString(str);

        ui->label->setText(sos);

}

}

void MainWindow::on_pushButton_umnozhit_clicked()
{
    if (flag == true)
    {
        Show();
        str = str + "*";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);




        flag = false;

    }
}

void MainWindow::on_pushButton_minus_clicked()
{
    if (flag == true)
    {
 Show();
        str = str + "-";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);




        flag = false;

    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    if (flag == true)
    {
        Show();

        str = str + "+";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);


        flag = false;
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    flag = true;
    str = str + "1";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
}

void MainWindow::on_pushButton_2_clicked()
{
    flag = true;
    str = str + "2";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
}

void MainWindow::on_pushButton_3_clicked()
{
    flag = true;
    str = str + "3";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_4_clicked()
{
    flag = true;
    str = str + "4";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_5_clicked()
{
    flag = true;
    str = str + "5";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_6_clicked()
{
    flag = true;
    str = str + "6";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_7_clicked()
{
    flag = true;
    str = str + "7";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_8_clicked()
{
    flag = true;
    str = str + "8";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_9_clicked()
{
    flag = true;
    str = str + "9";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

void MainWindow::on_pushButton_0_clicked()
{
    flag = true;
    str = str + "0";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);

}

bool canOrNot(string str)
{


    //str = to_string(digit);
    //sos = QString::fromStdString(str);
    //ui->label->setText(sos);


    bool testing = true;
    for (int i = 0; i < str.length() + 1; i++)
    {
        if  ((str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') && i > 0)
        {
            testing = false;
            break;
        }
    }
    if (str.length() == 0) return false;
    else return testing;
}


void MainWindow::on_pushButton_ravno_clicked()
{
    if (flag == true)
    {
    digit = function_for_QT(str);
    str = to_string(digit);
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
    ui->label_2->setText(sos);
    }
}

void MainWindow::on_pushButton_AC_clicked()
{
    str = "";
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
    ui->label_2->setText(sos);
}

void MainWindow::on_pushButton_plusminus_clicked()
{

    QString labal = ui->label->text();
    if  (canOrNot(labal.toStdString()))
    {
    digit = labal.toDouble();
    digit = digit * (-1);
    str = to_string(digit);
    sos = QString::fromStdString(str);
    ui->label->setText(sos);
    ui->label_2->setText(sos);
    }
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (flag == true)
    {
        str = str + ".";
        sos = QString::fromStdString(str);
        ui->label->setText(sos);
        flag = false;
    }
}

void MainWindow::on_pushButton_procent_clicked()
{
    if (flag == true)
    {
    QString labal = ui->label->text();
    if  (canOrNot(labal.toStdString()))
    {
        digit = labal.toDouble();
        digit = digit / 100;
        str = to_string(digit);
        sos = QString::fromStdString(str);
        ui->label->setText(sos);
        ui->label_2->setText(sos);
    }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_1)
        MainWindow::on_pushButton_1_clicked();

    if (e->key() == Qt::Key_2)
        MainWindow::on_pushButton_2_clicked();
    if (e->key() == Qt::Key_3)
        MainWindow::on_pushButton_3_clicked();
    if (e->key() == Qt::Key_4)
        MainWindow::on_pushButton_4_clicked();
    if (e->key() == Qt::Key_5)
        MainWindow::on_pushButton_5_clicked();
    if (e->key() == Qt::Key_6)
        MainWindow::on_pushButton_6_clicked();
    if (e->key() == Qt::Key_7)
        MainWindow::on_pushButton_7_clicked();
    if (e->key() == Qt::Key_8)
        MainWindow::on_pushButton_8_clicked();
    if (e->key() == Qt::Key_9)
        MainWindow::on_pushButton_9_clicked();
    if (e->key() == Qt::Key_0)
        MainWindow::on_pushButton_0_clicked();
    if (e->key() == Qt::Key_Minus)
        MainWindow::on_pushButton_minus_clicked();
    if (e->key() == Qt::Key_Plus)
        MainWindow::on_pushButton_plus_clicked();
    if (e->key() == Qt::Key_Backslash)
        MainWindow::on_pushButton_delit_clicked();
    if (e->key() == Qt::Key_Equal)
        MainWindow::on_pushButton_ravno_clicked();
    if (e->key() == Qt::Key_Enter)
        MainWindow::on_pushButton_ravno_clicked();
    if (e->key() == Qt::Key_W)
        MainWindow::on_pushButton_umnozhit_clicked();
    if (e->key() == Qt::Key_O)
            MainWindow::on_pushButton_dot_clicked();
    if (e->key() == Qt::Key_Delete)
        MainWindow::on_pushButton_AC_clicked();
}


void MainWindow::on_pushButton_log10_clicked()
{

        Show();
        if (flag == true)
        {
        QString labal = ui->label->text();
        if  (canOrNot(labal.toStdString()))
        {
            digit = labal.toDouble();

            digit = log10(digit);
            str = to_string(digit);
            sos = QString::fromStdString(str);
            ui->label->setText(sos);


        }
        }
}


void MainWindow::on_pushButton_1delitx_clicked()
{
    if (flag == true)
    {
        QString labal = ui->label->text();
        if  (canOrNot(labal.toStdString()))
        {
            digit = labal.toDouble();

            digit = 1 / digit;
            str = to_string(digit);
            sos = QString::fromStdString(str);
            ui->label->setText(sos);
        }
}

}


void MainWindow::on_pushButton_kdadrat_clicked()
{
    if (flag == true)
    {
        Show();
        QString labal = ui->label->text();
        if  (canOrNot(labal.toStdString()))
        {
            digit = labal.toDouble();

            digit = digit * digit;
            str = to_string(digit);
            sos = QString::fromStdString(str);
            ui->label->setText(sos);

        }
        }
}


void MainWindow::on_pushButton_sqrt_clicked()
{
        Show();
        if (flag == true)
        {
        QString labal = ui->label->text();
        if  (canOrNot(labal.toStdString()))
        {
            digit = labal.toDouble();

            digit = sqrt(digit);
            str = to_string(digit);
            sos = QString::fromStdString(str);
            ui->label->setText(sos);

}
        }
}


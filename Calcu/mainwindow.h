#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void clear();
    void add();
    void subtract();
    void multiply();
    void divide();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    void equals();
    void zero();

private:
   QLabel * label;
   QPushButton *clear_button;
   QPushButton *equal_button;
   QPushButton *add_button;
   QPushButton *subtract_button;
   QPushButton *mulltiply_button;
   QPushButton *divide_button;
   QPushButton *zero_button;
   QPushButton *one_button;
   QPushButton *two_button;
   QPushButton *three_button;
   QPushButton *four_button;
   QPushButton *five_button;
   QPushButton *six_button;
   QPushButton *seven_button;
   QPushButton *eight_button;
   QPushButton *nine_button;

   QString  value;
   QString  total;
   bool add_f;
   bool sub_f;
   bool did_f;
   bool mul_f;
};

#endif // MAINWINDOW_H

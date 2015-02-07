#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtCore"
#include "QCoreApplication"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    this->add_f=false;
    this->did_f=false;
    this->sub_f=false;
    this->mul_f=false;

    this->total="0";
    this->value="";
    this->label=new QLabel("0",this);
    this->label->setFont(QFont("Arial",20,QFont::Bold));
    this->label->setGeometry(QRect(QPoint(5,75),QSize(390,100)));
    this->label->setStyleSheet("QLabel{background-color:white; color:blue; qproperty-alignment: AlignCenter;}");

    clear_button=new QPushButton("Clear",this);
    this->clear_button->setGeometry(QRect(QPoint(15,400),QSize(50,30)));
    connect(this->clear_button,SIGNAL(released()),this,SLOT(clear()));
    this->clear_button->setFont(QFont("Arial",10,QFont::Bold));

    this->equal_button=new QPushButton("=",this);
    this->equal_button->setGeometry(QRect(QPoint(35,350),QSize(30,30)));
    connect(this->equal_button,SIGNAL(released()),this,SLOT(equals()));

    this->mulltiply_button=new QPushButton("x",this);
    this->mulltiply_button->setGeometry(QRect(QPoint(85,350),QSize(30,30)));
    connect(this->mulltiply_button,SIGNAL(released()),this,SLOT(multiply()));


    this->add_button=new QPushButton("+",this);
    this->add_button->setGeometry(QRect(QPoint(135,350),QSize(30,30)));
    connect(this->add_button,SIGNAL(released()),this,SLOT(add()));

    this->subtract_button=new QPushButton("-",this);
    this->subtract_button->setGeometry(QRect(QPoint(85,400),QSize(30,30)));
    connect(this->subtract_button,SIGNAL(released()),this,SLOT(subtract()));

    this->divide_button=new QPushButton("/",this);
    this->divide_button->setGeometry(QRect(QPoint(135,400),QSize(30,30)));
    connect(this->divide_button,SIGNAL(released()),this,SLOT(divide()));



    this->zero_button=new QPushButton("0",this);
    this->zero_button->setGeometry(QRect(QPoint(255,300),QSize(30,30)));
    connect(this->zero_button,SIGNAL(released()),this,SLOT(zero()));


    this->one_button=new QPushButton("1",this);
    this->one_button->setGeometry(QRect(QPoint(205,350),QSize(30,30)));
    connect(this->one_button,SIGNAL(released()),this,SLOT(one()));

    this->two_button=new QPushButton("2",this);
    this->two_button->setGeometry(QRect(QPoint(255,350),QSize(30,30)));
    connect(this->two_button,SIGNAL(released()),this,SLOT(two()));

    this->three_button=new QPushButton("3",this);
    this->three_button->setGeometry(QRect(QPoint(305,350),QSize(30,30)));
    connect(this->three_button,SIGNAL(released()),this,SLOT(three()));

    this->four_button=new QPushButton("4",this);
    this->four_button->setGeometry(QRect(QPoint(205,400),QSize(30,30)));
    connect(this->four_button,SIGNAL(released()),this,SLOT(four()));

    this->five_button=new QPushButton("5",this);
    this->five_button->setGeometry(QRect(QPoint(255,400),QSize(30,30)));
    connect(this->five_button,SIGNAL(released()),this,SLOT(five()));

    this->six_button=new QPushButton("6",this);
    this->six_button->setGeometry(QRect(QPoint(305,400),QSize(30,30)));
    connect(this->six_button,SIGNAL(released()),this,SLOT(six()));

    this->seven_button=new QPushButton("7",this);
    this->seven_button->setGeometry(QRect(QPoint(205,450),QSize(30,30)));
    connect(this->seven_button,SIGNAL(released()),this,SLOT(seven()));

    this->eight_button=new QPushButton("8",this);
    this->eight_button->setGeometry(QRect(QPoint(255,450),QSize(30,30)));
    connect(this->eight_button,SIGNAL(released()),this,SLOT(eight()));

    this->nine_button=new QPushButton("9",this);
    this->nine_button->setGeometry(QRect(QPoint(305,450),QSize(30,30)));
    connect(this->nine_button,SIGNAL(released()),this,SLOT(nine()));

   // qDebug("%d",this->value.toInt());
}

void MainWindow::zero()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }

    if(this->value!="")
    {
    this->value=value+"0";
    this->label->setText(this->value);
    }
    else
    {
        this->label->setText("0");
    }
}

void MainWindow::equals()
{
    if(this->add_f==true)
    {
        double sum=this->total.toDouble()+this->value.toDouble();
        this->total=QString::number(sum);
        this->label->setText(this->total);
        this->add_f=false;
        this->value="";
         qDebug("!!!%f",sum);
    }

    else if(this->sub_f==true)
    {
       double sum=this->total.toDouble()-this->value.toDouble();
        this->total=QString::number(sum);
        this->label->setText(this->total);
        this->sub_f=false;
        this->value="";
         qDebug("!!!%f",sum);
    }

   else if(this->mul_f==true)
    {
       double sum=this->total.toDouble()*this->value.toDouble();
        this->total=QString::number(sum);
        this->label->setText(this->total);
        this->mul_f=false;
        this->value="";
         qDebug("!!!%f",sum);
    }

   else if(this->did_f==true)
    {
        double sum=this->total.toDouble()/this->value.toDouble();
        this->total=QString::number(sum);
        this->label->setText(this->total);
        this->did_f=false;
        this->value="";
         qDebug("!!!%f",sum);
    }


}
void MainWindow::clear()
{
    this->total="0";
    this->value="";
    this->label->setText("0");


}
void MainWindow::add()
{

    double sum=this->total.toDouble()+this->value.toDouble();
    this->total=QString::number(sum);
    this->label->setText("+");
    this->value="";
    this->add_f=true;
}

void MainWindow::subtract()
{
    double sum=this->total.toDouble()+this->value.toDouble();
        this->total=QString::number(sum);

    this->label->setText("-");
    this->value="";
    this->sub_f=true;
}

void MainWindow::multiply()
{
    double sum=this->total.toDouble()+this->value.toDouble();
        this->total=QString::number(sum);
    this->label->setText("x");
    this->value="";
    this->mul_f=true;
}
void MainWindow::divide()
{
    double sum=this->total.toDouble()+this->value.toDouble();
    this->total=QString::number(sum);
 qDebug("????%f",sum);
    this->label->setText("/");
    this->value="";
    this->did_f=true;
}
void MainWindow:: one()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"1";
    this->label->setText(value);
}
void MainWindow::two()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"2";
    this->label->setText(value);

}
void MainWindow::three()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"3";
    this->label->setText(value);
}
void MainWindow::four()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"4";
    this->label->setText(value);
}
void MainWindow::five()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"5";
    this->label->setText(value);
}
void MainWindow::six()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"6";
    this->label->setText(value);
}
void MainWindow::seven()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"7";
    this->label->setText(value);
}
void MainWindow::eight()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"8";
    this->label->setText(value);
}
void MainWindow::nine()
{
    if(add_f==false&&sub_f==false&&did_f==false&&mul_f==false)
    {
        this->total="0";
    }
    value=value+"9";
    this->label->setText(value);
}

MainWindow::~MainWindow()
{

}

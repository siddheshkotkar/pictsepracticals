#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<iostream>
#include<math.h>
QImage img(500,500,QImage::Format_RGB888);

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


void MainWindow::on_Calculate_clicked()
{
    int x1=ui->plainTextEdit->toPlainText().toInt();
    int y1=ui->plainTextEdit_2->toPlainText().toInt();
    int x2=ui->plainTextEdit_3->toPlainText().toInt();
    int y2=ui->plainTextEdit_4->toPlainText().toInt();
    calculatedda(x1,y1,x2,y2);

    ui->label_5->setPixmap(QPixmap::fromImage(img));
}

void MainWindow :: calculatedda(int x1, int y1,int x2,int y2)
{
//    QPen pen(Qt::blue);
//    pen.setWidth(1);
////     qp->setPen(pen);
    float dx,dy,step,i,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
    {
        step=abs(dx);
    }
    else
    {
        step=abs(dy);
    }
    float xinc,yinc;
    xinc=dx/step;
    yinc=dy/step;
    i=0;
    x=x1;
    y=y1;
    while(i<=step)
    {
        img.setPixel(x,y,qRgb(255,255,255));

//        img.res
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void MainWindow:: calculatebresenham(int x1,int y1,int r)
{
    float x,y,p;
    y=r;
    x=0;
    p=3-(2*r);
    while(x<=y)
    {
        img.setPixel(x1+x,y1+y,qRgb(255,255,255));
        img.setPixel(x1-x,y1+y,qRgb(255,255,255));
        img.setPixel(x1+x,y1-y,qRgb(255,255,255));
        img.setPixel(x1-x,y1-y,qRgb(255,255,255));
        img.setPixel(x1+y,y1+x,qRgb(255,255,255));
        img.setPixel(x1+y,y1-x,qRgb(255,255,255));
        img.setPixel(x1-y,y1+x,qRgb(255,255,255));
        img.setPixel(x1-y,y1-x,qRgb(255,255,255));
        x=x+1;
        if(p<0)
        {
            p=p+(4*x)+6;
        }
        else
        {
            p=p+4*(x-y)+10;
            y=y-1;
        }
    }

}


void MainWindow::on_pushButton_clicked()
{
    int x1,y1,r;
    x1=ui->plainTextEdit->toPlainText().toInt();
    y1=ui->plainTextEdit_2->toPlainText().toInt();
    r=ui->plainTextEdit_5->toPlainText().toInt();
    calculatebresenham(x1,y1,r);
    ui->label_5->setPixmap(QPixmap::fromImage(img));
}

//250,250,100 for outer circle
//250,250,50 for inner circle
//250,150,336,300
//336,300,163,300
//163,300,250,150


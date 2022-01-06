#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QImage>
#include<QColorDialog>
#include<qvector.h>
#include<QMessageBox>
#include<QTime>
QImage img(700,700,QImage::Format_RGB888);
QRgb rgb(qRgb(255,255,255));
struct line
{
    float startx;
    float starty;
    float endx;
    float endy;
};

QVector <line> vect;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_5->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::delaytime(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
        while( QTime::currentTime() < dieTime )
        {
            QCoreApplication::processEvents( QEventLoop::AllEvents, 1000);
        }
}

void MainWindow::dda(int x1, int y1, int x2, int y2,int delay_time=0)
{

//    int delay_time=0
    float dx,dy;
    dx=x2-x1;
    dy=y2-y1;
    float step;
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
    float x,y;
    x=x1;
    y=y1;
    for(int i=0;i<step;i++)
    {
       img.setPixel(x,y,rgb);
       x=x+xinc;
       y=y+yinc;

    }
    ui->label_5->setPixmap(QPixmap::fromImage(img));
    delaytime(delay_time);

}

void MainWindow::scanfill()
{
    float ymin,ymax;
    ymin=vect[0].starty;
    ymax=0;
    int intpoints[10];
    float *m=new float[vect.size()];
    float dy,dx;
    for(int i=0;i<vect.size();i++)
    {
        if(vect[i].starty<ymin)
        {
            ymin=vect[i].starty;
        }
        if(vect[i].endy>ymax)
        {
            ymax=vect[i].endy;
        }
    }
    for(int i=0;i<vect.size();i++)
    {
        dx=vect[i].endx-vect[i].startx;
        dy=vect[i].endy-vect[i].starty;
        if(dy==0)
        {
            m[i]=1.0;
        }
        if(dx==0)
        {
            m[i]=0.0;
        }
        if((dx!=0)&&(dy!=0))
        {
            m[i]=dx/dy;
        }
    }

    for(int y=ymin+1;y<ymax;y++)//starts from ymin+1 and will run till ymax
    {
        int k=0;//for counting intersection points
        for(int i=0;i<vect.size();i++)
        {
            if((vect[i].starty<y && vect[i].endy>y) || (vect[i].starty>y && vect[i].endy<y))
            {
                intpoints[k]=vect[i].startx+(y-vect[i].starty)*m[i];
                k++;
            }
        }


    std::sort(intpoints,&intpoints[k-1]);
    for(int i=0;i<=k-2;i+=2)
    {
        dda(intpoints[i],y,intpoints[i+1],y,1);
    }
   }
    delete [] m;
}




void MainWindow::on_pushButton_clicked()
{
    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    dda(x1,y1,x2,y2,1);
    line temp{x1,y1,x2,y2};
    vect.push_back(temp);
//    ui->label_5->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_2_clicked()
{
    QRgb color(QColorDialog::getColor().rgb());
    rgb=color;
}





void MainWindow::on_pushButton_3_clicked()
{
    if((vect[0].startx==vect[vect.size()-1].endx) && (vect[0].starty==vect[vect.size()-1].endy))
  {
        scanfill();
    }
   else
   {
       QMessageBox message;
       message.information(0,"Error","Please enter valid cordinates for polygon to be closed!");
   }
}


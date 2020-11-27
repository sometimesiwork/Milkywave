#include "widget.h"
#include "ui_widget.h"


#include <QMouseEvent>
#include <math.h>
#include <random>
#include <QMovie>
#include <QLabel>
#include <QSize>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0, 1.4);

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timerAdd = new QTimer(this);
    timerAddPixmap = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&Widget::mover));
    connect(timerAdd, &QTimer::timeout, this, QOverload<>::of(&Widget::addObject));
    connect(timerAddPixmap, &QTimer::timeout, this, QOverload<>::of(&Widget::addObjectPixmap));
    timer->start(1);
    timerAdd->start(5000);
    timerAddPixmap->start(1000);
//    ui->showLabel->setMovie( movie );


//    label->resize(width()*4,height()*2);
    QSize sizeone(1500,1500);
    QSize sizetwo(200,200);
    for (int i = 0;i<200;i++) {
        vectorLabel.append(new QLabel(this));

    }
    for (int i = 0;i<1000;i++) {
        vectorLabelPixmap.append(new QLabel(this));

    }
    movie->setScaledSize(sizeone);
    movietwo->setScaledSize(sizetwo);
    movietwo->start();
    movie->start();


}


Rect::Rect()
{
}

Rect::~Rect()
{
}

Widget::~Widget()
{
    delete ui;
}




Rect::Rect(double m,int j,int g, double k)
{
p = m;
h = g;
w = j;
b = h;
t = k;
}

void Widget::animRect(){

    vectorAnimRect[0].h++;
    vectorAnimRect[0].w++;
//    update();
}

QRect Rect::showRect(){

//   x=20+rand()%1700, y=20+rand()%1000;
//   rect.setX(x);
//   rect.setY(y);
    x = w + (200 * cos(p * t) - 5 * cos((1 + p) * t)), y = h + (200 * sin(p * t) - 30 * sin((1 + p) * t));
    rect.moveBottomRight(QPoint(x, y));
    return rect;
}

QRect Rect::showRectPixmap(){
    b = b + 2;
    rectPixmap.moveBottomRight(QPoint(x, b));
    return rectPixmap;
}


void Widget::mover(){
    repaint();
//    update();
}

void Widget::addObject()
{

    v = new Rect(dis(gen),rand()%width(),rand()%height(), 0);
    vector.insert(n,*(v));
//    vectorRect.insert(n,v->showRect());
//    vectorRectPixmap.insert(n,v->showRect());
    vectorLabel[n]->setGeometry(vector[n].showRect());
    vectorLabel[n]->setMovie(movietwo);
//    vectorLabelPixmap[n]->setGeometry(vector[n].showRect());
//    vectorLabelPixmap[n]->setPixmap(pixmap);
    //    label->setMovie( movie );
    n++;
}

void Widget::addObjectPixmap()
{
    for (int i =0;i < vector.size();i++) {
      vectorRectPixmap.append((*(new Rect(vector[i].p,vector[i].w,vector[i].h, vector[i].t))));
//      vectorLabelPixmap.append(new QLabel(this));
      vectorLabelPixmap[vectorRectPixmap.size()-1]->setPixmap(pixmap);
      vectorLabelPixmap[vectorRectPixmap.size()-1]->setGeometry(vectorRectPixmap[vectorRectPixmap.size()-1].showRect());
    }




}



void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    mPoint = event->pos();
    rectM = QRect(mPoint.x(),mPoint.y(),1,1);
//   update();
//   repaint();

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
//   QRectF rectangle(x, y, h, w);

//   painter.drawEllipse(rectangle);
//   painter.drawLine(0, 0, width() - 1, height() - 1);
//   painter.drawLine(0, height() - 1, width() - 1, 0);


//    e.t = e.t + 0.1;
    vectorFragments.clear();
//    vectorLabel[i]->clear();
//    vectorRect.clear();
//    vectorRectPixmap.clear();
//    movietwo->stop();
    for (int i = 0; i < vector.size(); i++) {
        if((!mPoint.isNull()) && vector[i].showRect().contains(mPoint)/*&& vector.contains(vector[i])*/ ){
            k = i;
//            timeone.start();
//            for (;b!=50;) {
//                if(((timeone.elapsed()%1000) == 0 && timeone.elapsed()>1000) && (b != 50)){

//                    animRect();
//                    painter.drawRect(vector[i].showRect());
//                    b++;

//                }
//            vectorAnimRect.insert(0,vector[i]);
//            for (;b!=50;) {

//                    QTimer::singleShot(100, this, SLOT(animRect()));
//                    painter.drawRect(vectorAnimRect[0].showRect());
//                    b++;
////                    update();
//                    }


                   b = 0;
                   vector.remove(i);
                   vectorLabel.remove(i);
                   n--;

               }
    }
                mPoint.setX(0);
                mPoint.setY(0);


    for (int i = 0; i < vector.size(); i++) {

            vector[i].t = vector[i].t + 0.1;

//            vectorRect.insert(i,vector[i].showRect());
//            vectorRectPixmap.insert(i,vector[i].showRectPixmap());
            vectorLabel[i]->setGeometry(vector[i].showRect());

//            vectorFragments.insert(i, QPainter::PixmapFragment::create(vectorRectPixmap[i].center(),vectorRectPixmap[i]));
    }

    for (int i = 0; i < vectorRectPixmap.size(); i++) {
        vectorLabelPixmap[i]->setGeometry(vectorRectPixmap[i].showRectPixmap());
    }


        /*f(!vector.empty()){

               vector[0].t = vector[0].t + 0.1;
           }*/

//   painter.eraseRect(0,0,height(),width());
//   QRect r(0,0,width(),height());
    painter.drawPixmap(0,0,width(),height(),movie->currentPixmap());

//    QPainterPath path;
//    path.addRect(20, 20, 60, 60);

//    path.moveTo(0, 0);
//    path.cubicTo(99, 0,  50, 50,  99, 99);
//    path.cubicTo(0, 99,  50, 50,  0, 0);

//    movietwo->start();
//    painter.drawPixmapFragments(vectorFragments.constData(),vectorFragments.size(),pixmap);
    update();
    /*movietwo->stop()*/;
//    update();

//    painter.drawRects(vectorRect);

//   painter.fillRect(r,Qt::white);

//   painter.eraseRect(0,0,height(),width());

//   painter.drawEllipse(mPoint, 100 ,100 );


     painter.end();

}


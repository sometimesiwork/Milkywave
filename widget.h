#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QThread>
#include <QTime>
#include <QMovie>
#include <QLabel>
#include <QPainter>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Rect
{
//    int x = 10;
//    int y = 10;
    int i = 1;
    QPoint mPoint;
    QRect rect = QRect(20, 20, 200, 200);
    QRect rectPixmap = QRect(20, 20, 42, 68);
    QRect rectM = QRect(20, 20, 50, 50);

public:
    int h,w,x,y;
    double t = 500;
    double p,z = 500;
    int b = 0;
    QRect showRect();
    QRect showRectPixmap();

    Rect();
    Rect(double m,int j,int g, double k);
    ~Rect();

protected:

};

class Widget : public QWidget
{
    Q_OBJECT

public:
    QVector<Rect> vector;
    QVector<QLabel*> vectorLabel;
    QVector<QLabel*> vectorLabelPixmap;
    QVector<QPainter::PixmapFragment> vectorFragments;
    QVector<QRect> vectorRect;
    QVector<Rect> vectorRectPixmap;
    QVector<Rect> vectorAnimRect;
    explicit Widget(QWidget *parent = nullptr);
    void addObject();
    void addObjectPixmap();
    void mouseReleaseEvent(QMouseEvent *event) override;
    QLabel *label = new QLabel(this);
    QTime timeone;
    int h,w;
//    int x = 10;
//    int y = 10;
    int k = 0;
    int i = 0;
    int n = 0,f = 0,b = 0;
    QTimer *timer;
    QTimer *timerAdd;
    QTimer *timerAddPixmap;
    QPoint mPoint;
    QRect rect = QRect(20, 20, 50, 50);
    QRect rectM = QRect(20, 20, 50, 50);
    Rect e;
    double t = 500;
    Rect *v;
    QLabel *g;
    QMovie *movie = new QMovie(":/images/5.gif");
    QMovie *movietwo = new QMovie(":/images/3.gif");
    QPixmap pixmap = QPixmap(":/images/1.png");
    ~Widget();



private:
    Ui::Widget *ui;

public slots:
    void animRect();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    QRect showRect();
    void mover();
};
#endif // WIDGET_H

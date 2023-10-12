#include "qfish.h"
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsView>


Qfish::Qfish(const QString & fileName,QGraphicsScene *scence): Qpixmapitem(fileName,scence)
{
    setPos(200,400);
}

//虚函数先调用子类
void Qfish::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    char filename[100] ="0";
    static int i = 10;
    i++;
    if(i==25)
    {
        i=10;
    }
    sprintf(filename,":/img/boss/boss_%d.png",i);
    pixmap.load(filename);
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);


}


void Qfish::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=800)
    {
        setPos(-100,qrand()%480);
        this->show();
    }
    int speed = qrand() % 10;
    this->setPos(mapToScene(speed,-1));
}

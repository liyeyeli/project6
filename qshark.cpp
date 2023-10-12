#include "qshark.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
qshark::qshark(const QString & fileName,QGraphicsScene *scence): Qpixmapitem(fileName,scence)
{
    setPos(130,100+qrand()%400);
}
//虚函数先调用子类
void qshark::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    char filename[50] = "0";
    static int k = 2;
    if(k==13)
    {
        k=1;

    }
    sprintf(filename,":/img/shark/shark_%d.png",k++);
    pixmap.load(filename);

    painter->drawPixmap(0,0,pixmap);
}


void qshark::sharkadvance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=800)
    {
        setPos(-100,qrand()%480);
    }
    int speed = qrand() % 10;
    this->setPos(mapToScene(speed,-1));
}

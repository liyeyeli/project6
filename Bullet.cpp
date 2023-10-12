#include "Bullet.h"
#include <QGraphicsItem>
#include "qgun.h"
#include "qnet.h"


Bullet::Bullet(const QString &fileName,QGraphicsScene *scence,qreal angle): Qpixmapitem(fileName,scence)
{
    this->scence = scence;
    qreal dx,dy;
    qreal rad;
    rad = angle*3.14/180;
    dx = 66*cos(rad);
    dy = 66*sin(rad);
    this->setPos(400+dx,480-dy);
    this->setRotation(90-angle);
}
void Bullet::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
    if (this->collidingItems().count() > 0) {
        docolliding();}
}

void Bullet::advance(int phase)
{
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x()>=800)
    {
        delete this;
    }
    else {
        this->setPos(mapToScene(0,-50));
    }
}

void Bullet::docolliding()
{
    qnet *net = new qnet(":/img/fish_net/blue_net.png",this->scence);
    net->setPos(mapToScene(0,0));
    delete this;
}

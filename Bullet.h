#ifndef BULLET_H
#define BULLET_H
#include "qpixmapitem.h"
#include <QtGui>
#include <QGraphicsScene>
#include "qnet.h"


class Bullet:public Qpixmapitem
{

public:
    Bullet(const QString & fileName,QGraphicsScene *scence,qreal angle);
    void advance(int phase);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void docolliding();
private:
    QGraphicsScene *scence;

public slots:
};

#endif // BULLET_H

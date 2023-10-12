#ifndef QFISH_H
#define QFISH_H


#include "qpixmapitem.h"
#include <QGraphicsScene>


class Qfish:public Qpixmapitem
{
public:
    Qfish(const QString & fileName,QGraphicsScene *scence);
    void advance(int phase);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // QFISH_H

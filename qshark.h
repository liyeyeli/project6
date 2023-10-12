#ifndef QSHARK_H
#define QSHARK_H

#include "qpixmapitem.h"

class qshark:public Qpixmapitem
{
public:
    qshark(const QString & fileName,QGraphicsScene *scence);
    void sharkadvance(int phase);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
};

#endif // QSHARK_H

#ifndef QNET_H
#define QNET_H
#include "qpixmapitem.h"
#include "qfish.h"

class qnet:public Qpixmapitem
{
public:
    qnet(const QString & fileName,QGraphicsScene *scence);
void advance(int phase);
};

#endif // QNET_H

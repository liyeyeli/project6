#ifndef QGUN_H
#define QGUN_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include "qpixmapitem.h"
#include <QGraphicsScene>


class Qgun:public Qpixmapitem
{
public:
    Qgun(const QString & fileName,QGraphicsScene *scence);

};

#endif // QGUN_H

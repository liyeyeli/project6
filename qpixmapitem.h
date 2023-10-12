#ifndef QPIXMAPITEM_H
#define QPIXMAPITEM_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class Qpixmapitem:public QGraphicsItem
{
public:
    Qpixmapitem(const QString & fileName,QGraphicsScene *scence);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    QPixmap pixmap;
};

#endif // QPIXMAPITEM_H

#include "qnet.h"

qnet::qnet(const QString & fileName,QGraphicsScene *scence): Qpixmapitem(fileName,scence)
{

}

void qnet::advance(int phase)
{
    if (this->collidingItems().count() > 0)
    {QList<QGraphicsItem *> list = this->collidingItems();
        QList<QGraphicsItem *>::Iterator i;
        Qfish *zfish1;
        i = list.begin();
        while(i!=list.end())
        {
            zfish1 = (Qfish *)(*i);
            zfish1->hide();
            i++;
        }
    }
    this->hide();
    delete this;
}

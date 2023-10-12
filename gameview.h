#ifndef GAMEWIGET_H
#define GAMEWIGET_H
#include "qgun.h"
#include "qfish.h"
#include "Bullet.h"
#include "qshark.h"
#include "Bullet.h"
#include "qnet.h"
#include <QWidget>
#include <QGraphicsPixmapItem>  //图形元素
#include <QGraphicsView>    //视图
#include <QGraphicsScene>    //场景
#include <QMouseEvent>
#include <QPoint>
#include <QLine>
#include <QLineF>
#include "qpixmapitem.h"
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <QBrush>


class gameview : public QGraphicsView
{
    Q_OBJECT
public:
    explicit gameview(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QGraphicsView *zGameview;  //游戏视图
    QGraphicsScene *zGameScene;   //游戏场景
    QGraphicsScene zStartScene;   //开始界面
    QMouseEvent *event;

    QGraphicsPixmapItem zBackGround1;   //背景元素1
    QGraphicsPixmapItem zBackGround2;   //背景元素2
    Qgun *zgun;   //大炮
    Bullet *bullet;  //子弹
    Qfish *zfish1;   //鱼
    Qfish *zfish2;
    Qfish *zfish3;

    qshark *zfish4;
    qshark *zfish5;
    qshark *zfish6;

    //定时器
    QTimer* zBGmovetimer;      //背景移动定时器
    QTimer* zBullettimer;       //子弹移动定时器
    QTimer* zFishtimer;        //鱼游动定时器
    QTimer* zsharktimer;          //鲨鱼游动定时器


};

#endif // GAMEWIGET_H

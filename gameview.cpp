#include "gameview.h"

gameview::gameview(QWidget *parent)
{
    this->setFixedSize(800,480);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/image/R-d.jpg"));
    this->setBackgroundBrush(QBrush(QPixmap(":/image/018817582028d1a84a0d304fc2a953.jpg@1280w_1l_2o_100sh.jpg")));
    

    //创建视图
   // zGameview = new QGraphicsView();
   // zGameScene = new QGraphicsScene();
   // zGameview->setSceneRect(QRect(0,0,800,480));
    //创建游戏场景
//    zGameScene->setSceneRect(QRect(0,0,800,480));
//    //背景元素1
//    zBackGround1.setPixmap(QPixmap(":/image/018817582028d1a84a0d304fc2a953.jpg@1280w_1l_2o_100sh.jpg"));
//    //将背景元素加入场景
//    zGameScene->addItem(&zBackGround1);
    //将场景加入视图
   // zGameview->setScene(zGameScene);
    //视图在窗口
    //zGameScene->setParent(this);

     zGameScene = new QGraphicsScene;
     zGameScene->setSceneRect(0,0,this->width()-2,this->height()-2);
     this->setScene(zGameScene);


    //大炮
    zgun = new Qgun(":/image/gun.fw.png",zGameScene);

    this->setMouseTracking(true);




    // 鱼
    zfish1 = new Qfish(":/img/boss/boss_01.png",zGameScene);

    zfish2= new Qfish(":/img/boss/boss_01.png",zGameScene);

    zfish3= new Qfish(":/img/boss/boss_01.png",zGameScene);



    //shark
//    zfish4 = new qshark(":/img/shark/shark_01.png");
//    zGameScene->addItem(zfish4);

//    zfish5= new qshark(":/img/shark/shark_01.png");
//    zGameScene->addItem(zfish5);

//    zfish6= new qshark(":/img/shark/shark_01.png");
//    zGameScene->addItem(zfish6);


    //鱼游动定时器
    zFishtimer = new QTimer;
    zFishtimer->start(100);
    connect(zFishtimer,SIGNAL(timeout()),zGameScene,SLOT(advance()));

//    //鲨鱼游动定时器
//    zsharktimer = new QTimer;
//    zsharktimer->start(100);
//    connect(zsharktimer,SIGNAL(timeout()),zGameScene,SLOT(advance()));

}

    //
//    zBullettimer = new QTimer;
//    zBullettimer->start(200);
//    connect(zBullettimer,SIGNAL(timeout()),zGameScene,SLOT(moveby()));
//}


void gameview::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p;
    p=event->pos();
    QLine line(400,480,p.x(),p.y());
    QLineF linef(line);
    zgun->setRotation(90-linef.angle());
}
void gameview::mousePressEvent(QMouseEvent *event)
{

    //子弹
    QPoint p;
    p=event->pos();
    QLineF linef(400,480,p.x(),p.y());
    bullet = new Bullet(":/img/bullet/blue_bullet.png",zGameScene,linef.angle());
    bullet->setRotation(90-linef.angle());
}





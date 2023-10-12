#include "Widget.h"
#include "ui_widget.h"
#include "gameview.h"
#include "qgun.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QToolButton>
#include "Bullet.h"
#include <QPalette>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //设置窗口大小,标题，图标
    ui->setupUi(this);
    this->setFixedSize(800,480);
    this->setWindowTitle("捕鱼达人");
    this->setWindowIcon(QIcon(":/image/R-d.jpg"));

    //设置主窗口背景图片
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/image/startbg.fw.png")));
    this->setPalette(palette);

    //设置标签
    auto label = new QLabel();
    label->setPixmap(QPixmap(":/image/label.fw.png"));

    label->setParent(this);

    //设置开始按钮
    auto startbtn = new QPushButton(this);
    startbtn->setIcon(QIcon(":/img/game_start.png"));
    startbtn->setIconSize(QSize(200,60));
    //透明背景
    startbtn->setFlat(true);
    //去掉黑虚框
    startbtn->setFocusPolicy(Qt::NoFocus);

    //设置结束按钮
    auto quitbtn = new QPushButton(this);
    quitbtn->setIcon(QIcon(":/img/game_over_btn.png"));
    quitbtn->setIconSize(QSize(200,64));
    quitbtn->setFlat(true);
    quitbtn->setFocusPolicy(Qt::NoFocus);


    //    设置垂直布局
    auto vbox = new QVBoxLayout(this);
    vbox->addWidget(label);
    vbox->addWidget(startbtn);
    vbox->addWidget(quitbtn);
    //居中对齐
    vbox->setAlignment(Qt::AlignCenter);



    //实现结束按钮
    connect(quitbtn,&QPushButton::clicked,this,&Widget::Quitbtnclicked);
    //实现开始按钮
    connect(startbtn,&QPushButton::clicked,this,&Widget::Startbtnclicked);





    //    //创建视图
    //    zGameview.setSceneRect(QRect(0,0,800,480));
    //    //创建游戏场景
    //    zGameScene.setSceneRect(QRect(0,0,800,480));
    //    //    //创建开始场景
    //    //    zStartScene.setSceneRect(QRect(0,0,950,535));
    //    //    //添加开始场景背景图片
    //    //    zStartScene.addPixmap(QPixmap(":/image/R-C.jpg"));

    //    //    //定义一个toolButton按钮
    //    //    auto startbtn = new QToolButton();
    //    //    //设置按钮相关属性
    //    //    startbtn->resize(200,100);
    //    //    startbtn->setAutoRaise(true);
    //    //    startbtn->setIcon(QIcon(":/image/start.png"));
    //    //    startbtn->setIconSize(QSize(200,100));
    //    //    //按钮添加到开始场景
    //    //    zStartScene.addWidget(startbtn);
    //    //    //设置按钮位置
    //    //    startbtn->move(400,200);
    //    //点击信号绑定下一个游戏场景
    //    //    connect(startbtn,&QToolButton::clicked,[this](){
    //    //        zGameview.setScene(&zGameScene);
    //    //        zGameview.show();
    //    //   });
    //    //背景元素1
    //    zBackGround1.setPixmap(QPixmap(":/image/R-C.jpg"));
    //    // zBackGround2.setPixmap(QPixmap(":/image/R-C.jpg"));
    //    // zBackGround2.setPos(950,0);
    //    // zBoss.setPixmap(QPixmap("://img/boss/boss_01.png"));
    //    // zBoss.setPos(100,200);
    //    //将背景元素加入场景
    //    zGameScene.addItem(&zBackGround1);
    //    // zGameScene.addItem(&zBackGround2);
    //    //  zGameScene.addItem(&zBoss);
    //    //将场景加入视图
    //    zGameview.setScene(&zGameScene);
    //    //     zGameview.setScene(&zStartScene);
    //    //视图在窗口
    //    zGameview.setParent(this);


    //   //创建定时器
    //    mBGmovetimer = new QTimer(this);
    //    mBGmovetimer->start(10);
    //    connect(mBGmovetimer,&QTimer::timeout,this,&Widget::BGmove);

    //创建大炮
    //    auto cannonbtn = new QToolButton();
    //    //设置按钮相关属性
    //    cannonbtn->resize(40,40);
    //    cannonbtn->setAutoRaise(true);
    //    cannonbtn->setIcon(QIcon(":/img/gun/gun_02.png"));
    //    cannonbtn->setIconSize(QSize(40,40));
    //    //按钮添加到游戏场景
    //    zGameScene.addWidget(cannonbtn);
    //    //设置按钮位置
    //    cannonbtn->move(380,440);
    //    QPixmap bulletimg(":/img/bullet/blue_bullet.png");
    //    QPoint pos(100,440);
    //    Bullet* bullet = new Bullet(pos,bulletimg,1);
    //    zBullettimer = new QTimer(this);
    //    zBullettimer->start(10);
    //    zGameScene.addItem(bullet);
    //    connect(zBullettimer,&QTimer::timeout,[this](){
    //        bullet->zBulletMove();
    //    });
}

Widget::~Widget()
{
    delete ui;
}


//游戏场景交替移动
//void Widget::BGmove()
//{
//    zBackGround1.moveBy(-10,0);//移动量
//    zBackGround2.moveBy(-10,0);
//    if(zBackGround1.x() <= -950){
//        zBackGround1.setX(zBackGround1.pixmap().width());
//    }else if
//            (zBackGround2.x() <= -950)
//    {
//         zBackGround2.setX(zBackGround2.pixmap().width());
//    }


//  }


void Widget::Quitbtnclicked(){
    if(QMessageBox::Yes==QMessageBox::question(this,"提示","确定退出吗？",QMessageBox::No|QMessageBox::Yes))
        close();
}


void Widget::Startbtnclicked(){
    this->hide();
    gameview* view = new gameview();
    view->show();
}



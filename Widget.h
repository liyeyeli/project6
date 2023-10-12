#ifndef WIDGET_H
#define WIDGET_H
#include "gameview.h"


#include <QWidget>
#include <QGraphicsPixmapItem>  //图形元素
#include <QGraphicsView>    //视图
#include <QGraphicsScene>    //场景

//图形元素组成     ---》场景  -----》视图


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void BGmove();           //定义背景移动函数
    void Quitbtnclicked();
    void Startbtnclicked();
    void zBulletMove();       //定义子弹移动函数
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

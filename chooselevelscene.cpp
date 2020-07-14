#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>


ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置主場景//
    //設置固定大小
    setFixedSize(1000,800);
    //設置圖標
    setWindowIcon(QIcon(":/res/icon.png"));
    //設置標題
    setWindowTitle("選擇關卡");
    //創建菜單欄
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    //創建選擇菜單
    QMenu *selectMenu = bar->addMenu("選擇");
    //創建退出菜單項
   QAction *quitAction = selectMenu->addAction("退出");
   //點擊退出
   connect(quitAction,&QAction::triggered,[=](){
       this->close();
   });
   //返回按鈕
   MyPushButton *backbtn = new MyPushButton(":/res/backpage.png",":/res/backpage2.png");
   backbtn->setParent(this);
   backbtn->setIconSize(QSize(150,150));
   backbtn->setStyleSheet("QPushButton{border:0px;}");
   //backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
   backbtn->move(this->width()-400,this->height()-362);
   //點擊返回
   connect(backbtn,&MyPushButton::clicked,[=](){
       //qDebug() <<"點擊了回上頁";
       //qDebug() <<backbtn->size();
//       backbtn->zoom1();
//       backbtn->zoom2();

       //告訴主場景我要回前一頁，主場景監聽ChooseLevelScene的返回按鈕
       //延時返回
       QTimer::singleShot(200,this,[=](){emit this->chooseSceneBack();});
    });

   //選擇難度按鈕
   QStringList levelList;
   levelList<<"簡單"<<"普通"<<"困難";
   for(int i=0;i<3;i++){
       MyPushButton *levelBtn = new MyPushButton(":/res/levelbutton.png");
       levelBtn->setParent(this);
       levelBtn->setStyleSheet("QPushButton{border:0px;}");
       levelBtn->move(400,50+i*200);

       //監聽每個點擊事件
       connect(levelBtn,&MyPushButton::clicked,[=](){
           //QString str = QString("你選擇的是 %1 關").arg(i+1);
           //qDebug()<<str;
           //qDebug()<<levelList[i];
//           levelBtn->zoom1();
//           levelBtn->zoom2();

           //進入遊戲場景
           this->close();
           play = new playscene(i);
           //設置遊戲場景位置
           play->setGeometry(this->geometry());
           play->show();

           //監聽選擇關卡場景返回前一頁的訊號
           connect(play,&playscene::chooseSceneBack,this,[=](){
               this->setGeometry(play->geometry());
               this->show();
               delete play;
               play = NULL;
           });
       });

       QLabel *label = new QLabel;
       label->setParent(this);
       QFont font("BatangChe",30,QFont::Bold);
       label->setFont(font);
       label->setFixedSize(levelBtn->width(),levelBtn->height());
       label->setText(levelList[i]);
       label->move(400,50+i*200);

       //設置label上的文字對齊方式 水平居中 ＆ 垂直居中
       label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
       //讓滑鼠進行穿透
       label->setAttribute(Qt::WA_TransparentForMouseEvents);

   }

}

void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

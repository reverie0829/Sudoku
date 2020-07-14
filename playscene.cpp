#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "dataconfig.h"

//playscene::playscene(QWidget *parent) : QMainWindow(parent)
//{

//}

playscene::playscene(int levelNum){
    //QString str = QString("進入第 %1 關").arg(levelNum);
    //qDebug()<<str;
    this->levelIndex = levelNum;

    //初始化遊戲場景
    //設置固定大小
    setFixedSize(1000,800);
    //設置圖標
    setWindowIcon(QIcon(":/res/icon.png"));
    //設置標題
    setWindowTitle("遊戲場景");
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

   QStringList levelList;
   levelList<<"簡單關卡"<<"普通關卡"<<"困難關卡";
   //顯示關卡
   QLabel *label = new QLabel;
   label->setParent(this);
   QFont font("BatangChe",30,QFont::Bold);
   font.setPointSize(20);
   label->setFont(font);
   label->setText(levelList[levelIndex]);
   //label->setText(QString::number(this->levelIndex));
   label->setGeometry(this->width()-530,this->height()-130,120,50);

   //初始化每個關卡的陣列
   dataConfig config;
   for(int i=0;i<9;i++){
       for(int j=0;j<9;j++){
           this->gameArray[i][j]=config.mData[this->levelIndex][i][j];
       }
   }

   //顯示9*9格子
   for(int i=0;i<9;i++){
       for(int j=0;j<9;j++){
           QLabel *label = new QLabel;
           label->setFixedSize(50,50);
           //label->setGeometry(0,0,50,50);
//           label->setPixmap(QPixmap(":/res/R0.png"));
//           label->setParent(this);
//           label->move(280+i*55,100+j*55);
           QImage Image;
           Image.load(":/res/R0.png");
           QPixmap pixmap = QPixmap::fromImage(Image);
           int with = label->width();
           int height = label->height();
           QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 飽滿填充
           //QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例縮放
           label->setParent(this);
           label->setPixmap(fitpixmap);
           label->setStyleSheet(QString("border-image:url(:/res/R0.png);color:rgb(47,79,79);"));//圖當背景,字的rgb顏色
           label->setText(QString::number(gameArray[i][j]));
           label->move(280+i*55,100+j*55);
           //設置label上的文字對齊方式 水平居中 ＆ 垂直居中
           label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
           //改數獨盤的字體大小
           QFont ft;
           ft.setPointSize(20);
           label->setFont(ft);

           //失敗的（顯示圖也顯示字）會被覆蓋
//           QLabel *labelnum = new QLabel;
//           labelnum->setParent(this);
//           labelnum->setText(QString::number(gameArray[i][j]));
//           qDebug()<<gameArray[i][j];
//           qDebug()<<QString::number(gameArray[i][j]);
//           labelnum->move(295+i*55,100+j*55);
//           labelnum->raise();
       }
   }

}

void playscene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //畫cell線
    QPen penred(QColor(255,107,53));
    penred.setWidth(3);
    painter.setPen(penred);
    //畫矩形
    painter.drawRect(QRect(276,96,497,497));
    //畫線
    painter.drawLine(QPoint(442,98),QPoint(442,592));
    painter.drawLine(QPoint(607,98),QPoint(607,592));
    painter.drawLine(QPoint(276,262),QPoint(773,262));
    painter.drawLine(QPoint(276,427),QPoint(773,427));

}


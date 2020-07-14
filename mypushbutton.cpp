#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg){
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret){
        qDebug()<<"圖片加載失敗";
        return;
    }

    //設置圖片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //設置不規則圖片樣式
    this->setStyleSheet("QPushButton{border:0px;}");
    //設置圖標
    this->setIcon(pix);
    //設置圖標大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}

void MyPushButton::zoom1(){
    //創建動畫對象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //設置動畫時間間隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //結束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //設置彈跳曲線
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //執行動畫
    animation->start();
}
void MyPushButton::zoom2(){
    //創建動畫對象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //設置動畫時間間隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //結束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //設置彈跳曲線
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //執行動畫
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e){
    //傳入的按下圖片不為空 說明需要有按下狀態 切換圖片
     if(this->pressImgPath != ""){
         QPixmap pix;
         bool ret = pix.load(this->pressImgPath);
         if(!ret){
             qDebug()<<"圖片加載失敗";
             return;
         }

         //設置圖片固定大小
         this->setFixedSize(pix.width(),pix.height());
         //設置不規則圖片樣式
         this->setStyleSheet("QPushButton{border:0px;}");
         //設置圖標
         this->setIcon(pix);
         //設置圖標大小
         this->setIconSize(QSize(150,150));
     }
     //讓父類執行其他內容
     return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    //傳入的按下圖片不為空 說明需要有按下狀態 切換回初始圖片
     if(this->pressImgPath != ""){
         QPixmap pix;
         bool ret = pix.load(this->normalImgPath);
         if(!ret){
             qDebug()<<"圖片加載失敗";
             return;
         }

         //設置圖片固定大小
         this->setFixedSize(pix.width(),pix.height());
         //設置不規則圖片樣式
         this->setStyleSheet("QPushButton{border:0px;}");
         //設置圖標
         this->setIcon(pix);
         //設置圖標大小
         this->setIconSize(QSize(150,150));
     }
     //讓父類執行其他內容
     return QPushButton::mouseReleaseEvent(e);
}

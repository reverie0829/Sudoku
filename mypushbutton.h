#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);

    MyPushButton(QString normalImg, QString pressImg = "" );
    QString normalImgPath;
    QString pressImgPath;

    //彈跳特效
    void zoom1();//向上跳
    void zoom2();//向下跳

    //重寫按鈕 按下 ＆ 釋放 事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // MYPUSHBUTTON_H

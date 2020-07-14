#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    //加載背景：重寫painEvent事件
    void paintEvent(QPaintEvent *);
    //遊戲場景對象指標
    playscene *play = NULL;

signals:
    //寫一個自定義的信號，告訴主場景要回前一頁
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H

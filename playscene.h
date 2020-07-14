#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class playscene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit playscene(QWidget *parent = nullptr);
    playscene(int levelNum);
    int levelIndex;//紀錄所選關卡

    //加載背景：重寫painEvent事件
    void paintEvent(QPaintEvent *);

    int gameArray[9][9];

signals:
    //寫一個自定義的信號，告訴主場景要回前一頁
    void chooseSceneBack();
};

#endif // PLAYSCENE_H

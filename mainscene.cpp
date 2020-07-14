#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>


MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //配置主場景//
    //設置固定大小
    setFixedSize(1000,800);
    //設置圖標
    setWindowIcon(QIcon(":/res/icon.png"));
    //設置標題
    setWindowTitle("Sudoku");
    //退出按鈕
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });
    //開始按鈕
    MyPushButton *startBtn = new MyPushButton(":/res/start.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.45);

    //實例化選擇關卡場景
    chooseScene = new ChooseLevelScene;


    //監聽選擇關卡場景返回前一頁的訊號
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });

    connect(startBtn,&MyPushButton::clicked,[=](){
        //qDebug() <<"點擊了開始";
        //彈跳特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延時進入到選擇關卡場景
        QTimer::singleShot(200,[=](){
            //設置chooseScene場景的位置
            chooseScene->setGeometry(this->geometry());
            //進入選擇關卡的場景中
            //自身隱藏
            this->hide();
            //顯示選擇關卡場景
            chooseScene->show();

        });
    });

}

void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/background.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,120,pix.width(),pix.height(),pix);
}

MainScene::~MainScene()
{
    delete ui;
}


#include "helpingwindow.h"
#include "ui_helpingwindow.h"

helpingWindow::helpingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::helpingWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("宝石消消乐游戏规则：玩家可以通过点击两个相邻的宝石进行交换。\n 当三个或更多相同颜色的宝石连成一线时，这些宝石会被消除，玩家将获得分数。消除后，上方的宝石将下落填补空缺，新的宝石将从顶部出现。");
}

helpingWindow::~helpingWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gamepanelwindow.h"
#include"paihangwindow.h"
#include"usernamewindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//游戏面板
void MainWindow::on_pushButton_clicked()
{
    gamepanelWindow *en=new gamepanelWindow;
    en->setFixedSize(700, 550); // 设置固定大小为 800x600
    en->show();
}

//排行榜
void MainWindow::on_pushButton_3_clicked()
{
    paihangWindow *en=new paihangWindow;
    en->setFixedSize(340, 550); // 设置固定大小为 800x600
    en->show();
}

//改用户名
void MainWindow::on_pushButton_2_clicked()
{
    usernameWindow *en=new usernameWindow;
    en->setFixedSize(300, 200); // 设置固定大小为 800x600
    en->show();
}


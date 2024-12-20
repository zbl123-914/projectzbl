#include "usernamewindow.h"
#include "ui_usernamewindow.h"

usernameWindow::usernameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::usernameWindow)
{
    ui->setupUi(this);
}

usernameWindow::~usernameWindow()
{
    delete ui;
}
//登陆 和数据库内容作比对
void usernameWindow::on_pushButton_clicked()
{

}


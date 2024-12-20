#include "emailwindow.h"
#include "ui_emailwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QtCore>
#include"smtp.h"
emailWindow::emailWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::emailWindow)
{
    ui->setupUi(this);
}

emailWindow::~emailWindow()
{
    delete ui;
}

void emailWindow::on_makesureInputEmail_clicked() {
     QString emailnum = ui->inputEmail->text();
      Smtp smtp("zhang13522082502@163.com","GWV7w38mEHCqvYi6");
     smtp.send(emailnum.toUtf8(),"hello world!","hahaha你得了0分哦");

}

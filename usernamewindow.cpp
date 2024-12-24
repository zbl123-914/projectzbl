#include "usernamewindow.h"
#include "ui_usernamewindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

usernameWindow::usernameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::usernameWindow)
{
    ui->setupUi(this);
    openDatabase();
}

usernameWindow::~usernameWindow()
{
    delete ui;
}

void usernameWindow::openDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\19255\\Desktop\\Data Structures\\qtsql\\DB\\AppDataBase.db");

    if (db.open()) {
        qDebug() << "Connected to SQL Server!";
    } else {
        qDebug() << "Failed to connect to SQL Server: " << db.lastError().text();
    }
}

void usernameWindow::registerUser(const QString &name, const QString &pwd)
{
    if (checkUserExists(name)) {
        QMessageBox::warning(this, "注册失败", "用户已存在！");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO SysAdmins (LoginID, LoginName, LoginPwd, Role) VALUES (:id, :name, :pwd, :role)");
    query.bindValue(":id", "#");  // 使用#作为ID的占位符
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);
    query.bindValue(":role", "*");  // 使用*作为role的占位符

    if (query.exec()) {
        QMessageBox::information(this, "注册成功", "注册成功！");
    } else {
        qDebug() << "插入失败: " << query.lastError().text();
        QMessageBox::warning(this, "注册失败", "注册失败，请重试！");
    }
}


bool usernameWindow::checkUserExists(const QString &name)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM SysAdmins WHERE LoginName = :name");
    query.bindValue(":name", name);

    if (query.exec() && query.next()) {
        return true;
    }

    return false;
}

bool usernameWindow::loginUser(const QString &name, const QString &pwd)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM SysAdmins WHERE LoginName = :name AND LoginPwd = :pwd");
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);

    if (query.exec() && query.next()) {
        return true;
    }

    return false;
}

// 登录 查
void usernameWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit_username->text();
    QString pwd = ui->lineEdit_password->text();

    if (loginUser(name, pwd)) {
        QMessageBox::information(this, "登录成功", "登录成功！");
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    } else {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误！");
    }
}

// 注册 插入
void usernameWindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit_username->text();
    QString pwd = ui->lineEdit_password->text();

    registerUser(name, pwd);
}

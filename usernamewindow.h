#ifndef USERNAMEWINDOW_H
#define USERNAMEWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class usernameWindow; }
QT_END_NAMESPACE

class usernameWindow : public QMainWindow
{
    Q_OBJECT

public:
    usernameWindow(QWidget *parent = nullptr);
    ~usernameWindow();

private slots:
    void on_pushButton_clicked();  // 登录按钮槽函数
    void on_pushButton_2_clicked();  // 注册按钮槽函数

private:
    Ui::usernameWindow *ui;
    QSqlDatabase db;
    void openDatabase();
    void registerUser(const QString &name, const QString &pwd);
    bool checkUserExists(const QString &name);
    bool loginUser(const QString &name, const QString &pwd);
};

#endif // USERNAMEWINDOW_H

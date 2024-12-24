#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <qDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::cellClicked, [&](int row, int col) {
        ui->txt_id->setText(ui->tableWidget->item(row, 0)->text());
        ui->txt_name->setText(ui->tableWidget->item(row, 1)->text());
        ui->txt_pwd->setText(ui->tableWidget->item(row, 2)->text());
        ui->txt_role->setText(ui->tableWidget->item(row, 3)->text());
    });
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\19255\\Desktop\\Data Structures\\qtsql\\DB\\AppDataBase.db");

    if (db.open()) {
        qDebug() << "Connected to SQL Server!";
    } else {
        qDebug() << "Failed to connect to SQL Server: " << db.lastError().text();
    }

    // 连接 btnperform 按钮和槽函数
    connect(ui->btnperform, &QPushButton::clicked, this, &Widget::on_btnperform_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btninsert_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SysAdmins (LoginID, LoginName, LoginPwd, Role) VALUES (:value1, :value2, :value3, :value4)");
    query.bindValue(":value1", ui->txt_id->toPlainText().toInt());
    query.bindValue(":value2", ui->txt_name->toPlainText());
    query.bindValue(":value3", ui->txt_pwd->toPlainText());
    query.bindValue(":value4", ui->txt_role->toPlainText().toInt());
    if (query.exec()) {
        perform();
    } else {
        qDebug() << "插入失败: " << query.lastError().text();
    }
}

void Widget::perform()
{
    int row = 0;
    ui->tableWidget->setRowCount(0);

    QSqlQuery query;
    if (query.exec("SELECT * FROM SysAdmins")) {
        QSqlRecord record = query.record();
        ui->tableWidget->setColumnCount(record.count());
        ui->tableWidget->setHorizontalHeaderLabels({"ID", "Name", "Pwd", "Role"});

        while (query.next()) {
            ui->tableWidget->insertRow(row);
            for (int var = 0; var < record.count(); ++var) {
                ui->tableWidget->setItem(row, var, new QTableWidgetItem(query.value(var).toString()));
            }
            row++;
        }
    } else {
        qDebug() << "查询失败: " << query.lastError().text();
    }
}

void Widget::Query(const QString &name, const QString &pwd)
{
    int row = 0;
    ui->tableWidget->setRowCount(0);

    QSqlQuery query;
    query.prepare("SELECT * FROM SysAdmins WHERE LoginName = :name AND LoginPwd = :pwd");
    query.bindValue(":name", name);
    query.bindValue(":pwd", pwd);

    if (query.exec()) {
        QSqlRecord record = query.record();
        ui->tableWidget->setColumnCount(record.count());
        ui->tableWidget->setHorizontalHeaderLabels({"ID", "Name", "Pwd", "Role"});

        if (query.next()) {
            ui->tableWidget->insertRow(row);
            for (int var = 0; var < record.count(); ++var) {
                ui->tableWidget->setItem(row, var, new QTableWidgetItem(query.value(var).toString()));
            }
        } else {
            qDebug() << "没有找到匹配的记录";
        }
    } else {
        qDebug() << "查询失败: " << query.lastError().text();
    }
}

void Widget::on_btnquery_clicked()
{
    QString name = ui->txt_name->toPlainText();
    QString pwd = ui->txt_pwd->toPlainText();
    Query(name, pwd);
}

void Widget::on_btndelete_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM SysAdmins WHERE LoginID = :value1");
    query.bindValue(":value1", ui->txt_id->toPlainText().toInt());

    if (query.exec()) {
        perform();
    } else {
        qDebug() << "删除失败: " << query.lastError().text();
    }
}

void Widget::on_btnupdate_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE SysAdmins SET LoginName=:value2, LoginPwd=:value3, Role=:value4 WHERE LoginID=:value1");
    query.bindValue(":value1", ui->txt_id->toPlainText().toInt());
    query.bindValue(":value2", ui->txt_name->toPlainText());
    query.bindValue(":value3", ui->txt_pwd->toPlainText());
    query.bindValue(":value4", ui->txt_role->toPlainText().toInt());
    if (query.exec()) {
        perform();
    } else {
        qDebug() << "更新失败: " << query.lastError().text();
    }
}

void Widget::on_btnperform_clicked()
{
    perform();
}

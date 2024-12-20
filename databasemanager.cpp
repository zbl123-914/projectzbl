// DatabaseManager.cpp
#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("game_database.db");
}

DatabaseManager::~DatabaseManager()
{
    closeDatabase();
}

bool DatabaseManager::openDatabase()
{
    if (!db.open()) {
        qDebug() << "Error: 数据库打开失败";
        return false;
    }
    return true;
}

void DatabaseManager::closeDatabase()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::createTables()
{
    QSqlQuery query;

    QString createUserTable = "CREATE TABLE IF NOT EXISTS users ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "username TEXT NOT NULL UNIQUE, "
                              "password TEXT NOT NULL)";

    if (!query.exec(createUserTable)) {
        qDebug() << "Error: 用户表创建失败";
        return false;
    }

    QString createUserGameTable = "CREATE TABLE IF NOT EXISTS user_game_records ("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  "user_id INTEGER NOT NULL, "
                                  "game_duration INTEGER NOT NULL, "
                                  "score INTEGER NOT NULL, "
                                  "FOREIGN KEY(user_id) REFERENCES users(id))";

    if (!query.exec(createUserGameTable)) {
        qDebug() << "Error: 得分表失败";
        return false;
    }

    return true;
}



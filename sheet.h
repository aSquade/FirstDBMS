#ifndef SHEET_H
#define SHEET_H
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QMap>
#include <QQueue>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QTextStream>
#include <QVector>
#include <algorithm>
#include <field.h>
#include <set>
#include <QCoreApplication>
class Sheet {
public:
    Sheet();
    Sheet(QString username,QString tableName, QString databasename);
    bool readHead();
    bool readData();
    QVector<field> getHead();
    QVector<QVector<QString>> getData();
    void setData(QVector<QVector<QString>> newData);
    void setHead(QVector<field> newHead);
    bool UpdateOneData(int id, QString column, QString value);
    QVector<int> FindAllData(QString column, QString judge, QString condtion);
    bool DeleteAllData();
    bool InsertData(QMap<QString, QString> row);
    Sheet SelectData(QStringList columnList); //查询

    QVector<int> getWhere(QStringList judgeList);
    Sheet Cartesian(Sheet t);

    QString getTableName();
    QString getFieldType(QString name);
    int getFieldIndex(QString name);

    Sheet sort(QString column, bool desc);
    Sheet orderBy(QStringList orderList, bool desc);

    bool ExistinTable(QVector<QString> row);
    Sheet groupBy(QStringList groupList);

    bool constraint();
    void backups();
protected:
public:
    QString tableName;
    QString databasename;
    QString username;
    QString textcache;
    QVector<QVector<QString>> data;
    QVector<field> head;
};

#endif // SHEET_H

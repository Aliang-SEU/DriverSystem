#ifndef DRIVERDATABASE_H
#define DRIVERDATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <QObject>

#include <memory>

#include <MyDBModel.h>

class DriverDatabase{

public:
    DriverDatabase();
    ~DriverDatabase();
    bool addNewRecord(QString filename, QString username="annoymous");
    void queryAllRecord();
    void deleteRecord(int id);
    void initSqlTableModel();
    std::shared_ptr<MyDBModel> getModel();

private:
    std::shared_ptr<MyDBModel> m_tableModel;
    QSqlDatabase dataBase;
    const QString m_tablename="fatigue";
};

#endif // DRIVERDATABASE_H

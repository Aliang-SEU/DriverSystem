#include <DriverDatabase.h>
#include <QDebug>

DriverDatabase::DriverDatabase(){

    dataBase = QSqlDatabase::addDatabase("QSQLITE"); //使用mysql数据库
    dataBase.setDatabaseName("../db/driver.db");    //数据库名称

    if(!dataBase.open()) {
        qDebug() << "Error:数据库连接错误! 原因:" << dataBase.lastError().text();
    }else {
        qDebug() << "数据库连接成功！";
    }

}

DriverDatabase::~DriverDatabase(){
    dataBase.close();
}

/** 插入一条记录
 * @brief DriverDatabase::addNewRecord
 * @return
 */
bool DriverDatabase::addNewRecord(QString filename, QString username){
    //首先检查表是否存在
    QSqlQuery sqlQuery(dataBase);
//    sqlQuery.exec("SET NAMES 'Latin1'");   //支持中文
//    sqlQuery.exec("CREATE TABLE driving_record(id int primary key auto_increment,"
//               "username varchar(20),"
//               "createtime timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,"
//               "filename varchar(200)))");
    QString insertSql = QString("INSERT INTO driving_record(username, filename)");
    insertSql += QString("VALUES('%1','%2')").arg(username).arg(filename);
    bool ok = sqlQuery.exec(insertSql);
    if(ok) {
        qDebug() << "insert success!";
    }else {
        qDebug() << "insert failed!";
    }
}

/** 查询所有的疲劳驾驶记录
 * @brief DriverDatabase::queryAllRecord
 */
void DriverDatabase::queryAllRecord() {
    QSqlQuery sqlQuery(dataBase);
    sqlQuery.exec("select * from fatigue;");
    while(sqlQuery.next()) {
        QDateTime time = sqlQuery.value(2).toDateTime();
        qDebug() << sqlQuery.value(0).toInt() << " | " << sqlQuery.value(1).toString() << " | " << time.toString("yyyy/mm/dd hh:mm:ss") << " | " << sqlQuery.value(3).toString() << endl;
    }
}


/** 删除某个疲劳记录
 * @brief DriverDatabase::deleteRecord
 */
void DriverDatabase::deleteRecord(int id) {
    QSqlQuery sqlQuery(dataBase);
    sqlQuery.exec(QString("delect from driving_record where id = %1;").arg(id));
    qDebug() << sqlQuery.lastError() << endl;
}

void DriverDatabase::initSqlTableModel(){
    m_tableModel = std::make_shared<MyDBModel>( Q_NULLPTR, dataBase);

    m_tableModel->setTable(m_tablename);
    m_tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_tableModel->generateRoleNames();

    m_tableModel->setHeaderData(m_tableModel->fieldIndex("id"), Qt::Horizontal, ("id"));
    m_tableModel->setHeaderData(m_tableModel->fieldIndex("username"), Qt::Horizontal, ("username"));
    m_tableModel->setHeaderData(m_tableModel->fieldIndex("createtime"), Qt::Horizontal, ("createtime"));
    m_tableModel->setHeaderData(m_tableModel->fieldIndex("filename"), Qt::Horizontal, ("filename"));

    if(!m_tableModel->select())
        qDebug() << "select table failed!" << endl;
    else
        qDebug() << "select table success!" << endl;
}

std::shared_ptr<MyDBModel> DriverDatabase::getModel(){
    return m_tableModel;
}

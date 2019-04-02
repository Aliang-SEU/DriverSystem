#include "MyDBModel.h"
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>

MyDBModel::MyDBModel(QObject *parent,QSqlDatabase database)
    : QSqlTableModel(parent,database){
}

void MyDBModel::generateRoleNames(){
    roles.clear();
    int nbCols = this->columnCount();

    for (int i = 0; i < nbCols; i++){
        roles[Qt::UserRole + i + 1] = QVariant(this->headerData(i, Qt::Horizontal).toString()).toByteArray();
    }
}

QVariant MyDBModel::data(const QModelIndex &index, int role) const{
    if(index.row() >= rowCount()){
        return QString("");
    }
    if(role < Qt::UserRole){
        return QSqlQueryModel::data(index, role);
    }
    else{
        return record(index.row()).value(QString(roles.value(role)));
    }
}

bool MyDBModel::removeRow(const int row){
    qDebug() << this->rowCount();
    return this->removeRows(row, 1);
}

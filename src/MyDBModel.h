#ifndef MYDBMODEL_H
#define MYDBMODEL_H

#include <QAbstractListModel>
#include <QSqlTableModel>
#include <QSqlDatabase>

class MyDBModel : public QSqlTableModel{
    Q_OBJECT

public:
    MyDBModel(QObject *parent = Q_NULLPTR, QSqlDatabase db = QSqlDatabase());
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void generateRoleNames();

public slots:
    bool removeRow(const int row);

protected:
    QHash<int, QByteArray> roleNames() const{return roles;}

private:
    QHash<int, QByteArray> roles;
};

#endif // MYDBMODEL_H

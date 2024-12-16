#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "../filesManager/filesManager.h"


class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ListModel(QObject *parent = 0);

    ~ListModel() {};

public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QVector<QString> m_data;
    FilesManager filesManager;
};

#endif // LISTMODEL_H

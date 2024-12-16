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

enum data {
    name = Qt::UserRole,
    path = Qt::UserRole + 1
};

public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QVector<QString> m_data;
    FilesManager filesManager;

    // QAbstractItemModel interface
public:
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Q_INVOKABLE void loadVideos();
};

#endif // LISTMODEL_H

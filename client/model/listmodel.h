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
    bool setData(const QModelIndex &index, const QVariant &value, int role);

public:
    Q_INVOKABLE void loadVideos();
    Q_INVOKABLE QString getPrevious(const qsizetype &index) const;
    Q_INVOKABLE QString getNext(const qsizetype &index) const;

private:
    QVector<QString> m_data;
    FilesManager filesManager;
    static qsizetype currentIndex;
};

#endif // LISTMODEL_H

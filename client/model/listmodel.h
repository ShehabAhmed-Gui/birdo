#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QObject>

#include "../filesManager/filesManager.h"

class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ListModel(QObject *parent);

public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QVector<QString> m_data;
    AppManager filesManager;
};

#endif // LISTMODEL_H

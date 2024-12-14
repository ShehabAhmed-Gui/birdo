#include "listmodel.h"

ListModel::ListModel(QObject *parent) : QAbstractListModel(parent)
{
    m_data = filesManager.selectFiles();
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_data.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if (row < 0 || row >= m_data.count()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        return m_data.value(row);
    }

    return QVariant();
}

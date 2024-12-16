#include "listmodel.h"
#include <qcolor.h>

ListModel::ListModel(QObject *parent) : QAbstractListModel{parent}
{
    m_data = QColor::colorNames();
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

    if (role == Qt::UserRole) {
        QString koko = m_data.at(row).split('/').last().split('.').first();
        return koko;
    }

    return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    return {{Qt::UserRole, "name"}};
}

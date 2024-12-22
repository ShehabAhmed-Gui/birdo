#include "listmodel.h"
#include <qcolor.h>

ListModel::ListModel(QObject *parent) : QAbstractListModel{parent}
{
}

qsizetype ListModel::currentIndex = 0;

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

    switch(role) {
        case name:
            return m_data.at(row).split('/').last().split('.').first();
            break;
        case path:
            return m_data.at(row);
            break;

        default: return QVariant();
    }

    return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    return {
        {name, "name"},
        {path, "path"}
    };
}

bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::UserRole) {
        m_data[index.row()] = value.toString();

        return true;
    }

    return false;
}

void ListModel::loadVideos()
{
    currentIndex = 0;
    QVector<QString> selected = filesManager.selectFiles();

      for (const auto& item : selected) {
        if (!m_data.contains(item)) {
            beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
            m_data.append(item);
            endInsertRows();
        }
    }
}

QString ListModel::getPrevious(const qsizetype &index) const
{
    currentIndex = index;
    if (currentIndex <= 0) {
        currentIndex = m_data.size();
    }

    if (currentIndex > 0) {
        return m_data.at(currentIndex - 1);
    }
    return QString();
}

QString ListModel::getNext(const qsizetype &index) const
{
    currentIndex = index;
    if (currentIndex >= m_data.size() - 1) {
        currentIndex = -1;
    }

    if (currentIndex >= -1) {
        return m_data.at(currentIndex + 1);
    }
    return QString();
}

#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>

#include "../settings/settingsManager.h"

class AppManager : public QObject
{
    Q_OBJECT
public:
    explicit AppManager(QObject *parent = nullptr);

    Q_INVOKABLE QString selectFile();

    Q_INVOKABLE QVector<QString> selectFiles();

private:
    QFileDialog m_dialog;

    QString m_defaultPath;
    QString supportedVids;
    QString m_selected;

    SettingsManager settings;
};

#endif // APPMANAGER_H

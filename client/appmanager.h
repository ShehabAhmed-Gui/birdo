#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>

#include "settingsmanager.h"

class AppManager : public QObject
{
    Q_OBJECT
public:
    explicit AppManager(QObject *parent = nullptr);

    Q_INVOKABLE QString selectFile();

private:
    QFileDialog m_dialog;

    QString m_defaultPath;
    QString supportedVids;
    QString m_selected;

    SettingsManager settings;
};

#endif // APPMANAGER_H

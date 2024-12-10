#include "settingsmanager.h"

SettingsManager::SettingsManager(QObject *parent)
    : QObject{parent},
    m_settings(QSettings::NativeFormat, QSettings::UserScope, "Birdo", "Birdo"),
    m_settingsLocation(m_settings.fileName())
{qDebug() << "Called";}

SettingsManager::~SettingsManager()
{
    m_settings.clear();
}

void SettingsManager::saveSettings(const QString &group, QString key, QVariant data) {
    m_settings.beginGroup(group);

    m_settings.setValue(key, data);

    m_settings.endGroup();

    m_settings.sync();
}

QVariant SettingsManager::getSetting(const QString &group, QString key, const QVariant &defaultValue) {
    m_settings.beginGroup(group);

    QVariant value = m_settings.value(key);

    m_settings.endGroup();

    if (key == "muted") return value.toBool();

    return value;
}

#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>
#include <QList>
#include <QDebug>

class SettingsManager : public QObject
{
    Q_OBJECT
public:
    explicit SettingsManager(QObject *parent = nullptr);

    ~SettingsManager();


    QStringList getKeys(QString group);
    void removeKey(QString group, QString key);

    Q_INVOKABLE inline QString getSettLocation() const {
        return m_settingsLocation;
    }

    Q_INVOKABLE void saveSettings(const QString &group, QString key, QVariant data);

    Q_INVOKABLE QVariant getSetting(const QString &group, QString key, const QVariant &defaultValue = QVariant());

private:
    QSettings m_settings;
    QString m_settingsLocation;
};

#endif // SETTINGSMANAGER_H

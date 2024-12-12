#include "appmanager.h"

AppManager::AppManager(QObject *parent)
    : QObject{parent}, supportedVids("*.mp4 *.wav"), settings{SettingsManager()}
{
    m_defaultPath = settings.getSetting("Files", "lastSelectedPath").toString().remove("file://");
}

QString AppManager::selectFile()
{
    QString file = m_dialog.getOpenFileName(nullptr, "Select video file", m_defaultPath, supportedVids);

#ifdef Q_OS_LINUX
    if (!file.isEmpty()) {
        file = "file://" + file;
        settings.saveSettings("Files", "lastSelectedPath", file);
        return file;
    }

#endif
    if (!file.isEmpty()) {
        settings.saveSettings("Files", "lastSelectedPath", file);
        return file;
    }

    return settings.getSetting("Video", "video").toString();
}

#ifndef PLAYER_H
#define PLAYER_H

#include "defs.h"

#include <QFileDialog>
#include <QMediaPlayer>

struct VideoInformation
{
    VideoInformation(QString videoName, QString videoLocation, quint64 videoLengh) {
        m_videoName = videoName; m_videoLocation = videoLocation; m_videolengh = videoLengh;
    }

    QString m_videoName,  m_videoLocation;
    quint64 m_videolengh;
};

class Player : QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentVideoName READ currentVideoName WRITE currentVideoName NOTIFY  currentVideoNameChanged FINAL)
    Q_INVOKABLE QStringList videos;
public:
     Player();
    ~Player();
private:
    QString m_currentVideoName;

public:
    VideoInformation *videoInformation;
    QString currentVideoName() const;
    void currentVideoName(const QString &newCurrentVideoName);

signals:
    void currentVideoNameChanged();
};

#endif // PLAYER_H

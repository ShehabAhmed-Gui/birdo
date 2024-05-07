
#ifndef VIDEOCONTROLS_H
#define VIDEOCONTROLS_H

#include "defs.h"
#include <QMediaPlayer>
#include <QPushButton>
#include <QAudioOutput>
#include <QAudio>

using namespace birdo;

class videocontrols : public QWidget
{
    Q_OBJECT
public:
    videocontrols(QWidget *parent = nullptr);
public slots:
    void setRewind(qint64 position);
    void setState(QMediaPlayer::PlaybackState state);
    void setMuted(bool muted);
signals:
    void updateVideoState(VideoStates state);
    void openFile();
    void muteChange(bool mute);
    void volumeChanging(float volume);
    void rewind(qint64);
public slots:
    void videoClicked();
    void openFileClicked();
    void rewindClicked();
    void volumeSliderMoving(float pos);
    void muteClicked();
private:
    VideoStates m_state;

    qint64 rewindPos = 0;
    float currVolume;
    bool player_mute;
    QMediaPlayer::PlaybackState player_state = QMediaPlayer::StoppedState;
};

#endif // VIDEOCONTROLS_H

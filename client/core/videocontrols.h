
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
    void setSeekBackward(qint64 position);
    void setSeekForward(qint64 position);
    void setVideoState(QMediaPlayer::PlaybackState state);
    void setVolumeState(bool state);
    void setVideoPosition(qint64 position);
signals:
    void updateVideoState(VideoStates state);
    void updateVolumeState(VolumeStates muted);
    void openFile();

    void volumeChanging(float volume);
    void seekVideoPosition(qint64 pos);
public slots:
    void videoClicked();
    void openFileClicked();
    void rewindBackwardClicked();
    void rewindForwardClicked();
    void volumeSliderMoving(float pos);
    void muteClicked();
private:
    VideoStates m_state;
    VolumeStates m_volumeStates;

    qint64 rewindPos = 0;
    float currVolume;
    bool player_mute = false;
    QMediaPlayer::PlaybackState player_state = QMediaPlayer::StoppedState;
};

#endif // VIDEOCONTROLS_H

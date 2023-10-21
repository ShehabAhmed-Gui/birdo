
#ifndef VIDEOCONTROLS_H
#define VIDEOCONTROLS_H

#include <QMediaPlayer>
#include <QPushButton>
#include <QAudioOutput>
#include <QAudio>

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
    void stop();
    void play();
    void pause();
    void openFile();
    void muteChange(bool mute);
    void volumeChanging(float volume);
    void rewind(qint64);
public slots:
    void videoClicked();
    void openFileClicked();
    void playClicked();
    void rewindClicked();
    void volumeSliderMoving(float pos);
    void muteClicked();
private:
    qint64 rewindPos = 0;
    float currVolume;
    bool player_mute;
    QMediaPlayer::PlaybackState player_state = QMediaPlayer::StoppedState;
};

#endif // VIDEOCONTROLS_H

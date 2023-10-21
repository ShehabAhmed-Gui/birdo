#include "videocontrols.h"

#include <QMediaPlayer>
videocontrols::videocontrols(QWidget *parent) :QWidget(parent)
{

}

void videocontrols::setState(QMediaPlayer::PlaybackState state)
{
    player_state = state;
    if(state == QMediaPlayer::StoppedState){emit stop();}
}

void videocontrols::setRewind(qint64 position)
{
    rewindPos = position;
    if(position > 10000){
        rewindPos -=10000;}
    else{
        rewindPos = 0;
    }
}

void videocontrols::playClicked()
{
    switch (player_state) {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        emit play();
        break;
    case QMediaPlayer::PlayingState:
        emit pause();
        break;
    default:
        break;
    }
}

void videocontrols::setMuted(bool muted)
{
    if(muted != player_mute){player_mute = muted;}
}

void videocontrols::videoClicked()
{
    switch (player_state) {
    case QMediaPlayer::StoppedState:
        emit play();
        break;
    case QMediaPlayer::PausedState:
        emit play();
        break;
    case QMediaPlayer::PlayingState:
        emit pause();
        break;
    default:
        break;
    }
}

void videocontrols::openFileClicked()
{
    emit openFile();
}

void videocontrols::rewindClicked()
{
    emit rewind(rewindPos);
}

void videocontrols::volumeSliderMoving(float pos)
{
    emit volumeChanging(pos /100);
}

void videocontrols::muteClicked()
{
    emit muteChange(!player_mute);
}


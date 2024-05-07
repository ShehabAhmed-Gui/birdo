#include "videocontrols.h"

#include <QMediaPlayer>
videocontrols::videocontrols(QWidget *parent) :QWidget(parent)
{

}

void videocontrols::setState(QMediaPlayer::PlaybackState state)
{
    switch(state)
    {
        case QMediaPlayer::StoppedState:  m_state = VideoStates::Stopped;
        case QMediaPlayer::PausedState: m_state = VideoStates::Paussed; break;
        case QMediaPlayer::PlayingState: m_state = VideoStates::Playing; break;
        default:
            m_state = VideoStates::Stopped;
    }
}

void videocontrols::setRewind(qint64 position)
{
    rewindPos = position;
    if(position > 10000){
        rewindPos -= 10000;
    }else{
        rewindPos = 0;
    }
}

void videocontrols::setMuted(bool muted)
{
    if(muted != player_mute)
        player_mute = muted;
}

void videocontrols::videoClicked()
{
    switch (m_state) {
    case VideoStates::Stopped: emit updateVideoState(m_state); break;
    case VideoStates::Paussed: emit updateVideoState(m_state); break;
    case VideoStates::Playing: emit updateVideoState(m_state); break;
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


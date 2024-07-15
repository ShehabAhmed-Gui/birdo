#include "videocontrols.h"

#include <QMediaPlayer>
videocontrols::videocontrols(QWidget *parent) :QWidget(parent)
{
}
void videocontrols::setVideoState(QMediaPlayer::PlaybackState state)
{
    switch(state) {
    case QMediaPlayer::StoppedState: m_state = VideoStates::Stopped;
    case QMediaPlayer::PausedState: m_state = VideoStates::Paussed; break;
    case QMediaPlayer::PlayingState: m_state = VideoStates::Playing; break;
    default:
        m_state = VideoStates::Stopped; break;
    }
}

void videocontrols::setVolumeState(bool state)
{
    switch((int)state) {
    case VolumeStates::Muted: m_volumeStates = VolumeStates::Muted; break;
    case VolumeStates::UnMuted:
    default:
        m_volumeStates = VolumeStates::UnMuted; break;
    }
}

void videocontrols::setVideoPositionState(qint64 position)
{
    rewindPos = position;
}

void videocontrols::setSeekBackward(qint64 position)
{
    position -= 10000;
    rewindPos = position;
    emit seekVideoPosition(rewindPos);
}

void videocontrols::setSeekForward(qint64 position)
{
    position += 10000;
    rewindPos = position;
    emit  seekVideoPosition(rewindPos);
}

void videocontrols::videoClicked()
{
    switch (m_state) {
    case VideoStates::Stopped: emit updateVideoState(m_state); break;
    case VideoStates::Paussed: emit updateVideoState(m_state); break;
    case VideoStates::Playing: emit updateVideoState(m_state); break;
    }
}

void videocontrols::openFileClicked()
{
    emit openFile();
}

void videocontrols::rewindBackwardClicked()
{
    setSeekBackward(rewindPos);
}

void videocontrols::rewindForwardClicked()
{
    setSeekForward(rewindPos);
}

void videocontrols::volumeSliderMoving(float pos)
{
    emit volumeChanging(pos/100);
}

void videocontrols::muteClicked()
{
    switch(m_volumeStates) {
    case VolumeStates::Muted: emit updateVolumeState(VolumeStates::Muted); break;
    case VolumeStates::UnMuted: emit updateVolumeState(VolumeStates::UnMuted); break;
    }
}

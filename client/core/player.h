#ifndef PLAYER_H
#define PLAYER_H

#include "defs.h"
#include "videocontrols.h"
#include "adjustapp.h"
#include "videowidget.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QAudio>
#include <QFileDialog>
#include <QStandardPaths>
#include <QSysInfo>
#include <QThread>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QEvent>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QSlider>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT
public:
     Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void changeVideoState(VideoStates state);
    void stop();
    void play();
    void pause();

    void goneAfk();
    void mouseMoving();

    void openVideo();

    void FullScreen();
    void Restoredown();
    void seek(int currPosition);

    void setDuration(qint64 duration);
    void setPosition(qint64 position);
    void changeVolumeState(VolumeStates muted);
    void setVolumeText(float volume);
signals:
    void setVideoFullScreen();
private:
    QEvent *event;
    QStringList loadVideo;
    QString ToolStyle;
    qint64 maximum;
    double volumeRange;

    adjustapp *editTheApp;
    videocontrols *controls;
    videowidget *videoWidget;

    QWidget *Bottom;
    QVideoWidget *video;
    QMediaPlayer *player;
    QAudioOutput *audio;

    QAbstractSlider *volumeSlider;
    QAbstractSlider *videoProgress;

    QAbstractButton *openFile;
    QAbstractButton *playButton;
    QAbstractButton *audioButton;
    QAbstractButton *exitButton;
    QAbstractButton *MiniMize;
    QAbstractButton *fullScreen;
    QAbstractButton *btm_Button_fullScreen;
    QAbstractButton *seekBackwardButton;
    QAbstractButton *seekForwardButton;

    QLabel *currVolume;
public:
    void loadVolume();
    void loadvideo();
private:
    Ui::Widget *ui;
};

#endif // PLAYER_H

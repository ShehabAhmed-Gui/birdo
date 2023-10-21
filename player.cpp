#include "player.h"
#include "ui_Player.h"
#include <QSplitter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*on-exeCute*/
    Widget::setWindowIcon(QIcon(":/Icons/Resoruces/appIcon.png"));
    Widget::setWindowTitle("Birdo");
    Widget::setWindowFlags(Qt::FramelessWindowHint);
    /*initilaize Vribls*/
    controls = new videocontrols();
    editTheApp = new adjustapp();
    videoWidget = new videowidget();

    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);
    /*Buttons*/
    openFile = ui->openFile;
    playButton = ui->Play_PAUSe;
    audioButton = ui->Audio;
    exitButton = ui->Exit_4;
    MiniMize = ui->MiniMize_4;
    fullScreen = ui->Full_Restore_Screen_4;
    btm_Button_fullScreen = ui->Btm_fullScreen;
    rewindButton = ui->BackWard;
    /*Widget*/
    Bottom = ui->Bottom;
    /*Labels*/
    currVolume = ui->currVolume;
    /*App-Sliders*/
    volumeSlider = ui->Audio_Slider;
    videoProgress = ui->Video_LEngth_2;
    /*call-Functions*/
    loadvideo();
    loadVolume();
    /*connects*/
    connect(exitButton, &QAbstractButton::clicked, this, &Widget::close);
    connect(MiniMize, &QAbstractButton::clicked, this, &Widget::showMinimized);
    connect(videoProgress, &QSlider::sliderMoved, this, &Widget::seek);

    connect(openFile, &QAbstractButton::clicked, controls, &videocontrols::openFileClicked);
    connect(controls, &videocontrols::openFile, this, &Widget::openFileMethod);

    connect(ui->video_player, &videowidget::videoClicked, controls, &videocontrols::videoClicked);
    connect(ui->video_player, &videowidget::goneAfk, this, &Widget::goneAfk);
    connect(ui->video_player, &videowidget::afkChanging, this, &Widget::mouseMoving);
}
Widget::~Widget()
{
    delete ui;
    delete controls;
    delete videoWidget;
}
void Widget::loadvideo()
{
    controls->setState(player->playbackState());
    controls->setMuted(audio->isMuted());
    controls->setRewind(player->position());

    editTheApp->setFullScreen(Widget::isFullScreen());
    connect(editTheApp, &adjustapp::fullScreenChange, this, &Widget::FullScreen);
    connect(editTheApp, &adjustapp::restoreDown, this, &Widget::Restoredown);
    connect(fullScreen, &QAbstractButton::clicked, editTheApp, &adjustapp::fullScreenClicked);   
    connect(btm_Button_fullScreen, &QAbstractButton::clicked, editTheApp,
            &adjustapp::fullScreenClicked);

    connect(controls, &videocontrols::stop, this, &Widget::stop);
    connect(controls, &videocontrols::play, this, &Widget::play);
    connect(controls, &videocontrols::pause, this, &Widget::pause);
    connect(playButton, &QAbstractButton::clicked, controls, &videocontrols::playClicked);

    connect(controls, &videocontrols::muteChange, this, &Widget::setMuted);
    connect(audio, &QAudioOutput::mutedChanged, controls, &videocontrols::setMuted);
    connect(audioButton, &QAbstractButton::clicked, controls, &videocontrols::muteClicked);

    /*setting the Video*/
    player->setAudioOutput(audio);
    video = ui->video_player;
    player->setVideoOutput(video);

    connect(player, &QMediaPlayer::durationChanged, this, &Widget::setDuration);
    connect(player, &QMediaPlayer::positionChanged, this, &Widget::setPosition);
    connect(controls, &videocontrols::rewind, player, &QMediaPlayer::setPosition);

    connect(player, &QMediaPlayer::positionChanged, controls, &videocontrols::setRewind);
    connect(rewindButton, &QAbstractButton::clicked, controls, &videocontrols::rewindClicked);

    connect(player, &QMediaPlayer::playbackStateChanged, controls, &videocontrols::setState);
    connect(player, &QMediaPlayer::hasVideoChanged, this, &Widget::play);

}

void Widget::loadVolume()
{
    const float sound(0.50);
    audio->setVolume(sound);
    const QString soundToString = QString::number(sound *100);

    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(sound *100);
    currVolume->setText(soundToString);

    connect(volumeSlider, &QAbstractSlider::sliderMoved, controls,
            &videocontrols::volumeSliderMoving);

    connect(controls, &videocontrols::volumeChanging, audio, &QAudioOutput::setVolume);
    connect(controls, &videocontrols::volumeChanging, this, &Widget::setVolumeText);
}
void Widget::openFileMethod()
{
    openFile->setText("Proccesing");
    loadVideo = QFileDialog::getOpenFileName(this, "select Video",
                                                         "/home", ("*.mp4 *.wav"));
    if(loadVideo != "")
    {
        player->setSource(QUrl::fromLocalFile(loadVideo));
        openFile->setText("openFile");
        emit controls->play();
    }
    else{openFile->setText("openFile");}
}

void Widget::setDuration(qint64 duration)
{
    maximum = (duration / 1000);
    videoProgress->setMaximum(duration);
}

void Widget::setPosition(qint64 position)
{
    if(!videoProgress->isSliderDown()){
        videoProgress->setValue(position);}
}

void Widget::setMuted(bool muted)
{
    if(muted)
    {
        audio->setMuted(muted);
        audioButton->setIcon(QIcon(":/Icons/Resoruces/Muted.png"));
        audioButton->setIconSize(QSize(24,24));
        audioButton->setToolTip("unMute");
    }
    else
    {
        audio->setMuted(muted);
        audioButton->setIcon(QIcon(":/Icons/Resoruces/Speaker.png"));
        audioButton->setToolTip("Mute");
    }
}

void Widget::setVolumeText(float volume)
{
    volume = volume *100;
    QString Volume = QString::number(volume);
    currVolume->setText(Volume);
}

void Widget::goneAfk()
{
    this->setCursor(Qt::BlankCursor);
    Bottom->setVisible(false);
    ui->Head_Bar->setVisible(false);
}

void Widget::mouseMoving()
{
    this->setCursor(Qt::CursorShape::ArrowCursor);
    Bottom->setVisible(true);
    ui->Head_Bar->setVisible(true);
}

void Widget::seek(int currPosition)
{
    player->setPosition(currPosition);
}

void Widget::stop()
{
    player->setPosition(0);
    playButton->setIcon(QIcon(":/Icons/Resoruces/Play.png"));
}

void Widget::play()
{
    if(player->hasVideo() == true){
        player->play();
        playButton->setIcon(QIcon(":/Icons/Resoruces/Pause.png"));
        playButton->setToolTip("Pause");}
}

void Widget::pause()
{
    player->pause();
    playButton->setIcon(QIcon(":/Icons/Resoruces/Play.png"));
    playButton->setToolTip("Play");
}

void Widget::FullScreen()
{
    Widget::showFullScreen();
    fullScreen->setIcon(QIcon(":/Icons/Resoruces/restoreDown.png"));
    fullScreen->setToolTip("restoreDown");
    btm_Button_fullScreen->setIcon(QIcon(":/Icons/Resoruces/restoreDown.png"));
    btm_Button_fullScreen->setToolTip("restoreDown");
}

void Widget::Restoredown()
{
    Widget::showNormal();
    fullScreen->setIcon(QIcon(":/Icons/Resoruces/fullScreen.png"));
    fullScreen->setToolTip("fullScreen");
    btm_Button_fullScreen->setIcon(QIcon(":/Icons/Resoruces/fullScreen_Btm.png"));
    btm_Button_fullScreen->setToolTip("fullScreen");
}

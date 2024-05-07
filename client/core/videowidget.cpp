#include "videowidget.h"

videowidget::videowidget(QWidget *parent) : QVideoWidget(parent)
{
    installEventFilter(this);
    this->setAttribute(Qt::WA_Hover);

    checkingAfk();
    connect(this, &videowidget::afkChanging, this, &videowidget::restartTimer);
}

void videowidget::mouseDoubleClickEvent(QMouseEvent *event)
{

    setFullScreen(!isFullScreen());
    event->accept();
}

void videowidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit videoClicked();
    }
    else {return;}
}

bool videowidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this && event->type() == QEvent::HoverMove)
    {
        emit afkChanging();
    }
    return false;
}

void videowidget::restartTimer()
{

    timer->stop();
    timer->start(5000);
}

void videowidget::checkingAfk()
{
    timer = new QTimer(this);
    timer->start(5000);
    connect(timer, &QTimer::timeout, this, [&]{emit goneAfk();});
}

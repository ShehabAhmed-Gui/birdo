#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H
#include <QVideoWidget>

#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <QObject>
#include <QTimer>

class videowidget : public QVideoWidget
{
    Q_OBJECT
public:
     videowidget(QWidget *parent = nullptr);
signals:
    void videoClicked();
    void afkChanging();

    void goneAfk();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
public:
    void restartTimer();
    void checkingAfk();
private:
    QTimer *timer;
};

#endif // VIDEOWIDGET_H

#ifndef ADJUSTAPP_H
#define ADJUSTAPP_H

#include <QObject>
#include <QWidget>


class adjustapp : public QWidget
{
    Q_OBJECT
public:
    adjustapp();
signals:
    void fullScreenChange(bool fullScreen);
    void restoreDown(bool fullScreen);
public slots:
    void setFullScreen(bool fullScreen);
    void fullScreenClicked();
private:
    bool isFull_Screen = false;
};

#endif // ADJUSTAPP_H

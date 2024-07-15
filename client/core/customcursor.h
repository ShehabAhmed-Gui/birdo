#ifndef CUSTOMCURSOR_H
#define CUSTOMCURSOR_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QCursor>
#include <QPixmap>
#include <QQmlContext>
#include <QQuickItem>

class CursorHandler : public QObject
{
    Q_OBJECT
public:
    explicit CursorHandler(QObject *parent = nullptr);

    Q_INVOKABLE void setCustomCursor(QQuickItem *item, const QString &imagePath, int width = 40, int height = 40);
    Q_INVOKABLE void resetDefaultCursor(QQuickItem *item);
    Q_INVOKABLE void hideCursor(QQuickItem *item);
    Q_INVOKABLE void showCursor(QQuickItem *item);

private:
    QQuickWindow *findWindow(QQuickItem *item);
signals:
};

#endif // CUSTOMCURSOR_H

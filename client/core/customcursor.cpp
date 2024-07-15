#include "customcursor.h"

CursorHandler::CursorHandler(QObject *parent)
    : QObject{parent}
{}

void CursorHandler::setCustomCursor(QQuickItem *item, const QString &imagePath, int width, int height)
{
    QQuickWindow *window = findWindow(item);
    if (!window) {
        qWarning("CursorHandler::setCustomCursor - Could not find QQuickWindow");
        return;
    }

    QImage image(imagePath);
    if (image.isNull()) {
        qWarning("CursorHandler::setCustomCursor - Failed to load image %s", qPrintable(imagePath));
        return;
    }

    QPixmap pixmap = QPixmap::fromImage(image).scaled(width, height);
    if (pixmap.isNull()) {
        qWarning("CursorHandler::setCustomCursor - Failed to create QPixmap from image %s", qPrintable(imagePath));
        return;
    }

    QCursor cursor(pixmap);
    window->setCursor(cursor);
}

void CursorHandler::resetDefaultCursor(QQuickItem *item)
{
    if (item){
        QQuickItem *currentItem = item;
        while (currentItem) {
            QQuickWindow *window = qobject_cast<QQuickWindow *>(currentItem->window());
            if (window) {
                window->unsetCursor();
            }
            break;
        }
    }
}

void CursorHandler::hideCursor(QQuickItem *item)
{
    QQuickWindow *window = qobject_cast<QQuickWindow *>(item->window());
    window->setCursor(Qt::BlankCursor);
}

void CursorHandler::showCursor(QQuickItem *item)
{
    QQuickWindow *window = qobject_cast<QQuickWindow *>(item->window());
    window->setCursor(Qt::PointingHandCursor);
}

QQuickWindow *CursorHandler::findWindow(QQuickItem *item)
{
    if (!item) {
        return nullptr;
    }

    QQuickItem *currentItem = item;
    while (currentItem) {
        QQuickWindow *window = qobject_cast<QQuickWindow *>(currentItem->window());
        if (window) {
            return window;
        }
        currentItem = qobject_cast<QQuickItem *>(currentItem->parentItem());
    }

    return nullptr;
}

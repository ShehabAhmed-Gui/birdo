#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "core/customcursor.h"
#include "core/player.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CursorHandler>("CustomCursor", 1, 0, "CursorHandler");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/ui/qml/Main.qml")));

    app.setWindowIcon(QIcon(":/images/appIcon.png"));

    if (engine.rootObjects().isEmpty())
        return -1;

    Player player;

    return app.exec();
}

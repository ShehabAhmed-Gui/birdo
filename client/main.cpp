#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/ui/qml/Main.qml")));

    app.setWindowIcon(QIcon(":/images/appIcon.png"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

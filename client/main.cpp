#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "settingsmanager.h"

using namespace std;

int main(int argc, char *argv[])
{
    qmlRegisterSingletonInstance<SettingsManager>("com.qt.birdo", 1, 0, "AppSettings", new SettingsManager());

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/ui/qml/Main.qml")));

    app.setWindowIcon(QIcon(":/images/appIcon.png"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

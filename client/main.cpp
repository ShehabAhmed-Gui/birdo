#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QApplication>

#include "settingsmanager.h"
#include "appmanager.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterSingletonInstance<SettingsManager>("com.qt.birdo", 1, 0, "AppSettings", new SettingsManager(&app));
    qmlRegisterSingletonInstance("com.qt.birdo", 1, 0, "AppManager", new AppManager(&app));

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/ui/qml/Main.qml")));

    app.setWindowIcon(QIcon(":/images/icon.png"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

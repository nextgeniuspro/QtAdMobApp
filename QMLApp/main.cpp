#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "QtAdMob/QtAdMobBanner.h"
#include "QtAdMob/QtAdMobInterstitial.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlAdMobBanner::DeclareQML();
    QmlAdMobInterstitial::DeclareQML();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "test.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Test test;
    QAbstractListModel *userModel = chat::LibChat::instance().model()->usersListModel();
    QQmlContext *pcon=engine.rootContext();
    pcon->setContextProperty("usermodel", userModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

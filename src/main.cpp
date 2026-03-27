#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QIcon>

#include "BulbManager.h"
#include "Bulb.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("LightboxController");
    app.setOrganizationName("LightboxController");
    app.setApplicationVersion("1.0.0");

    // Note: Material style not used to avoid naming conflict with Qt3D's Material type
    // QQuickStyle::setStyle("Material");

    // Register QML types
    qmlRegisterType<Bulb>("LightboxController", 1, 0, "Bulb");
    qmlRegisterType<BulbManager>("LightboxController", 1, 0, "BulbManager");

    QQmlApplicationEngine engine;

    // Create and expose BulbManager as context property
    BulbManager bulbManager;
    engine.rootContext()->setContextProperty("bulbManager", &bulbManager);

    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

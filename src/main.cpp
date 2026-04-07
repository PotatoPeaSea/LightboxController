#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include <QIcon>

#include "BulbManager.h"
#include "Bulb.h"
#include "VideoPatternEngine.h"

int main(int argc, char *argv[])
{
    // Force Windows Media Foundation backend for video decoding.
    // DirectShow lacks H.264/H.265 decoders; WMF uses OS-native codecs.
    qputenv("QT_MULTIMEDIA_PREFERRED_PLUGINS", "windowsmediafoundation");

    QApplication app(argc, argv);
    app.setApplicationName("LightboxController");
    app.setOrganizationName("LightboxController");
    app.setApplicationVersion("1.0.0");

    // Note: Material style not used to avoid naming conflict with Qt3D's Material type
    // QQuickStyle::setStyle("Material");

    // Register QML types
    qmlRegisterType<Bulb>("LightboxController", 1, 0, "Bulb");
    qmlRegisterType<BulbManager>("LightboxController", 1, 0, "BulbManager");
    qmlRegisterType<VideoPatternEngine>("LightboxController", 1, 0, "VideoPatternEngine");

    QQmlApplicationEngine engine;

    // Create and expose context properties
    BulbManager bulbManager;
    VideoPatternEngine patternEngine;

    engine.rootContext()->setContextProperty("bulbManager", &bulbManager);
    engine.rootContext()->setContextProperty("patternEngine", &patternEngine);

    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

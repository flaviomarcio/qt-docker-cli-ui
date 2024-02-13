#ifdef QMFE_MODULE
    #include <QMfe>
    QMFE_CONSOLE_MAIN()//
#else
    #include <QGuiApplication>
    #include <QQmlApplicationEngine>

    int main(int argc, char* argv[]){
    #ifdef QT_DEBUG
        if (qEnvironmentVariableIsEmpty("QTGLESSTREAM_DISPLAY")) {
            qputenv("QT_QPA_EGLFS_PHYSICAL_WIDTH", QByteArray("213"));
            qputenv("QT_QPA_EGLFS_PHYSICAL_HEIGHT", QByteArray("120"));
        }
    #endif
        QGuiApplication app(argc, argv);

        QQmlApplicationEngine engine;
        const QUrl url(u"qrc:/main.qml"_qs);
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                         &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
        engine.load(url);

        return app.exec();
    }
#endif

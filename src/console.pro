TARGET = ConsoleApp
TEMPLATE = app

VERSION = 1.0
PRODUCT_NAME = QERPConsole
CURRENT_PROJECT_VERSION = 1.0.0

QT += core widgets network qml quick

CONFIG+=qml_debug
CONFIG+=c++20
CONFIG+=silent

include($$PWD/../3rdparty/qt-docker-cli-lib/qt-docker-cli.pri)
include($$PWD/../3rdparty/qmfe/qmfe-frontend.pri)

SOURCES += main.cpp

RESOURCES += \
    $$PWD/resources/public/public.qrc \

DEPENDPATH += .

OBJECTS_DIR = .obj
MOC_DIR = .moc




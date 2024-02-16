#include "./app_qml_register.h"
#include <QLocale>
#include <QMfe>
#include <QtDockerCli>
#include <QCoreApplication>
#include <QQmlContext>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QtDockerCli>

namespace DockerUI {

#define Q_UI_QML_REGISTER_ENUMS(enumClass, enumName)\
    qRegisterMetaType<enumClass>(#enumName);\
    qmlRegisterUncreatableType<enumClass>("QDKC", 0, 0, #enumName, "Not creatable as it is an enum type");\
    qmlRegisterUncreatableType<enumClass>("QDKC", 1, 0, #enumName, "Not creatable as it is an enum type")


#define Q_UI_QML_REGISTER_CLASS(CLASS, className)\
    qmlRegisterType<CLASS>("QDKC", 1, 0, #className);\
    qmlRegisterType<CLASS>("QDKC", 0, 0, #className)\

#define Q_UI_QML_REGISTER_NAME(NAME)\
    engine.rootContext()->setContextProperty(#NAME, &object);

Q_GLOBAL_STATIC(QtDockerCli::Instance, dockerInstance)


ObjectRegister::ObjectRegister(QObject *parent):QMFE::Register{parent}
{

}

void ObjectRegister::objectRegister(QQmlApplicationEngine &engine)
{
    Q_UNUSED(engine)

    {//basic class
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Container, DockerContainer);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Deploy, DockerDeploy);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Image, DockerImage);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Instance, DockerInstance);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Labels, DockerResourceLabels);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Mount, DockerMount);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Network, DockerNetwork);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Node, DockerNode);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Port, DockerPort);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Resource, DockerResource);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::ResourceLimit, DockerResourceLimit);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Server, DockerServer);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Service, DockerService);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Stack, DockerStack);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Swarm, DockerSwarm);
        Q_UI_QML_REGISTER_CLASS(QtDockerCli::Volume, DockerVolume);
    }

    engine.rootContext()->setContextProperty("dockerInstance", dockerInstance);
}


} // namespace QERPConsole

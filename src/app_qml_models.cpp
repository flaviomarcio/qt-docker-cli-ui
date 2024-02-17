#include "app_qml_models.h"

namespace DockerUI {

class DockerModelsPvt:public QObject{
public:
    DockerModels *parent=nullptr;
    QtDockerCli::Instance instance;
    QtDockerCli::Server server;
    QMFE::ObjectModel pages;
    QMFE::ObjectModel networks;
    QMFE::ObjectModel images;
    QMFE::ObjectModel volumes;
    QMFE::ObjectModel swarm;
    QMFE::ObjectModel nodes;
    QMFE::ObjectModel services;
    QMFE::ObjectModel containers;
    explicit DockerModelsPvt(DockerModels *parent):QObject{parent}, parent{parent}
    {
        pages.setItems(QObjectList({&networks,&images,&volumes,&swarm,&nodes,&services,&containers}));
        QObject::connect(&instance, &QtDockerCli::Instance::refreshed, this, &DockerModelsPvt::refreshed);
        QObject::connect(&instance, &QtDockerCli::Instance::started, parent, &DockerModels::started);
        QObject::connect(&instance, &QtDockerCli::Instance::connected, parent, &DockerModels::connected);
        QObject::connect(&instance, &QtDockerCli::Instance::fail, parent, &DockerModels::fail);
        QObject::connect(&instance, &QtDockerCli::Instance::finished, parent, &DockerModels::finished);
    }
private slots:
    void refreshed(){
        this->networks.setItems<QtDockerCli::Network>(instance.networks());
        this->images.setItems<QtDockerCli::Image>(instance.images());
        this->volumes.setItems<QtDockerCli::Volume>(instance.volumes());
        this->swarm.setItems<QtDockerCli::Swarm>(QList<QtDockerCli::Swarm*>({&instance.swarm()}));
        this->nodes.setItems<QtDockerCli::Node>(instance.nodes());
        this->services.setItems<QtDockerCli::Service>(instance.services());
        this->containers.setItems<QtDockerCli::Container>(instance.containers());
        emit this->parent->refreshed();
    }
};

DockerModels::DockerModels(QObject *parent)
    : QObject{parent}, p{new DockerModelsPvt{this}}
{}

void DockerModels::clear()
{
    for(auto&o:p->pages.list()){
        auto model=dynamic_cast<QMFE::ObjectModel*>(o);
        if(model!=nullptr)
            model->clear();
    }
}

void DockerModels::refresh()
{
    p->instance.refresh();
}

QtDockerCli::Instance &DockerModels::instance()
{
    return p->instance;
}

QtDockerCli::Server *DockerModels::server()
{
    return &p->server;
}

void DockerModels::setServer(const QtDockerCli::Server *newServer)
{
    if(newServer==nullptr){
        this->clear();
        emit refreshed();
        return;
    }

    p->server.setValues(newServer->toHash());
    emit this->refreshed();
}

QMFE::ObjectModel *DockerModels::pages() const
{
    return &p->pages;
}

QMFE::ObjectModel *DockerModels::networks() const
{
    return &p->networks;
}

QMFE::ObjectModel *DockerModels::images() const
{
    return &p->images;
}

QMFE::ObjectModel *DockerModels::volumes() const
{
    return &p->volumes;
}

QMFE::ObjectModel *DockerModels::swarm() const
{
    return &p->swarm;
}

QMFE::ObjectModel *DockerModels::nodes() const
{
    return &p->nodes;
}

QMFE::ObjectModel *DockerModels::services() const
{
    return &p->services;
}

QMFE::ObjectModel *DockerModels::containers() const
{
    return &p->containers;
}

} // namespace DockerUI

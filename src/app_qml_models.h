#pragma once

#include <QObject>
#include <QtDockerCli>
#include <QMfe>

namespace DockerUI {

class DockerModelsPvt;

//!
//! \brief The DockerModels class
//!
class DockerModels : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QMFE::ObjectModel *pages READ pages NOTIFY pagesChanged)
    Q_PROPERTY(QtDockerCli::Server *server READ server WRITE setServer NOTIFY serverChanged)
    Q_PROPERTY(QMFE::ObjectModel *networks READ networks NOTIFY networksChanged)
    Q_PROPERTY(QMFE::ObjectModel *images READ images NOTIFY imagesChanged)
    Q_PROPERTY(QMFE::ObjectModel *volumes READ volumes NOTIFY volumesChanged)
    Q_PROPERTY(QMFE::ObjectModel *swarm READ swarm NOTIFY swarmChanged)
    Q_PROPERTY(QMFE::ObjectModel *nodes READ nodes NOTIFY nodesChanged)
    Q_PROPERTY(QMFE::ObjectModel *services READ services NOTIFY servicesChanged)
    Q_PROPERTY(QMFE::ObjectModel *containers READ containers NOTIFY containersChanged)
public:
    //!
    //! \brief DockerModels
    //! \param parent
    //!
    Q_INVOKABLE explicit DockerModels(QObject *parent = nullptr);

    //!
    //! \brief clear
    //!
    Q_INVOKABLE void clear();

    //!
    //! \brief refresh
    //!
    Q_INVOKABLE void refresh();

    //!
    //! \brief instance
    //! \return
    //!
    QtDockerCli::Instance &instance();

    //!
    //! \brief server
    //! \return
    //!
    QtDockerCli::Server *server();
    void setServer(const QtDockerCli::Server *newServer);

    //!
    //! \brief pages
    //! \return
    //!
    QMFE::ObjectModel *pages()const;

    //!
    //! \brief networks
    //! \return
    //!
    QMFE::ObjectModel *networks()const;

    //!
    //! \brief images
    //! \return
    //!
    QMFE::ObjectModel *images()const;

    //!
    //! \brief volumes
    //! \return
    //!
    QMFE::ObjectModel *volumes()const;

    //!
    //! \brief swarm
    //! \return
    //!
    QMFE::ObjectModel *swarm()const;

    //!
    //! \brief nodes
    //! \return
    //!
    QMFE::ObjectModel *nodes()const;

    //!
    //! \brief services
    //! \return
    //!
    QMFE::ObjectModel *services()const;

    //!
    //! \brief containers
    //! \return
    //!
    QMFE::ObjectModel *containers()const;

signals:
    void started();
    void connected();
    void fail(const QString &message);
    void refreshed();
    void finished();

    void pagesChanged();
    void serverChanged();
    void networksChanged();
    void imagesChanged();
    void volumesChanged();
    void swarmChanged();
    void nodesChanged();
    void servicesChanged();
    void containersChanged();
private:
    DockerModelsPvt *p=nullptr;
};

} // namespace DockerUI

#pragma once

#include <QMfe>
#include <QQmlApplicationEngine>

namespace DockerUI {

//!
//! \brief The Register class
//!
class ObjectRegister : public QMFE::Register
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit ObjectRegister(QObject *parent = nullptr);

    //!
    //! \brief objectRegister
    //! \param engine
    //!
    virtual void objectRegister(QQmlApplicationEngine &engine);

signals:

};

Q_MFE_OBJECT_REGISTER(ObjectRegister);

}

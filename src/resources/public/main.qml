import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window 2.15
import QtQuick.Controls.Material
import QMFE
import "qrc:/QMFE/EngineV1"
import "qrc:/QMFE/Home"
import "qrc:/QMFE/Layout"
import "qrc:/QMFE/Controls"
import "qrc:/Customer"

ApplicationWindow {
    id: root
    visible : true
    title : qsTr("QMFEConsole")
    height: 600
    width: 1000

    QMFEApplication{
        id: mfeApp
        root: root
        z:0
        anchors.fill: parent
        visible: true

        onBeforeInit: {
            QMFEFactory.insert("home",dockerHome)
        }

        onCompleted: {
        }
    }

    Component{
        id: dockerHome
        DockerHome{
            anchors.fill: parent
        }
    }

    font{
        pixelSize: DesignDefinition.scale.font.pixelSize
    }

    Component.onCompleted: {
        if(qmfeApp.osUtil.isQ_DEBUG){
            root.x=DesignMeasures.centerX(root.width)
            root.y=DesignMeasures.centerY(root.height)
        }
    }
}

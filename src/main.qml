import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
import "qrc:/QMFE/Home"
import QMFE;

ApplicationWindow {
    id: root
    visible : true
    title : qsTr("ERP-Transul")
    height: 800
    width: 1600
//    x:DesignMeasures.centerX(root.width)
//    y:DesignMeasures.centerY(root.height)

    Item{
        id: rootContainer
        anchors.fill: parent
        visible: !show.visible
    }

    Component{
        id: application
        QMFEApplication{
            root: root
            parent: rootContainer
            anchors.fill: parent
        }
    }

    Loader{
        id: loader
    }

    Component.onCompleted: {
        loader.sourceComponent=application
    }
}

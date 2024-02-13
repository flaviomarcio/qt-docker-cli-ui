import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window 2.15
import QtQuick.Controls.Material
import QMFE
import "qrc:/QMFE/Home"
import "qrc:/QMFE/Layout"
import "qrc:/QMFE/Controls"

QMFEPage {
    id: control
    title: qsTr("DockerListItem.qml")

    signal refresh()

    ColumnLayout{
        anchors.fill: parent
        QMFETitleBox{
            Layout.fillWidth: true
            text: control.title
        }
        ColumnLayout{
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}

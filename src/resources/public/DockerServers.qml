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

Item {
    id: control
    visible : true

    ColumnLayout{
        anchors.fill: parent
        SwipeView{
            Layout.fillWidth: true
            Layout.fillHeight: true
            interactive: false
            currentIndex: tab.currentIndex
            DockerDashBoard{
            }
            DockerSessions{
            }
        }
        QMFETabBar{
            id: tab
            Layout.fillWidth: true
            position: TabBar.Footer
            model: ["Dashboard", "Sessions"]
        }
    }


}

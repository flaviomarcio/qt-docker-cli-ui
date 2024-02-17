import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window 2.15
import QtQuick.Controls.Material
import QMFE
import QDKC
import "qrc:/QMFE/EngineV1"
import "qrc:/QMFE/Home"
import "qrc:/QMFE/Layout"
import "qrc:/QMFE/Controls"

ColumnLayout {
    id: control
    visible : true
    property DockerServer server;

    function refresh(){
        if(control.server===undefined || control.server===null){
            dockerModels.clear()
            return;
        }
    }
    onServerChanged: {
        dockerModels.server=control.server;
    }
    QMFETitleBox{
        Layout.fillWidth: true
        text: (control.server===null)?"No server":control.server.name;
    }
    SwipeView{
        Layout.fillWidth: true
        Layout.fillHeight: true
        Repeater{
            model: dockerModels.pages
            delegate: DockerListItem{
                property QMFEObjectModel objModel: model.object
                model: objModel
            }
        }
    }
    QMFETabBar{
        id: tab
        Layout.fillWidth: true
        position: TabBar.Footer
        model: dockerModels.pages//["Containers", "Services", "Stacks", "Images", "Volumes", "Network", "Nodes", "Swarm"]
    }
    DockerModels{
        id: dockerModels
        onStarted: {
        }
        onConnected: {
        }
        onRefreshed: {
        }
        onFail: message => {
        }
        onFinished: {
        }
    }
}

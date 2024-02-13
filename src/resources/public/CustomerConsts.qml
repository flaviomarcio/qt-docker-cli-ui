import QtQuick

Item {
    readonly property string mfeCargoCollectRegister : String("CargoCollectRegister").toLowerCase()
    readonly property string mfeCargoCollectRegisterEdit: String("CargoCollectRegisterEdit").toLowerCase()
    readonly property string mfeCargoDashboard: String("CargoDashboard").toLowerCase()

    function proxyForm(inputType){
        return compCargoDeshboardForm
    }
}


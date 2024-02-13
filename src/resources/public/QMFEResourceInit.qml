import QtQuick
import "qrc:/QMFE/Business/Forms"
import "qrc:/Customer/CargoCollect"
import "qrc:/Customer/Report"


Item {
    id: control

    readonly property string moduleName: "QMFEResourceInit"

    signal init()

    CustomerConsts{
        id: consts
    }

    Component{
        id: mfeInputRegister
        QMFEInputRegister{
        }
    }

    Component{
        id: mfeInputRecordEdit
        QMFEInputRecordEdit{
        }
    }


    Component{
        id: mfeCargoCollectRegister
        CargoCollectRegister{
        }
    }

    Component{
        id: mfeCargoDashboard
        ReportCargoDeshboard{
        }
    }

    onInit:
    {
        console.log(`${control.moduleName}::init::started`)
        QMFEInputFactory.proxyComponent=undefined/*function(inputType){
            if(!inputType)
                return undefined;
            var __return=undefined
            let inputTypeLW=String(inputType).toLowerCase()
            switch (inputTypeLW){
            case ccr.mfeCargoCollectRegister:
                __return=mfeCargoCollectRegister;
                break
            default:
                return undefined
            }
            console.log(`${control.moduleName}::proxyComponent.resolved: ${inputType}`)
        }*/
/*
*/
        QMFEInputFactory.proxyComponentForm=function(inputType){
            if(!inputType)
                return undefined;

            var __return=undefined

            let inputTypeLW=String(inputType).toLowerCase()
            switch (inputTypeLW){
            case consts.mfeCargoCollectRegister:
                __return=mfeCargoCollectRegister;
//                __return=mfeInputRegister
                break
            case consts.mfeCargoCollectRegisterEdit:
                __return=mfeInputRecordEdit
//                __return=mfeCargoCollectRegisterEdit;
                break
            case consts.mfeCargoDashboard:
                __return=mfeCargoDashboard
//                __return=mfeCargoCollectRegisterEdit;
                break
            default:
                return undefined
            }
            console.log(`${control.moduleName}::proxyComponentForm.resolved: ${inputType}`)
            return __return;
        }
        console.log(`${control.moduleName}::init::finished`)
    }
}

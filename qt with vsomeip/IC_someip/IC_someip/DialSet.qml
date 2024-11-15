import QtQuick 2.0
import QtQuick.Controls 2.0
import "."
Item {
    id: dialSet

    width: 360
    height: 360


    Dial{
        id: dial_default
        anchors.verticalCenter: parent.verticalCenter
        anchors.centerIn: parent

        visible: modeObject.modeValue === "#A2F2D9" ? true : false

        property int dialSize: dialSet.width
        modeColor: "#A2F2D9"
    }

    Dial{
        id: dial_sports
        anchors.verticalCenter: parent.verticalCenter
        anchors.centerIn: parent
        visible: modeObject.modeValue === "#411414" ? true : false

        property int dialSize: dialSet.width
        modeColor: "#411414"
    }

    Dial{
        id: dial_simple
        anchors.verticalCenter: parent.verticalCenter
        anchors.centerIn: parent
        visible: modeObject.modeValue === "#120102" ? true : false
        z: -1

        property int dialSize: dialSet.width
        //property string modeColor : "#120102"
        modeColor: "#120102"
    }

    Component.onCompleted: {
        console.log("modeValue:", modeObject.modeValue)
    }


}

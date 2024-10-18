import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.15

Item {
    id: gearBox
    width: 65
    height: 460

    AppWidget {
        widthData: 65
        heightData: 460

        GearText{
            id:pButton
            buttonSize: gearBox.width * 0.9
            gearLevel: "P"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
        }

        GearText{
            id:rButton
            buttonSize: gearBox.width * 0.9
            gearLevel: "R"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: pButton.bottom
            anchors.topMargin: 50
        }

        GearText{
            id:nButton
            buttonSize: gearBox.width * 0.9
            gearLevel: "N"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: rButton.bottom
            anchors.topMargin: 50
        }

        GearText{
            id:dButton
            buttonSize: gearBox.width * 0.9
            gearLevel: "D"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: nButton.bottom
            anchors.topMargin: 50
        }
    }
}

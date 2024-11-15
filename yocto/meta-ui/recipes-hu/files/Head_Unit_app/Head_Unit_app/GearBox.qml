import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.15

Item {
    id: gearBox
    width: 400
    height: 80

    AppWidget {
        widthData: 400
        heightData: 80

        GearText{
            id:pButton
            buttonSize: gearBox.height * 0.9
            gearLevel: "P"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20
        }

        GearText{
            id:rButton
            buttonSize: gearBox.height * 0.9
            gearLevel: "R"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: pButton.right
            anchors.leftMargin: 25
        }

        GearText{
            id:nButton
            buttonSize: gearBox.height * 0.9
            gearLevel: "N"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: rButton.right
            anchors.leftMargin: 25
        }

        GearText{
            id:dButton
            buttonSize: gearBox.height * 0.9
            gearLevel: "D"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: nButton.right
            anchors.leftMargin: 25
        }
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
        id: gearBoxOverlay
        visible: showGearBox
        color: "transparent"
        anchors.fill: parent

        GearBox {
            anchors.right: parent.right
            anchors.rightMargin: 25
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenterOffset: -25
        }

        // GearBox 외부 클릭 시 숨김 처리
        MouseArea {
            anchors.fill: parent
            onClicked: {
                mainWindow.showGearBox = false
            }
            z: -1
        }
}

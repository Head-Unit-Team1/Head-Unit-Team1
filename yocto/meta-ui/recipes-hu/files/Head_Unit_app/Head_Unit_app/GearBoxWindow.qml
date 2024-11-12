import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
        id: gearBoxOverlay
        visible: showGearBox
        color: "transparent"
        anchors.fill: parent

        GearBox {
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
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

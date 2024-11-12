import QtQuick 2.12
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "QML Button Example"

    StackView{
        id: stackView
        anchors.fill: parent

        initialItem: Item {
            Button {
                text: "Open Info Window"
                anchors.centerIn: parent
                onClicked: {
                    stackView.push("qrc:/InfoWindow.qml")
                }
            }
        }
    }
}

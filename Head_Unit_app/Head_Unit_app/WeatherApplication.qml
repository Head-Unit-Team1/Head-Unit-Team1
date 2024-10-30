import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0

Item {
    id: weatherApplication
    width: 1024
    height: 600

    TopBar {
        id: topBar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    property string searchText: ""
    property var forecastData: []

    Row {
        id: searchBox
        anchors.top: topBar.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter

        spacing: 10

        TextField {
            id: searchField
            placeholderText: "Enter the city..."
            width: 200

            onTextChanged: searchText = text
        }

        Button {
            text: "Search"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    weather.fetch5daysWeather(searchField.text)
                    //console.log()
                }
            }
        }
    }

    Row {
        id: forecastInfo
        anchors.top: searchBox.bottom
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 15

        Repeater {
            model: forecastData
            Row {
                spacing: 10

                Text {
                    text: model.dateTime // 날짜
                    font.pixelSize: 20
                    color: "white"
                }

                Image {
                    source: model.iconPath // 아이콘 경로
                    width: 50
                    height: 50
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    text: model.temperature + " °C" // 온도
                    font.pixelSize: 20
                    color: "white"
                }

                Text {
                    text: model.description // 날씨 설명
                    font.pixelSize: 20
                    color: "white"
                }
            }
        }

        Connections {
                target: weather
                function onForecastDataReceived(cityName, receivedData) {
                    forecastData = receivedData
                }
            }
    }

    HomeWidget {
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }
}

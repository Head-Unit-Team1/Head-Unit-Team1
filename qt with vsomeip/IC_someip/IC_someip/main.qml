import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import com.DESInstrumentClusterTeam7.speedometer 1.0
import QtQuick.Layouts 1.1
import QtQuick.Window 2.12



ApplicationWindow  {
    id: gauge
    visible: true
    width: 1280
    height: 400
    //color: "#28282c"
    //color: "#461414"
    color : "#28282c"//modeObject.modeValue
    //color: Qt.rgba(rSlider.value / 255, gSlider.value / 255, bSlider.value / 255, 1)
    title: qsTr("Instrument Cluster")
    //flags: Qt.FramelessWindowHint
    //visibility: Window.FullScreen
    property bool blinking : true
    property int dial_Size: height * 0.9
    property int needleLength: height * 0.3
    property int speedValue: 0
//    Button{
//        text: "<-"
//        onClicked: signObject.sendLrsignRandom(2)
//    }
//    Button{
//        x: 111
//        y: 0
//        text: "x"
//        onClicked: signObject.sendLrsignRandom(1)
//    }
//    Button{
//        x: 215
//        y: 0
//        text: "->"
//        onClicked: signObject.sendLrsignRandom(3)
//    }

//    Dial{
//        id: dial
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.left: parent.left
//        anchors.leftMargin: height * 0.2
//        z: 2

//        property int dialSize: gauge.dial_Size
//        property string modeColor: modeObject.modeValue
//    }

    DialSet {
        id: dial
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: height * 0.2
        z: 2
    }

    Text{
        id: timeDisplay
        text: Clock.currentTime
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        font.pixelSize: 50
        anchors.horizontalCenterOffset: 1
        anchors.topMargin: 85
        color: "#00b890"
    }

    Connections{
        target: Clock
        onTimeChanged: timeDisplay.text = Clock.currentTime
    }

    Image {
        id: image
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.verticalCenter: dial.verticalCenter
        source: "images/Ellipse 1.svg"
        fillMode: Image.PreserveAspectFit
        z: 0
    }

    Image {
        id: image1
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.verticalCenter: dial.verticalCenter
        width: 335
        height: 325
        source: "images/Ellipse 5.svg"
        fillMode: Image.PreserveAspectFit
    }//*/

    Needle{
        id: needle
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.bottom: dial.bottom
        anchors.bottomMargin: dial.height / 2
        length: needleLength
        angle: (Receiver.speedKmh * 2.5 + 210)

        Connections{
            target: Receiver
            onSpeedChanged: needle.angle = (Receiver.speedKmh * 2.5 + 210)
        }
    }

    SpeedText{
        id: speedText
        anchors.horizontalCenter: dial.horizontalCenter
        anchors.verticalCenter: dial.verticalCenter
    }


    ///////////////////////////////////////////
    Image {
        id: leftSignOrigin
        x: 440
        y: 37
        source:"images/left_origin.png"

        //anchors.top: carImage.bottom
        //anchors.topMargin: 5
        //anchors.left: parent.left
        //anchors.leftMargin: 40
    }

    Image {
        id: rightSignOrigin
        x: 807
        y: 37
        source: "images/right_origin.png"

        //anchors.verticalCenter: leftSign.verticalCenter
        //anchors.left: leftSign.right
        //anchors.leftMargin: 10
    }
    Image {
        id: leftSign
        x: 440
        y: 37
        source: "images/left_green.png"
        //visible:  (carInfoController.blinkDirection === "left" || carInfoController.blinkDirection === "emergency") && blinking
        visible: (signObject.directionValue === 2 || signObject.directionValue ===1) && blinking
        //anchors.top: carImage.bottom
        //anchors.left: parent.left
        //anchors.leftMargin: 40
    }

    Image {
        id: rightSign
        x: 807
        y: 37
        //anchors.verticalCenterOffset: 346
        source: "images/right_green.png"
        //visible:  (carInfoController.blinkDirection === "right" || carInfoController.blinkDirection === "emergency" ) && blinking
        visible: (signObject.directionValue === 3 || signObject.directionValue ===1) && blinking
        //anchors.verticalCenter: leftSign.verticalCenter
        //anchors.left: leftSign.right
        //anchors.leftMargin: 732
    }
    Timer{
        id: blinkTimer
        interval : 500
        repeat: true
        running: true
        onTriggered: {
            blinking = !blinking
        }
    }


    /////
    /*///////////////////////////////////////////////////////// battery_component */
    Rectangle {
        id: batterygaugealignAngleChanged
        y: 0
        width: 400
        height: 400
        anchors.right: parent.right
        anchors.rightMargin: 32
        color: "#28282c"
        //color: Qt.rgba(rSlider.value / 255, gSlider.value / 255, bSlider.value / 255, 1)
        Speedometer {
            id: battery_speedometer
            objectName: "Battery_Gauge"
            anchors.horizontalCenter: parent.horizontalCenter
            //            anchors.bottom: parent.bottom
            //            anchors.bottomMargin: -10
            anchors.centerIn: parent
            width: speedometerSize
            height: speedometerSize
            startAngle: startAngle
            alignAngle: alignAngle
            lowestRange: lowestRange
            highestRange: highestRange
            battery: battery // rpm
            arcWidth: arcWidth
            outerColor: outerColor
            innerColor: innerColor
            textColor: textColor
            backgroundColor: backgroundColor
        }

        Text {
            id: battery_speedometer_value
            anchors.centerIn: parent
            anchors.bottom: parent.bottom
            font.pixelSize: 55 // 30
            color: "white"

            text: battery_value + "%"
            //text: Math.floor(rpm_speedometer.speed) // Math.floor(Math.random() * 101);
        }

        Text {
            id: battery_text
            text: qsTr("Battery")
            anchors.verticalCenterOffset: 116
            anchors.horizontalCenterOffset: 0
            anchors.bottomMargin: -116
            font.pixelSize: 30
            color: "white"
            anchors.centerIn: parent
            anchors.bottom: parent.bottom
        }

        Image {
            id: out_circleline
            x: 22
            y: 19
            width: 360
            height: 360
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            source: "images/out_ring.png"
        }

        Image {
            id: inner_circleline
            x: 58
            y: 68
            width: 220
            height: 220
            anchors.verticalCenterOffset: -9
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            source: "images/ring.svg"
        }

        Text {
            id: gear_text
            y: 245
            text: gearObject.gearValue
            anchors.horizontalCenterOffset: 0
            font.pointSize: 40
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }


    }

    /*///////////////////////////////////////////////////////// runningRate_component */
    function timeformat(elapsedTime){
        var minutes = Math.floor(elapsedTime / 60);
        var secs = elapsedTime % 60;

        var minutes_format = minutes < 10 ? "0" + minutes : minutes;
        var secs_format = secs < 10 ? "0" + secs : secs;

        return minutes_format + ":" + secs_format;
    }

    Text {
        id: running_rate
        text: "Running Rate: " + timeformat(elapsedTime)
        anchors.verticalCenterOffset: 164
        anchors.horizontalCenterOffset: 0 // "Running Rate: " + elapsedTime + " seconds"
        anchors.centerIn: parent
        font.pixelSize: 13
        color: "white"
    }


    /*///////////////////////////////////////////////////////// background */
    // version 1
    //    Image {
    //        id: left_load
    //        x: 486
    //        y: 134
    //        width: 135
    //        height: 266
    //        source: "Vector 1.svg"
    //        fillMode: Image.PreserveAspectFit
    //    }

    //    Image {
    //        id: right_load
    //        x: 665
    //        y: 134
    //        width: 135
    //        height: 266
    //        source: "Vector 2.svg"
    //        fillMode: Image.PreserveAspectFit
    //    }

    // version 2
    Image {
        id: background
        x: 430 //430
        y: 157 //158
        fillMode: Image.PreserveAspectFit
        source:  "images/back_ground_bright.png" // "background_g.png"

        Image {
            id: highlight
            x: 0
            y: 0
            fillMode: Image.PreserveAspectFit
            source: "images/car-highlights.png"


        }
    }

    Image {
        id: top_bar
        x: 353
        y: 0
        width: 575
        height: 79
        fillMode: Image.PreserveAspectFit
        source: "images/Vector 70.svg"

        Image {
            id: iconizerheadphoneicon
            x: 247
            y: 158
            width: 25
            height: 25
            source: "images/iconizer-headphone-icon.svg"
            asynchronous: false
            autoTransform: false
            mipmap: false
            mirror: false
            sourceSize.height: 120
            sourceSize.width: 120
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: iconizerdaycloudyicon
            x: 351
            y: 156
            width: 30
            height: 30
            source: "images/iconizer-day-cloudy-icon.svg"
            asynchronous: false
            autoTransform: false
            mipmap: false
            mirror: false
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: iconizergasstationicon
            x: 193
            y: 158
            width: 25
            height: 25
            source: "images/iconizer-gas-station-icon.svg"
            asynchronous: false
            autoTransform: false
            mipmap: false
            mirror: false
            sourceSize.height: 120
            sourceSize.width: 120
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: iconizeraddresslocationicon
            x: 301
            y: 158
            width: 25
            height: 25
            source: "images/iconizer-address-location-icon.svg"
            asynchronous: false
            autoTransform: false
            mipmap: false
            mirror: false
            sourceSize.height: 120
            sourceSize.width: 120
            fillMode: Image.PreserveAspectFit
        }


    }

    //    Image {
    //        id: bottom_bar
    //        x: 346
    //        y: 400
    //        width: 588
    //        height: 84
    //        transform: Scale {
    //            yScale: -1
    //        }
    //        fillMode: Image.PreserveAspectFit
    //        source: "Vector 70.svg"
    //    }
    Image{
        id : logoImage
        width: 1280
        height: 400
        source: "images/lam_logo.jpg"
        anchors.centerIn: parent
        z: 999
        visible: true
        PropertyAnimation {
            id: fadeOutAnimation
            target: logoImage
            property: "opacity"
            from: 1
            to: 0
            duration: 500 // 밀리초 단위 (500ms)
            onStopped: {
                bg_dial.visible = false // 애니메이션이 끝나면 완전히 숨김
            }
        }

    }
    Connections {
           target: gearObject
           onClientConnected: {
               fadeOutAnimation.running = true
           }
    }

    Component.onCompleted: {
        console.log(modeObject.modeValue)
    }
}

/*##^##
Designer {
    D{i:18;anchors_x:92;anchors_y:54}
}
##^##*/


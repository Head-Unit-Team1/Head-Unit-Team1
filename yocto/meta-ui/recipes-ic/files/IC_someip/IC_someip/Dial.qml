import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: bg_dial

    property int dialSize: 350

    width: dialSize
    height: dialSize
/*
    Rectangle{
        width: bg_dial.dialSize / 4
        height: bg_dial.dialSize / 4
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        //anchors.fill: parent
        radius: parent.dialSize / 4
        color: "#a2f2d9"
    }//*/

    Canvas {
        anchors.fill: parent
        onPaint: {
            var ctx = getContext("2d");
            ctx.clearRect(0, 0, bg_dial.width, bg_dial.height);

            //Outer Circle
            ctx.beginPath();
            ctx.arc(bg_dial.dialSize / 2, bg_dial.dialSize / 2, bg_dial.dialSize / 2 - 10, 0, Math.PI * 2);
            ctx.lineWidth = 5;
            ctx.strokeStyle = "#00b890";
            ctx.stroke();

            //Inner Circle
            ctx.beginPath();
            ctx.arc(bg_dial.dialSize / 2, bg_dial.dialSize / 2, bg_dial.dialSize / 4, 0, Math.PI * 2);
            ctx.lineWidth = 5;
            ctx.strokeStyle = "#a2f2d9";
            ctx.stroke();

            ctx.lineWidth = 3;
            for(var i = 4; i < 15; i++){
                var angle = (Math.PI / 6) * i;
                var x1 = bg_dial.width / 2 + Math.cos(angle) * (bg_dial.width / 2 - 20);
                var y1 = bg_dial.height / 2 + Math.sin(angle) * (bg_dial.height / 2 - 20);
                var x2 = bg_dial.width / 2 + Math.cos(angle) * (bg_dial.width / 2 - 40);
                var y2 = bg_dial.height / 2 + Math.sin(angle) * (bg_dial.height / 2 - 40);

                ctx.beginPath();
                ctx.moveTo(x1,y1);
                ctx.lineTo(x2,y2);
                ctx.strokeStyle = "#a2f2d9";
                ctx.stroke();

                if (i < 14) {
                    var midAngle = angle + (Math.PI / 12); // 큰 눈금 사이 각도의 절반
                    var mx1 = bg_dial.width / 2 + Math.cos(midAngle) * (bg_dial.width / 2 - 20);
                    var my1 = bg_dial.height / 2 + Math.sin(midAngle) * (bg_dial.width / 2 - 20);
                    var mx2 = bg_dial.width / 2 + Math.cos(midAngle) * (bg_dial.width / 2 - 30); // 더 짧은 눈금
                    var my2 = bg_dial.height / 2 + Math.sin(midAngle) * (bg_dial.width / 2 - 30);

                    ctx.lineWidth = 2;  // 중간 눈금은 조금 얇게
                    ctx.beginPath();
                    ctx.moveTo(mx1, my1);
                    ctx.lineTo(mx2, my2);
                    ctx.strokeStyle = "#a2f2d9";
                    ctx.stroke();
                }
            }
        }
    }

}

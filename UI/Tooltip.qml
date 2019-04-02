import QtQuick 2.4

Rectangle {
    id:tooltip
    property alias text: textContainer.text
    property int verticalPadding: 10
    property int horizontalPadding: 50
    width: textContainer.width + horizontalPadding * 2
    height: textContainer.height + verticalPadding * 2
    color: "#FF4040"
    property int count: 0
    property int endCount: 5
    Text {
        anchors.centerIn: parent
        id:textContainer
        wrapMode: Text.WordWrap
        color: "white"
        text: "Gering geding ding ding!"
    }
    NumberAnimation {
        id: fadein
        target: tooltip
        property: "opacity"
        easing.type: Easing.InOutQuad
        duration: 1000
        from: 0
        to: 1
        onStopped:fadeout.start()
    }
    NumberAnimation {
        id: fadeout
        target: tooltip
        property: "opacity"
        easing.type: Easing.InOutQuad
        duration: 1000
        from: 1
        to: 0
        onStopped: {
            count++;
            if(count != endCount){
                fadein.start()
            }else{
                count = 0;
                visible = false;
            }
        }
    }
    visible:false
    onVisibleChanged: if(visible)fadein.start();
    function show(){
       visible = true;
       fadein.start();
    }
    function hide(){
        fadeout.start();
    }
}

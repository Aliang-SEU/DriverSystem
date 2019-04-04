import QtQuick 2.4
import Material 0.3
import QtQuick.Controls 1.3 as Controls
import QtQuick.Dialogs 1.2 as Dialogs

Item {

    property var menu1Text: ["实时监测", "停止监测"]
    property var menu2Text: ["离线视频监测", "停止监测"]

    Row {
        x:dp(10)
        y:dp(15)
        spacing: dp(10)
        Button {
            id:openCam
            width:100;
            height:30;
            elevation: 1
            darkBackground:true
            text:menu1Text[0];
            onClicked:{
                if(openCam.text === menu1Text[0]) {
                    cameraSelectDialog.open()
                }else{
                    count.running = false;
                    cameraCapture.stop();
                    openCam.text = menu1Text[0];
                    openFile.enabled = true
                }
            }
        }

        Button {
            id:openFile
            width:120;
            height:30;
            text:menu2Text[0];
            elevation: 1
            onClicked:{
                if(openFile.text === menu2Text[0]){
                    videoFileDialog.open()
                }else{
                    count.running = false;
                    cameraCapture.stop();
                    openFile.text = menu2Text[0]
                    openFile.enabled = true
                    openCam.enabled = true
                }
            }
        }

        Label {
            anchors.verticalCenter: parent.verticalCenter
            text: "检测效果显示"
            color: index == 0 ? Theme.light.textColor : Theme.dark.textColor
        }

        Switch {
            id:showProcessFlag
            anchors.verticalCenter: parent.verticalCenter
            checked: true
            darkBackground: index == 1
            onCheckedChanged: {
                processor.getShowProcessFLag(showProcessFlag.checked)
            }
        }

        ProgressBar{
             id:fileProgressBar
             anchors.verticalCenter: parent.verticalCenter
             minimumValue: 0;
             maximumValue: 100;
             value: 0;
             width: 200;
             height: 20;
             Timer{
                 id:progressBarTimer
                 interval: 30;
                 repeat: true;
                 running: false;
                 onTriggered: {
                     if(fileProgressBar.value < 99.1){
                         fileProgressBar.value += 1;
                     }else{
                         stop();
                         snackbar.open("视频文件上传成功")
                         fileProgressBar.value = 0;
                     }
                 }
             }
         }
    }
    Connections{
        target:fatigueAlarm
        onProgressStart: {
            progressBarTimer.running=true;
        }
    }

    //摄像头选择对话框
    Dialog {
        id: cameraSelectDialog
        title: "选择摄像头"
        positiveButtonText: "确定"
        negativeButtonText: "取消"
        MenuField {
            id: cameraSelection
            width: dp(400)
        }
        //打开对话框的时候获取对应的摄像头列表
        onOpened: {
            cameraSelection.model = cameraCapture.getCameraList();
        }
        onRejected: {
            // TODO set default colors again but we currently don't know what that is
        }
        onAccepted: {
            console.log("打开摄像头" + cameraSelection.selectedText)
            cameraCapture.readCamera(cameraSelection.selectedIndex);
            count.running = true;
            openCam.text = menu1Text[1];
            openFile.enabled = false
            imagewindow.source = "";

        }
    }

    //视频文件选择对话框
    Dialogs.FileDialog{
        id:videoFileDialog
        title: qsTr("选择视频文件")
        nameFilters: ["Video Files (*.avi *.mp4)"]
        onAccepted: {
            cameraCapture.readVideoFiles(String(videoFileDialog.fileUrl));
            count.running = true;
            imagewindow.source = "";
            openFile.text = menu2Text[1]
            openCam.enabled = false
        }
    }

    //定时器用于显示对应的图像区域
    Timer {
        id: count
        interval: 1000 / 30
        repeat: true
        running: false
        triggeredOnStart: false
        onTriggered: {
            imagewindow.source = "";
            imagewindow.source = "image://video/";
        }
    }

    Rectangle {
        id: rectangle
        x: 10
        y: 63
        width: 640
        height: 480
        color: "#ffffff"
        radius: 1
        //border.color: "#b93434"

        Image {
            id: imagewindow
            x: 0
            y: 0
            cache: false
            width: 640 //图像宽度
            height: 480
            //图像高度
        }
    }
}


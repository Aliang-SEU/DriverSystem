import QtQuick 2.4
import Material 0.3
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
import QtQuick.Layouts 1.1

Item {
    View {
        anchors {
            fill: parent
            margins: dp(32)
        }

        elevation: 1

        Column {
            anchors.fill: parent

            ListItem.Subheader {
                text: "警报设置"
            }

            ListItem.Subtitled {
                text: "语音提醒"
                secondaryItem: Switch {
                    id: enablingSwitch
                    anchors.verticalCenter: parent.verticalCenter
                }

                onClicked: enablingSwitch.checked = !enablingSwitch.checked

                action: Icon {
                    anchors.centerIn: parent
                    name: "device/access_alarm"
                    size: dp(32)
                }
            }

            ListItem.SimpleMenu {
                text: "语音选择"
                model: ["语音A", "语音Ｂ","语音Ｃ"]
            }

            ListItem.Subheader {
                text: "远程服务器设置"
            }

            ListItem.Subtitled {
                text: "FTP服务器"
                subText: "10.193.3.202:20"
                onClicked: {
                    ftpFieldDialog.open()
                }
            }
        }
    }


    Dialog {
        id: ftpFieldDialog
        title: "修改FTP服务器地址"
        width: dp(400)
        positiveButtonText:"确认"
        negativeButtonText:"取消"
        ColumnLayout {
           id: column
           width: dp(300)

           Item {
               Layout.fillWidth: true
               Layout.preferredHeight: dp(8)
           }

           ListItem.Standard {
               action:  Label {
                   anchors.centerIn: parent
                   text:'地址'
               }

               content: TextField {
                   anchors.centerIn: parent
                   width: parent.width
                   text: "10.193.3.202"
               }
           }

           ListItem.Standard {
               action: Label {
                   anchors.centerIn: parent
                   text:'端口'
               }

               content: TextField {
                   anchors.centerIn: parent
                   width: parent.width

                   text: "20"
               }
           }

           Item {
               Layout.fillWidth: true
               Layout.preferredHeight: dp(8)
           }

        }
        onAccepted: {
            Snackbar.open("地址修改成功")
        }
    }
}

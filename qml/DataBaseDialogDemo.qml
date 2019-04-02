import QtQuick 2.4
import Material 0.3
import QtQuick.Controls 1.3 as Controls
import QtQuick.Dialogs 1.2 as Dialogs

Item {
    Row{
        x:10
        y:10
        height: 30
        width: parent.width
        Button{
            elevation: 1
            text: qsTr("刷新")
            onClicked: {
                myModel.select()
                snackbar.open("数据库刷新成功")
            }
        }
    }
    Controls.TableView {
        id:fatigueDatabase
        height: dp(500)
        width: parent.width
        anchors.bottom: parent.bottom
        Controls.TableViewColumn {
            role: "id"
            title: "序号"
            width: 80
        }
        Controls.TableViewColumn {
            role: "username"
            title: "用户名"
            width: 100
        }
        Controls.TableViewColumn {
            role: "createtime"
            title: "创建时间"
            width: 150
        }
        Controls.TableViewColumn {
            role: "filename"
            title: "文件名称"
            width: 400
        }
        model: myModel

        onDoubleClicked: {
            actionSheet.open()
        }
    }

    BottomActionSheet {
           id: actionSheet
           title: "选择你要进行的操作!"
           actions: [
               Action {
                   iconName: "action/settings"
                   name: "打开视频"
                   onTriggered:{

                   }
               },
               Action {
                   iconName: "action/delete"
                   name: "删除记录"
                   onTriggered:{
                       //首先删除数据库内对应的文件
                        deleeFileDialog.open()
                   }
               }
           ]
    }

    Dialog {
        id: deleeFileDialog
        width: dp(300)
        text: "你确定要删除该条记录吗?"
        hasActions: true
        positiveButtonText: "删除"
        negativeButtonText: "取消"
        onAccepted: {
            if(myModel.removeRow(fatigueDatabase.currentRow)){
                fatigueDatabase.model = myModel
                snackbar.open("文件删除成功")
            }else{
                snackbar.open("文件删除失败")
            }
        }
    }

}


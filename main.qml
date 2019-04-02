import QtQuick 2.4
import QtQuick.Dialogs 1.2
import Material 0.3
import Material.ListItems 0.1 as ListItem
import "./UI" as ALiang

ApplicationWindow {
    id:app
    visible: true
    width: 660
    height: 650

    theme {
        primaryColor: "black"
        accentColor: "red"
        tabHighlightColor: "blue"
        //backgroundColor:"white"
    }

    //选择的对应
    property var sections: [ "Main", "DataBase", "Settings"]
    property var sectionTitles: [ "监测主界面", "疲劳数据库", "系统设置" ]

    //选择的菜单项
    property string selectedComponent: sections[0]

    ALiang.Label {
        id: timeLabel
        anchors.right:parent.right
        y:60
    }

    ALiang.Tooltip{
        id:fatigueTooltip
        text:"检测到您处于疲劳状态，\r请注意休息"
        x:150
        y:300
        height: 100
    }


    Connections{
        target:fatigueAlarm
        onFatigueAlarm: {
            fatigueTooltip.show()
        }
    }

    Timer {
        id: timeTimer
        interval: 1000
        repeat: true
        running: true
        triggeredOnStart: false
        onTriggered: {
            var date = new Date(Date.now())
            timeLabel.text = date.toLocaleTimeString(Qt.locale(), "hh:mm:ss")
        }

    }

    initialPage: TabbedPage {
        id: page
        title: "疲劳驾驶监测预警系统v1.0"
        actionBar.maxActionCount: navDrawer.enabled ? 3:4
        actions: [
            Action {
                iconName: "image/color_lens"
                name: "Colors"
                onTriggered: colorPicker.show()
            },
            Action {
                iconName: "action/language"
                name: "Language"
                enabled: true
                onTriggered: {
//                    snackbar.open("检测到您有疲劳驾驶的行为，请注意休息!")
//                    fatigueTooltip.show()
                }
            }
        ]
        backAction: navDrawer.action
        //头部导航菜单
        NavigationDrawer {
            id: navDrawer
            enabled: page.width < dp(400)
            onEnabledChanged: smallLoader.active = enabled
            Flickable {
                anchors.fill: parent
                contentHeight: Math.max(content.implicitHeight, height)
                Column {
                    id: content
                    anchors.fill: parent
                    Repeater {
                        model: sections
                        delegate: Column {
                            width: parent.width
                            ListItem.Subheader {
                                text: sectionTitles[index]
                            }
                        }
                    }
                }
            }
        }

        //导航菜单重复子项
        Repeater {
            model: !navDrawer.enabled ? sections : 0
            delegate: Tab {
                title: sectionTitles[index]
                property string selectedComponent: modelData
                property var section: modelData
                sourceComponent: tabDelegate
            }
        }

        //延迟加载组件
        Loader {
            id: smallLoader
            anchors.fill: parent
            sourceComponent: tabDelegate
            property var section: []
            visible: active
            active: false
        }
    }
    //每个菜单主界面
    Component {
        id: tabDelegate
        Item {
            Flickable {
                id: flickable
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                }
                clip: true
                contentHeight: Math.max(example.implicitHeight + 40, height)
                Loader {
                    id: example
                    anchors.fill: parent
                    asynchronous: true
                    visible: status == Loader.Ready
                    // selectedComponent will always be valid, as it defaults to the first component
                    source: {
                        if (navDrawer.enabled) {
                            return Qt.resolvedUrl("qml/%1DialogDemo.qml").arg(app.selectedComponent.replace(" ", ""))
                        } else {
                            return Qt.resolvedUrl("qml/%1DialogDemo.qml").arg(selectedComponent.replace(" ", ""))
                        }
                    }
                }

                ProgressCircle {
                    anchors.centerIn: parent
                    visible: example.status == Loader.Loading
                }
            }
            Scrollbar {
                flickableItem: flickable
            }
        }
    }

    //底部提示栏
    Snackbar {
        id: snackbar
    }
    //颜色选择对话框
    Dialog {
        id: colorPicker
        title: "界面主题设置"
        positiveButtonText: "确定"
        negativeButtonText: "取消"
        MenuField {
            id: selection
            model: ["菜单栏颜色", "字体颜色", "背景色"]
            width: dp(160)
        }
        onOpened: {
            selection.selectedIndex = 0
        }
        Grid {
            columns: 7
            spacing: dp(8)
            Repeater {
                model: [
                    "red", "pink", "purple", "deepPurple", "indigo",
                    "blue", "lightBlue", "cyan", "teal", "green",
                    "lightGreen", "lime", "yellow", "amber", "orange",
                    "deepOrange", "grey", "blueGrey", "brown", "black",
                    "white"
                ]
                Rectangle {
                    width: dp(30)
                    height: dp(30)
                    radius: dp(2)
                    color: Palette.colors[modelData]["500"]
                    border.width: modelData === "white" ? dp(2) : 0
                    border.color: Theme.alpha("#000", 0.26)
                    Ink {
                        anchors.fill: parent
                        onPressed: {
                            switch(selection.selectedIndex) {
                                case 0:
                                    theme.primaryColor = parent.color
                                    break;
                                case 1:
                                    theme.accentColor = parent.color
                                    break;
                                case 2:
                                    theme.backgroundColor = parent.color
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
}

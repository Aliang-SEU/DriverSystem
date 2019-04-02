import QtQuick 2.4
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Item {
    id: root
    implicitHeight: labelTextMetrics.tightBoundingRect.height
    implicitWidth: label.implicitWidth

    property alias text: label.text
    property alias font: label.font
    property alias horizontalAlignment: label.horizontalAlignment
    property alias verticalAlignment: label.verticalAlignment
    property bool glowEnabled: true
    property color glowColor: "#0FA2BE"

    Label {
        id: label
        anchors.baseline: root.baseline
        color: "white"
        font.pixelSize: 26
        layer.enabled: root.glowEnabled
        layer.effect: Glow {
            color: glowColor
            samples: 20
            spread: 0.3
        }

        TextMetrics {
            id: labelTextMetrics
            text: label.text
            font: label.font
        }

        transform: Translate {
            y: -labelTextMetrics.tightBoundingRect.y
        }
    }
}

import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Fusion

Button {
    id: root

    property string backgroundColor: "transparent"
    property string onHoverBackgroundColor: "#191919"
    property string iconSource

    property int iconWidth: isMobileTarget? 15 : 20
    property int iconHeight: isMobileTarget? 15 : 20

    width: iconWidth
    height: iconHeight

    Image {
        anchors.centerIn: parent
        smooth: true
        width: iconWidth
        height: iconHeight
        source: iconSource
    }

    background: Rectangle {
        id: buttonBackGround
        anchors.centerIn: parent
        width: 30
        height: 30
        color: backgroundColor
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: buttonBackGround.color = onHoverBackgroundColor
        onExited: buttonBackGround.color = "transparent"
    }
}

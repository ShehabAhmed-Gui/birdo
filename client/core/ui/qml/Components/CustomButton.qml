import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Fusion

Rectangle {
    id: root

    property string backgroundColor: "transparent"
    property string onHoverBackgroundColor: "#191919"
    property string iconSource
    property alias hovered: btn.hovered

    property int iconWidth: isMobileTarget? 12 : 18
    property int iconHeight: isMobileTarget? 12 : 18


    radius: 11

    width: iconWidth + 10
    height: iconHeight + 10
    color: backgroundColor

    Button {
        id: btn

        width: iconWidth
        height: iconHeight

        anchors.fill: parent

        Image {
            anchors.centerIn: parent
            smooth: true
            width: iconWidth
            height: iconHeight
            source: iconSource
        }
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: root.color = onHoverBackgroundColor
        onExited: root.color = "transparent"
    }
}

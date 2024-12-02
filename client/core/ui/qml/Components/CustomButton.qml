import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Fusion
import QtQuick.Layouts

Button {
    id: root

    property string backgroundColor: "transparent"
    property string onHoverBackgroundColor: "#6b6a58"
    property string buttonBorderColor: "transparent"

    property double backgroundOpacity: 1
    property double buttonRadius: width / 2

    property bool isHovered: false

    property int buttonWidth: iconWidth + 10
    property int buttonHeight: iconHeight + 10

    property int iconWidth: isMobileTarget? 10 : 18
    property int iconHeight: isMobileTarget? 10 : 18
    property string iconSource

    Layout.minimumWidth: buttonWidth
    Layout.minimumHeight: buttonHeight

    contentItem: Item {
        anchors.fill: parent

        Image {
            id: buttonIcon
            anchors.centerIn: parent

            smooth: true
            width: iconWidth
            height: iconHeight
            source: iconSource
        }
    }

    background: Rectangle {
        id: backgroundRec
        anchors.fill: parent
        width: parent.width
        height: parent.height

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            preventStealing: true
            hoverEnabled: true
            onEntered: {
                controlHovered(true)
                isHovered = true
            }
            onExited: {
                controlHovered(false);
                isHovered = false
            }
        }

        radius: buttonRadius
        opacity: backgroundOpacity
        border.color: buttonBorderColor

        color: root.isHovered? onHoverBackgroundColor : backgroundColor
    }
}

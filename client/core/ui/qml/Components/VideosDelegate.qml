import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    color: "#1A1A1D"
    anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined
    width: parent? parent.width - 20 : 20

    height: 40
    radius: 11

    Text {
        text: name
        color: "#D8D2C2"

        width: parent.width - 10

        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10

        font.pixelSize: 12
        font.weight: 400

        wrapMode: Text.WordWrap
    }
}

import QtQuick
import QtQuick.Layouts
import QtMultimedia

Rectangle {
    id: root
    color: "#1A1A1D"
    anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined
    width: parent? parent.width - 20 : 20

    height: 40
    radius: 11

    CustomButton {
        id: playVideo

        iconSource: video.source.toString() === path && video.playbackState === MediaPlayer.PlayingState
            ? "qrc:/images/svg/Stop_Icon.svg"
            : "qrc:/images/svg/play.svg"

        iconWidth: 16
        iconHeight: 16

        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter

        MouseArea {
            anchors.fill: parent
            cursorShape: parent.hovered? Qt.PointingHandCursor : Qt.ArrowCursor

            onClicked: {
                if (video.source.toString() === path && video.playbackState === MediaPlayer.PlayingState) {
                    video.pause()
                } else {
                    video.source = path
                    video.play()
                }
            }
        }
    }

    Text {
        id: videoName
        text: name
        color: "#D8D2C2"

        width: parent.width - 10

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: playVideo.right
        anchors.leftMargin: 7

        font.pixelSize: 13
        font.weight: 400

        wrapMode: Text.WordWrap
    }
}

import QtQuick
import QtQuick.Layouts
import QtMultimedia

Rectangle {
    id: root
    color: "#1A1A1D"
    anchors.horizontalCenter: parent? parent.horizontalCenter : undefined
    width: parent? parent.width - 20 : 20

    property bool isCurrentlyPlaying: video.source.toString() === path

    function setCurrentIndex() {
        listView.currentIndex = index
    }

    Component.onCompleted: {
        // Schedule the code for the next available event loop iteration
        Qt.callLater(() => {
            if (isCurrentlyPlaying) {
                if (listView) {
                    listView.currentIndex = index;
                }
            }
        });
    }

    Connections {
        target: listView
        enabled: isCurrentlyPlaying
        function onPlayNext() {
            setCurrentIndex()
        }
    }

    Connections {
        target: listView
        enabled: isCurrentlyPlaying
        function onPlayPrevious() {
            setCurrentIndex()
        }
    }

    border.color: isCurrentlyPlaying? "#04471c" : "transparent"
    border.width: 0.5

    height: 40
    radius: 11

    CustomButton {
        id: playVideo
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter

        iconSource:  isCurrentlyPlaying && videoState === MediaPlayer.PlayingState
            ? "qrc:/images/svg/Stop_Icon.svg"
            : "qrc:/images/svg/play.svg"

        iconWidth: 18
        iconHeight: 18
        width: 24
        height: 24

        MouseArea {
            anchors.fill: parent
            cursorShape: parent.hovered? Qt.PointingHandCursor : Qt.ArrowCursor

            onClicked: {
                listView.currentIndex = index
                if (isCurrentlyPlaying && video.playbackState === MediaPlayer.PlayingState) {
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

    CustomButton {
        id: deleteItem
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 10

        iconSource: "qrc:/images/svg/trash.svg"

        MouseArea {
            anchors.fill: parent
            cursorShape: parent.hovered? Qt.PointingHandCursor : Qt.ArrowCursor

            onClicked: listModel.deleteItem(index);
        }
    }
}

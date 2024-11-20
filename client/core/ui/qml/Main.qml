import QtQuick
import QtQuick.Window
import QtQuick.Controls.Fusion
import QtMultimedia

import "Controls"
import "Components"

ApplicationWindow {
    id: root
    readonly property bool isMobileTarget : Qt.platform.os === "android" || Qt.platform.os === "ios"

    width: 1200
    height: 780
    minimumHeight: 460
    minimumWidth: 640
    visible: true
    title: qsTr("Birdo")
    color: "#000000"
    Component.onCompleted: {
        console.debug("Application Started")
        video.play()
    }

    Timer {
        id: hoverTimer
        interval: 3000

        onTriggered: showControls.start()
    }

    Timer {
        id: afkTimer
        interval: 2500
        repeat: true
        onTriggered: {
            showControls.start()
            if(bottomControls.isMediaSliderPressed) {
                afkTimer.restart()
            } else {
                hideControls.start()
            }
        }
    }

    VideoPlayerType {
        id: video
        width: 500
        height: 500

        anchors.fill: parent

        source: "file:///home/charmylinuxer/Music/2Pac - Mask Off Oldschool Instrumental (My Chain remix).mp4"
        cursorWidth: 40
        cursorHeight: 40

        onPlaybackStateChanged: bottomControls.videoStateChanged()

        Component.onCompleted: afkTimer.start()

        MouseArea {
            id: videoMouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                hoverTimer.start()
            }

            onExited: {
                hoverTimer.stop();
            }

            onClicked: {
                video.playbackState === MediaPlayer.PlayingState? video.pause() : video.play()
            }

            onPositionChanged: {
                if (!isMobileTarget) {
                    afkTimer.restart()
                    showControls.start()
                }
            }
        }

        Timer {
            id: videoFocusTimer
            interval: 300
            repeat: true
            onTriggered: video.focus = true
        }

        Keys.onSpacePressed: video.playbackState === MediaPlayer.PlayingState? video.pause() : video.play()
        Keys.onLeftPressed: bottomControls.seekBackward()
        Keys.onRightPressed: bottomControls.seekForward()

        Keys.onPressed: (key) => {
            if (key.key === Qt.Key_K) {
                 if(video.playbackState === MediaPlayer.PlayingState) {
                    video.pause()
                 } else {
                    video.play()
                }
            }
        }
    }

    BottomControls {
        id: bottomControls
        width: parent.width
        anchors.bottom: video.bottom
        color: "transparent"
    }

    ParallelAnimation {
        id: hideControls

        NumberAnimation {
            targets: bottomControls
            property: "opacity"
            to: 0
            duration: 1000
            easing.type: Easing.InOutQuad
        }
    }

    ParallelAnimation {
        id: showControls

        NumberAnimation {
            targets: bottomControls
            property: "opacity"
            to: 1
            duration: 500
            easing.type: Easing.InOutQuad
        }
        NumberAnimation {
            target: bottomControls.bottomOpacity
            property: "opacity"
            to: 0.40
            duration: 500
            easing.type: Easing.InOutQuad
        }
    }
}

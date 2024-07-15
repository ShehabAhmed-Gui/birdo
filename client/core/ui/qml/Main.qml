import QtQuick
import QtQuick.Window
import QtQuick.Controls.Fusion
import QtMultimedia
import CustomCursor
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
    }

    Timer {
        id: afkTimer
        interval: 2500
        repeat: true
        onTriggered: {
            if(bottomControls.isMediaSliderPressed) {
                afkTimer.restart()
            } else {
                hideControls.start()
                customCursor.hideCursor(parent)
            }
        }
    }

    VideoPlayerType {
        id: video
        width: 500
        height: 500

        anchors.fill: parent

        videoSource: isMobileTarget? "https://commondatastorage.googleapis.com/gtv-videos-bucket/sample/WhatCarCanYouGetForAGrand.mp4" : "E:/songs/2019 das lo Jaius - äscg) g) äsélTaHBeCT - HnpBaHa - Jarico Remix.mp4"
        cursorWidth: 40
        cursorHeight: 40
        enableCustomCursor: true

        onPlaybackStateChanged: bottomControls.videoStateChanged()
        Component.onCompleted: isMobileTarget? video.play() : afkTimer.start()

        CursorHandler {
            id: customCursor
        }

        MouseArea {
            id: videoMouseArea
            anchors.fill: parent
            hoverEnabled: video.enableCustomCursor
            cursorShape: Qt.ArrowCursor

            Timer {
                id: hoverTimer
                interval: 50
                onTriggered: {
                    if (videoMouseArea.containsMouse) {
                        customCursor.setCustomCursor(video, video.cursorPath, video.cursorWidth, video.cursorHeight)
                    }
                }
            }

            onEntered: {
                hoverTimer.start()
            }

            onExited: {
                hoverTimer.stop();
                customCursor.resetDefaultCursor(video)
            }

            onClicked: {
                video.playbackState === MediaPlayer.PlayingState? video.pause() : video.play()
            }

            onPositionChanged: {
                if (!isMobileTarget) {
                    afkTimer.restart()
                    showControls.start()
                }
                customCursor.setCustomCursor(parent, ":/images/video_cursor.png")
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

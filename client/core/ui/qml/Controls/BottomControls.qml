import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia
import "../Components"

Rectangle {
    id: root
    width: parent.width
    height: 150
    color: "transparent"
    radius: 7
    anchors.bottom: parent.bottom

    property alias isMediaSliderPressed: videoSlider.pressed
    property alias bottomOpacity: bottomOpacity


    function seekBackward() {
        video.seek(video.position -= 10000)
    }

    function seekForward() {
        video.seek(video.position += 10000)
    }

    function formatTime(seconds) {
        var day = Math.floor(seconds / (24 * 3600));
        seconds %= 24 * 3600;
        var hour = Math.floor(seconds / 3600);
        seconds %= 3600;
        var minute = Math.floor(seconds / 60);
        var second = Math.floor(seconds % 60);
        return (day > 0 ? day + ":" : "") +
               (hour > 0 ? hour + ":" : "") +
               (minute > 0 ? (minute < 10 ? "0" + minute : minute) + ":" : "00:") +
               (second < 10 ? "0" + second : second);
    }

    signal videoStateChanged()

    Component.onCompleted: root.videoStateChanged.connect(videoIsPlaying)

    function videoIsPlaying() {
        if(video.playbackState === MediaPlayer.PlayingState) {
            startStopButton.ToolTip.text = qsTr("Pause")
            startStopButton.iconSource = "qrc:/images/svg/Stop_Icon.svg"
        } else {
            startStopButton.ToolTip.text = qsTr("Play")
            startStopButton.iconSource = "qrc:/images/play-button.png"
        }
    }

    property bool userChangingSlider: false
    property Timer userInteractionTimer: Timer {
        interval: 300
        repeat: false
        onTriggered: userChangingSlider = false
    }

    Connections {
        target: videoSlider
        function onMoved() {
            if (userChangingSlider) {
                video.seek(videoSlider.value * 1000)
            }
        }
    }

    MouseArea {
        id: bottomControlsMouseArea
        anchors.fill: parent
        preventStealing: true
    }

    Rectangle {
        id: bottomOpacity

        anchors.fill: parent
        opacity: 0.40
        color: "#111111"
    }

    Rectangle {
        id: videoSliderContainer
        width: parent.width - 80
        color: "transparent"
        anchors.top: parent.top
        anchors.topMargin: 20

        CustomSliderType {
            id: videoSlider

            property int videoDuration: video.duration / 1000

            sliderWidth: parent.width - 30
            sliderHeight: 7

            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 30

            from: 0
            to: videoDuration

            onValueChanged: {
                userChangingSlider = true
                userInteractionTimer.restart()
                video.focus = true
            }

            Connections {
                target: video
                function onPositionChanged() {
                    if (!userChangingSlider) {
                        videoSlider.value = video.position / 1000
                    }
                }
            }
        }
    }

    Text {
        id: videoTime
        text: formatTime(videoSlider.value)
        color: "#ffffff"
        font.pixelSize: 13

        anchors.left: videoSliderContainer.right
        anchors.verticalCenter: videoSliderContainer.verticalCenter
        anchors.leftMargin: 10
    }

    RowLayout {
        id: playerControls
        anchors.fill: root

        Item {
            visible: Screen.primaryOrientation === Qt.LandscapeOrientation
            Layout.fillWidth: true
            Layout.minimumWidth: 40
            Layout.maximumWidth: 95
        }

        PlaybackSpeed {
            id: playBackSpeed
            showPlaybackSpeedIcon: Screen.primaryOrientation === Qt.LandscapeOrientation

            Layout.minimumWidth: isMobileTarget? 120 :150
            Layout.maximumWidth: isMobileTarget? 120 : 150
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Item {
            Layout.fillWidth: true
        }

        RowLayout {
            id: controlButtons
            spacing: Screen.primaryOrientation === Qt.LandscapeOrientation ? 30 : 10

            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true

            CustomButton {
                id: skipBackward
                iconSource: "qrc:/images/svg/Previous_Icon_Dark.svg"
            }

            CustomButton {
                id: seekBackward
                iconSource: "qrc:/images/rewind-backward.png"

                MouseArea {
                    anchors.fill: parent
                    onClicked: root.seekBackward()
                }
            }

            CustomButton {
                id: startStopButton
                iconWidth: isMobileTarget? 25 : 40
                iconHeight: isMobileTarget? 25 : 40
                iconSource: "qrc:/images/play-button.png"

                ToolTip.delay: 500
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Play")

                onHoverBackgroundColor: "transparent"
                MouseArea {
                    anchors.fill: parent
                    onClicked: video.playbackState === MediaPlayer.PlayingState? video.pause() : video.play()
                }
            }

            CustomButton {
                id: seekForward
                iconSource: "qrc:/images/seek-forward.png"

                MouseArea {
                    anchors.fill: parent
                    onClicked: root.seekForward()
                }
            }

            CustomButton {
                id: skipForward
                iconSource: "qrc:/images/svg/Next_Icon_Dark.svg"
            }

            CustomButton {
                id: loop

                visible: Screen.primaryOrientation === Qt.LandscapeOrientation
                iconSource: "qrc:/images/svg/Loop_Icon_Dark.svg"
            }
        }

        Item {
            Layout.fillWidth: true
        }

        AudioControls {
            id: audioControl

            Layout.minimumWidth: isMobileTarget? 120 : 150
            Layout.maximumWidth: isMobileTarget? 120 : 150
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Item {
            Layout.fillWidth: true
            Layout.minimumWidth: 40
            Layout.maximumWidth: 95
        }
    }
}

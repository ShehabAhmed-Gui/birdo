import QtQuick
import QtQuick.Layouts
import "../Components"

Item {
    id: root
    Layout.minimumWidth: 150
    Layout.maximumWidth: 150

    property alias volumeSlider: volumeSlider
    property alias volumeButton: volume
    property alias volumeLevel: volumeSlider.value

    function setMuted(muted) {
        switch (muted) {
        case true: video.muted = true; volumeButton.iconSource = "qrc:/images/mute.png"
            break;
        case false: video.muted = false; volumeButton.iconSource = "qrc:/images/volume-high.png"
            break;
        }
    }

    RowLayout {
        id: audioRL
        anchors.fill: root
        spacing: 10

        CustomButton {
            id: volume

            ToolTipType {
                toolTipText: video.muted? "Unmute" : "Mute"
            }

            iconSource: volumeLevel === 0? "qrc:/images/mute.png" : volumeLevel <= 70? "qrc:/images/low-volume.png" : "qrc:/images/volume-high.png"
            iconHeight: 18

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    video.muted? setMuted(false) : setMuted(true)
                    parent.iconSource
                }
            }
        }

        CustomSliderType {
            id: volumeSlider

            Layout.minimumWidth: 100
            Layout.maximumWidth: 100

            enableGradiant: true
            gradiantFirstColor: "#04471c"
            gradiantSecondColor: "#054a29"
            subPageColor: "#111d13"
            handleColor: "#111d13"
            sliderHeight: 7

            from: 0
            to: 100
            value: (video.volume * 100).toFixed()

            onValueChanged: {
                video.volume = volumeSlider.value / 100
                video.focus = true
            }

            Connections {
                target: video
                property int videoVolume
                function onVolumeChanged() {
                    videoVolume = video.volume * 100
                    volumeSlider.value = videoVolume
                }
            }

            Layout.fillWidth: true
            Layout.alignment: Qt.AlignVCenter
        }

        Text {
            id: volumeLevelText
            text: volumeSlider.value
            font.pixelSize: 13

            color: "#f3eff5"
        }
    }
}

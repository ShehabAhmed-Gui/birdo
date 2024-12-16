import QtQuick
import QtQuick.Layouts
import com.qt.birdo 1.0

import "../Components"


Rectangle {
    id: root

    color: "#000000"
    radius: 8
    border.color: "#685752"

    MouseArea {
        anchors.fill: parent
        preventStealing: true
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 15

        Rectangle {
            width: parent.width
            height: 50
            color: "transparent"

            Text {
                id: playlistTitle
                text: "Videos Playlist"

                color: "#ffffff"
                font.pixelSize: 13
                font.weight: 400

                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }

            CustomButton {
                iconSource: "qrc:/images/svg/plus.svg"
                backgroundColor: "transparent"
                onHoverBackgroundColor: "lightblue"

                width: iconWidth + 5
                height: iconHeight + 5

                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    anchors.fill: parent

                    onClicked:  listModel.loadVideos();
                }
            }
        }

        ListView {
            id: listView
            Layout.fillHeight: true
            Layout.fillWidth: true

            model: listModel

            spacing: 20
            clip: true

            delegate: VideosDelegate {}
        }

        MVideos {
            id: listModel
        }
    }
}



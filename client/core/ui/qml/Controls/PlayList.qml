import QtQuick
import QtQuick.Layouts
import com.qt.birdo 1.0

import "../Components"

Rectangle {
    id: root

    color: "#000000"
    radius: 8
    border.color: "#685752"

    ColumnLayout {
        anchors.fill: parent
        spacing: 15

        Text {
            id: playlistTitle
            text: "Videos Playlist"

            color: "#ffffff"
            font.pixelSize: 13
            font.weight: 400

            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 15
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



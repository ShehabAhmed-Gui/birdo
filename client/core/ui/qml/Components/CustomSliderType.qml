import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Fusion

Slider {
    id: customSlider

    property bool enableGradiant: true
    property bool enableHandler: true
    property double gradiantFirstPos: 0.40448
    property double gradiantLastStop: 1

    property string gradiantFirstColor: "#07c8f9"
    property string gradiantSecondColor: "#0d41e1"
    property string handleColor: "#26355D"
    property string subPageColor: "#333333"

    property int sliderWidth: 150
    property int sliderHeight: 7



    focus: false
    stepSize: 1

    // MouseArea {
    //     id: sliderMA
    //     anchors.fill: parent
    //     preventStealing: true
    // }

    background: Rectangle {
        x: customSlider.leftPadding
        y: customSlider.topPadding + customSlider.availableHeight / 2 - height / 2
        implicitWidth: sliderWidth
        implicitHeight: sliderHeight
        width: customSlider.availableWidth
        height: implicitHeight
        radius: 2
        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop { position: 0.40448; color: subPageColor }
        }

        Rectangle {
            width: customSlider.visualPosition * parent.width
            height: parent.height
            gradient: Gradient {
                orientation: Gradient.Horizontal
                GradientStop { position: gradiantFirstPos; color: gradiantFirstColor  }
                GradientStop { position: gradiantLastStop; color: gradiantSecondColor }
            }
            radius: 2
        }
    }

    handle: Rectangle {
        visible: enableHandler? true : false
        x: customSlider.leftPadding + customSlider.visualPosition * (customSlider.availableWidth - width)
        y: customSlider.topPadding + customSlider.availableHeight / 2 - height / 2
        implicitWidth: 15
        implicitHeight: 15
        radius: 13
        color: handleColor
    }
}

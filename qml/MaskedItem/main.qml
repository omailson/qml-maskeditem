import QtQuick 1.0
import MLItem 1.0

Rectangle {
    id: root

    width: 360
    height: 360

    MaskedItem {
        id: maskedItem

        anchors.fill: parent

        maskSource: "../../mask.png"

        Image {
            id: imagem

            anchors.centerIn: parent
            source: "../../image.png"
        }

        Rectangle {
            anchors.centerIn: imagem
            width: 200
            height: 200
            color: "blue"
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            imagem.source = "../../MaskedItem64.png"
        }
    }
}

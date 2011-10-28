import QtQuick 1.0
import MLItem 1.0

Rectangle {
    id: root

    width: 360
    height: 360
    Text {
        visible: false
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }

    Component {
        id: imagem

        Item {
//            anchors.fill: root
//            color: "yellow"

            Image {
                anchors.centerIn: parent

                source: "../../image.png"
            }

            Image {
                anchors.centerIn: parent

                source: "../../MaskedItem80.png"
            }
        }
    }

    Component {
        id: imagem2

        Item {
            width: childrenRect.width
            height: childrenRect.height

            Rectangle {
                id: rect

                color: "blue"
                width: 200
                height: 200
//                anchors.fill: parent
            }
        }
    }

    Component {
        id: imagem3
        Image {
            source: "../../image.png"
        }
    }

    MaskedItem {
        id: maskedItem

        visible: true

        anchors.centerIn: parent

//        sourceComponent: imagem
        maskSource: "../../mask.png"

        Image {
            anchors.right: parent.right
            source: "../../image.png"
        }

//        source: "../../MaskedItem80.png"
    }

    Loader {
        visible: false

        anchors.centerIn: parent
        sourceComponent: imagem
    }


    MouseArea {
        anchors.fill: parent
        onClicked: {
//            imagem.source = "../../MaskedItem64.png"
        }
    }
}

import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Chat")

    ScrollView {
        anchors.fill: parent
        ListView {
            width: parent.width
            model: usermodel
            delegate: ItemDelegate {
                text: userId
                width: parent.width
            }
        }
    }
}

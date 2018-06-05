import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
ApplicationWindow {
    visible: true
    minimumHeight: 800
    minimumWidth: 600
    width: 600
    height: 800
    title: qsTr("Chat1")
    Item{
        anchors.fill: parent
        ScrollView {
            id:listUsers
            height: parent.height
            width: 200
            ListView {
                width: 100
                model: usermodel
                delegate: ItemDelegate {
                    text: userId
                    width: parent.width
                }
            }
        }
        Item{
            anchors.bottom: parent.bottom
            anchors.left: listUsers.right
            anchors.right: parent.right
            height: 200
            Button{
                id:btnSend
                text:"Отправить"
                font.pixelSize: 12
                width: 100
                height: 50
                anchors.right: parent.right
                anchors.margins: 10
                anchors.bottom: parent.bottom
            }
            ScrollView {
                anchors.left: parent.left
                anchors.right: btnSend.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.margins: 10

                TextArea{
                    font.pixelSize: 16
                    wrapMode: TextArea.Wrap
                    textFormat: Qt.RichText
                    selectByMouse: true
                    leftPadding: 10
                    rightPadding: 10
                    placeholderText : "Введите сообщение"
                    selectedTextColor: "#eee"
                    selectionColor: "steelblue"

                    background: Rectangle{
                        color: "#eee"
                        radius: 10
                    }
                }
            }
        }

    }
}

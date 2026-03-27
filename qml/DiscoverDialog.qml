import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Dialog {
    id: discoverDialog
    title: "Discover Bulbs"
    modal: true
    anchors.centerIn: parent
    width: 500
    height: 450

    onOpened: {
        bulbManager.discover()
    }

    onClosed: {
        bulbManager.stopScan()
    }

    contentItem: ColumnLayout {
        spacing: 12

        // Status
        RowLayout {
            spacing: 8
            BusyIndicator {
                visible: bulbManager.scanning
                running: bulbManager.scanning
                Layout.preferredWidth: 24
                Layout.preferredHeight: 24
            }
            Label {
                text: bulbManager.scanning
                    ? "Scanning network for bulbs..."
                    : "Scan complete. Found " + discoveredList.count + " bulb(s)."
                color: "#ccc"
                font.pixelSize: 14
            }
        }

        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: "#0f3460"
        }

        // Discovered list
        ListView {
            id: discoveredList
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: bulbManager.discoveredCount

            delegate: Rectangle {
                width: discoveredList.width
                height: 60
                color: index % 2 === 0 ? "#1a1a3e" : "#16213e"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 8
                    spacing: 12

                    Rectangle {
                        width: 8; height: 8; radius: 4
                        color: "#4caf50"
                    }

                    ColumnLayout {
                        spacing: 2
                        Layout.fillWidth: true

                        Label {
                            text: bulbManager.discoveredIp(index)
                            color: "#e0e0e0"
                            font.pixelSize: 14
                            font.bold: true
                        }
                        Label {
                            text: "MAC: " + bulbManager.discoveredMac(index) +
                                  " · Model: " + bulbManager.discoveredModel(index)
                            color: "#888"
                            font.pixelSize: 11
                        }
                    }

                    Button {
                        text: "Add"
                        palette.button: "#e94560"
                        palette.buttonText: "#ffffff"
                        onClicked: {
                            bulbManager.addBulb(
                                bulbManager.discoveredIp(index),
                                bulbManager.discoveredMac(index),
                                bulbManager.discoveredModel(index)
                            )
                        }
                    }
                }
            }

            // Empty state
            Label {
                visible: discoveredList.count === 0 && !bulbManager.scanning
                anchors.centerIn: parent
                text: "No bulbs found.\nMake sure bulbs are powered on\nand on the same 2.4GHz WiFi network."
                color: "#666"
                font.pixelSize: 13
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: "#0f3460"
        }

        // Actions
        RowLayout {
            spacing: 8
            Layout.fillWidth: true

            Button {
                text: bulbManager.scanning ? "Scanning..." : "🔍 Rescan"
                enabled: !bulbManager.scanning
                palette.button: "#0f3460"
                palette.buttonText: "#e0e0e0"
                onClicked: bulbManager.discover()
            }

            Item { Layout.fillWidth: true }

            Button {
                text: "Close"
                palette.button: "#333333"
                palette.buttonText: "#e0e0e0"
                onClicked: discoverDialog.close()
            }
        }
    }
}

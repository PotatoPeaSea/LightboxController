import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ScrollView {
    id: inspectorRoot

    property var bulb: bulbManager.selectedBulb

    ColumnLayout {
        width: inspectorRoot.width - 16
        spacing: 16

        // ─── Header ──────────────────────────────────

        Label {
            text: "Inspector"
            font.pixelSize: 20
            font.bold: true
            color: "#e94560"
            Layout.fillWidth: true
        }

        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: "#0f3460"
        }

        // ─── No Selection ────────────────────────────

        Label {
            visible: !inspectorRoot.bulb
            text: "Select a bulb to inspect"
            color: "#666"
            font.italic: true
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
        }

        // ─── Bulb Info ──────────────────────────────

        ColumnLayout {
            visible: !!inspectorRoot.bulb
            Layout.fillWidth: true
            spacing: 12

            // Label
            Label { text: "LABEL"; color: "#888"; font.pixelSize: 10; font.bold: true }
            TextField {
                id: labelField
                Layout.fillWidth: true
                text: inspectorRoot.bulb ? inspectorRoot.bulb.label : ""
                color: "#e0e0e0"
                onTextEdited: {
                    if (inspectorRoot.bulb) {
                        inspectorRoot.bulb.label = text
                    }
                }
            }

            // Connection status
            Row {
                spacing: 8
                Rectangle {
                    width: 10; height: 10; radius: 5
                    color: (inspectorRoot.bulb && inspectorRoot.bulb.connected) ? "#4caf50" : "#f44336"
                    anchors.verticalCenter: parent.verticalCenter
                }
                Label {
                    text: (inspectorRoot.bulb && inspectorRoot.bulb.connected) ? "Connected" : "Disconnected"
                    color: "#aaa"
                    font.pixelSize: 12
                }
                Label {
                    text: inspectorRoot.bulb ? inspectorRoot.bulb.ip : ""
                    color: "#666"
                    font.pixelSize: 11
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // Power toggle
            Label { text: "POWER"; color: "#888"; font.pixelSize: 10; font.bold: true }
            Switch {
                id: powerSwitch
                checked: inspectorRoot.bulb ? inspectorRoot.bulb.power : false
                onToggled: {
                    if (inspectorRoot.bulb) {
                        if (checked) inspectorRoot.bulb.turnOn()
                        else inspectorRoot.bulb.turnOff()
                    }
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ─── Color Controls ─────────────────────

            Label { text: "COLOR"; color: "#888"; font.pixelSize: 10; font.bold: true }

            // Color preview
            Rectangle {
                Layout.fillWidth: true
                height: 40
                radius: 6
                color: inspectorRoot.bulb ? inspectorRoot.bulb.displayColor : "#333"
                border.color: "#0f3460"
                border.width: 1
            }

            // Red slider
            Label { text: "Red: " + redSlider.value.toFixed(0); color: "#ef5350"; font.pixelSize: 12 }
            Slider {
                id: redSlider
                Layout.fillWidth: true
                from: 0; to: 255; stepSize: 1
                value: inspectorRoot.bulb ? inspectorRoot.bulb.red : 0
                onMoved: {
                    if (inspectorRoot.bulb)
                        inspectorRoot.bulb.setColor(value, greenSlider.value, blueSlider.value)
                }
            }

            // Green slider
            Label { text: "Green: " + greenSlider.value.toFixed(0); color: "#66bb6a"; font.pixelSize: 12 }
            Slider {
                id: greenSlider
                Layout.fillWidth: true
                from: 0; to: 255; stepSize: 1
                value: inspectorRoot.bulb ? inspectorRoot.bulb.green : 0
                onMoved: {
                    if (inspectorRoot.bulb)
                        inspectorRoot.bulb.setColor(redSlider.value, value, blueSlider.value)
                }
            }

            // Blue slider
            Label { text: "Blue: " + blueSlider.value.toFixed(0); color: "#42a5f5"; font.pixelSize: 12 }
            Slider {
                id: blueSlider
                Layout.fillWidth: true
                from: 0; to: 255; stepSize: 1
                value: inspectorRoot.bulb ? inspectorRoot.bulb.blue : 0
                onMoved: {
                    if (inspectorRoot.bulb)
                        inspectorRoot.bulb.setColor(redSlider.value, greenSlider.value, value)
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ─── White Controls ─────────────────────

            Label { text: "WHITE TEMPERATURE"; color: "#888"; font.pixelSize: 10; font.bold: true }

            // Warm White
            Label { text: "Warm White: " + warmSlider.value.toFixed(0); color: "#ffab40"; font.pixelSize: 12 }
            Slider {
                id: warmSlider
                Layout.fillWidth: true
                from: 0; to: 255; stepSize: 1
                value: inspectorRoot.bulb ? inspectorRoot.bulb.warmWhite : 0
                onMoved: {
                    if (inspectorRoot.bulb)
                        inspectorRoot.bulb.setWhite(value, coolSlider.value)
                }
            }

            // Cool White
            Label { text: "Cool White: " + coolSlider.value.toFixed(0); color: "#80deea"; font.pixelSize: 12 }
            Slider {
                id: coolSlider
                Layout.fillWidth: true
                from: 0; to: 255; stepSize: 1
                value: inspectorRoot.bulb ? inspectorRoot.bulb.coolWhite : 0
                onMoved: {
                    if (inspectorRoot.bulb)
                        inspectorRoot.bulb.setWhite(warmSlider.value, value)
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ─── Quick Colors ───────────────────────

            Label { text: "QUICK COLORS"; color: "#888"; font.pixelSize: 10; font.bold: true }

            GridLayout {
                Layout.fillWidth: true
                columns: 5
                rowSpacing: 6
                columnSpacing: 6

                Repeater {
                    model: [
                        "#FF0000", "#00FF00", "#0000FF", "#FFFF00", "#FF00FF",
                        "#00FFFF", "#FF8000", "#FF0080", "#8000FF", "#FFFFFF"
                    ]

                    delegate: Rectangle {
                        width: 36; height: 36
                        radius: 6
                        color: modelData
                        border.color: Qt.lighter(modelData, 1.3)
                        border.width: 1

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            hoverEnabled: true
                            onClicked: {
                                if (inspectorRoot.bulb) {
                                    var c = modelData
                                    var r = parseInt(c.substr(1,2), 16)
                                    var g = parseInt(c.substr(3,2), 16)
                                    var b = parseInt(c.substr(5,2), 16)
                                    inspectorRoot.bulb.setColor(r, g, b)
                                }
                            }
                        }

                        scale: parent.children[0].containsMouse ? 1.15 : 1.0
                        Behavior on scale { NumberAnimation { duration: 100 } }
                    }
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ─── Position ───────────────────────────

            Label { text: "POSITION"; color: "#888"; font.pixelSize: 10; font.bold: true }

            GridLayout {
                Layout.fillWidth: true
                columns: 2
                columnSpacing: 8
                rowSpacing: 4

                Label { text: "X:"; color: "#aaa"; font.pixelSize: 12 }
                SpinBox {
                    id: posXSpin
                    Layout.fillWidth: true
                    from: -100; to: 100
                    value: inspectorRoot.bulb ? Math.round(inspectorRoot.bulb.posX * 10) : 0
                    stepSize: 5
                    editable: true

                    property real realValue: value / 10.0
                    textFromValue: function(value) { return (value / 10.0).toFixed(1) }
                    valueFromText: function(text) { return Math.round(parseFloat(text) * 10) }

                    onValueModified: {
                        if (inspectorRoot.bulb)
                            inspectorRoot.bulb.posX = realValue
                    }
                }

                Label { text: "Y:"; color: "#aaa"; font.pixelSize: 12 }
                SpinBox {
                    id: posYSpin
                    Layout.fillWidth: true
                    from: -100; to: 100
                    value: inspectorRoot.bulb ? Math.round(inspectorRoot.bulb.posY * 10) : 0
                    stepSize: 5
                    editable: true

                    property real realValue: value / 10.0
                    textFromValue: function(value) { return (value / 10.0).toFixed(1) }
                    valueFromText: function(text) { return Math.round(parseFloat(text) * 10) }

                    onValueModified: {
                        if (inspectorRoot.bulb)
                            inspectorRoot.bulb.posY = realValue
                    }
                }

                Label { text: "Z:"; color: "#aaa"; font.pixelSize: 12 }
                SpinBox {
                    id: posZSpin
                    Layout.fillWidth: true
                    from: -100; to: 100
                    value: inspectorRoot.bulb ? Math.round(inspectorRoot.bulb.posZ * 10) : 0
                    stepSize: 5
                    editable: true

                    property real realValue: value / 10.0
                    textFromValue: function(value) { return (value / 10.0).toFixed(1) }
                    valueFromText: function(text) { return Math.round(parseFloat(text) * 10) }

                    onValueModified: {
                        if (inspectorRoot.bulb)
                            inspectorRoot.bulb.posZ = realValue
                    }
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ─── Actions ────────────────────────────

            Label { text: "ACTIONS"; color: "#888"; font.pixelSize: 10; font.bold: true }

            Button {
                text: "🔄 Refresh State"
                Layout.fillWidth: true
                palette.button: "#0f3460"
                palette.buttonText: "#e0e0e0"
                onClicked: {
                    if (inspectorRoot.bulb)
                        inspectorRoot.bulb.queryState()
                }
            }

            Button {
                text: "🗑 Remove Bulb"
                Layout.fillWidth: true
                palette.button: "#b71c1c"
                palette.buttonText: "#e0e0e0"
                onClicked: {
                    if (inspectorRoot.bulb) {
                        var idx = -1
                        for (var i = 0; i < bulbManager.count; i++) {
                            var b = bulbManager.bulbAt(i)
                            if (b === inspectorRoot.bulb) { idx = i; break }
                        }
                        if (idx >= 0) bulbManager.removeBulb(idx)
                    }
                }
            }

            // Spacer
            Item { Layout.fillHeight: true }
        }
    }
}

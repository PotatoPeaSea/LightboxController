import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1 as Platform

// Side-panel component (not a Dialog) so the 3D view stays accessible
Rectangle {
    id: vpPanel
    color: "#16213e"

    property bool panelVisible: false

    // ─── File Dialog ──────────────────────────────────
    Platform.FileDialog {
        id: videoFileDialog
        title: "Select a pattern video"
        nameFilters: ["Video files (*.mp4 *.avi *.mov *.wmv *.webm *.mkv)", "All files (*)"]
        onAccepted: {
            patternEngine.loadVideo(file.toString())
        }
    }

    ScrollView {
        anchors.fill: parent
        anchors.margins: 8
        clip: true

        ColumnLayout {
            width: vpPanel.width - 24
            spacing: 12

            // ═══ Header ═══════════════════════════════
            Label {
                text: "🎬 VIDEO PATTERN"
                font.pixelSize: 16
                font.bold: true
                color: "#e94560"
                Layout.fillWidth: true
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Status Message ════════════════════════
            Rectangle {
                Layout.fillWidth: true
                height: statusLabel.implicitHeight + 12
                radius: 4
                color: "#0a0a2a"
                border.color: "#0f3460"
                border.width: 1

                Label {
                    id: statusLabel
                    anchors.fill: parent
                    anchors.margins: 6
                    text: patternEngine.statusMessage ? patternEngine.statusMessage : "Ready"
                    color: {
                        var msg = patternEngine.statusMessage || ""
                        if (msg.startsWith("Error")) return "#f44336"
                        if (msg.startsWith("Extraction complete")) return "#4caf50"
                        if (msg.startsWith("Extracting")) return "#ffab40"
                        if (msg.startsWith("Playing")) return "#42a5f5"
                        return "#aaa"
                    }
                    font.pixelSize: 11
                    wrapMode: Text.WordWrap
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Source ════════════════════════════════
            Label { text: "SOURCE"; color: "#888"; font.pixelSize: 10; font.bold: true }

            RowLayout {
                Layout.fillWidth: true
                spacing: 8

                Button {
                    text: "📁 Load Video"
                    palette.button: "#0f3460"
                    palette.buttonText: "#e0e0e0"
                    onClicked: videoFileDialog.open()
                }

                Label {
                    text: patternEngine.fileName ? patternEngine.fileName : "No file"
                    color: patternEngine.fileName ? "#e0e0e0" : "#666"
                    font.pixelSize: 11
                    font.italic: !patternEngine.fileName
                    elide: Text.ElideMiddle
                    Layout.fillWidth: true
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Configuration ════════════════════════
            Label { text: "CONFIG"; color: "#888"; font.pixelSize: 10; font.bold: true }

            RowLayout {
                Layout.fillWidth: true
                spacing: 8

                Label { text: "Samples:"; color: "#aaa"; font.pixelSize: 12 }
                SpinBox {
                    id: sampleSpin
                    from: 1; to: 20
                    value: patternEngine.sampleCount
                    onValueModified: patternEngine.sampleCount = value
                    Layout.preferredWidth: 90
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 8

                Label { text: "Loop:"; color: "#aaa"; font.pixelSize: 12 }
                Switch {
                    checked: patternEngine.looping
                    onToggled: patternEngine.looping = checked
                }
            }



            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Extraction ═══════════════════════════
            Label { text: "EXTRACTION"; color: "#888"; font.pixelSize: 10; font.bold: true }

            RowLayout {
                Layout.fillWidth: true
                spacing: 8

                Button {
                    text: patternEngine.extracting ? "⏳ Extracting..." : "⚡ Extract"
                    enabled: !!patternEngine.fileName && !patternEngine.extracting
                    palette.button: "#533483"
                    palette.buttonText: "#e0e0e0"
                    onClicked: patternEngine.extractPattern()
                }

                Button {
                    text: "✖ Cancel"
                    visible: patternEngine.extracting
                    palette.button: "#b71c1c"
                    palette.buttonText: "#e0e0e0"
                    onClicked: patternEngine.cancelExtraction()
                }
            }

            // Progress bar
            ProgressBar {
                Layout.fillWidth: true
                value: patternEngine.extractionProgress
                visible: patternEngine.extracting

                background: Rectangle {
                    implicitHeight: 6
                    color: "#0a0a2a"
                    radius: 3
                }
                contentItem: Item {
                    implicitHeight: 6
                    Rectangle {
                        width: parent.width * patternEngine.extractionProgress
                        height: parent.height
                        radius: 3
                        color: "#e94560"
                    }
                }
            }

            // Pattern info
            Label {
                visible: patternEngine.patternReady
                text: "✅ " + patternEngine.patternFrameCount + " frames, "
                      + (patternEngine.patternDurationMs / 1000.0).toFixed(1) + "s"
                color: "#4caf50"
                font.pixelSize: 12
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Target Bulbs ═════════════════════════
            Label { text: "TARGET BULBS"; color: "#888"; font.pixelSize: 10; font.bold: true }

            Label {
                text: "Select bulbs in 3D view, then assign."
                color: "#666"
                font.pixelSize: 10
                font.italic: true
                wrapMode: Text.WordWrap
                Layout.fillWidth: true
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 6

                Button {
                    text: "🎯 Assign Selected"
                    palette.button: "#0f3460"
                    palette.buttonText: "#e0e0e0"
                    onClicked: {
                        var bulbs = bulbManager.selectedBulbsList()
                        if (bulbs.length === 0) {
                            bulbs = bulbManager.allBulbsList()
                        }
                        patternEngine.setTargetBulbs(bulbs)
                        sampleSpin.value = bulbs.length
                    }
                }

                Button {
                    text: "🗑"
                    palette.button: "#333"
                    palette.buttonText: "#e0e0e0"
                    onClicked: patternEngine.clearTargetBulbs()
                    implicitWidth: 36
                }
            }

            Label {
                text: patternEngine.targetBulbCount > 0
                      ? "🔵 " + patternEngine.targetBulbCount + " bulb(s)"
                      : "No bulbs assigned"
                color: patternEngine.targetBulbCount > 0 ? "#42a5f5" : "#666"
                font.pixelSize: 11
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Playback ═════════════════════════════
            Label { text: "PLAYBACK"; color: "#888"; font.pixelSize: 10; font.bold: true }

            RowLayout {
                Layout.fillWidth: true
                spacing: 6

                Button {
                    text: patternEngine.playing && !patternEngine.paused ? "⏸" : "▶"
                    enabled: patternEngine.patternReady
                    palette.button: "#1b5e20"
                    palette.buttonText: "#e0e0e0"
                    implicitWidth: 40
                    onClicked: {
                        if (patternEngine.playing && !patternEngine.paused)
                            patternEngine.pause()
                        else
                            patternEngine.play()
                    }
                }

                Button {
                    text: "⏹"
                    enabled: patternEngine.playing
                    palette.button: "#b71c1c"
                    palette.buttonText: "#e0e0e0"
                    implicitWidth: 40
                    onClicked: patternEngine.stop()
                }

                Label {
                    visible: patternEngine.patternReady
                    text: (patternEngine.playbackPositionMs / 1000.0).toFixed(1) + "s"
                    color: "#aaa"
                    font.pixelSize: 11
                }

                Slider {
                    id: scrubSlider
                    visible: patternEngine.patternReady
                    Layout.fillWidth: true
                    from: 0
                    to: patternEngine.patternDurationMs > 0 ? patternEngine.patternDurationMs : 1
                    value: patternEngine.playbackPositionMs
                    
                    // Break the binding while dragging so the 33ms timer doesn't snap it back
                    Binding on value {
                        when: !scrubSlider.pressed
                        value: patternEngine.playbackPositionMs
                    }
                    
                    onMoved: {
                        patternEngine.playbackPositionMs = value
                    }
                }

                Label {
                    visible: patternEngine.patternReady
                    text: (patternEngine.patternDurationMs / 1000.0).toFixed(1) + "s"
                    color: "#aaa"
                    font.pixelSize: 11
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 8

                Label { text: "Speed:"; color: "#aaa"; font.pixelSize: 12; Layout.preferredWidth: 40 }
                Slider {
                    id: speedSlider
                    from: 0.1
                    to: 5.0
                    stepSize: 0.1
                    value: patternEngine.playbackSpeed !== undefined ? patternEngine.playbackSpeed : 1.0
                    onValueChanged: patternEngine.playbackSpeed = value
                    Layout.fillWidth: true
                }
                Label {
                    text: speedSlider.value.toFixed(1) + "x"
                    color: "#e0e0e0"
                    font.pixelSize: 11
                    Layout.preferredWidth: 30
                    horizontalAlignment: Text.AlignRight
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Save Pattern ═════════════════════════
            Label { text: "SAVE PATTERN"; color: "#888"; font.pixelSize: 10; font.bold: true }

            RowLayout {
                Layout.fillWidth: true
                spacing: 6

                TextField {
                    id: patternNameField
                    placeholderText: "Pattern name..."
                    Layout.fillWidth: true
                    color: "#e0e0e0"
                    font.pixelSize: 11
                }

                Button {
                    text: "💾 Save"
                    enabled: patternEngine.patternReady && patternNameField.text.length > 0
                    palette.button: "#1b5e20"
                    palette.buttonText: "#e0e0e0"
                    onClicked: {
                        patternEngine.saveCurrentPattern(patternNameField.text)
                        patternNameField.text = ""
                    }
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Live Color Preview ═══════════════════
            Label { text: "PREVIEW"; color: "#888"; font.pixelSize: 10; font.bold: true }

            RowLayout {
                Layout.fillWidth: true
                spacing: 3

                Repeater {
                    model: patternEngine.currentColors

                    delegate: Rectangle {
                        Layout.fillWidth: true
                        height: 40
                        radius: 4
                        color: modelData
                        border.color: Qt.lighter(modelData, 1.3)
                        border.width: 1

                        Label {
                            anchors.centerIn: parent
                            text: (index === 0) ? "Far" : (index === patternEngine.currentColors.length - 1 ? "Near" : "")
                            color: "#000"
                            font.pixelSize: 8
                            font.bold: true
                            opacity: 0.6
                        }
                    }
                }

                Label {
                    visible: patternEngine.currentColors.length === 0
                    text: "—"
                    color: "#555"
                    font.pixelSize: 11
                }
            }

            // Spacer
            Item { Layout.fillHeight: true; Layout.minimumHeight: 8 }
        }
    }

    // Error handling
    Connections {
        target: patternEngine
        function onErrorOccurred(message) {
            console.warn("Pattern engine error:", message)
        }
    }
}

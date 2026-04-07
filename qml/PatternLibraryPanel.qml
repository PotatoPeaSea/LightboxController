import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

// Side-panel: lists saved patterns, click to load & play
Rectangle {
    id: libPanel
    color: "#16213e"

    ScrollView {
        anchors.fill: parent
        anchors.margins: 8
        clip: true

        ColumnLayout {
            width: libPanel.width - 24
            spacing: 12

            // ═══ Header ═══════════════════════════════
            Label {
                text: "📚 PATTERN LIBRARY"
                font.pixelSize: 16
                font.bold: true
                color: "#e94560"
                Layout.fillWidth: true
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Status ═══════════════════════════════
            Label {
                text: patternEngine.statusMessage ? patternEngine.statusMessage : "Select a pattern to play"
                color: "#aaa"
                font.pixelSize: 11
                wrapMode: Text.WordWrap
                Layout.fillWidth: true
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Target Bulbs ═════════════════════════
            Label { text: "TARGET BULBS"; color: "#888"; font.pixelSize: 10; font.bold: true }

            RowLayout {
                Layout.fillWidth: true
                spacing: 6

                Button {
                    text: "🎯 Assign Selected"
                    palette.button: "#0f3460"
                    palette.buttonText: "#e0e0e0"
                    onClicked: {
                        var bulbs = bulbManager.selectedBulbsList()
                        if (bulbs.length === 0)
                            bulbs = bulbManager.allBulbsList()
                        patternEngine.setTargetBulbs(bulbs)
                    }
                }

                Label {
                    text: patternEngine.targetBulbCount > 0
                          ? "🔵 " + patternEngine.targetBulbCount
                          : "None"
                    color: patternEngine.targetBulbCount > 0 ? "#42a5f5" : "#666"
                    font.pixelSize: 11
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Saved Patterns List ══════════════════
            Label { text: "SAVED PATTERNS"; color: "#888"; font.pixelSize: 10; font.bold: true }

            // Empty state
            Label {
                visible: patternList.count === 0
                text: "No saved patterns yet.\nExtract a pattern and save it."
                color: "#555"
                font.pixelSize: 11
                font.italic: true
                wrapMode: Text.WordWrap
                Layout.fillWidth: true
            }

            // Pattern list
            Repeater {
                id: patternList
                model: patternEngine.savedPatterns

                delegate: Rectangle {
                    Layout.fillWidth: true
                    height: 44
                    radius: 6
                    color: patternItemMa.containsMouse ? "#2a2a5e" : "#1e1e3a"
                    border.color: patternItemMa.containsMouse ? "#e94560" : "#0f3460"
                    border.width: 1

                    MouseArea {
                        id: patternItemMa
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            patternEngine.loadPattern(modelData)
                        }
                    }

                    RowLayout {
                        anchors.fill: parent
                        anchors.margins: 8
                        spacing: 8

                        Label {
                            text: "▶"
                            color: "#4caf50"
                            font.pixelSize: 16
                        }

                        Label {
                            text: modelData
                            color: "#e0e0e0"
                            font.pixelSize: 13
                            elide: Text.ElideRight
                            Layout.fillWidth: true
                        }

                        // Delete button
                        Button {
                            text: "✖"
                            implicitWidth: 28
                            implicitHeight: 28
                            palette.button: "transparent"
                            palette.buttonText: "#777"
                            onClicked: {
                                patternEngine.deletePattern(modelData)
                            }
                        }
                    }
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Playback Controls ════════════════════
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

                Switch {
                    checked: patternEngine.looping
                    onToggled: patternEngine.looping = checked
                }

                Label {
                    text: "Loop"
                    color: "#aaa"
                    font.pixelSize: 10
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: "#0f3460" }

            // ═══ Color Preview ════════════════════════
            RowLayout {
                Layout.fillWidth: true
                spacing: 3

                Repeater {
                    model: patternEngine.currentColors
                    delegate: Rectangle {
                        Layout.fillWidth: true
                        height: 30
                        radius: 3
                        color: modelData
                        border.color: Qt.lighter(modelData, 1.3)
                        border.width: 1
                    }
                }
            }

            // Spacer
            Item { Layout.fillHeight: true; Layout.minimumHeight: 8 }
        }
    }
}

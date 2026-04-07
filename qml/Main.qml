import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt3D.Core 2.15
import Qt3D.Render 2.15
import Qt3D.Input 2.15
import Qt3D.Extras 2.15
import QtQuick.Scene3D 2.15
import LightboxController 1.0

ApplicationWindow {
    id: root
    width: 1400
    height: 900
    minimumWidth: 1000
    minimumHeight: 600
    visible: true
    title: "LightboxController"

    color: "#1a1a2e"

    property bool videoPatternVisible: false
    property bool patternLibraryVisible: false

    // ─── Header Toolbar ───────────────────────────────────

    header: ToolBar {
        background: Rectangle {
            color: "#16213e"
            border.color: "#0f3460"
            border.width: 1
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 16
            anchors.rightMargin: 16
            spacing: 12

            Label {
                text: "💡 LightboxController"
                font.pixelSize: 18
                font.bold: true
                color: "#e94560"
            }

            Item { Layout.fillWidth: true }

            Button {
                text: bulbManager.scanning ? "⏳ Scanning..." : "🔍 Discover"
                enabled: !bulbManager.scanning
                palette.button: "#0f3460"
                palette.buttonText: "#e0e0e0"
                onClicked: discoverDialog.open()
            }

            Button {
                text: "➕ Add Manual"
                palette.button: "#0f3460"
                palette.buttonText: "#e0e0e0"
                onClicked: addManualDialog.open()
            }

            Button {
                text: "🔌 Connect All"
                palette.button: "#533483"
                palette.buttonText: "#e0e0e0"
                onClicked: bulbManager.connectAll()
            }

            Button {
                text: videoPatternVisible ? "🎬 Hide Extract" : "🎬 Extract"
                palette.button: videoPatternVisible ? "#533483" : "#0f3460"
                palette.buttonText: "#e0e0e0"
                onClicked: videoPatternVisible = !videoPatternVisible
            }

            Button {
                text: patternLibraryVisible ? "📚 Hide Library" : "📚 Patterns"
                palette.button: patternLibraryVisible ? "#533483" : "#0f3460"
                palette.buttonText: "#e0e0e0"
                onClicked: patternLibraryVisible = !patternLibraryVisible
            }

            Label {
                text: "Bulbs: " + bulbManager.count
                font.pixelSize: 14
                color: "#aaa"
            }
        }
    }

    // ─── Main Content ─────────────────────────────────────

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // ─── Bulb List Sidebar ────────────────────────
        Rectangle {
            Layout.preferredWidth: 200
            Layout.fillHeight: true
            color: "#111133"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 8
                spacing: 8

                Label {
                    text: "Bulbs"
                    font.pixelSize: 16
                    font.bold: true
                    color: "#e94560"
                }

                Rectangle {
                    Layout.fillWidth: true
                    height: 1
                    color: "#0f3460"
                }

                ListView {
                    id: bulbListView
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    clip: true
                    model: bulbManager
                    spacing: 4

                    delegate: Rectangle {
                        width: bulbListView.width
                        height: 56
                        radius: 6
                        color: (model.selected !== undefined && model.selected) ? "#2a2a5e" : (bulbItemMa.containsMouse ? "#1e1e4a" : "#16213e")
                        border.color: (model.selected !== undefined && model.selected) ? "#e94560" : "transparent"
                        border.width: (model.selected !== undefined && model.selected) ? 2 : 0

                        MouseArea {
                            id: bulbItemMa
                            anchors.fill: parent
                            hoverEnabled: true
                            cursorShape: Qt.PointingHandCursor
                            onClicked: bulbManager.handleBulbClick(index)
                        }

                        RowLayout {
                            anchors.fill: parent
                            anchors.margins: 8
                            spacing: 8

                            // Color indicator
                            Rectangle {
                                width: 12; height: 12; radius: 6
                                color: model.displayColor !== undefined ? model.displayColor : "#333"
                                border.color: Qt.lighter(model.displayColor !== undefined ? model.displayColor : "#333", 1.3)
                                border.width: 1
                            }

                            ColumnLayout {
                                spacing: 2
                                Layout.fillWidth: true

                                Label {
                                    text: model.label !== undefined ? model.label : ""
                                    color: (model.selected !== undefined && model.selected) ? "#e94560" : "#e0e0e0"
                                    font.pixelSize: 13
                                    font.bold: model.selected !== undefined ? model.selected : false
                                    elide: Text.ElideRight
                                    Layout.fillWidth: true
                                }
                                Label {
                                    text: model.ip !== undefined ? model.ip : ""
                                    color: "#666"
                                    font.pixelSize: 10
                                    elide: Text.ElideRight
                                    Layout.fillWidth: true
                                }
                            }

                            // Connection dot
                            Rectangle {
                                width: 8; height: 8; radius: 4
                                color: (model.connected !== undefined && model.connected) ? "#4caf50" : "#f44336"
                            }
                        }
                    }

                    // Empty state
                    Label {
                        visible: bulbListView.count === 0
                        anchors.centerIn: parent
                        text: "No bulbs added.\nUse Discover or\nAdd Manual."
                        color: "#555"
                        font.pixelSize: 12
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        }

        // ─── 3D Viewport ──────────────────────────────
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                anchors.fill: parent
                color: "#0a0a1a"

                Scene3D {
                    id: scene3d
                    anchors.fill: parent
                    focus: true
                    aspects: ["input", "logic"]
                    cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

                    Entity {
                        id: sceneRoot

                        Camera {
                            id: mainCamera
                            projectionType: CameraLens.PerspectiveProjection
                            fieldOfView: 55
                            nearPlane: 0.1
                            farPlane: 1000.0
                            position: Qt.vector3d(0, 8, 15)
                            upVector: Qt.vector3d(0, 1, 0)
                            viewCenter: Qt.vector3d(0, 0, 0)
                        }

                        OrbitCameraController {
                            camera: mainCamera
                            linearSpeed: 20
                            lookSpeed: 150
                        }

                        components: [
                            RenderSettings {
                                activeFrameGraph: ForwardRenderer {
                                    clearColor: "#0a0a1a"
                                    camera: mainCamera
                                }
                            },
                            InputSettings {}
                        ]

                        // Ambient light
                        Entity {
                            components: [
                                PointLight {
                                    color: "#556677"
                                    intensity: 0.4
                                },
                                Transform {
                                    translation: Qt.vector3d(0, 10, 0)
                                }
                            ]
                        }

                        // Secondary light
                        Entity {
                            components: [
                                PointLight {
                                    color: "#334455"
                                    intensity: 0.2
                                },
                                Transform {
                                    translation: Qt.vector3d(10, 5, 10)
                                }
                            ]
                        }

                        // Grid floor
                        Entity {
                            components: [
                                PlaneMesh {
                                    width: 30
                                    height: 30
                                },
                                PhongAlphaMaterial {
                                    ambient: "#111133"
                                    diffuse: "#0a0a2a"
                                    specular: "#000000"
                                    alpha: 0.5
                                },
                                Transform {
                                    translation: Qt.vector3d(0, -0.5, 0)
                                }
                            ]
                        }

                        // Grid lines (X direction)
                        NodeInstantiator {
                            model: 31
                            delegate: Entity {
                                property int lineIndex: index
                                components: [
                                    CuboidMesh {
                                        xExtent: 30
                                        yExtent: 0.01
                                        zExtent: 0.02
                                    },
                                    PhongMaterial {
                                        ambient: "#1a1a4e"
                                        diffuse: "#1a1a4e"
                                    },
                                    Transform {
                                        translation: Qt.vector3d(0, -0.49, (lineIndex - 15))
                                    }
                                ]
                            }
                        }

                        // Grid lines (Z direction)
                        NodeInstantiator {
                            model: 31
                            delegate: Entity {
                                property int lineIndex: index
                                components: [
                                    CuboidMesh {
                                        xExtent: 0.02
                                        yExtent: 0.01
                                        zExtent: 30
                                    },
                                    PhongMaterial {
                                        ambient: "#1a1a4e"
                                        diffuse: "#1a1a4e"
                                    },
                                    Transform {
                                        translation: Qt.vector3d((lineIndex - 15), -0.49, 0)
                                    }
                                ]
                            }
                        }

                        // ─── Bulb boxes (using bulbAt to avoid NodeInstantiator role issues) ───
                        NodeInstantiator {
                            id: bulbInstantiator
                            model: bulbManager

                            delegate: Entity {
                                id: bulbEntity
                                property int bulbIndex: index
                                property var bulbObj: bulbManager.bulbAt(bulbIndex)

                                // Bind to the actual Bulb object's properties
                                property real bPosX: bulbObj ? bulbObj.posX : 0
                                property real bPosY: bulbObj ? bulbObj.posY : 0
                                property real bPosZ: bulbObj ? bulbObj.posZ : 0
                                property color bColor: bulbObj ? bulbObj.displayColor : "#333"
                                property bool bPower: bulbObj ? bulbObj.power : false
                                property bool bSelected: bulbObj ? bulbObj.selected : false

                                components: [
                                    CuboidMesh {
                                        xExtent: 1.0
                                        yExtent: 1.0
                                        zExtent: 1.0
                                    },
                                    PhongMaterial {
                                        ambient: bulbEntity.bColor
                                        diffuse: bulbEntity.bColor
                                        specular: Qt.lighter(bulbEntity.bColor, 1.5)
                                        shininess: 50
                                    },
                                    Transform {
                                        translation: Qt.vector3d(bulbEntity.bPosX,
                                                                  bulbEntity.bPosY,
                                                                  bulbEntity.bPosZ)
                                    },
                                    ObjectPicker {
                                        hoverEnabled: true
                                        onClicked: {
                                            bulbManager.handleBulbClick(bulbEntity.bulbIndex)
                                        }
                                    }
                                ]

                                // Point light (glow effect)
                                Entity {
                                    components: [
                                        PointLight {
                                            color: bulbEntity.bColor
                                            intensity: bulbEntity.bPower ? 1.5 : 0.0
                                            constantAttenuation: 1.0
                                            linearAttenuation: 0.2
                                            quadraticAttenuation: 0.05
                                        },
                                        Transform {
                                            translation: Qt.vector3d(0, 0.8, 0)
                                        }
                                    ]
                                }

                                // Selection highlight ring
                                Entity {
                                    enabled: bulbEntity.bSelected
                                    components: [
                                        TorusMesh {
                                            radius: 0.85
                                            minorRadius: 0.04
                                            rings: 32
                                            slices: 16
                                        },
                                        PhongMaterial {
                                            ambient: "#e94560"
                                            diffuse: "#e94560"
                                        },
                                        Transform {
                                            translation: Qt.vector3d(0, 0, 0)
                                            rotationX: 90
                                        }
                                    ]
                                }
                            }
                        }
                    }
                }
            }
        }

        // ─── Video Pattern Panel (toggleable) ─────────
        Rectangle {
            visible: videoPatternVisible
            Layout.preferredWidth: 280
            Layout.minimumWidth: 240
            Layout.maximumWidth: 350
            Layout.fillHeight: true
            color: "#16213e"
            border.color: "#0f3460"
            border.width: 1

            VideoPatternPanel {
                id: videoPatternPanel
                anchors.fill: parent
            }
        }

        // ─── Pattern Library Panel (toggleable) ───────
        Rectangle {
            visible: patternLibraryVisible
            Layout.preferredWidth: 260
            Layout.minimumWidth: 220
            Layout.maximumWidth: 320
            Layout.fillHeight: true
            color: "#16213e"
            border.color: "#0f3460"
            border.width: 1

            PatternLibraryPanel {
                id: patternLibraryPanel
                anchors.fill: parent
            }
        }

        // ─── Inspector Panel ──────────────────────────
        Rectangle {
            Layout.preferredWidth: 320
            Layout.minimumWidth: 280
            Layout.maximumWidth: 450
            Layout.fillHeight: true
            color: "#16213e"

            InspectorPanel {
                anchors.fill: parent
                anchors.margins: 8
            }
        }
    }

    // ─── Discover Dialog ─────────────────────────────────

    DiscoverDialog {
        id: discoverDialog
    }

    // ─── Add Manual Dialog ───────────────────────────────

    Dialog {
        id: addManualDialog
        title: "Add Bulb Manually"
        modal: true
        anchors.centerIn: parent
        width: 350

        contentItem: ColumnLayout {
            spacing: 12
            Label {
                text: "Enter the bulb's IP address:"
                color: "#ccc"
            }
            TextField {
                id: manualIpField
                placeholderText: "192.168.1.100"
                Layout.fillWidth: true
            }
        }

        standardButtons: Dialog.Ok | Dialog.Cancel

        onAccepted: {
            if (manualIpField.text.length > 0) {
                bulbManager.addBulbManual(manualIpField.text)
                manualIpField.text = ""
            }
        }
    }
}

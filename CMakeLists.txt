cmake_minimum_required(VERSION 3.16)
project(LightboxController VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Find Qt5 packages
find_package(Qt5 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Quick
    QuickControls2
    Network
    3DCore
    3DRender
    3DInput
    3DExtras
    3DQuick
    3DQuickExtras
    3DQuickRender
    3DQuickInput
    Multimedia
    MultimediaWidgets
)

# Source files
set(SOURCES
    src/main.cpp
    src/ZenggeProtocol.cpp
    src/BulbScanner.cpp
    src/Bulb.cpp
    src/BulbManager.cpp
    src/VideoPatternEngine.cpp
)

set(HEADERS
    src/ZenggeProtocol.h
    src/BulbScanner.h
    src/Bulb.h
    src/BulbManager.h
    src/VideoPatternEngine.h
)

# QML resource file
qt5_add_resources(QML_RESOURCES qml/qml.qrc)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${QML_RESOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Quick
    Qt5::QuickControls2
    Qt5::Network
    Qt5::3DCore
    Qt5::3DRender
    Qt5::3DInput
    Qt5::3DExtras
    Qt5::3DQuick
    Qt5::3DQuickExtras
    Qt5::3DQuickRender
    Qt5::3DQuickInput
    Qt5::Multimedia
    Qt5::MultimediaWidgets
    ws2_32
)

# Windows subsystem (disabled for debugging, re-enable for release)
# if(WIN32)
#     set_target_properties(${PROJECT_NAME} PROPERTIES
#         WIN32_EXECUTABLE TRUE
#     )
# endif()

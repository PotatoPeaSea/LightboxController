# LightboxController

LightboxController is a Windows desktop application built to give users direct, local control over Surplife/Luckystyle WiFi LED smart bulbs (manufactured by Zengge). It departs from standard mobile applications by offering a 3D spatial interface where users can add, label, arrange, and control multiple bulbs simultaneously on their local network.

The application uses a **C++ backend** for reliable local-network communication, and a **Qt 6 / Qt Quick 3D frontend** for the user interface.

## Features

- **Local Discovery & Registration**: Auto-discover Zengge/LEDENET bulbs on your local network via UDP (no cloud or internet access required).
- **Individual Bulb Control**: Direct control over Power, RGB Color, Brightness, and White Temperature (Warm to Cool).
- **3D Spatial Interface**: Visualize and interact with your bulb arrangements in a real-time 3D environment.
- **Group Settings**: Select and control multiple bulbs simultaneously through the 3D viewport.
- **Fast Local Networking**: Commands are dispatched via raw TCP using the 9-byte LEDENET protocol, ensuring low-latency responses over your local LAN.

## Technology Stack

- **Language**: C++17
- **Platform**: Windows Desktop
- **UI Framework**: Qt 6, Qt Quick 3D
- **Networking**: `QTcpSocket` / `QUdpSocket` (LEDENET Protocol on port 5577, Discovery on port 48899)
- **Persistence**: Qt JSON configuration

## Project Structure

- `src/` - Provides the C++ application backend and logic.
  - `Bulb` - Represents the state of a single physical bulb.
  - `BulbManager` - Central registry handling state, settings, and group selections.
  - `BulbScanner` - Network UDP discovery for finding Zengge bulbs on the LAN.
  - `ZenggeProtocol` - The TCP socket handler for issuing properly formatted 9-byte control packets.
- `qml/` - Contains the Qt Quick user interface configuration.
  - `Main.qml` - Main application window and 3D scene setup.
  - `DiscoverDialog.qml` - The network discovery and device addition screen.
  - `InspectorPanel.qml` - UI for tweaking colors, power, and options of selected bulbs.

## Building and Running

### Prerequisites
- Windows 10/11
- Qt 6 (with Qt Quick 3D and network components installed)
- CMake
- C++17 compatible compiler (e.g., MSVC, MinGW)

### Compiling

You can use the provided build scripts to configure and compile the project into the `build/` directory:

```bat
build.bat
```
*(Or use `.\build.ps1` if you are using PowerShell)*

### Running

After building successfully, run the application using:

```bat
run.bat
```
*(Or `.\run.ps1` if you are using PowerShell)*

## How It Works

LightboxController communicates directly with smart bulbs using the local network **LEDENET protocol**:
- **Discovery**: A UDP broadcast is sent on Port 48899 (`HF-A11ASSISTHREAD`). Responsive bulbs reply with their IP, MAC, and Model.
- **Control**: Once added, LightboxController opens a direct TCP connection to the bulb on Port 5577. It sends control instructions as raw byte-arrays (e.g. 9-byte commands mapping Color, Warm White, Cool White, and operation mode), terminating with a checksum. This allows it to instantly adjust device state without reliance on external servers.

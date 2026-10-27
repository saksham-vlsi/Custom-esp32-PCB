# ESP32 firmware example (PlatformIO)

The example uses Arduino framework with PlatformIO and publishes a periodic JSON telemetry message to an MQTT broker. It intentionally avoids hard-coded Wi-Fi passwords and broker credentials.

## Setup

1. Install VS Code and PlatformIO, or install PlatformIO Core.
2. Copy `include/secrets.example.h` to `include/secrets.h` (create the file locally; it is gitignored by convention if named `secrets.h`).
3. Fill in Wi-Fi SSID/password and broker details.
4. Update `platformio.ini` for the exact ESP32 board/module.
5. Add real sensor drivers and replace the example placeholder reading.
6. Use TLS and broker authentication for non-lab deployments.

## Build

```bash
cd firmware
pio run
pio device monitor
```

Do not commit secrets. This sample's `temperature_c` and `humidity_pct` are placeholders until connected sensors and calibration logic are added.

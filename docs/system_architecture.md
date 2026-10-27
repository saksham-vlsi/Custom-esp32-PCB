# System architecture

## Functional blocks

- **ESP32:** Wi-Fi connectivity, sensor polling, local diagnostics, MQTT publication.
- **Power input:** connector and protection sized for the selected input source.
- **3.3 V rail:** regulator and local decoupling for logic and sensors.
- **I2C header:** SDA, SCL, 3V3, GND for supported sensors.
- **SPI header:** SCLK, MOSI, MISO, CS, 3V3, GND.
- **UART header:** TX, RX, GND for debug or external sensor modules.
- **Programming/debug:** use the selected DevKit's USB-UART/debug path or provide compatible programming access.

## Data flow

`Sensors → ESP32 driver layer → validation/scaling → MQTT payload → broker → dashboard/consumer`

MQTT is transport, not sensor calibration. Each sensor requires a documented conversion, units, valid range, sampling interval, and error handling.

## Suggested MQTT topic

`lab/esp32-sensor-01/telemetry`

Example payload:

```json
{
  "device_id": "esp32-sensor-01",
  "uptime_ms": 123456,
  "temperature_c": 25.4,
  "humidity_pct": 51.2,
  "sensor_status": "ok"
}
```

This payload is illustrative. Publish only fields that are actually connected, sampled, and validated.

# Schematic design notes

## Sheet organization

Recommended KiCad hierarchy:
1. `Power`: input connector, protection, regulator, bulk capacitor, local decoupling.
2. `ESP32`: exact module/DevKit connector, enable/reset, boot strapping considerations.
3. `Sensor_Interfaces`: I2C, SPI, UART headers, optional level shifting.
4. `Debug_Test`: test points for GND, VIN, 3V3, EN, UART TX/RX.

## Power design

Do not assume every ESP32 board exposes the same pins or includes the same regulator. If the design uses a DevKit carrier, confirm whether its 3V3 pin is an output and whether it can support the total sensor and radio peak load. If the PCB uses a bare ESP32 module, follow the module reference design, antenna keep-out, flash/PSRAM requirements, and programming circuit.

## Pull-ups and logic levels

- I2C pull-ups should go to the bus logic rail and be sized for bus capacitance and speed.
- Avoid adding duplicate pull-ups on every attached sensor board without checking the effective parallel resistance.
- All signals must share a compatible logic level. Add level shifting when an attached device is not 3.3 V compatible.
- Never connect 5 V UART/I2C/SPI signals directly to ESP32 GPIO unless the specific interface is explicitly 5 V tolerant (ESP32 GPIO generally is not).

## Connector labels

Silkscreen should identify pin 1, voltage, GND, and signal names. Prefer keyed connectors where field wiring errors are possible.

# Board bring-up and validation plan

## Before power-on

- [ ] Visual inspection for shorts, solder bridges, wrong orientation, and missing parts.
- [ ] Verify input connector polarity and board revision.
- [ ] Measure resistance from supply to GND and investigate unexpected low resistance.
- [ ] Confirm regulator and module pinouts against datasheets.
- [ ] Use a current-limited supply for first power-up.

## Power checks

- [ ] Verify input voltage at the connector.
- [ ] Verify 3.3 V rail under idle and Wi-Fi transmit conditions.
- [ ] Observe supply droop and reset/brownout events.
- [ ] Check regulator and ESP32 temperature.

## Interface checks

- [ ] Confirm I2C pull-up voltage and scan expected device addresses.
- [ ] Validate SPI mode, clock frequency, chip select, and signal integrity.
- [ ] Validate UART baud rate, logic levels, and ground reference.
- [ ] Confirm no 5 V signal reaches a non-5-V-tolerant ESP32 GPIO.

## Firmware / connectivity

- [ ] Verify serial boot log.
- [ ] Confirm Wi-Fi connection and reconnect behavior.
- [ ] Confirm MQTT broker authentication and TLS policy as required.
- [ ] Validate payload schema and timestamps.
- [ ] Test broker loss, Wi-Fi loss, malformed sensor reads, and recovery.

## Evidence to add to the repo

Include dated photos, DRC/ ERC reports, power measurements, scope captures, firmware version, test conditions, and pass/fail results. Do not report unperformed tests as completed.

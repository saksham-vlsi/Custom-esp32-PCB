# Troubleshooting

| Symptom | Possible cause | What to check |
|---|---|---|
| ESP32 repeatedly resets | Supply droop, watchdog, brownout, firmware fault | Scope 3V3 rail; inspect serial log |
| I2C scan finds no device | Wrong pins/address, no pull-ups, power issue, bus stuck | Check voltage levels, continuity, address straps |
| SPI reads are corrupt | Wrong mode/clock, CS timing, long traces | Reduce clock and inspect SCLK/MISO/CS |
| MQTT fails | Wi-Fi, DNS, broker host/port, credentials, TLS time | Log each connection stage; never print secrets |
| Board overheats | Regulator dissipation, short, wrong part | Disconnect power and measure rail resistance |
| Poor Wi-Fi range | Antenna keep-out violation, enclosure, ground/copper placement | Compare against module antenna layout rules |
| Upload fails | Wrong boot mode, UART wiring, USB-UART issue | Check EN/BOOT sequence and selected board target |

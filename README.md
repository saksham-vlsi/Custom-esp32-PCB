# Custom ESP32 IoT Sensor PCB

**KiCad · 2-layer PCB · ESP32 module · sensor headers · power integrity · MQTT firmware example**

This repository is a detailed reference design package for a custom ESP32-based sensor interface board. It documents the architecture, pin planning, power budget, PCB layout rules, manufacturing outputs, firmware structure, and bring-up plan.

> **Honest status statement:** The repository is a design/reference package. Do not describe the board as manufactured, electrically validated, or field-tested unless you have actually completed those steps. A real production handoff requires the final KiCad schematic and PCB to be ERC/DRC-clean and the generated Gerber/BOM files to match the reviewed revision. The documents here are a foundation for creating and validating that design in KiCad.

## What the board is intended to do

- Host an ESP32 DevKit/module.
- Provide 3.3 V sensor interfaces for I2C and SPI devices.
- Provide UART access for debug or an external sensor.
- Provide a regulated and decoupled power path.
- Publish sensor readings over Wi-Fi using MQTT firmware.
- Expose programming, reset, ground, and test access.

## Repository layout

```text
custom-esp32-iot-sensor-pcb/
├── README.md
├── LICENSE
├── .gitignore
├── docs/
│   ├── system_architecture.md
│   ├── schematic_design.md
│   ├── pcb_layout_rules.md
│   ├── power_budget.md
│   ├── manufacturing_handoff.md
│   ├── bringup_test_plan.md
│   └── troubleshooting.md
├── design/
│   ├── pin_map.csv
│   ├── bom.csv
│   ├── netlist_intent.csv
│   └── design_review_checklist.md
├── firmware/
│   ├── README.md
│   ├── platformio.ini
│   └── src/main.cpp
├── manufacturing/
│   ├── README.md
│   └── fabrication_notes.md
└── images/
    └── system_block_diagram.svg
```

## Hardware design scope

The pin map is a proposed assignment and must be reconciled with the exact ESP32 board/module variant. Some ESP32 pins are boot-strapping pins, input-only pins, or reserved by flash/PSRAM; validate every pin before routing. If using a DevKit carrier, account for its USB-UART bridge, regulator, and header arrangement rather than treating it as a bare module.

## Build workflow

1. Confirm the exact ESP32 module/DevKit variant.
2. Create the KiCad schematic from `design/netlist_intent.csv` and the system diagram.
3. Run ERC and resolve all intentional exceptions with comments.
4. Create the 2-layer PCB; apply the constraints in `docs/pcb_layout_rules.md`.
5. Run DRC and inspect all clearances, solder mask, silkscreen, and board-edge checks.
6. Generate Gerbers, drill files, BOM, and assembly drawings only from the reviewed KiCad revision.
7. Build one prototype and follow `docs/bringup_test_plan.md`.
8. Add the actual `.kicad_sch`, `.kicad_pcb`, exports, photos, and measurement logs to this repo when they exist.

## Firmware

The firmware is a starting example using Arduino framework via PlatformIO. Configure Wi-Fi/MQTT credentials locally; never commit secrets. It demonstrates MQTT publishing structure and should be adapted to the actual sensor drivers and pin map.

## Suggested GitHub topics

`esp32`, `kicad`, `pcb-design`, `iot`, `mqtt`, `embedded-systems`, `hardware-design`, `sensor-interface`

## Important

This repository intentionally does not include fabricated Gerber files or claim completed manufacturing data. Manufacturing outputs must be generated from the final reviewed KiCad project, not copied from a template or inferred from the documentation.

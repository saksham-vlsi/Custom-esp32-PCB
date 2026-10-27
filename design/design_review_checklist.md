# Design review checklist

## Architecture
- [ ] Exact ESP32 module/DevKit variant selected.
- [ ] Sensor voltage and current requirements documented.
- [ ] Power budget includes Wi-Fi peak current.
- [ ] Every connector has a defined pinout and voltage level.

## Schematic
- [ ] Correct symbols and footprints.
- [ ] ERC warnings reviewed and documented.
- [ ] Regulator follows vendor recommended capacitors/layout.
- [ ] Programming/reset/boot path verified.
- [ ] Pull-ups, decoupling, and protection reviewed.

## PCB
- [ ] Antenna keep-out follows exact module datasheet.
- [ ] DRC clean or exceptions documented.
- [ ] Copper zones refilled and thermal relief checked.
- [ ] Board outline is closed on Edge.Cuts.
- [ ] Silkscreen is readable and does not overlap exposed pads.
- [ ] Connector orientation and pin 1 marked.
- [ ] Test points are accessible.

## Release
- [ ] Gerbers independently inspected.
- [ ] BOM and footprints cross-checked.
- [ ] Fabrication/assembly notes match final files.
- [ ] Revision and release tag assigned.

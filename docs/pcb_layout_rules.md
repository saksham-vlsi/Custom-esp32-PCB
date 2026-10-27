# Two-layer PCB layout rules

These are starting constraints. Final values must satisfy the board house capability and the selected footprint datasheets.

## Placement

- Place the ESP32 antenna at the board edge with the manufacturer's keep-out maintained on all layers and under the antenna.
- Keep the regulator, switching nodes, and noisy digital traces away from the antenna and sensitive analog inputs.
- Place regulator input/output capacitors close to their respective pins.
- Place each IC's 100 nF decoupling capacitor as close as possible to its supply pin with a short ground return.
- Place external connectors so cable insertion and pin-1 orientation are obvious.

## Routing

- Use a continuous ground plane where practical; avoid splitting return paths under high-speed signals.
- Keep high-current power paths short and wide enough for the expected current and temperature rise.
- Route I2C pull-ups near the bus or according to the chosen system topology.
- Keep SPI clock short and avoid unnecessary stubs.
- Use a clear, intentional path for return current; do not route signals across plane gaps.
- Add test points for input supply, 3V3, GND, and key communication signals.

## Design rules

- Set trace width, clearance, via size, and annular ring to the chosen fabricator's published capabilities.
- Define copper-to-edge clearance and board outline on `Edge.Cuts`.
- Check solder-mask slivers, silkscreen over pads, unconnected items, and thermal relief.
- Run KiCad DRC after every substantial routing change.
- Use a ground pour only after routing and then refill zones before final DRC.

## ESP32 antenna

Follow the exact module datasheet's antenna keep-out dimensions. Do not put copper, traces, components, battery, or metal enclosure material in the prohibited region. Antenna rules vary by module; a generic keep-out dimension is not a substitute for the datasheet.

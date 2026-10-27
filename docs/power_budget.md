# Power budget worksheet

The ESP32 radio can create short current peaks. Size the supply for peak demand, not only average sensor current.

| Load | Typical current | Peak/current note |
|---|---:|---|
| ESP32 module | Measure/consult exact module datasheet | Wi-Fi transmit peaks can be much higher than idle |
| I2C sensors | Datasheet-specific | Sum all connected sensors |
| SPI sensor | Datasheet-specific | Include startup current if applicable |
| LEDs / indicators | Design-specific | Include resistor and duty cycle |
| Regulator quiescent current | Datasheet-specific | Matters for battery operation |

## Calculation

For each rail, record:
- nominal voltage;
- minimum and maximum input;
- average load;
- peak load and duration;
- regulator current rating and thermal dissipation;
- input/output capacitor values and ESR requirements;
- battery or adapter constraints.

Regulator dissipation for a linear regulator is approximately:

\[
P_D=(V_{IN}-V_{OUT})I_{OUT}
\]

For battery operation, also calculate conversion efficiency, low-battery behavior, brownout margin, and expected runtime. Do not select a regulator until the actual ESP32 module and sensor set are fixed.

# Manufacturing handoff

## Required outputs from the final reviewed KiCad project

- Gerber files for F.Cu, B.Cu, solder masks, silkscreens, and board outline.
- Excellon drill files.
- BOM with manufacturer part number, footprint, quantity, and sourcing notes.
- Pick-and-place/centroid file if assembly is outsourced.
- Assembly drawing with reference designators and polarity marks.
- Schematic PDF and PCB layout PDF.
- Revision, date, and checksum or release tag.

## Release procedure

1. Freeze schematic and PCB revision.
2. Run ERC and DRC; save reports.
3. Inspect Gerbers in an independent Gerber viewer.
4. Verify board dimensions, layer order, drill alignment, solder-mask openings, and silkscreen.
5. Check BOM against actual footprints and assembly choices.
6. Create a tagged release, e.g. `v1.0.0`, only after review.
7. Archive source project and generated outputs together.

**Do not fabricate from placeholder data.** This repository's documentation and CSVs are design aids, not a substitute for a reviewed KiCad schematic/PCB or actual Gerber exports.

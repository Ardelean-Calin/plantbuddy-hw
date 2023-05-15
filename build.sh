#!/usr/bin/bash

# podman build -t kikit . # Run this once on a new machine.
podman run -it -w /kikit -v $(pwd):/kikit:Z kikit fab jlcpcb --no-drc --assembly --schematic PlantBuddy.kicad_sch PlantBuddy.kicad_pcb output/

#!/usr/bin/bash

podman run -it -w /kikit -v $(pwd):/kikit:Z yaqwsx/kikit:nightly fab jlcpcb --no-drc --assembly --schematic PlantBuddy.kicad_sch PlantBuddy.kicad_pcb output/

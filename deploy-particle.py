#!/usr/bin/env python3
"""
Script deploys the current light-swing index.ino to a Particle IoT device
"""
from pathlib import Path
import subprocess

root = Path(__file__).parent

source = (root / "test-swing/index.ino").read_text()

# Empty all lines before the main.h include, this allows error message line numbers to match up.
lines = source.split("\n")
start = lines.index('#include "main.h"')
lines = [""] * start + lines[start:]

controller = root / "particle-init"
(controller / "index.ino").write_text("\n".join(lines))

subprocess.run(
    "particle flash beacon-watch",
    cwd=controller,
    shell=True,
    check=True,
)

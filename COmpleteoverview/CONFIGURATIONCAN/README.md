# CAN Stack Manual Configuration Project

## Overview
This directory contains manual configuration of the complete AUTOSAR CAN communication stack.

## Configuration Approach
Starting from **CanIf (CAN Interface)** and building upward through the stack layers.

## Directory Structure

```
CONFIGURATIONCAN/
├── 01_CanDriver/        # CAN Driver (MCAL) configuration
├── 02_CanIf/            # CAN Interface configuration (STARTING POINT)
├── 03_CanTp/            # CAN Transport Protocol configuration
├── 04_PduR/             # PDU Router configuration
├── 05_Com/              # COM layer configuration
├── diagrams/            # PlantUML diagrams
└── startedhere/         # Initial notes and planning
```

## Configuration Order

1. **CanIf** (Current Focus)
   - Controller configuration
   - HOH (Hardware Object Handle) mapping
   - L-PDU configuration
   - Buffer management

2. **CanTp** (Next)
   - N-SDU configuration
   - Channel configuration
   - Timing parameters

3. **PduR**
   - Routing paths
   - Routing tables
   - Buffer configuration

4. **COM**
   - Signal definitions
   - I-PDU groups
   - Signal groups

## References
- AUTOSAR Standard: CP R21-11
- Existing diagrams: `../AUTOSARstackconf/`
- Hardware details: `../AUTOSARstackconf/deepdiveintoissue.plantuml`

## Status
- [x] Directory structure created
- [ ] CanIf configuration started
- [ ] CanTp configuration
- [ ] PduR configuration
- [ ] COM configuration

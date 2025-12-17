# CanIf Configuration Quick Reference

## What You Should Write

### 1. In Your Configuration Files

You now have:
- **`CanIf_Cfg.h`** - All symbolic names and compile-time settings
- **`CanIf_PBcfg.c`** - Runtime configuration data structures
- **`canif_config_notes.txt`** - Detailed explanation and guidance

### 2. Configuration Workflow

```
Step 1: Define Your System Requirements
----------------------------------------
□ How many CAN controllers? (e.g., CAN0, CAN1)
□ What messages do you need to send? (List with CAN IDs)
□ What messages do you need to receive? (List with CAN IDs)
□ What are the message sizes (DLC)?
□ Which upper layer handles each message? (COM, CanTp, PduR)

Step 2: Map to Hardware (From Can Driver Config)
-------------------------------------------------
□ Which HRHs are available? (e.g., HRH_0, HRH_1)
□ Which HTHs are available? (e.g., HTH_0, HTH_1)
□ What CAN ID ranges does each HRH filter?
□ What priorities do HTHs have?

Step 3: Create L-PDU Mappings
------------------------------
For each RX message:
  - Assign unique RxPduId
  - Map to CAN ID
  - Map to HRH
  - Specify DLC
  - Assign to upper layer (COM/CanTp)

For each TX message:
  - Assign unique TxPduId
  - Map to CAN ID
  - Map to HTH
  - Specify DLC
  - Assign to upper layer (COM/CanTp)

Step 4: Update Configuration Files
-----------------------------------
□ Edit CanIf_Cfg.h with your IDs and counts
□ Edit CanIf_PBcfg.c with actual configurations
□ Update symbolic names to match your system

Step 5: Validate Configuration
-------------------------------
□ All PduIds are unique
□ All CAN IDs match your CAN database (.dbc file)
□ HRH/HTH references match Can Driver config
□ DLCs match message definitions
□ Upper layer callbacks are correctly specified
```

### 3. Example Configuration Snippet

For a real message, you would write in `CanIf_PBcfg.c`:

```c
/* RX: Engine Speed from ECM */
{
    .CanIfRxPduId = CanIfConf_CanIfRxPduCfg_EngineSpeed,
    .CanIfRxPduCanId = 0x123,                    // From CAN database
    .CanIfRxPduCanIdType = CANIF_CAN_ID_TYPE_11, // 11-bit standard
    .CanIfRxPduDlc = 8,                          // 8 bytes
    .CanIfRxPduHrhIdRef = HRH_0,                 // From Can Driver
    .CanIfRxPduUserRxIndicationUL = CANIF_UL_COM,
    .CanIfRxPduUserRxIndicationName = "Com_RxIndication"
}
```

### 4. Integration with Repository

All files are now organized in:
```
CONFIGURATIONCAN/
├── README.md                    (Master guide)
├── 02_CanIf/
│   ├── CanIf_Cfg.h             (Your symbolic names)
│   ├── CanIf_PBcfg.c           (Your configurations)
│   └── canif_config_notes.txt  (Detailed help)
├── diagrams/
│   ├── canif_architecture.plantuml
│   └── pdu_flow.plantuml
└── startedhere/
    └── configuration.txt        (Your updated notes)
```

### 5. Next Steps

After CanIf, configure:
1. **CanTp** - For diagnostic messages (UDS)
2. **PduR** - For routing between modules
3. **COM** - For signal packing/unpacking

### 6. How to Use These Files

**In your repository:**
- These files serve as templates
- Customize based on your actual CAN network
- Reference them when creating actual ECU software

**For learning:**
- Study the structure
- Understand the relationships
- Use PlantUML diagrams for visualization

**For documentation:**
- Keep configuration.txt updated with your decisions
- Add notes about why you configured things certain ways
- Document any issues or lessons learned

### 7. Common Customization Points

In `CanIf_Cfg.h`, change:
```c
#define CANIF_CFG_MAX_RXPDU    10U  // Your number of RX messages
#define CANIF_CFG_MAX_TXPDU    10U  // Your number of TX messages
```

In `CanIf_PBcfg.c`, modify:
- Array `CanIf_RxPduConfig[]` - Add/remove your RX messages
- Array `CanIf_TxPduConfig[]` - Add/remove your TX messages
- CAN IDs to match your system
- DLCs to match your messages

### 8. Validation Checklist

Before moving to next layer:
- [ ] All RX PDUs have unique IDs
- [ ] All TX PDUs have unique IDs
- [ ] All CAN IDs match your CAN database
- [ ] All HRH/HTH references are valid
- [ ] All DLCs are correct
- [ ] Upper layer callbacks are specified
- [ ] Configuration compiles without errors
- [ ] PlantUML diagrams render correctly


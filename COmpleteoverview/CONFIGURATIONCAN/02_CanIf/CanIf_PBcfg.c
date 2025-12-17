/**
 * @file CanIf_PBcfg.c
 * @brief CAN Interface Post-Build Configuration
 * @details Runtime configuration data structures for CanIf module
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "CanIf.h"
#include "CanIf_Cfg.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/**
 * @brief RX L-PDU Configuration
 * @details Configuration for each received CAN message (L-PDU)
 */
static const CanIf_RxPduConfigType CanIf_RxPduConfig[] = 
{
    /* Index 0: EngineSpeed */
    {
        .CanIfRxPduId = CanIfConf_CanIfRxPduCfg_EngineSpeed,
        .CanIfRxPduCanId = CANIF_CANID_RX_ENGINE_SPEED,
        .CanIfRxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfRxPduDlc = 8U,
        .CanIfRxPduHrhIdRef = CanIfConf_CanIfHrhCfg_CAN0_HRH0,
        .CanIfRxPduReadData = TRUE,
        .CanIfRxPduReadNotifyStatus = FALSE,
        .CanIfRxPduUserRxIndicationUL = CANIF_UL_COM,
        .CanIfRxPduUserRxIndicationName = "Com_RxIndication"
    },
    
    /* Index 1: EngineTorque */
    {
        .CanIfRxPduId = CanIfConf_CanIfRxPduCfg_EngineTorque,
        .CanIfRxPduCanId = CANIF_CANID_RX_ENGINE_TORQUE,
        .CanIfRxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfRxPduDlc = 8U,
        .CanIfRxPduHrhIdRef = CanIfConf_CanIfHrhCfg_CAN0_HRH0,
        .CanIfRxPduReadData = TRUE,
        .CanIfRxPduReadNotifyStatus = FALSE,
        .CanIfRxPduUserRxIndicationUL = CANIF_UL_COM,
        .CanIfRxPduUserRxIndicationName = "Com_RxIndication"
    },
    
    /* Index 2: VehicleSpeed */
    {
        .CanIfRxPduId = CanIfConf_CanIfRxPduCfg_VehicleSpeed,
        .CanIfRxPduCanId = CANIF_CANID_RX_VEHICLE_SPEED,
        .CanIfRxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfRxPduDlc = 8U,
        .CanIfRxPduHrhIdRef = CanIfConf_CanIfHrhCfg_CAN0_HRH0,
        .CanIfRxPduReadData = TRUE,
        .CanIfRxPduReadNotifyStatus = FALSE,
        .CanIfRxPduUserRxIndicationUL = CANIF_UL_COM,
        .CanIfRxPduUserRxIndicationName = "Com_RxIndication"
    },
    
    /* Index 3: BrakeStatus */
    {
        .CanIfRxPduId = CanIfConf_CanIfRxPduCfg_BrakeStatus,
        .CanIfRxPduCanId = CANIF_CANID_RX_BRAKE_STATUS,
        .CanIfRxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfRxPduDlc = 8U,
        .CanIfRxPduHrhIdRef = CanIfConf_CanIfHrhCfg_CAN0_HRH1,
        .CanIfRxPduReadData = TRUE,
        .CanIfRxPduReadNotifyStatus = FALSE,
        .CanIfRxPduUserRxIndicationUL = CANIF_UL_COM,
        .CanIfRxPduUserRxIndicationName = "Com_RxIndication"
    },
    
    /* Index 4: SteeringAngle */
    {
        .CanIfRxPduId = CanIfConf_CanIfRxPduCfg_SteeringAngle,
        .CanIfRxPduCanId = CANIF_CANID_RX_STEERING_ANGLE,
        .CanIfRxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfRxPduDlc = 8U,
        .CanIfRxPduHrhIdRef = CanIfConf_CanIfHrhCfg_CAN0_HRH1,
        .CanIfRxPduReadData = TRUE,
        .CanIfRxPduReadNotifyStatus = FALSE,
        .CanIfRxPduUserRxIndicationUL = CANIF_UL_COM,
        .CanIfRxPduUserRxIndicationName = "Com_RxIndication"
    },
    
    /* Index 5: DiagRequest (CanTp) */
    {
        .CanIfRxPduId = CanIfConf_CanIfRxPduCfg_DiagRequest,
        .CanIfRxPduCanId = CANIF_CANID_RX_DIAG_REQUEST,
        .CanIfRxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfRxPduDlc = 8U,
        .CanIfRxPduHrhIdRef = CanIfConf_CanIfHrhCfg_CAN0_HRH1,
        .CanIfRxPduReadData = FALSE,
        .CanIfRxPduReadNotifyStatus = FALSE,
        .CanIfRxPduUserRxIndicationUL = CANIF_UL_CANTP,
        .CanIfRxPduUserRxIndicationName = "CanTp_RxIndication"
    }
};

/**
 * @brief TX L-PDU Configuration
 * @details Configuration for each transmitted CAN message (L-PDU)
 */
static const CanIf_TxPduConfigType CanIf_TxPduConfig[] = 
{
    /* Index 0: GearPosition */
    {
        .CanIfTxPduId = CanIfConf_CanIfTxPduCfg_GearPosition,
        .CanIfTxPduCanId = CANIF_CANID_TX_GEAR_POSITION,
        .CanIfTxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfTxPduDlc = 8U,
        .CanIfTxPduHthIdRef = CanIfConf_CanIfHthCfg_CAN0_HTH0,
        .CanIfTxPduPnFilterPdu = FALSE,
        .CanIfTxPduReadNotifyStatus = FALSE,
        .CanIfTxPduTriggerTransmit = FALSE,
        .CanIfTxPduUserTxConfirmationUL = CANIF_UL_COM,
        .CanIfTxPduUserTxConfirmationName = "Com_TxConfirmation"
    },
    
    /* Index 1: ThrottlePosition */
    {
        .CanIfTxPduId = CanIfConf_CanIfTxPduCfg_ThrottlePosition,
        .CanIfTxPduCanId = CANIF_CANID_TX_THROTTLE_POSITION,
        .CanIfTxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfTxPduDlc = 8U,
        .CanIfTxPduHthIdRef = CanIfConf_CanIfHthCfg_CAN0_HTH0,
        .CanIfTxPduPnFilterPdu = FALSE,
        .CanIfTxPduReadNotifyStatus = FALSE,
        .CanIfTxPduTriggerTransmit = FALSE,
        .CanIfTxPduUserTxConfirmationUL = CANIF_UL_COM,
        .CanIfTxPduUserTxConfirmationName = "Com_TxConfirmation"
    },
    
    /* Index 2: BatteryVoltage */
    {
        .CanIfTxPduId = CanIfConf_CanIfTxPduCfg_BatteryVoltage,
        .CanIfTxPduCanId = CANIF_CANID_TX_BATTERY_VOLTAGE,
        .CanIfTxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfTxPduDlc = 8U,
        .CanIfTxPduHthIdRef = CanIfConf_CanIfHthCfg_CAN0_HTH1,
        .CanIfTxPduPnFilterPdu = FALSE,
        .CanIfTxPduReadNotifyStatus = FALSE,
        .CanIfTxPduTriggerTransmit = FALSE,
        .CanIfTxPduUserTxConfirmationUL = CANIF_UL_COM,
        .CanIfTxPduUserTxConfirmationName = "Com_TxConfirmation"
    },
    
    /* Index 3: AmbientTemp */
    {
        .CanIfTxPduId = CanIfConf_CanIfTxPduCfg_AmbientTemp,
        .CanIfTxPduCanId = CANIF_CANID_TX_AMBIENT_TEMP,
        .CanIfTxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfTxPduDlc = 8U,
        .CanIfTxPduHthIdRef = CanIfConf_CanIfHthCfg_CAN0_HTH1,
        .CanIfTxPduPnFilterPdu = FALSE,
        .CanIfTxPduReadNotifyStatus = FALSE,
        .CanIfTxPduTriggerTransmit = FALSE,
        .CanIfTxPduUserTxConfirmationUL = CANIF_UL_COM,
        .CanIfTxPduUserTxConfirmationName = "Com_TxConfirmation"
    },
    
    /* Index 4: DiagResponse (CanTp) */
    {
        .CanIfTxPduId = CanIfConf_CanIfTxPduCfg_DiagResponse,
        .CanIfTxPduCanId = CANIF_CANID_TX_DIAG_RESPONSE,
        .CanIfTxPduCanIdType = CANIF_CAN_ID_TYPE_11,
        .CanIfTxPduDlc = 8U,
        .CanIfTxPduHthIdRef = CanIfConf_CanIfHthCfg_CAN0_HTH0,
        .CanIfTxPduPnFilterPdu = FALSE,
        .CanIfTxPduReadNotifyStatus = FALSE,
        .CanIfTxPduTriggerTransmit = FALSE,
        .CanIfTxPduUserTxConfirmationUL = CANIF_UL_CANTP,
        .CanIfTxPduUserTxConfirmationName = "CanTp_TxConfirmation"
    }
};

/**
 * @brief HRH (Hardware Receive Handle) Configuration
 */
static const CanIf_HrhConfigType CanIf_HrhConfig[] = 
{
    /* HRH 0: CAN0 FIFO 0 */
    {
        .CanIfHrhIdSymRef = CanIfConf_CanIfHrhCfg_CAN0_HRH0,
        .CanIfHrhCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN0,
        .CanIfHrhSoftwareFilter = FALSE
    },
    
    /* HRH 1: CAN0 FIFO 1 */
    {
        .CanIfHrhIdSymRef = CanIfConf_CanIfHrhCfg_CAN0_HRH1,
        .CanIfHrhCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN0,
        .CanIfHrhSoftwareFilter = FALSE
    },
    
    /* HRH 2: CAN1 FIFO 0 */
    {
        .CanIfHrhIdSymRef = CanIfConf_CanIfHrhCfg_CAN1_HRH0,
        .CanIfHrhCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN1,
        .CanIfHrhSoftwareFilter = FALSE
    },
    
    /* HRH 3: CAN1 FIFO 1 */
    {
        .CanIfHrhIdSymRef = CanIfConf_CanIfHrhCfg_CAN1_HRH1,
        .CanIfHrhCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN1,
        .CanIfHrhSoftwareFilter = FALSE
    }
};

/**
 * @brief HTH (Hardware Transmit Handle) Configuration
 */
static const CanIf_HthConfigType CanIf_HthConfig[] = 
{
    /* HTH 0: CAN0 TX Mailbox 0 (High Priority) */
    {
        .CanIfHthIdSymRef = CanIfConf_CanIfHthCfg_CAN0_HTH0,
        .CanIfHthCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN0
    },
    
    /* HTH 1: CAN0 TX Mailbox 1 (Normal Priority) */
    {
        .CanIfHthIdSymRef = CanIfConf_CanIfHthCfg_CAN0_HTH1,
        .CanIfHthCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN0
    },
    
    /* HTH 2: CAN1 TX Mailbox 0 (High Priority) */
    {
        .CanIfHthIdSymRef = CanIfConf_CanIfHthCfg_CAN1_HTH0,
        .CanIfHthCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN1
    },
    
    /* HTH 3: CAN1 TX Mailbox 1 (Normal Priority) */
    {
        .CanIfHthIdSymRef = CanIfConf_CanIfHthCfg_CAN1_HTH1,
        .CanIfHthCanCtrlIdRef = CanIfConf_CanIfCtrlCfg_CAN1
    }
};

/**
 * @brief Controller Configuration
 */
static const CanIf_CtrlConfigType CanIf_CtrlConfig[] = 
{
    /* Controller 0: CAN0 */
    {
        .CanIfCtrlId = CanIfConf_CanIfCtrlCfg_CAN0,
        .CanIfCtrlCanCtrlRef = 0U,  /* Reference to Can Driver Controller 0 */
        .CanIfCtrlWakeupSupport = FALSE
    },
    
    /* Controller 1: CAN1 */
    {
        .CanIfCtrlId = CanIfConf_CanIfCtrlCfg_CAN1,
        .CanIfCtrlCanCtrlRef = 1U,  /* Reference to Can Driver Controller 1 */
        .CanIfCtrlWakeupSupport = FALSE
    }
};

/**
 * @brief Main CanIf Configuration Structure
 */
const CanIf_ConfigType CanIf_Config = 
{
    .CanIfCtrlConfig = CanIf_CtrlConfig,
    .CanIfHrhConfig = CanIf_HrhConfig,
    .CanIfHthConfig = CanIf_HthConfig,
    .CanIfRxPduConfig = CanIf_RxPduConfig,
    .CanIfTxPduConfig = CanIf_TxPduConfig,
    
    .CanIfMaxRxPduCfg = CANIF_CFG_MAX_RXPDU,
    .CanIfMaxTxPduCfg = CANIF_CFG_MAX_TXPDU,
    .CanIfMaxHrhCfg = CANIF_CFG_MAX_HRH,
    .CanIfMaxHthCfg = CANIF_CFG_MAX_HTH,
    .CanIfMaxCtrlCfg = CANIF_CFG_MAX_CONTROLLER
};

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

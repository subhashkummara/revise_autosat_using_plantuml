/**
 * @file CanIf_Cfg.h
 * @brief CAN Interface Configuration Header
 * @details Compile-time configuration parameters for CanIf module
 */

#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Development Error Detection */
#define CANIF_DEV_ERROR_DETECT              STD_ON

/* Version Info API */
#define CANIF_VERSION_INFO_API              STD_ON

/* Public APIs */
#define CANIF_PUBLIC_ICOM_SUPPORT           STD_OFF
#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT   STD_OFF
#define CANIF_PUBLIC_READRXPDU_DATA_API     STD_ON
#define CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API    STD_OFF
#define CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API    STD_OFF
#define CANIF_PUBLIC_SETDYNAMICTXID_API     STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION    STD_OFF
#define CANIF_PUBLIC_TX_BUFFERING           STD_ON
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT STD_OFF

/* Number of configured elements */
#define CANIF_CFG_MAX_CONTROLLER            2U      /* Number of CAN controllers */
#define CANIF_CFG_MAX_HRH                   4U      /* Number of Hardware Receive Handles */
#define CANIF_CFG_MAX_HTH                   4U      /* Number of Hardware Transmit Handles */
#define CANIF_CFG_MAX_RXPDU                 10U     /* Number of RX L-PDUs */
#define CANIF_CFG_MAX_TXPDU                 10U     /* Number of TX L-PDUs */

/* TX Buffer Configuration */
#define CANIF_CFG_TX_BUFFER_SIZE            8U      /* Number of buffered TX PDUs */

/* DLC Check */
#define CANIF_PRIVATE_DLC_CHECK             STD_ON

/* Software Filtering */
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE  CANIF_PRIVATE_SOFTWARE_FILTER_LINEAR

/*==================================================================================================
*                                CONTROLLER CONFIGURATION IDs
==================================================================================================*/
#define CanIfConf_CanIfCtrlCfg_CAN0         0U
#define CanIfConf_CanIfCtrlCfg_CAN1         1U

/*==================================================================================================
*                                HRH (Hardware Receive Handle) IDs
==================================================================================================*/
/* CAN0 Receive Handles */
#define CanIfConf_CanIfHrhCfg_CAN0_HRH0     0U      /* FIFO 0: Standard messages 0x100-0x1FF */
#define CanIfConf_CanIfHrhCfg_CAN0_HRH1     1U      /* FIFO 1: Standard messages 0x200-0x2FF */

/* CAN1 Receive Handles */
#define CanIfConf_CanIfHrhCfg_CAN1_HRH0     2U      /* FIFO 0: Standard messages 0x300-0x3FF */
#define CanIfConf_CanIfHrhCfg_CAN1_HRH1     3U      /* FIFO 1: Standard messages 0x400-0x4FF */

/*==================================================================================================
*                                HTH (Hardware Transmit Handle) IDs
==================================================================================================*/
/* CAN0 Transmit Handles */
#define CanIfConf_CanIfHthCfg_CAN0_HTH0     0U      /* TX Mailbox 0: High priority */
#define CanIfConf_CanIfHthCfg_CAN0_HTH1     1U      /* TX Mailbox 1: Normal priority */

/* CAN1 Transmit Handles */
#define CanIfConf_CanIfHthCfg_CAN1_HTH0     2U      /* TX Mailbox 0: High priority */
#define CanIfConf_CanIfHthCfg_CAN1_HTH1     3U      /* TX Mailbox 1: Normal priority */

/*==================================================================================================
*                                RX L-PDU IDs (Examples - Customize as needed)
==================================================================================================*/
#define CanIfConf_CanIfRxPduCfg_EngineSpeed             0U
#define CanIfConf_CanIfRxPduCfg_EngineTorque            1U
#define CanIfConf_CanIfRxPduCfg_VehicleSpeed            2U
#define CanIfConf_CanIfRxPduCfg_BrakeStatus             3U
#define CanIfConf_CanIfRxPduCfg_SteeringAngle           4U
#define CanIfConf_CanIfRxPduCfg_DiagRequest             5U

/*==================================================================================================
*                                TX L-PDU IDs (Examples - Customize as needed)
==================================================================================================*/
#define CanIfConf_CanIfTxPduCfg_GearPosition            0U
#define CanIfConf_CanIfTxPduCfg_ThrottlePosition        1U
#define CanIfConf_CanIfTxPduCfg_BatteryVoltage          2U
#define CanIfConf_CanIfTxPduCfg_AmbientTemp             3U
#define CanIfConf_CanIfTxPduCfg_DiagResponse            4U

/*==================================================================================================
*                                CAN IDs (Message Identifiers)
==================================================================================================*/
/* RX Message CAN IDs */
#define CANIF_CANID_RX_ENGINE_SPEED         0x123U
#define CANIF_CANID_RX_ENGINE_TORQUE        0x124U
#define CANIF_CANID_RX_VEHICLE_SPEED        0x125U
#define CANIF_CANID_RX_BRAKE_STATUS         0x200U
#define CANIF_CANID_RX_STEERING_ANGLE       0x201U
#define CANIF_CANID_RX_DIAG_REQUEST         0x7DFU

/* TX Message CAN IDs */
#define CANIF_CANID_TX_GEAR_POSITION        0x456U
#define CANIF_CANID_TX_THROTTLE_POSITION    0x457U
#define CANIF_CANID_TX_BATTERY_VOLTAGE      0x458U
#define CANIF_CANID_TX_AMBIENT_TEMP         0x459U
#define CANIF_CANID_TX_DIAG_RESPONSE        0x7E8U

/*==================================================================================================
*                                UPPER LAYER MODULE IDs
==================================================================================================*/
#define CANIF_UL_COM                        0U
#define CANIF_UL_CANTP                      1U
#define CANIF_UL_PDUR                       2U

#endif /* CANIF_CFG_H */

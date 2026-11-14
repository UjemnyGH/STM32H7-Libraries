#ifndef _H7_SDMMC_
#define _H7_SDMMC_

#include "base.h"

typedef struct sdmmc_s {
  uio32_t powerCtrl;
  uio32_t clockCtrl;
  uio32_t argument;
  uio32_t command;
  uio32_t commandResponse;
  uio32_t response1;
  uio32_t response2;
  uio32_t response3;
  uio32_t response4;
  uio32_t dataTimer;
  uio32_t dataLen;
  uio32_t dataCtrl;
  uio32_t dataCounter;
  uio32_t status;
  uio32_t intClear;
  uio32_t mask;
  uio32_t ackTimer;
  uint32_t RESERVED1[3];
  uio32_t dmaCtrl;
  uio32_t dmaBufferSize;
  uio32_t idmaBuffer0BaseAddr;
  uio32_t idmaBuffer1BaseAddr;
} sdmmc_t;

#define sdmmc1 ((sdmmc_t*)H7_BASE_MMC1)
#define sdmmc2 ((sdmmc_t*)H7_BASE_MMC2)

#define sdmmc1_fifo ((uio32_t*)(H7_BASE_MMC1 + 0x80))
#define sdmmc2_fifo ((uio32_t*)(H7_BASE_MMC2 + 0x80))

typedef enum sdmmc_power_e {
  sdmmc_power_powerOff = 0,
  sdmmc_power_powerCycle = BIT(1),
  sdmmc_power_powerOn = BIT(0) | BIT(1),
  sdmmc_power_powerMask = sdmmc_power_powerOn,

  sdmmc_power_voltageSwitchSequenceStart = BIT(2),
  sdmmc_power_voltageSwitchProcedureEnable = BIT(3),
  sdmmc_power_dataAndCmdDirSignalsHigh = BIT(4),

  sdmmc_power_reset = 0x0
} sdmmc_power_t;

typedef enum sdmmc_clockCtrl_e {
  sdmmc_clockCtrl_clockDivideFactorMask = MASK32(0, 9),
  sdmmc_clockCtrl_clockDivideFactorShift = 0,

  sdmmc_clockCtrl_powerSavingConfig = BIT(12),
  
  sdmmc_clockCtrl_wideBusMode1Bit = 0,
  sdmmc_clockCtrl_wideBusMode4Bit = BIT(14),
  sdmmc_clockCtrl_wideBusMode8Bit = BIT(15),
  sdmmc_clockCtrl_wideBusModeMask = BIT(14) | BIT(15),

  sdmmc_clockCtrl_clkDephasingSelectionBitForDataAndCmd = BIT(16),
  sdmmc_clockCtrl_hardwareFlowControlEnable = BIT(17),
  sdmmc_clockCtrl_dataRateSignalingSelectDouble = BIT(18),
  sdmmc_clockCtrl_busSpeed = BIT(19),

  sdmmc_clockCtrl_rxClockSdmmcIoInCk = 0,
  sdmmc_clockCtrl_rxClockSdmmcCkIn = BIT(20),
  sdmmc_clockCtrl_rxClockSdmmcFbCk = BIT(21),
  sdmmc_clockCtrl_rxClockMask = BIT(20) | BIT(21),

  sdmmc_clockCtrl_reset = 0x0
} sdmmc_clockCtrl_t;

typedef enum sdmmc_dataCtrl_e {
  sdmmc_dataCtrl_dataTransferEnable = BIT(0),
  sdmmc_dataCtrl_dataTransferDirCardAsMaster = BIT(1),
  
  sdmmc_dataCtrl_dataTransferModeBlockData = 0,
  sdmmc_dataCtrl_dataTransferModeSDIOMultibyte = BIT(2),
  sdmmc_dataCtrl_dataTransferModeEMMCStream = BIT(3),
  sdmmc_dataCtrl_dataTransferModeBlockDataCmdTerminated = BIT(2) | BIT(3),
  sdmmc_dataCtrl_dataTransferModeMask = sdmmc_dataCtrl_dataTransferModeBlockDataCmdTerminated,
  
  sdmmc_dataCtrl_dataBlock1Byte = 0,
  sdmmc_dataCtrl_dataBlock2Byte = BIT(4),
  sdmmc_dataCtrl_dataBlock4Byte = BIT(5),
  sdmmc_dataCtrl_dataBlock8Byte = BIT(4) | BIT(5),
  sdmmc_dataCtrl_dataBlock16Byte = BIT(6),
  sdmmc_dataCtrl_dataBlock32Byte = BIT(4) | BIT(6),
  sdmmc_dataCtrl_dataBlock64Byte = BIT(5) | BIT(6),
  sdmmc_dataCtrl_dataBlock128Byte = BIT(4) | BIT(5) | BIT(6),
  sdmmc_dataCtrl_dataBlock256Byte = BIT(7),
  sdmmc_dataCtrl_dataBlock512Byte = BIT(4) | BIT(7),
  sdmmc_dataCtrl_dataBlock1024Byte = BIT(5) | BIT(7),
  sdmmc_dataCtrl_dataBlock2048Byte = BIT(4) | BIT(5) | BIT(7),
  sdmmc_dataCtrl_dataBlock4092Byte = BIT(6) | BIT(7),
  sdmmc_dataCtrl_dataBlock8192Byte = BIT(4) | BIT(6) | BIT(7),
  sdmmc_dataCtrl_dataBlock16384Byte = BIT(5) | BIT(6) | BIT(7),
  sdmmc_dataCtrl_dataBlockMask = BIT(4) | BIT(5) | BIT(6) | BIT(7),

  sdmmc_dataCtrl_readWaitStart = BIT(8),
  sdmmc_dataCtrl_readWaitStop = BIT(9),
  sdmmc_dataCtrl_readWaitModeUsingCK = BIT(10),
  sdmmc_dataCtrl_SDIOIntEnable = BIT(11),
  sdmmc_dataCtrl_bootAckEnable = BIT(12),
  sdmmc_dataCtrl_fifoResetAndFlush = BIT(13),

  sdmmc_dataCtrl_reset = 0x0
} sdmmc_dataCtrl_t;

typedef enum sdmmc_status_e {
  sdmmc_status_cmdCrcFail = BIT(0),
  sdmmc_status_dataCrcFail = BIT(1),
  sdmmc_status_cmdResponseTimeout = BIT(2),
  sdmmc_status_dataTimeout = BIT(3),
  sdmmc_status_txFifoUnderrunError = BIT(4),
  sdmmc_status_rxFifoOverrunError = BIT(5),
  sdmmc_status_cmdResponseReceived = BIT(6),
  sdmmc_status_cmdSent = BIT(7),
  sdmmc_status_dataTransferEndedCorrectly = BIT(8),
  sdmmc_status_dataTransferHold = BIT(9),
  sdmmc_status_dataBlockSendOrReceived = BIT(10),
  sdmmc_status_dataTransferAbortedByCMD12 = BIT(11),
  // Cannot be cleared in intClear, cannot be masked in mask
  sdmmc_status_dataPathStateMachineActive = BIT(12),
  // Cannot be cleared in intClear, cannot be masked in mask
  sdmmc_status_cmdPathStateMachineActive = BIT(13),
  // Cannot be cleared in intClear
  sdmmc_status_txFifoHalfEmpty = BIT(14),
  // Cannot be cleared in intClear
  sdmmc_status_rxFifoHalfFull = BIT(15),
  // Cannot be cleared in intClear, cannot be masked in mask
  sdmmc_status_txFifoFull = BIT(16),
  // Cannot be cleared in intClear
  sdmmc_status_rxFifoFull = BIT(17),
  // Cannot be cleared in intClear
  sdmmc_status_txFifoEmpty = BIT(18),
  // Cannot be cleared in intClear, cannot be masked in mask
  sdmmc_status_rxFifoEmpty = BIT(19),
  // Cannot be cleared in intClear, cannot be masked in mask
  sdmmc_status_cardBusyOnD0 = BIT(20),
  sdmmc_status_cardNotBusyOnD0 = BIT(21),
  sdmmc_status_sdioIntReceived = BIT(22),
  sdmmc_status_bootAckCheckFail = BIT(23),
  sdmmc_status_bootAckTimeout = BIT(24),
  sdmmc_status_voltageSwitchCriticalTimingSectionCompletion = BIT(25),
  sdmmc_status_ckStoppedInVoltageSwitchProcedure = BIT(26),
  // Cannot be masked in mask
  sdmmc_status_idmaTransferError = BIT(27),
  sdmmc_status_idmaBufferTransferComplete = BIT(28),

  sdmmc_status_reset = 0x0
} sdmmc_status_t;

typedef enum sdmmc_dmaCtrl_e {
  sdmmc_dmaCtrl_enableDma = BIT(0),
  sdmmc_dmaCtrl_doubleBufferMode = BIT(1),
  sdmmc_dmaCtrl_useBuffer1 = BIT(2),

  sdmmc_dmaCtrl_reset = 0x0
} sdmmc_dmaCtrl_t;

#define sdmmc_dmaBufferSize(bufferSize) ((bufferSize) << 5)

#endif

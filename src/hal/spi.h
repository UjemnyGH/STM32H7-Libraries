#ifndef _H7_SPI_
#define _H7_SPI_

#include "base.h"

typedef struct spi_s {
  uio32_t control1;
  uio32_t control2;
  uio32_t config1;
  uio32_t config2;
  uio32_t intEnable;
  uio32_t status;
  uio32_t intClear;
  uio32_t txData;
  uint32_t RESERVED1[3];
  uio32_t rxData;
  uint32_t RESERVED2[3];
  uio32_t crcPoly;
  uio32_t txCrc;
  uio32_t rxCrc;
  uio32_t underrunData;
  uio32_t i2sConfig;
} spi_t;

#define spi1 ((spi_t*)H7_BASE_SPI1)
#define spi2 ((spi_t*)H7_BASE_SPI2)
#define spi3 ((spi_t*)H7_BASE_SPI3)
#define spi4 ((spi_t*)H7_BASE_SPI4)
#define spi5 ((spi_t*)H7_BASE_SPI5)
#define spi6 ((spi_t*)H7_BASE_SPI6)

typedef enum spi_control1_e {
  spi_control1_enableSpi = BIT(0),
  spi_control1_masterAutoSuspend = BIT(8),
  spi_control1_masterTxStart = BIT(9),
  spi_control1_masterSuspend = BIT(10),
  spi_control1_txInHalfDuplex = BIT(11),
  spi_control1_internalCS = BIT(12),
  spi_control1_crcFullSize = BIT(13),
  spi_control1_rxCrcAllOnes = BIT(14),
  spi_control1_txCrcAllOnes = BIT(15),
  // Quite cool feature of H7
  spi_control1_pinsAltFuncConfigLock = BIT(16),

  spi_control1_reset = 0x0
} spi_control1_t;

typedef enum spi_config1_e {
  spi_config1_bitsSizeMask = MASK32(0, 4),
  spi_config1_bitsSizeShift = 0,
  
  spi_config1_fifoThresholdLevelMask = MASK32(5, 8),
  spi_config1_fifoThresholdLevelShift = 5,

  spi_config1_slaveSendsConstPattern = 0,
  spi_config1_slaveRepeatsRxFrame = BIT(9),
  spi_config1_slaveRepeatsFrame = BIT(10),
  spi_config1_slaveUnderrunCondMask = BIT(9) | BIT(10),

  spi_config1_detectUnderrunAtStart = 0,
  spi_config1_detectUnderrunAtEnd = BIT(11),
  spi_config1_detectUnderrunAtNSS = BIT(12),
  spi_config1_detectUnderrunMask = BIT(11) | BIT(12),

  spi_config1_rxDma = BIT(14),
  spi_config1_txDma = BIT(15),

  spi_config1_crcSizeMask = MASK32(16, 20),
  spi_config1_crcSizeShift = 16,

  spi_config1_crcCalcEnable = BIT(22),

  spi_config1_clockDiv2 = 0,
  spi_config1_clockDiv4 = BIT(28),
  spi_config1_clockDiv8 = BIT(29),
  spi_config1_clockDiv16 = BIT(28) | BIT(29),
  spi_config1_clockDiv32 = BIT(30),
  spi_config1_clockDiv64 = BIT(28)| BIT(30),
  spi_config1_clockDiv128 = BIT(29) | BIT(30),
  spi_config1_clockDiv256 = BIT(28) | BIT(29) | BIT(30),
  spi_config1_clockDivMask = spi_config1_clockDiv256,

  spi_config1_reset = 0x0
} spi_config1_t;

typedef enum spi_config2_e {
  spi_config2_masterNSSDelayMask = MASK32(0, 3),
  spi_config2_masterNSSDelayShift = 0,

  spi_config2_masterInterDataDelayMask = MASK32(4, 7),
  spi_config2_masterInterDataDelayShift = 4,

  spi_config2_swapMISOAndMOSI = BIT(15),
  spi_config2_spiCommFulDuplex = 0,
  spi_config_spiCommSimplexTx = BIT(17),
  spi_config_spiCommSimplexRx = BIT(18),
  spi_config2_spiCommHalfDuplex = BIT(17) | BIT(18),
  spi_config2_spiCommMask = spi_config2_spiCommHalfDuplex,

  spi_config2_serialProtocolTI = BIT(19),
  spi_config2_masterMode = BIT(22),
  spi_config2_lsbFirst = BIT(23),
  spi_config2_clockPhase = BIT(24),
  spi_config2_sckHighOnIdle = BIT(25),
  spi_config2_SSIControlNSS = BIT(26),
  spi_config2_nssActiveOnHigh = BIT(28),
  spi_config2_nssEnable = BIT(29),
  spi_config2_nssMasterManagement = BIT(30),
  spi_config2_controlAltFuncsOfGPIO = BIT(31),

  spi_config2_reset = 0x0
} spi_config2_t;

typedef enum spi_status_e {
  // Applies to intEnable and status registers
  spi_status_rxPacketAvailable = BIT(0),
  spi_status_txPAcketSpaceAvailable = BIT(1),
  spi_status_duplexPacket = BIT(2),
  // Applies to all intEnable, status and intClear registers
  spi_status_endOfTransfer = BIT(3),
  spi_status_txTransferFinished = BIT(4),
  spi_status_underrun = BIT(5),
  spi_status_overrun = BIT(6),
  spi_status_crcError = BIT(7),
  spi_status_TIFormatFrameError = BIT(8),
  spi_status_modeFault = BIT(9),
  spi_status_additionalDataReload = BIT(10),
  // Applies to status and intClear registers
  spi_status_suspended = BIT(11),
  // Applies to status register
  spi_status_txFifoTransferComplete = BIT(12),

  spi_status_rxFifoPackingAvailableNoFrames = 0,
  spi_status_rxFifoPackingAvailable1Frame = BIT(13),
  spi_status_rxFifoPackingAvailable2Frame = BIT(14),
  spi_status_rxFifoPackingAvailable3Frame = BIT(13) | BIT(14),
  spi_status_rxFifoPackingAvailableMask = spi_status_rxFifoPackingAvailable3Frame,

  spi_status_rxFifoWordNotEmpty = BIT(15),

  spi_status_dataFramesRemainingMask = MASK32(16, 31),
  spi_status_dataFramesRemainingShift = 16,

  spi_status_intReset = 0x0,
  spi_status_reset = 0x1002
} spi_status_t;

#endif

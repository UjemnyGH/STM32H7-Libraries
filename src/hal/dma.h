#ifndef _H7_DMA_
#define _H7_DMA_

#include "base.h"

typedef struct dma_s {
  uio32_t lowIntStat;
  uio32_t highIntStat;
  uio32_t lowIntFlagClear;
  uio32_t highIntFlagClear;
  struct {
    uio32_t config;
    uio32_t dataNumber;
    uio32_t periphAddr;
    uio32_t mem0Addr;
    uio32_t mem1Addr;
    uio32_t fifoCtrl;
  } stream[8];
} dma_t;

#define dma1 ((dma_t*)H7_BASE_DMA1)
#define dma2 ((dma_t*)H7_BASE_DMA2)

/*
 * Applies to: lowIntStat, highIntStat, lowIntFlagClear, highIntFlagClear
 * */
typedef enum dma_intFlagBits_e {
  dma_intFlagBits_FIFOError =         BIT(0),
  dma_intFlagBits_directModeError =   BIT(2),
  dma_intFlagBits_transferError =     BIT(3),
  dma_intFlagBits_halfTransfer =      BIT(4),
  dma_intFlagBits_transferComplete =  BIT(5),

  dma_intFlagBits_mask =              0x3D,
  dma_intFlagBits_stream0_4Shift =    0,
  dma_intFlagBits_stream1_5Shift =    6,
  dma_intFlagBits_stream2_6Shift =    16,
  dma_intFlagBits_stream3_7Shift =    22,

  dma_intFlagBits_reset =             0x0
} dma_intFlagBits_t;

typedef enum dma_stream_config_e {
  dma_stream_config_enable =                          BIT(0),
  dma_stream_config_directModeIntEnable =             BIT(1),
  dma_stream_config_transferModeIntEnable =           BIT(2),
  dma_stream_config_halfTransferModeIntEnable =       BIT(3),
  dma_stream_config_transferCompleteModeIntEnable =   BIT(4),
  dma_stream_config_peripheralFlowController =        BIT(5),

  dma_stream_config_dataTransferPeriphToMemory =      0,
  dma_stream_config_dataTransferMemoryToPeriph =      BIT(6),
  dma_stream_config_dataTransferMemoryToMemory =      BIT(7),
  dma_stream_config_dataTransferMask =                BIT(6) | BIT(7),

  dma_stream_config_circularMode =                    BIT(8),
  dma_stream_config_periphIncrement =                 BIT(9),
  dma_stream_config_memoryIncrement =                 BIT(10),

  dma_stream_config_periphDataSize8Bit =              0,
  dma_stream_config_periphDataSize16Bit =             BIT(11),
  dma_stream_config_periphDataSize32Bit =             BIT(12),
  dma_stream_config_periphDataSizeMask =              BIT(11) | BIT(12),

  dma_stream_config_memoryDataSize8Bit =              0,
  dma_stream_config_memoryDataSize16Bit =             BIT(13),
  dma_stream_config_memoryDataSize32Bit =             BIT(14),
  dma_stream_config_memoryDataSizeMask =              BIT(13) | BIT(14),

  dma_stream_config_periphIncrementOffsetFixed32Bit = BIT(15),

  dma_stream_config_priorityLevelLow =                0,
  dma_stream_config_priorityLevelMedium =             BIT(16),
  dma_stream_config_priorityLevelHigh =               BIT(17),
  dma_stream_config_priorityLevelVeryHigh =           BIT(16) | BIT(17),
  dma_stream_config_priorityLevelMask =               BIT(16) | BIT(17),

  dma_stream_config_doubleBufferMode =                BIT(18),
  // Only in double buffer mode
  dma_stream_config_useMem1AddrAsCurrentTarget =      BIT(19),
  dma_stream_config_bufferableTransfersEnabled =      BIT(20),

  dma_stream_config_periphBurstSingle =               0,
  dma_stream_config_periphBurst4Beats =               BIT(21),
  dma_stream_config_periphBurst8Beats =               BIT(22),
  dma_stream_config_periphBurst16Beats =              BIT(21) | BIT(22),
  dma_stream_config_periphBurstMask =                 BIT(21) | BIT(22),

  dma_stream_config_memoryBurstSingle =               0,
  dma_stream_config_memoryBurst4Beats =               BIT(23),
  dma_stream_config_memoryBurst8Beats =               BIT(24),
  dma_stream_config_memoryBurst16Beats =              BIT(23) | BIT(24),
  dma_stream_config_memoryBurstMask =                 BIT(23) | BIT(24),

  dma_stream_config_reset =                           0x0
} dma_stream_config_t;

typedef enum dma_stream_fifoCtrl_e {
  dma_stream_fifoCtrl_thresholdQuarterFull =    0,
  dma_stream_fifoCtrl_thresholdHalfFull =       BIT(0),
  dma_stream_fifoCtrl_threshold3QuartersFull =  BIT(1),
  dma_stream_fifoCtrl_thresholdFull =           BIT(0) | BIT(1),
  dma_stream_fifoCtrl_thresholdMask =           BIT(0) | BIT(1),

  dma_stream_fifoCtrl_directModeDisable =       BIT(2),

  dma_stream_fifoCtrl_statusUpToQuarterFull =   0,
  dma_stream_fifoCtrl_statusUpToHalfFull =      BIT(3),
  dma_stream_fifoCtrl_statusUpTo3QuartersFull = BIT(4),
  dma_stream_fifoCtrl_statusUpToFull =          BIT(3) | BIT(4),
  dma_stream_fifoCtrl_statusFull =              BIT(5),
  dma_stream_fifoCtrl_statusEmpty =             BIT(3) | BIT(5),
  dma_stream_fifoCtrl_statusMask =              BIT(3) | BIT(4) | BIT(5),

  dma_stream_fifoCtrl_fifoErrorIntEnable =      BIT(7),

  dma_stream_fifoCtrl_reset =                   0x21
} dma_stream_fifoCtrl_t;

#endif

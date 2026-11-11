#ifndef _H7_UART_
#define _H7_UART_

#include "base.h"

typedef struct uart_s {
  uio32_t control1;
  uio32_t control2;
  uio32_t control3;
  uio32_t baudrate;
  // Not present in LPUART
  uio32_t guardTime;
  // Not present in LPUART
  uio32_t rxTimeout;
  uio32_t request;
  uio32_t intStatus;
  uio32_t intClear;
  uio32_t rxData;
  uio32_t txData;
  uio32_t prescaler;
} uart_t;

#define usart1 ((uart_t*)H7_BASE_USART1)
#define usart2 ((uart_t*)H7_BASE_USART2)
#define usart3 ((uart_t*)H7_BASE_USART3)
#define uart4 ((uart_t*)H7_BASE_UART4)
#define uart5 ((uart_t*)H7_BASE_UART5)
#define usart6 ((uart_t*)H7_BASE_USART6)
#define uart7 ((uart_t*)H7_BASE_UART7)
#define uart8 ((uart_t*)H7_BASE_UART8)

#define lpuart1 ((uart_t*)H7_BASE_LPUART1)

typedef enum uart_control1_e {
  uart_control1_enable = BIT(0),
  uart_control1_enableLP = BIT(1),
  uart_control1_rxEnable = BIT(2),
  uart_control1_txEnable = BIT(3),
  uart_control1_idleIntEnable = BIT(4),
  uart_control1_rxNotEmptyIntEnable = BIT(5),
  uart_control1_transmissionCompleteIntEnable = BIT(6),
  uart_control1_txNotFullIntEnable = BIT(7),
  uart_control1_peIntEnable = BIT(8),
  uart_control1_oddParity = BIT(9),
  uart_control1_parityControlEnable = BIT(10),
  uart_control1_rxWakeupAddressMarkMethod = BIT(11),
  uart_control1_wordLength0 = BIT(12),
  uart_control1_muteMode = BIT(13),
  uart_control1_charMatchIntEnable = BIT(14),
  uart_control1_oversamplingBy8 = BIT(15),
  
  uart_control1_driverEnableDeassertionTimeMask = MASK32(16, 20),
  uart_control1_driverEnableDeassertionTimeShift = 16,

  uart_control1_driverEnableAssertionTimeMask = MASK32(21, 25),
  uart_control1_driverEnableAssertionTimeShift = 21,

  uart_control1_rxTimeoutIntEnable = BIT(26),
  uart_control1_endOfBlockIntEnable = BIT(27),
  uart_control1_wordLength1 = BIT(28),
  uart_control1_fifoModeEnable = BIT(29),
  uart_control1_txFifoEmptyIntEnable = BIT(30),
  uart_control1_rxFifoFullIntEnable = BIT(31),

  uart_control1_reset = 0x0
} uart_control1_t;

typedef enum uart_control2_e {
  uart_control2_syncSlaveModeEnable = BIT(0),
  uart_control2_nssPinEnable = BIT(3),
  uart_control2_7BitAddressDetection = BIT(4),
  uart_control2_LIN11BitBreakDetection = BIT(5),
  uart_control2_LINBreakDetectionIntEnable = BIT(6),
  uart_control2_lastBitClockPulse = BIT(8),
  uart_control2_clockPhaseSecondTrans = BIT(9),
  uart_control2_clockPolarityAsHigh = BIT(10),
  uart_control2_clockEnable = BIT(11),
  
  uart_control2_stopBits1 = 0,
  uart_control2_stopBits0_5 = BIT(12),
  uart_control2_stopBits2 = BIT(13),
  uart_control2_stopBits1_5 = BIT(12) | BIT(13),
  uart_control2_stopBitsMask = BIT(12) | BIT(13),

  uart_control2_LINModeEnable = BIT(14),
  uart_control2_swapTxAndRx = BIT(15),
  uart_control2_rxActiveInvert = BIT(16),
  uart_control2_txActiveInvert = BIT(17),
  uart_control2_invertBinaryData = BIT(18),
  uart_control2_MSBFirst = BIT(19),
  uart_control2_autoBaudrateENable = BIT(20),
  
  uart_control2_autoBaudrateModeStartBit = 0,
  uart_control2_autoBaudrateModeFallingEdge = BIT(21),
  uart_control2_autoBaudrateMode0x7FDetection = BIT(22),
  uart_control2_autoBaudrateMode0x55Detection = BIT(21) | BIT(22),
  uart_control2_autoBaudrateModeMask = BIT(21) | BIT(22),

  uart_control2_rxTimeoutEnable = BIT(23),
  
  uart_control2_usartNodeAddressMask = MASK32(24, 31),
  uart_control2_usartNodeAddressShift = 24,

  uart_control2_reset = 0x0
} uart_control2_t;

typedef enum uart_control3_e {
  uart_control3_errorIntEnable = BIT(0),
  uart_control3_IrDAModeEnable = BIT(1),
  uart_control3_IrDALPMode = BIT(2),
  uart_control3_halfDuplexMode = BIT(3),
  uart_control3_smartcardNACKEnable = BIT(4),
  uart_control3_smartcardModeEnable = BIT(5),
  uart_control3_rxEnableDma = BIT(6),
  uart_control3_txEnableDma = BIT(7),
  uart_control3_rtsEnable = BIT(8),
  uart_control3_ctsEnable = BIT(9),
  uart_control3_ctsIntEnable = BIT(10),
  uart_control3_oneSampleBitMethodEnable = BIT(11),
  uart_control3_overrunDisable = BIT(12),
  uart_control3_dmaDisableOnReceptionError = BIT(13),
  uart_control3_driverEnableMode = BIT(14),
  uart_control3_driverEnableActiveLow = BIT(15),
  
  uart_control3_smartcardAutoRetryCountMask = MASK32(17, 19),
  uart_control3_smartcardAutoRetryCountShift = 17,

  uart_control3_wakeupFromLPOnAddressMatch = 0,
  uart_control3_wakeupFromLPOnStartBitDetection = BIT(21),
  uart_control3_wakeupFromLPOnRXNE_RXFNE = BIT(20) | BIT(21),
  uart_control3_wakeupFromLPMask = uart_control3_wakeupFromLPOnRXNE_RXFNE,

  uart_control3_wakeupFromLPIntEnable = BIT(22),
  uart_control3_txFifoThresholdIntEnable = BIT(23),
  uart_control3_transmissionCompleteBeforeGuartTimeIntEnable = BIT(24),
  
  uart_control3_rxFifoReaches1_8Depth = 0,
  uart_control3_rxFifoReaches1_4Depth = BIT(25),
  uart_control3_rxFifoReaches1_2Depth = BIT(26),
  uart_control3_rxFifoReaches3_4Depth = BIT(25) | BIT(26),
  uart_control3_rxFifoReaches7_8Depth = BIT(27),
  uart_control3_rxFifoBecomesFull = BIT(25) | BIT(27),
  uart_control3_rxFifoMask = MASK32(25, 27),

  uart_control3_rxFifoIntEnable = BIT(28),
  
  uart_control3_txFifoReaches1_8Depth = 0,
  uart_control3_txFifoReaches1_4Depth = BIT(29),
  uart_control3_txFifoReaches1_2Depth = BIT(30),
  uart_control3_txFifoReaches3_4Depth = BIT(29) | BIT(30),
  uart_control3_txFifoReaches7_8Depth = BIT(31),
  uart_control3_txFifoBecomesFull = BIT(29) | BIT(31),
  uart_control3_txFifoMask = MASK32(29, 31),

  uart_control3_reset = 0x0
} uart_control3_t;

typedef enum uart_request_e {
  uart_request_autoBaudrate = BIT(0),
  uart_request_sendBreak = BIT(1),
  uart_request_muteMode = BIT(2),
  uart_request_rxDataFlush = BIT(3),
  uart_request_txDataFlush = BIT(4),

  uart_request_reset = 0x0
} uart_request_t;

typedef enum uart_intStatus_e {
  uart_intStatus_parityError = BIT(0),
  uart_intStatus_framingError = BIT(1),
  uart_intStatus_noiseDetected = BIT(2),
  uart_intStatus_overrunError = BIT(3),
  uart_intStatus_idleLineDetected = BIT(4),
  uart_intStatus_rxFifoNotEmpty = BIT(5),
  uart_intStatus_transmissionComplete = BIT(6),
  uart_intStatus_txFifoNotFull = BIT(7),
  uart_intStatus_LINBreakDetected = BIT(8),
  uart_intStatus_ctsInt = BIT(9),
  // Cannot clear in intClear
  uart_intStatus_ctsLineReset = BIT(10),
  uart_intStatus_rxTimeout = BIT(11),
  uart_intStatus_endOfBlock = BIT(12),
  uart_intStatus_underrunError = BIT(13),
  // Cannot clear in intClear
  uart_intStatus_autoBaudrateError = BIT(14),
  // Cannot clear in intClear
  uart_intStatus_autoBaudrateSet = BIT(15),
  // Cannot clear in intClear
  uart_intStatus_busy = BIT(16),
  uart_intStatus_charMatch = BIT(17),
  // Cannot clear in intClear
  uart_intStatus_sendBreakRequest = BIT(18),
  // Cannot clear in intClear
  uart_intStatus_rxWakeupFromMute = BIT(19),
  uart_intStatus_wakeupFromLP = BIT(20),
  // Cannot clear in intClear
  uart_intStatus_txEnableAck = BIT(21),
  // Cannot clear in intClear
  uart_intStatus_rxEnableAck = BIT(22),
  // Not available without fifo, cannot clear in intClear
  uart_intStatus_txFifoEmpty = BIT(23),
  // Not available without fifo, cannot clear in intClear
  uart_intStatus_rxFifoFull = BIT(24),
  // Cannot clear in intClear
  uart_intStatus_transmissionCompleteBeforeGuardTime = BIT(25),
  // Not available without fifo, cannot clear in intClear
  uart_intStatus_rxFifoThreasholdReached = BIT(26),
  // Not available without fifo, cannot clear in intClear
  uart_intStatus_txFifoThreasholdReached = BIT(27),

  uart_intStatus_resetWithSmartcardEnabled = 0x028000C0,
  uart_intStatus_resetFifoDisabled = 0xC0,
  uart_intStatus_reset = 0x008000C0,
  uart_intStatus_resetIntClear = 0x0
} uart_intStatus_t;

#endif

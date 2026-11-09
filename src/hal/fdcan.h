#ifndef _H7_FDCAN_
#define _H7_FDCAN_

#include "base.h"

typedef struct fdcan_s {
  uio32_t coreRelease;
  uio32_t endian;
  uint32_t RESERVED1;
  uio32_t dataBitTiming;
  uio32_t test;
  uio32_t ramWDG;
  uio32_t ccControl;
  uio32_t nominalBitTiming;
  uio32_t timestampCounterCtrl;
  uio32_t timestampCounterVal;
  uio32_t timeoutCounterCtrl;
  uio32_t timeoutCounterVal;
  uint32_t RESERVED2[4];
  uio32_t errorCounter;
  uio32_t protocolStatus;
  uio32_t transmitterDelayCompens;
  uint32_t RESEREVD3;
  uio32_t interrupt;
  uio32_t intEnable;
  uio32_t intLineSelect;
  uio32_t intLineEnable;
  // 0x5C end
  // 0x80
  uio32_t 
} fdcan_t;

#endif

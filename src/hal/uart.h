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

#endif

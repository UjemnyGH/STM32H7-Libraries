#ifndef _H7_GPIO_
#define _H7_GPIO_

#include "base.h"

typedef struct gpio_s {
  uio32_t mode;
  uio32_t outputType;
  uio32_t outputSpeed;
  uio32_t pull;
  uio32_t inputData;
  uio32_t outputData;
  uio32_t bitSetReset;
  uio32_t lock;
  uio32_t altFuncLow;
  uio32_t altFuncHigh;
} gpio_t;

#define gpio_a ((gpio_t*)H7_BASE_GPIO_A)
#define gpio_b ((gpio_t*)H7_BASE_GPIO_B)
#define gpio_c ((gpio_t*)H7_BASE_GPIO_C)
#define gpio_d ((gpio_t*)H7_BASE_GPIO_D)
#define gpio_e ((gpio_t*)H7_BASE_GPIO_E)
#define gpio_f ((gpio_t*)H7_BASE_GPIO_F)
#define gpio_g ((gpio_t*)H7_BASE_GPIO_G)
#define gpio_h ((gpio_t*)H7_BASE_GPIO_H)
#define gpio_i ((gpio_t*)H7_BASE_GPIO_I)
#define gpio_j ((gpio_t*)H7_BASE_GPIO_J)
#define gpio_k ((gpio_t*)H7_BASE_GPIO_K)

typedef enum gpio_mode_e {
  mode_input =    0,
  mode_output =   BIT(0),
  mode_altFunc =  BIT(1),
  mode_analog =   BIT(0) | BIT(1),
  mode_mask =     mode_analog,

  mode_resetA =   0xABFFFFFF,
  mode_resetB =   0xFFFFFEBF,
  mode_reset =    0xFFFFFFFF
} gpio_mode_t;

typedef enum gpio_outputType_e {
  outputType_pull =   0,
  outputType_open =   BIT(0),

  outputType_reset =  0x0
} gpio_outputType_t;

typedef enum gpio_outputSpeed_e {
  outputSpeed_low =       0,
  outputSpeed_medium =    BIT(0),
  outputSpeed_high =      BIT(1),
  outputSpeed_veryHigh =  BIT(0) | BIT(1),
  outputSpeed_mask =      outputSpeed_veryHigh,

  outputSpeed_resetA =    0x0C000000,
  outputSpeed_resetB =    0xC0,
  outputSpeed_reset =     0x0
} gpio_outputSpeed_t;

typedef enum gpio_pull_e {
  pull_none =     0,
  pull_up =       BIT(0),
  pull_down =     BIT(1),
  pull_mask =     BIT(0) | BIT(1),

  pull_resetA =   0x64000000,
  pull_resetB =   0x0100,
  pull_reset =    0x0
} gpio_pull_t;

typedef enum gpio_altFunc_e {
  altFunc_SYS = 0x0,
  altFunc_TIM1_2_16_17_LPTIM1_HRTIM1 = 0x1,
  altFunc_SAI1_TIM3_4_5_12_HRTIM1 = 0x2,
  altFunc_LPUART_TIM8_LPTIM2_3_4_5_HRTIM1_DFSDM = 0x3,
  altFunc_I2C1_2_3_4_USART1_TIM15_LPTIM2_DFSDM_CEC = 0x4,
  altFunc_SPI1_2_3_4_5_6_CEC = 0x5,
  altFunc_SPI2_3_SAI1_3_I2C4_UART4_DFSDM = 0x6,
  altFunc_SPI2_3_6_USART1_2_3_6_UART7_SDMMC1 = 0x7,
  altFunc_SPI6_SAI2_4_UART4_5_8_LPUART_SDMMC1_SPDIFRX1 = 0x8,
  altFunc_SAI4_FDCAN1_FDACN2_TIM13_14_QUADSPI_FMC_SDMMC2_LCD_SPDIFRX1 = 0x9,
  altFunc_SAI2_4_TIM8_QUADSPI_SDMMC2_OTGHS1_OTGFS2_LCD_CRS = 0xA,
  altFunc_I2C4_UART7_SWPMI1_TIM1_8_DFSDM_SDMMC2_MDIOS_ETH = 0xB,
  altFunc_TIM1_8_FMC_SDMMC1_MDIOS_OTGFS1_LCD = 0xC,
  altFunc_TIM1_DCMI_LCD_DSI_COMP = 0xD,
  altFunc_UART5_LCD = 0xE,
  altFunc_EVENTOUT = 0xF
} gpio_altFunc_t;

// TODO: Full automatic setup for alternate pin functions
/*
// GPIO indices for GPIOMAFE
#define IOAI 0
#define IOBI 1 
#define IOCI 2
#define IODI 3
#define IOEI 4
#define IOFI 5
#define IOGI 6
#define IOHI 7
#define IOII 8
#define IOJI 9
#define IOKI 10

#define GPIOMAFE_ALT_FUNC_MASK  0x000F
#define GPIOMAFE_PIN_MASK       0x00F0
#define GPIOMAFE_INDEX_MASK     0x0F00
#define GPIOMAFE_ALT_FUNC_SHIFT 0
#define GPIOMAFE_PIN_SHIFT      4
#define GPIOMAFE_INDEX_SHIFT    8

// GPIO Make Alternate Function Entry
#define GPIOMAFE(IO_INDEX, PIN, ALTFN) (((ALTFN &GPIOMAFE_ALT_FUNC_MASK) << GPIOMAFE_ALT_FUNC_SHIFT) | ((PIN & GPIOMAFE_PIN_MASK) << GPIOMAFE_PIN_SHIFT) | ((IO_INDEX & GPIOMAFE_INDEX_MASK) << GPIOMAFE_INDEX_SHIFT))

typedef enum gpio_alternateFunctionMap_e {
  // PA0
  altFn_tim2ch1_a0 = GPIOMAFE(IOAI, 0, 1),
} gpio_alternateFunctionMap_t;*/

void gpio_setupPin(gpio_t *const pIo, uint8_t pin, gpio_mode_t mode, gpio_outputType_t type, gpio_outputSpeed_t speed, gpio_pull_t pull);

/**
 * Read the DS_stm32h757ai.pdf Section 5 Table 9 for the approprieate alternate function selection for the pin
 * */
void gpio_setAltFunc(gpio_t *const pIo, uint8_t pin, gpio_altFunc_t altFn);

bool_t gpio_getInput(gpio_t *const pIo, uint8_t pin);

void gpio_setOutput(gpio_t *const pIo, uint8_t pin, bool_t state);

#endif

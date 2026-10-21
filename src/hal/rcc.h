#ifndef _H7_RCC_
#define _H7_RCC_

#include "base.h"

typedef struct rcc_s {
  uio32_t sourceControl;
  uio32_t hsiConfig;
  uio32_t clockRecoveryRC;
  uio32_t csiConfig;
  uio32_t clockConfig;
  uint32_t RESERVED1;
  uio32_t clockConfigD1;
  uio32_t clockConfigD2;
  uio32_t clockConfigD3;
  uint32_t RESERVED2;
  uio32_t clockSrcSelectPLL;
  uio32_t configPLL;
  uio32_t configDivPLL1;
  uio32_t fractDivPLL1;
  uio32_t configDivPLL2;
  uio32_t fractDivPLL2;
  uio32_t configDivPLL3;
  uio32_t fractDivPLL3;
  uint32_t RESERVED3;
  uio32_t kernelClockConfigD1;
  uio32_t kernelClockConfigD2;
  uio32_t kernelClockConfigD2_2;
  uio32_t kernelClockConfigD3;
  uint32_t RESERVED4;
  uio32_t clockSrcIntEnable;
  uio32_t clockSrcIntFlag;
  uio32_t clockSrcIntClear;
  uint32_t RESERVED5;
  uio32_t backupControl;
  uio32_t clockControlStat;
  uint32_t RESREVED6;
  uio32_t resetAHB3;
  uio32_t resetAHB1;
  uio32_t resetAHB2;
  uio32_t resetAHB4;
  uio32_t resetAPB3;
  uio32_t resetLowAPB1;
  uio32_t resetHighAPB1;
  uio32_t resetAPB2;
  uio32_t resetAPB4;
  uio32_t globalControl;
  uint32_t RESERVED6;
  uio32_t autonomusD3;
  uint8_t RESREVED7[36];
  uio32_t resetStatus;
  uio32_t clockAHB3;
  uio32_t clockAHB1;
  uio32_t clockAHB2;
  uio32_t clockAHB4;
  uio32_t clockAPB3;
  uio32_t clockLowAPB1;
  uio32_t clockHighAPB1;
  uio32_t clockAPB2;
  uio32_t clockAPB4;
  uint32_t RESREVED8;
  uio32_t sleepClockAHB3;
  uio32_t sleepClockAHB1;
  uio32_t sleepClockAHB2;
  uio32_t sleepClockAHB4;
  uio32_t sleepClockAPB3;
  uio32_t sleepClockLowAPB1;
  uio32_t sleepClockHighAPB1;
  uio32_t sleepClockAPB2;
  uio32_t sleepClockAPB4;
  uint8_t RESREVED9[16];


  uio32_t resetStatusC1;
  uio32_t clockAHB3C1;
  uio32_t clockAHB1C1;
  uio32_t clockAHB2C1;
  uio32_t clockAHB4C1;
  uio32_t clockAPB3C1;
  uio32_t clockLowAPB1C1;
  uio32_t clockHighAPB1C1;
  uio32_t clockAPB2C1;
  uio32_t clockAPB4C1;
  uint32_t RESREVED8C1;
  uio32_t sleepClockAHB3C1;
  uio32_t sleepClockAHB1C1;
  uio32_t sleepClockAHB2C1;
  uio32_t sleepClockAHB4C1;
  uio32_t sleepClockAPB3C1;
  uio32_t sleepClockLowAPB1C1;
  uio32_t sleepClockHighAPB1C1;
  uio32_t sleepClockAPB2C1;
  uio32_t sleepClockAPB4C1;
  uint8_t RESERVED9C1[16];

  uio32_t resetStatusC2;
  uio32_t clockAHB3C2;
  uio32_t clockAHB1C2;
  uio32_t clockAHB2C2;
  uio32_t clockAHB4C2;
  uio32_t clockAPB3C2;
  uio32_t clockLowAPB1C2;
  uio32_t clockHighAPB1C2;
  uio32_t clockAPB2C2;
  uio32_t clockAPB4C2;
  uint32_t RESREVED8C2;
  uio32_t sleepClockAHB3C2;
  uio32_t sleepClockAHB1C2;
  uio32_t sleepClockAHB2C2;
  uio32_t sleepClockAHB4C2;
  uio32_t sleepClockAPB3C2;
  uio32_t sleepClockLowAPB1C2;
  uio32_t sleepClockHighAPB1C2;
  uio32_t sleepClockAPB2C2;
  uio32_t sleepClockAPB4C2;
} rcc_t;

#define rcc ((rcc_t*)H7_BASE_RCC)

typedef enum rcc_sourceControl_e {
  sc_enableHSI = BIT(0),
  sc_HSIStopMode = BIT(1),
  sc_HSIReady = BIT(2),
  sc_HSIDiv1 = 0,
  sc_HSIDiv2 = BIT(3),
  sc_HSIDiv4 = BIT(4),
  sc_HSIDiv8 = BIT(3) | BIT(4),
  sc_HSIDivFlag = BIT(5),
  sc_enableCSI = BIT(7),
  sc_CSIReady = BIT(8),
  sc_CSIStopMode = BIT(9),
  sc_enableHSI48 = BIT(12),
  sc_HSI48Ready = BIT(13),
  sc_D1ClkReady = BIT(14),
  sc_D2ClkReady = BIT(15),
  sc_enableHSE = BIT(16),
  sc_HSEReady = BIT(17),
  sc_HSEBypass = BIT(18),
  sc_enableHSECSS = BIT(19),
  sc_enablePLL1 = BIT(24),
  sc_PLL1Ready = BIT(25),
  sc_enablePLL2 = BIT(26),
  sc_PLL2Ready = BIT(27),
  sc_enablePLL3 = BIT(28),
  sc_PLL3Ready = BIT(29),

  sc_reset = 0x1
} rcc_sourceControl_t;

typedef enum rcc_hsiConfig_e {
  hsic_HSIClkCalibrationMask = MASK32(0, 11),
  hsic_HSIClkTrimMask = MASK32(24, 30),

  hsic_reset = 0x40000000
} rcc_hsiConfig_t;

typedef enum rcc_clockRecoveryRC_e {
  crrc_HSI48ClkCalibrationMask = MASK32(0, 9),

  crrc_reset = 0x0
} rcc_clockRecoveryRC_t;

typedef enum rcc_csiConfig_e {
  csic_CSIClkCalibrationMask = MASK32(0, 9),
  csic_CSIClkTrimMask = MASK32(24, 29),

  csic_reset = 0x20000000
} rcc_csiConfig_t;

typedef enum rcc_clockConfig_e {
  cc_selectHSI = 0,
  cc_selectCSI = BIT(0),
  cc_selectHSE = BIT(1),
  cc_selectPLL1 = BIT(0) | BIT(1),
  cc_selectClockMask = MASK32(0, 2),
  cc_HSIClkStat = 0,
  cc_CSIClkStat = BIT(3),
  cc_HSEClkStat = BIT(4),
  cc_PLL1ClkStat = BIT(3) | BIT(4),
  cc_clockStatusMask = MASK32(3, 5),
  cc_CSIAsSystemWakeUp = BIT(6),
  cc_CSIAsKernelWakeUp = BIT(7),
  cc_HSEDivRTCMask = MASK32(8, 13),
  cc_HRTIMPrescalerC1 = BIT(14),
  cc_TIMPrescalerSelection = BIT(15),
  cc_MCO1PescalerMask = MASK32(18, 21),
  cc_MCO1HSI = 0,
  cc_MCO1LSE = BIT(22),
  cc_MCO1HSE = BIT(23),
  cc_MCO1PLL1 = BIT(22) | BIT(23),
  cc_MCO1HSI48 = BIT(24),
  cc_MCO1ClockSelectionMask = MASK32(22, 24),
  cc_MCO2PrescalerMask = MASK32(25, 28),
  cc_MCO2SysClk = 0,
  cc_MCO2PLL2 = BIT(29),
  cc_MCO2HSE = BIT(30),
  cc_MCO2PLL1 = BIT(29) | BIT(30),
  cc_MCO1CSI = BIT(31),
  cc_MCO2LSI = BIT(29) | BIT(31),
  cc_MCO2ClockSelectionMask = MASK32(29, 31),

  cc_reset = 0x0
} rcc_clockConfig_t;

typedef enum rcc_clockConfigD_e {
  ccd_D1AHBPrescalerMask = MASK32(0, 3),
  ccd_APB3PrescalerMask = MASK32(4, 6),
  ccd_D1CorePrescalerMask = MASK32(8, 11),
  ccd_D2APB2PrescalerMask = MASK32(8, 10),

  ccd_reset = 0x0
} rcc_clockConfigD_t;

typedef enum rcc_clockSrcSelectPLL_e {
  csspll_DIVMPLLClkSrcHSI = 0,
  csspll_DIVMPLLClkSrcCSI = BIT(0),
  csspll_DIVMPLLClkSrcHSE = BIT(1),
  csspll_DIVMPLLClkSrcNone = BIT(0) | BIT(1),
  csspll_DIVMPLL1PrescalerMask = MASK32(4, 9),
  csspll_DIVMPLL2PrescalerMask = MASK32(12, 17),
  csspll_DIVMPLL3PrescalerMask = MASK32(20, 25),

  csspll_reset = 0x02020200
} rcc_clockSrcSelectPLL_t;

typedef enum rcc_configPLL_e {
  cpll_PLL1FractLatchEnable = BIT(0),
  cpll_PLL1VCOSelection = BIT(1),
  cpll_PLL1InputFreqRange1_2MHz = 0,
  cpll_PLL1InputFreqRange2_4MHz = BIT(2),
  cpll_PLL1InputFreqRange4_8MHz = BIT(3),
  cpll_PLL1InputFreqRange8_16MHz = BIT(2) | BIT(3),
  cpll_PLL2FractLatchEnable = BIT(4),
  cpll_PLL2VCOSelection = BIT(5),
  cpll_PLL2InputFreqRange1_2MHz = 0,
  cpll_PLL2InputFreqRange2_4MHz = BIT(6),
  cpll_PLL2InputFreqRange4_8MHz = BIT(7),
  cpll_PLL2InputFreqRange8_16MHz = BIT(6) | BIT(7),
  cpll_PLL3FractLatchEnable = BIT(8),
  cpll_PLL3VCOSelection = BIT(9),
  cpll_PLL3InputFreqRange1_2MHz = 0,
  cpll_PLL3InputFreqRange2_4MHz = BIT(10),
  cpll_PLL3InputFreqRange4_8MHz = BIT(11),
  cpll_PLL3InputFreqRange8_16MHz = BIT(10) | BIT(11),
  cpll_PLL1DIVPEnable = BIT(16),
  cpll_PLL1DIVQEnable = BIT(17),
  cpll_PLL1DIVREnable = BIT(18),
  cpll_PLL2DIVPEnable = BIT(19),
  cpll_PLL2DIVQEnable = BIT(20),
  cpll_PLL2DIVREnable = BIT(21),
  cpll_PLL3DIVPEnable = BIT(22),
  cpll_PLL3DIVQEnable = BIT(23),
  cpll_PLL3DIVREnable = BIT(24),

  cpll_reset = 0x01FF0000
} rcc_configPLL_t;

typedef enum rcc_configDivPLL_e {
  cdpll_PLL1MulMask = MASK32(0, 8),
  cdpll_PLL1DIVPMask = MASK32(9, 15),
  cppll_PLL1DIVQMask = MASK32(16, 22),
  cdpll_PLL1DIVRMask = MASK32(24, 30),

  cdpll_reset = 0x01010280
} rcc_configDivPLL_t;

typedef enum rcc_fractDivPLL_e {
  fdpll_PLL1MulMask = MASK32(3, 15),

  fdpll_reset = 0x0
} rcc_fractDivPLL_t;

typedef enum rcc_kernelClockConfigD1_e {
  kccd1_FMCHardClkSelect = 0,
  kccd1_FMCPLL1QClkSelect = BIT(0),
  kccd1_FMCPLL2RClkSelect = BIT(1),
  kccd1_FMCPeriphClkSelect = BIT(0) | BIT(1),
  kccd1_QSPIHardClkSelect = 0,
  kccd1_QSPIPLL1QClkSelect = BIT(4),
  kccd1_QSPIPLL2RClkSelect = BIT(5),
  kccd1_QSPIPeriphClkSelect = BIT(4) | BIT(5),
  kccd1_DSIClkSelect = BIT(8),
  kccd1_SDMMCClkSelect = BIT(16),
  kccd1_PeriphHSIKernelClkSelect = 0,
  kccd1_PeriphCSIKernelClkSelect = BIT(28),
  kccd1_PeriphHSEClkSelect = BIT(29),
  
  kccd1_reset = 0x0
} rcc_kernelClockConfigD1_t;

typedef enum rcc_kernelClockConfigD2_e {
  kccd2_SAI1PLL1ClkSelect = 0,
  kccd2_SAI1PLL2ClkSelect = BIT(0),
  kccd2_SAI1PLL3ClkSelect = BIT(1),
  kccd2_SAI1I2SClkSelect = BIT(0) | BIT(1),
  kccd2_SAI1PeriphClkSelect = BIT(2),
  kccd2_SAI23PLL1ClkSelect = 0,
  kccd2_SAI23PLL2ClkSelect = BIT(6),
  kccd2_SAI23PLL3ClkSelect = BIT(7),
  kccd2_SAI23I2SClkSelect = BIT(6) | BIT(7),
  kccd2_SAI23PeriphClkSelect = BIT(8),
  kccd2_SPI123PLL1ClkSelect = 0,
  kccd2_SPI123PLL2ClkSelect = BIT(12),
  kccd2_SPI123PLL3ClkSelect = BIT(13),
  kccd2_SPI123I2SClkSelect = BIT(12) | BIT(13),
  kccd2_SPI123PeriphClkSelect = BIT(14),
  kccd2_SPI45APBClkSelect = 0,
  kccd2_SPI45PLL2ClkSelect = BIT(16),
  kccd2_SPI45PLL3ClkSelect = BIT(17),
  kccd2_SPI45HSIKernelClkSelect = BIT(16) | BIT(17),
  kccd2_SPI45CSIKernelClkSelect = BIT(18),
  kccd2_SPI45HSEClkSelect = BIT(16) | BIT(18),
  kccd2_SPDIFRXPLL1ClkSelect = 0,
  kccd2_SPDIFRXPLL2ClkSelect = BIT(20),
  kccd2_SPDIFRXPLL3ClkSelect = BIT(21),
  kccd2_SPDIFRXHSIKernelClkSelect = BIT(20) | BIT(21),
  kccd2_DFSDM1KernelClkSysSelect = BIT(24),
  kccd2_FDCANHSEClkSelect = 0,
  kccd2_FDCANPLL1ClkSelect = BIT(28),
  kccd2_FDCANPLL2ClkSelect = BIT(29),
  kccd2_SWPMIHSIKernelClkSelect = BIT(31),

  kccd2_reset = 0x0
} rcc_kernelClockConfigD2_t;

typedef enum rcc_kernelClockConfigD2_2_t {
  kccd22_USART234578PLL2ClkSelect = BIT(0),
  kccd22_USART234578PLL3ClkSelect = BIT(1),
  kccd22_USART234578HSIKernelClkSelect = BIT(0) | BIT(1),
  kccd22_USART234578CSIKernelClkSelect = BIT(2),
  kccd22_USART234578LSEClkSelect = BIT(0) | BIT(2),
  kccd22_USART16PLL2ClkSelect = BIT(3),
  kccd22_USART16PLL3ClkSelect = BIT(4),
  kccd22_USART16HSIKernelClkSelect = BIT(3) | BIT(4),
  kccd22_USART16CSIKernelClkSelect = BIT(5),
  kccd22_USART16LSEClkSelect = BIT(3) | BIT(5),
  kccd22_RNGPLL1ClkSelect = BIT(8),
  kccd22_RNGLSEClkSelect = BIT(9),
  kccd22_RNGLSIClkSelect = BIT(8) | (9),
  kccd22_I2C123PLL3ClkSelect = BIT(12),
  kccd22_I2C123HSIClkSelect = BIT(13),
  kccd22_I2C123CSIClkSelect = BIT(12) | BIT(13),
  kccd22_USBPLL1ClkSelect = BIT(20),
  kccd22_USBPLL3ClkSelect = BIT(21),
  kccd22_USBHSI48ClkSelect = BIT(20) | BIT(21),
  kccd22_HDMILSIClkSelect = BIT(22),
  kccd22_HDMICSIClkSelect = BIT(23),
  kccd22_LPTIM1PLL2ClkSelect = BIT(28),
  kccd22_LPTIM1PLL3ClkSelect = BIT(29),
  kccd22_LPTIM1LSEClkSelect = BIT(28) | BIT(29),
  kccd22_LPTIM1LSIClkSelect = BIT(30),
  kccd22_LPTIM1PeriphClkSelect = BIT(28) | BIT(30),

  kccd22_reset = 0x0
} rcc_kernelClockConfigD2_2_t;

typedef enum rcc_kernelClockConfigD3_e {
  kccd3_LPUART1PLL2ClkSelect = BIT(0),
  kccd3_LPUART1PLL3ClkSelect = BIT(1),
  kccd3_LPUART1HSIClkSelect = BIT(0) | BIT(1),
  kccd3_LPUART1CSIClkSelect = BIT(2),
  kccd3_LPUART1LSEClkSelect = BIT(0) | BIT(2),
  kccd3_I2C4PLL3ClkSelect = BIT(8),
  kccd3_I2C4HSIClkSelect = BIT(9),
  kccd3_I2C4CSIClkSelect = BIT(8) | BIT(9),
  kccd3_LPTIM2PLL2ClkSelect = BIT(10),
  kccd3_LPTIM2PLL3ClkSelect = BIT(11),
  kccd3_LPTIM2LSEClkSelect = BIT(10) | BIT(11),
  kccd3_LPTIM2LSIClkSelect = BIT(12),
  kccd3_LPTIM2PeriphClkSelect = BIT(10) | BIT(12),
  kccd3_LPTIM345PLL2ClkSelect = BIT(13),
  kccd3_LPTIM345PLL3ClkSelect = BIT(14),
  kccd3_LPTIM345LSEClkSelect = BIT(13) | BIT(14),
  kccd3_LPTIM345LSIClkSelect = BIT(15),
  kccd3_LPTIM345PeriphClkSelect = BIT(13) | BIT(15),
  kccd3_ADCPLL3ClkSelect = BIT(16),
  kccd3_ADCPeriphClkSelect = BIT(17),
  kccd3_SAI4APLL2ClkSelect = BIT(21),
  kccd3_SAI4APLL3ClkSelect = BIT(22),
  kccd3_SAI4AI2SClkSelect = BIT(21) | BIT(22),
  kccd3_SAI4APeriphClkSelect = BIT(23),
  kccd3_SAI4BPLL2ClkSelect = BIT(24),
  kccd3_SAI4BPLL3ClkSelect = BIT(25),
  kccd3_SAI4BI2SClkSelect = BIT(24) | BIT(25),
  kccd3_SAI4BPeriphClkSelect = BIT(26),
  kccd3_SPI6PLL2ClkSelect = BIT(28),
  kccd3_SPI6PLL3ClkSelect = BIT(29),
  kccd3_SPI6HSIClkSelect = BIT(28) | BIT(29),
  kccd3_SPI6CSIClkSelect = BIT(30),
  kccd3_SPI6HSEClkSelect = BIT(28) | BIT(30),

  kccd3_reset = 0x0
} rcc_kernelClockConfigD3_t;

typedef enum rcc_clockSrcInt_e {
  csi_LSI = BIT(0),
  csi_LSE = BIT(1),
  csi_HSI = BIT(2),
  csi_HSE = BIT(3),
  csi_CSI = BIT(4),
  csi_HSI48 = BIT(5),
  csi_PLL1 = BIT(6),
  csi_PLL2 = BIT(7),
  csi_PLL3 = BIT(8),
  csi_LSECSS = BIT(9),
  csi_HSECSS = BIT(10),

  csi_reset = 0x0
} rcc_clockSrcInt_t;

typedef enum rcc_backupControl_e {
  bc_enableLSE = BIT(0),
  bc_LSEReady = BIT(1),
  bc_LSEBBypass = BIT(2),
  bc_LSEDriveMediumLow = BIT(3),
  bc_LSEDriveMediumHigh = BIT(4),
  bc_LSEDriveHigh = BIT(3) | BIT(4),
  bc_enableLSECSS = BIT(5),
  bc_LSECSSFailDetection = BIT(6),
  bc_RTCUseLSEClk = BIT(8),
  bc_RTCUseLSIClk = BIT(9),
  bc_RTCUseHSEClk = BIT(8) | BIT(9),
  bc_enableRTC = BIT(15),
  bc_softReset = BIT(16),

  bc_reset = 0x0
} rcc_backupControl_t;

typedef enum rcc_clockControlStat_e {
  ccs_enableLSI = BIT(0),
  ccs_LSIReady = BIT(1),

  ccs_reset = 0x0
} rcc_clockControlStat_t;

typedef enum rcc_resetAHB3_e {
  rahb3_MDMA = BIT(0),
  rahb3_DMA2D = BIT(4),
  rahb3_JPEGDec = BIT(5),
  // C1 AHB3 EN register only
  rahb3_FLIFT = BIT(8),
  rahb3_FMC = BIT(12),
  rahb3_QSPI = BIT(14),
  rahb3_SDMMC1 = BIT(16),

  // C1 AHB3 EN register only
  rahb3_DTCM1 = BIT(28),
  rahb3_DTCM2 = BIT(29),
  rahb3_ITCM = BIT(30),
  rahb3_AXISRAM = BIT(31),

  rahb3_reset = 0x0
} rcc_resetAHB3_t;

typedef enum rcc_resetAHB1_e {
  rahb1_DMA1 = BIT(0),
  rahb1_DMA2 = BIT(1),
  rahb1_ADC12 = BIT(5),
  rahb1_ART = BIT(14),
  rahb1_ETH1MAC = BIT(15),
  rahb1_ETH1TX = BIT(16),
  rahb1_ETH1RX = BIT(17),
  rahb1_USBOTGHS1 = BIT(25),
  rahb1_USB1OTGHSULPI = BIT(26),
  rahb1_USBOTGHS2 = BIT(27),
  rahb1_USB2OTGHSULPI = BIT(28),
  
  rahb1_reset = 0x0
} rcc_resetAHB1_t;

typedef enum rcc_resetAHB2_e {
  rahb2_DCMI = BIT(0),
  rahb2_CRYPT = BIT(4),
  rahb2_HASH = BIT(5),
  rahb2_RNG = BIT(6),
  rahb2_SDMMC2 = BIT(9),

  // C2 AHB2 EN register only
  rahb2_SRAM1 = BIT(29),
  rahb2_SRAM2 = BIT(29),
  rahb2_SRAM3 = BIT(29),

  rahb2_reset = 0x0
} rcc_resetAHB2_t;

typedef enum rcc_resetAHB4_e {
  rahb4_GPIOA = BIT(0),
  rahb4_GPIOB = BIT(1),
  rahb4_GPIOC = BIT(2),
  rahb4_GPIOD = BIT(3),
  rahb4_GPIOE = BIT(4),
  rahb4_GPIOF = BIT(5),
  rahb4_GPIOG = BIT(6),
  rahb4_GPIOH = BIT(7),
  rahb4_GPIOI = BIT(8),
  rahb4_GPIOJ = BIT(9),
  rahb4_GPIOK = BIT(10),
  rahb4_CRC = BIT(19),
  rahb4_BDMA = BIT(21),
  rahb4_ADC3 = BIT(24),
  rahb4_HSEM = BIT(25),

  rhab4_BKRAM = BIT(28),

  rahb4_reset = 0x0
} rcc_resetAHB4_t;

typedef enum rcc_resetAPB3_e {
  rapb3_LTDC = BIT(3),
  rapb3_DSI = BIT(4),

  rapb3_WWDG1 = BIT(6),

  rapb3_reset = 0x0
} rcc_resetAPB3_t;

typedef enum rcc_resetLowAPB1_e {
  rlapb1_TIM2 = BIT(0),
  rlapb1_TIM3 = BIT(1),
  rlapb1_TIM4 = BIT(2),
  rlapb1_TIM5 = BIT(3),
  rlapb1_TIM6 = BIT(4),
  rlapb1_TIM7 = BIT(5),
  rlapb1_TIM12 = BIT(6),
  rlapb1_TIM13 = BIT(7),
  rlapb1_TIM14 = BIT(8),
  rlapb1_LPTIM1 = BIT(9),
  rlapb1_WWDG2 = BIT(11),
  rlapb1_SPI2 = BIT(14),
  rlapb1_SPI3 = BIT(15),
  rlapb1_SPDIFRX = BIT(16),
  rlapb1_USART2 = BIT(17),
  rlapb1_USART3 = BIT(18),
  rlapb1_UART4 = BIT(19),
  rlapb1_UART5 = BIT(20),
  rlapb1_I2C1 = BIT(21),
  rlapb1_I2C2 = BIT(22),
  rlapb1_I2C3 = BIT(23),
  rlapb1_HDMICEC = BIT(27),
  rlapb1_DAC1 = BIT(29),
  rlapb1_UART7 = BIT(30),
  rlapb1_UART8 = BIT(31),

  rlapb1_reset = 0x0
} rcc_resetLowAPB1_t;

typedef enum rcc_resetHighAPB1_e {
  rhapb1_CRS = BIT(1),
  rhapb1_SWPMI = BIT(2),
  rhapb1_OPAMP = BIT(4),
  rhapb1_MDIOS = BIT(5),
  rhapb1_FDCAN = BIT(8),

  rhapb1_reset = 0x0
} rcc_resetHighAPB1_t;

typedef enum rcc_resetAPB2_e {
  rapb2_TIM1 = BIT(0),
  rapb2_TIM8 = BIT(1),
  rapb2_USART1 = BIT(4),
  rapb2_USART6 = BIT(5),
  rapb2_SPI1 = BIT(12),
  rapb2_SPI4 = BIT(13),
  rapb2_TIM15 = BIT(16),
  rapb2_TIM16 = BIT(17),
  rapb2_TIM17 = BIT(18),
  rapb2_SPI5 = BIT(20),
  rapb2_SAI1 = BIT(22),
  rapb2_SAI2 = BIT(23),
  rapb2_SAI3 = BIT(24),
  rapb2_DFSCM1 = BIT(28),
  rapb2_HRTIM = BIT(29),

  rapb2_reset = 0x0
} rcc_resetAPB2_t;

typedef enum rcc_resetAPB4_e {
  rapb4_SYSCFG = BIT(1),
  rapb4_LPUART1 = BIT(3),
  rapb4_SPI6 = BIT(5),
  rapb4_I2C4 = BIT(7),
  rapb4_LPTIM2 = BIT(9),
  rapb4_LPTIM3 = BIT(10),
  rapb4_LPTIM4 = BIT(11),
  rapb4_LPTIM5 = BIT(12),
  rapb4_COMP12 = BIT(14),
  rapb4_VREF = BIT(15),
  rapb4_RTCAPB = BIT(16),
  rapb4_SAI4 = BIT(21),

  rapb4_resetEnable = 0x10000,
  rapb4_reset = 0x0
} rcc_resetAPB4_t;

typedef enum rcc_globalControl_e {
  gc_WWDG1Reset = BIT(0),
  gc_WWDG2Reset = BIT(1),
  gc_bootCPU1 = BIT(2),
  gc_bootCPU2 = BIT(3),

  gc_reset = 0x0
} rcc_globalControl_t;

typedef enum rcc_autonomusD3_e {
  ad3_BDMA = BIT(0),
  ad3_LPUART1 = BIT(3),
  ad3_SPI6 = BIT(5),
  ad3_I2C4 = BIT(7),
  ad3_LPTIM2 = BIT(9),
  ad3_LPTIM3 = BIT(10),
  ad3_LPTIM4 = BIT(11),
  ad3_LPTIM5 = BIT(12),
  ad3_COMP12 = BIT(14),
  ad3_VREF = BIT(15),
  ad3_RTC = BIT(16),
  ad3_CRC = BIT(19),
  ad3_SAI4 = BIT(21),
  ad3_ADC3 = BIT(24),
  ad3_BKRAM = BIT(28),
  ad3_SRAM = BIT(29),

  ad3_reset = 0x0
} rcc_autonomusD3_t;

typedef enum rcc_resetStatus_e {
  rs_removeResetFlags = BIT(16),
  rs_CPU1 = BIT(17),
  rs_CPU2 = BIT(18),
  rs_D1PowerSwitch = BIT(19),
  rs_D2PowerSwitch = BIT(20),
  rs_BOR = BIT(21),
  rs_NRST = BIT(22),
  rs_POR = BIT(23),
  rs_SysRstCPU1 = BIT(24),
  rs_SysRstCPU2 = BIT(25),
  rs_CPU1IWDG = BIT(26),
  rs_CPU2IWDG = BIT(27),
  rs_WWDG1 = BIT(28),
  rs_WWDG2 = BIT(29),
  rs_D1Dstby = BIT(30),
  rs_D2Dstby = BIT(31),

  rs_reset = 0x00FE0000
} rcc_resetStatus_t;

void rcc_setupMaxSpeedMulticore();

#endif

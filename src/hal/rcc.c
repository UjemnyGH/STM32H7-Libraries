#include "rcc.h"

void rcc_setupMaxSpeedMulticore() {
  rcc->clockSrcSelectPLL = csspll_DIVMPLLClkSrcHSE;
  rcc->clockConfig = cc_selectPLL1;
}

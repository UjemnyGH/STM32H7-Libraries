#include "gpio.h"

void gpio_setupPin(gpio_t *const pIo, uint8_t pin, gpio_mode_t mode, gpio_outputType_t type, gpio_outputSpeed_t speed, gpio_pull_t pull) {
  pIo->mode &= ~(mode_mask << (2 * (pin & 0xF)));
  pIo->mode |= (mode << (2 * (pin & 0xF)));

  pIo->outputType &= ~(outputType_open << (pin & 0xF));
  pIo->outputType |= (type << (pin & 0xF));

  pIo->outputSpeed &= ~(outputSpeed_mask << (2 * (pin & 0xF)));
  pIo->outputSpeed |= (speed << (2 * (pin & 0xF)));
  
  pIo->pull &= ~(pull_mask << (2 * (pin & 0xF)));
  pIo->pull |= (pull << (2 * (pin & 0xF)));
}

void gpio_setAltFunc(gpio_t *const pIo, uint8_t pin, gpio_altFunc_t altFn) {
  if(!(pin & 0x8)) {
    pIo->altFuncLow &= ~(0xF << (4 * (pin & 0x7)));
    pIo->altFuncLow |= (altFn << (4 * (pin & 0x7)));
  }
  else {
    pIo->altFuncHigh &= ~(0xF << (4 * (pin & 0x7)));
    pIo->altFuncHigh |= (altFn << (4 * (pin & 0x7)));
  }
}

bool_t gpio_getInput(gpio_t *const pIo, uint8_t pin) {
  return (pIo->inputData & BIT(pin & 0xF)) != 0 ? btrue : bfalse;
}

void gpio_setOutput(gpio_t *const pIo, uint8_t pin, bool_t state) {
  if(!state)
    pIo->outputData &= ~BIT(pin & 0xF);
  else
    pIo->outputData |= BIT(pin & 0xF);
}

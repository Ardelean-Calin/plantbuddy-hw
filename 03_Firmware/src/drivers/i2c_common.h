#pragma once
#include <stdint.h>

void i2c_read_register8(uint8_t address, uint8_t registerAddress, uint8_t* pRxByte);
void i2c_write_register8(uint8_t address, uint8_t registerAddress, uint8_t txByte);
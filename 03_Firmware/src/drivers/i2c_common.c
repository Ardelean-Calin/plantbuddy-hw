#include "i2c_common.h"
#include "nrf_drv_twi.h"

static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(0);

void i2c_read_register8(uint8_t address, uint8_t registerAddress, uint8_t* pRxByte)
{
    /* TODO: Error detection */
    nrf_drv_twi_tx(&m_twi, address, (const uint8_t*)&registerAddress, 1, true);
    nrf_drv_twi_rx(&m_twi, address, pRxByte, 1);
}

void i2c_write_register8(uint8_t address, uint8_t registerAddress, uint8_t txByte)
{
    uint8_t transaction[] = {registerAddress, txByte};
    nrf_drv_twi_tx(&m_twi, address, (const uint8_t*)&transaction, 2, false);
}
#include "sensor.h"



void sensor::get_sensor_data(void)
{
	uint8_t i2cbuffer[7] = {0,};
    uint8_t cmd[3] = {0xAC, 0x33, 0x00};

    HAL_I2C_Master_Transmit(&hi2c2, 0x70, cmd, 3, HAL_MAX_DELAY);
    HAL_Delay(90);
    HAL_I2C_Master_Receive(&hi2c2, 0x70, i2cbuffer, 7, HAL_MAX_DELAY);
    uint32_t humid = (i2cbuffer[1] << 12) + (i2cbuffer[2] << 4) + ((i2cbuffer[3]&0xF0) >> 4);
    humid = (humid*100/1048576);
    uint32_t temp = ((i2cbuffer[3] & 0x0F) << 16) + (i2cbuffer[4] << 8) + i2cbuffer[5];
    temp = (temp*200/1048576) - 50;

    sensor::humid = (uint8_t)humid;
    sensor::temp = (uint8_t)temp;


}

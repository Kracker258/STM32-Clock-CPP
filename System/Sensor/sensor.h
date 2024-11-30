#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "main.h"

extern I2C_HandleTypeDef hi2c2;


class sensor
{

public:
	uint8_t temp;
	uint8_t humid;

	void get_sensor_data(void);
};

#endif /* __SENSOR_H__ */

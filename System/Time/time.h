#ifndef __TIME_H__
#define __TIME_H__

#include "main.h"

extern RTC_HandleTypeDef hrtc;


class time
{

public:
	uint8_t WeekDay;
	uint8_t Month;
	uint8_t Date;
	uint8_t Year;
	uint8_t Hours;
	uint8_t Minutes;
	uint8_t Seconds;
	uint8_t TimeFormat;
	uint32_t SubSeconds;
	uint32_t SecondFraction;
	uint32_t DayLightSaving;
	uint32_t StoreOperation;

	void get_time(void);
    void set_time(void);
};

#endif /* __TIME_H__ */

#include "time.h"



void time::get_time(void)
{
	RTC_TimeTypeDef stimestructureget = {0,};
	RTC_DateTypeDef sdatestructureget = {0,};

	HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);

	time::WeekDay = sdatestructureget.WeekDay;
	time::Month = sdatestructureget.Month;
	time::Date = sdatestructureget.Date;
	time::Year = sdatestructureget.Year;
	time::Hours = stimestructureget.Hours;
	time::Minutes = stimestructureget.Minutes;
	time::Seconds = stimestructureget.Seconds;
	time::TimeFormat = stimestructureget.TimeFormat;
	time::SubSeconds = stimestructureget.SubSeconds;
	time::SecondFraction = stimestructureget.SecondFraction;
	time::DayLightSaving = stimestructureget.DayLightSaving;
	time::StoreOperation = stimestructureget.StoreOperation;
}

void time::set_time(void)
{
	RTC_TimeTypeDef stimestructureget = {0,};
	RTC_DateTypeDef sdatestructureget = {0,};

	sdatestructureget.WeekDay = time::WeekDay;
	sdatestructureget.Month = time::Month;
	sdatestructureget.Date = time::Date;
	sdatestructureget.Year = time::Year;
	stimestructureget.Hours = time::Hours;
	stimestructureget.Minutes = time::Minutes;
	stimestructureget.Seconds = time::Seconds;
	stimestructureget.TimeFormat = time::TimeFormat;
	stimestructureget.SubSeconds = time::SubSeconds;
	stimestructureget.SecondFraction = time::SecondFraction;
	stimestructureget.DayLightSaving = time::DayLightSaving;
	stimestructureget.StoreOperation = time::StoreOperation;

	HAL_RTC_SetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
	HAL_RTC_SetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);
}

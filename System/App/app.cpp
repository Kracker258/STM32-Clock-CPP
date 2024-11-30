#include "app.h"

#include "main.h"
#include <string>
#include "ssd1306.h"

std::string date_map[8] {"", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};


ssd1306 oledPanel;
time date_time;
keypad key_pad;
sensor aht30;





//Main Application
void app::main(void)
{
	oledPanel.Init();
	aht30.get_sensor_data();

	//Main loop, never end
	while(1)
	{
		page_main();
		key get_key = key_pad.get_key_pressed();
		if (key::KEY_OK == get_key)
		{
			page_set_time();
		}
	}
}

void app::page_main(void)
{
	char screen_time_buff_c[20];

	//Render Main UI
	oledPanel.DrawRectangle(0, 0, 127, 63, White);
	oledPanel.DrawRectangle(94, 0, 127, 63, White);
	oledPanel.DrawRectangle(0, 24, 94, 63, White);
	oledPanel.SetCursor(4, 28);
	oledPanel.WriteString(" ---Khai--- ", Font_7x10, White);

	//Show time
	date_time.get_time();
	sprintf((char *)screen_time_buff_c, "%02d:%02d:%02d", date_time.Hours, date_time.Minutes, date_time.Seconds);
	oledPanel.SetCursor(4, 4);
	oledPanel.WriteString(screen_time_buff_c, Font_11x18, White);
	oledPanel.SetCursor(100, 4);
	oledPanel.WriteString(date_map[date_time.WeekDay].c_str(), Font_7x10, White);
	sprintf((char *)screen_time_buff_c, "%02d", date_time.Date);
	oledPanel.SetCursor(104, 14);
	oledPanel.WriteString(screen_time_buff_c, Font_7x10, White);

	if (date_time.Seconds%5 == 0)
	{
		aht30.get_sensor_data();
	}

	//Show sensor data
	sprintf((char *)screen_time_buff_c, "Temp : %02d`C ", aht30.temp);
	oledPanel.SetCursor(4, 38);
	oledPanel.WriteString(screen_time_buff_c, Font_7x10, White);
	sprintf((char *)screen_time_buff_c, "Humid: %02d%% ", aht30.humid);
	oledPanel.SetCursor(4, 48);
	oledPanel.WriteString(screen_time_buff_c, Font_7x10, White);

	oledPanel.UpdateScreen();
}

void app::page_set_time(void)
{
	uint8_t time_out = 0;
	uint8_t step = 1;
	key get_key = key::KEY_NONE;
	//Display buffer
	char screen_time_buff_c[20];

	oledPanel.ClearDisplay();
	oledPanel.DrawRectangle(0, 0, 127, 63, White);
	oledPanel.DrawRectangle(94, 0, 127, 63, White);
	oledPanel.DrawRectangle(0, 24, 94, 63, White);
	oledPanel.SetCursor(4, 28);
	oledPanel.WriteString("Time setting", Font_7x10, White);

	while(!time_out)
	{
		date_time.get_time();
		sprintf((char *)screen_time_buff_c, "%02d:%02d:%02d", date_time.Hours, date_time.Minutes, date_time.Seconds);
		oledPanel.SetCursor(4, 4);
		oledPanel.WriteString(screen_time_buff_c, Font_11x18, White);
		oledPanel.SetCursor(100, 4);
		oledPanel.WriteString(date_map[date_time.WeekDay].c_str(), Font_7x10, White);
		sprintf((char *)screen_time_buff_c, "%02d", date_time.Date);
		oledPanel.SetCursor(104, 14);
		oledPanel.WriteString(screen_time_buff_c, Font_7x10, White);
		oledPanel.UpdateScreen();

		get_key = key_pad.get_key_pressed();
		if (key::KEY_BACK == get_key)
		{
			step--;
		}
		if (key::KEY_OK == get_key)
		{
			step++;
		}
		if ((step == 8) || (step == 0))
		{
			oledPanel.ClearDisplay();
			break;
		}
		switch(step)
		{
		case 1:
			oledPanel.SetCursor(4, 38);
			oledPanel.WriteString("Hour      ", Font_7x10, White);
			if (key::KEY_UP == get_key)
			{
				date_time.Hours++;
				if (date_time.Hours == 24)
					date_time.Hours = 0;
				break;
			}
			if (key::KEY_DOWN == get_key)
			{
					if (date_time.Hours == 0)
						date_time.Hours = 24;
					date_time.Hours--;
					break;
			}
			break;
		case 2:
			oledPanel.SetCursor(4, 38);
			oledPanel.WriteString("Minutes   ", Font_7x10, White);
			if (key::KEY_UP == get_key)
			{
				date_time.Minutes++;
				if (date_time.Minutes == 60)
					date_time.Minutes = 0;
				break;
			}
			if (key::KEY_DOWN == get_key)
			{
				if (date_time.Minutes == 0)
					date_time.Minutes = 60;
				date_time.Minutes--;
				break;
			}
			break;
		case 3:
			oledPanel.SetCursor(4, 38);
			oledPanel.WriteString("Seconds   ", Font_7x10, White);
			if (key::KEY_UP == get_key)
			{
				date_time.Seconds++;
				if (date_time.Seconds == 60)
					date_time.Seconds = 0;
				break;
			}
			if (key::KEY_DOWN == get_key)
			{
				if (date_time.Seconds == 0)
					date_time.Seconds = 60;
				date_time.Seconds--;
				break;
			}
			break;
		case 4:
			oledPanel.SetCursor(4, 38);
			oledPanel.WriteString("Date      ", Font_7x10, White);
			if (key::KEY_UP == get_key)
			{
				date_time.Date++;
				if (date_time.Date == 32)
					date_time.Date = 1;
				break;
			}
			if (key::KEY_DOWN == get_key)
			{
				if (date_time.Date == 1)
					date_time.Date = 32;
				date_time.Date--;
				break;
			}
			break;
		case 5:
			oledPanel.SetCursor(4, 38);
			oledPanel.WriteString("Month     ", Font_7x10, White);
			if (key::KEY_UP == get_key)
			{
				date_time.Month++;
				if (date_time.Month == 13)
					date_time.Month = 1;
				break;
			}
			if (key::KEY_DOWN == get_key)
			{
				if (date_time.Month == 1)
					date_time.Month = 13;
				date_time.Month--;
				break;
			}
			break;
		case 6:
			oledPanel.SetCursor(4, 38);
			oledPanel.WriteString("Year      ", Font_7x10, White);
			if (key::KEY_UP == get_key)
			{
				date_time.Year++;
				break;
			}
			if (key::KEY_DOWN == get_key)
			{
				if (date_time.Year != 0)
					date_time.Year--;
				break;
			}
			break;
		case 7:
			oledPanel.SetCursor(4, 38);
			oledPanel.WriteString("WeekDay   ", Font_7x10, White);
			if (key::KEY_UP == get_key)
			{
				date_time.WeekDay++;
				if (date_time.WeekDay == 8)
					date_time.WeekDay = 1;
				break;
			}
			if (key::KEY_DOWN == get_key)
			{
				if (date_time.WeekDay == 1)
					date_time.WeekDay = 8;
				date_time.WeekDay--;
				break;
			}
			break;

		default:
			break;
		}
		//Set the time
		date_time.set_time();

	}
}

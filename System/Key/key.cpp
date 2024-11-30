#include "key.h"


key keypad::get_current_key(void)
{
	HAL_GPIO_WritePin(KEY_PAD_0_GPIO_Port, KEY_PAD_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(KEY_PAD_1_GPIO_Port, KEY_PAD_1_Pin, GPIO_PIN_SET);
	if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PAD_2_GPIO_Port, KEY_PAD_2_Pin))
	{
		return key::KEY_UP;
	}
	if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PAD_3_GPIO_Port, KEY_PAD_3_Pin))
	{
		return key::KEY_BACK;
	}
	HAL_GPIO_WritePin(KEY_PAD_0_GPIO_Port, KEY_PAD_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(KEY_PAD_1_GPIO_Port, KEY_PAD_1_Pin, GPIO_PIN_RESET);
	if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PAD_2_GPIO_Port, KEY_PAD_2_Pin))
	{
		return key::KEY_DOWN;
	}
	if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PAD_3_GPIO_Port, KEY_PAD_3_Pin))
	{
		return key::KEY_OK;
	}

	return key::KEY_NONE;
}

key keypad::get_key_pressed(void)
{
	key pressed_key = get_current_key();

	if (pressed_key == last_key_pressed)
	{
		pressed_key = key::KEY_NONE;
	}
	else
	{
		last_key_pressed = pressed_key;
	}

	return pressed_key;
}


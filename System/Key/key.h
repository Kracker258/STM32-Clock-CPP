#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

enum class key : int
{
	KEY_NONE = 0,
	KEY_BACK, KEY_OK, KEY_UP, KEY_DOWN
};

class keypad
{

private:
    key last_key_pressed = key::KEY_NONE;
public:
	key get_current_key(void);
    key get_key_pressed(void);
};


#endif /* __KEY__H__ */

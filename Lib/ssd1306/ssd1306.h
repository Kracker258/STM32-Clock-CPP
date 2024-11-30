/**
 * This Library was originally written by Olivier Van den Eede (4ilo) in 2016.
 * Some refactoring was done and SPI support was added by Aleksander Alekseev (afiskon) in 2018.
 *
 * https://github.com/afiskon/stm32-ssd1306
 */

#ifndef __SSD1306_H__
#define __SSD1306_H__

//#include <stddef.h>
//#include <_ansi.h>


#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"

#if defined(STM32WB)
#include "stm32wbxx_hal.h"
#elif defined(STM32F0)
#include "stm32f0xx_hal.h"
#elif defined(STM32F1)
#include "stm32f1xx_hal.h"
#elif defined(STM32F4)
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#elif defined(STM32L0)
#include "stm32l0xx_hal.h"
#elif defined(STM32L1)
#include "stm32l1xx_hal.h"
#elif defined(STM32L4)
#include "stm32l4xx_hal.h"
#elif defined(STM32L5)
#include "stm32l5xx_hal.h"
#elif defined(STM32F3)
#include "stm32f3xx_hal.h"
#elif defined(STM32H7)
#include "stm32h7xx_hal.h"
#elif defined(STM32F7)
#include "stm32f7xx_hal.h"
#elif defined(STM32G0)
#include "stm32g0xx_hal.h"
#elif defined(STM32G4)
#include "stm32g4xx_hal.h"
#else
#error "SSD1306 library was tested only on STM32F0, STM32F1, STM32F3, STM32F4, STM32F7, STM32L0, STM32L1, STM32L4, STM32H7, STM32G0, STM32G4, STM32WB MCU families. Please modify ssd1306.h if you know what you are doing. Also please send a pull request if it turns out the library works on other MCU's as well!"
#endif


#ifdef SSD1306_X_OFFSET
#define SSD1306_X_OFFSET_LOWER (SSD1306_X_OFFSET & 0x0F)
#define SSD1306_X_OFFSET_UPPER ((SSD1306_X_OFFSET >> 4) & 0x07)
#else
#define SSD1306_X_OFFSET_LOWER 0
#define SSD1306_X_OFFSET_UPPER 0
#endif



#if defined(SSD1306_USE_I2C)
extern I2C_HandleTypeDef SSD1306_I2C_PORT;
#elif defined(SSD1306_USE_SPI)
extern SPI_HandleTypeDef SSD1306_SPI_PORT;
#else
#error "You should define SSD1306_USE_SPI or SSD1306_USE_I2C macro!"
#endif


#ifndef SSD1306_BUFFER_SIZE
#define SSD1306_BUFFER_SIZE   SSD1306_WIDTH * SSD1306_HEIGHT / 8
#endif

// Enumeration for screen colors
typedef enum {
    Black = 0x00, // Black color, no pixel
    White = 0x01  // Pixel is set. Color depends on OLED
} SSD1306_COLOR;

typedef enum {
    SSD1306_OK = 0x00,
    SSD1306_ERR = 0x01  // Generic error.
} SSD1306_Error_t;

typedef struct {
    uint8_t x;
    uint8_t y;
} SSD1306_VERTEX;

// Procedure definitions
class ssd1306 {
private:
	uint8_t SSD1306_Buffer[SSD1306_BUFFER_SIZE];
	uint16_t PanelAddr;
    uint16_t CurrentX;
    uint16_t CurrentY;
    uint8_t IsDisplayOn;

    void WriteCommand(uint8_t byte);
    void WriteData(uint8_t* buffer, size_t buff_size);
public:
    ssd1306(uint16_t Addr = SSD1306_DEFAULT_I2C_ADDR) {
    	PanelAddr = Addr;
    	CurrentX = 0;
    	CurrentY = 0;
    	IsDisplayOn = 1;
    }
    void Reset(void);
	void Init(void);
	void Fill(SSD1306_COLOR color);
	void UpdateScreen(void);
	void ClearDisplay(void);
	void DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
	char WriteChar(char ch, FontDef Font, SSD1306_COLOR color);
	char WriteString(const char* str, FontDef Font, SSD1306_COLOR color);
	void SetCursor(uint8_t x, uint8_t y);
	void Line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color);
	void DrawArc(uint8_t x, uint8_t y, uint8_t radius, uint16_t start_angle, uint16_t sweep, SSD1306_COLOR color);
	void DrawArcWithRadiusLine(uint8_t x, uint8_t y, uint8_t radius, uint16_t start_angle, uint16_t sweep, SSD1306_COLOR color);
	void DrawCircle(uint8_t par_x, uint8_t par_y, uint8_t par_r, SSD1306_COLOR color);
	void FillCircle(uint8_t par_x,uint8_t par_y,uint8_t par_r,SSD1306_COLOR par_color);
	void Polyline(const SSD1306_VERTEX *par_vertex, uint16_t par_size, SSD1306_COLOR color);
	void DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color);
	void FillRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color);
	void DrawBitmap(uint8_t x, uint8_t y, const unsigned char* bitmap, uint8_t w, uint8_t h, SSD1306_COLOR color);
	SSD1306_Error_t FillBuffer(uint8_t* buf, uint32_t len);
	void SetContrast(const uint8_t value);
	void DisplayOn(void);
	void DisplayOff(void);
	uint8_t GetDisplayOn(void);
};

#endif // __SSD1306_H__

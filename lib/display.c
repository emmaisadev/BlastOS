#include <hardware/i2c.h>
#include <hardware/gpio.h>
#include "display.h"
#include "ssd1306/ssd1306.h"
    

static ssd1306_t displayConfig;

bool setupDisplay()
{
    // IO Setup
    gpio_set_function(DISPLAY_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(DISPLAY_SCL_PIN, GPIO_FUNC_I2C);
    
    bool screenStatus = ssd1306_init(&displayConfig, DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_ADDRESS, i2c0);

    return screenStatus;
}

void 

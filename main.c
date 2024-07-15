#include <stdlib.h>
#include <hardware/gpio.h>
#include "pinSetup.h"
#include "main.h"
#include "lib/display.h"

int main()
{
    // Initialize the microcontroller
    pinSetup();
    return EXIT_SUCCESS;
}

void pinSetup() {

    gpio_set_dir(TriggerPin, GPIO_IN);
    gpio_set_dir(MenuButtonOnePin, GPIO_IN);
    gpio_set_dir(MenuButtonTwoPin, GPIO_IN);

    gpio_set_dir(ESCOnePin, GPIO_OUT);
    gpio_set_dir(ESCTwoPin, GPIO_OUT);
    gpio_set_dir(SolenoidPin, GPIO_OUT);

    gpio_set_function(DisplaySDA, GPIO_FUNC_I2C);
    gpio_set_function(DisplaySCL, GPIO_FUNC_I2C);

}

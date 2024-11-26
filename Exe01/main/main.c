#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

#define PIN 2

void app_main(void)
{
    // gpio_pad_select_gpio(PIN); // essa função está obsoleta

    //configura o pino especificado (PIN) para funcionar como um GPIO (General Purpose Input/Output).
    esp_rom_gpio_pad_select_gpio(PIN); // essa função pode ser substituida ou omitida

    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

    bool status = 0;
    while (1)
    {
        status = !status;
        gpio_set_level(PIN, status);

        vTaskDelay(pdMS_TO_TICKS(1000));
        
    }
}
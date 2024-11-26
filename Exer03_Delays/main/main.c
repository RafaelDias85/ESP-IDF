#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

#define PIN 2

void app_main(void)
{

    esp_rom_gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);

    bool status = 0;

    while (1)
    {
        status = !status;

        gpio_set_level(PIN, status);

        vTaskDelay(pdMS_TO_TICKS(100)); // Mudar para 1 para ver o erro

        /*
        erro de delay task_wdt

        E (10315) task_wdt: Task watchdog got triggered. The following tasks/users did not reset the watchdog in time:
        E (10315) task_wdt:  - IDLE0 (CPU 0)
        E (10315) task_wdt: Tasks currently running:
        E (10315) task_wdt: CPU 0: main // task main tomando muito tempo do Processador.
        E (10315) task_wdt: CPU 1: IDLE1
        E (10315) task_wdt: Print CPU 0 (current core) backtrace
        */
    }
}
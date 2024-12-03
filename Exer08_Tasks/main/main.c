#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void Task1();
void Task2();

void app_main(void)
{
    xTaskCreate(&Task1, "Task 01", 2048, NULL, 5, NULL);
    xTaskCreate(&Task2, "Task 02", 2048, NULL, 2, NULL);
}

void Task1()
{
    while (1)
    {
        printf("Realizando leitura de temperatura \n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void Task2()
{
    while (1)
    {
        printf("Realiza leitura de umidade \n");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
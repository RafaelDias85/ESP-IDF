/*
 * FOI UTILIZADO UM POTENCIOMETRO DE 10K OHMS PARA SIMULAR O VALOR
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "esp_system.h"
#include "esp_spi_flash.h" // ESSA BIBLIOTECA ESTÁ OBSOLETA, FOI SUBSTITUIDA POR "spi_flash_mmap.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "driver/adc.h" //O driver legado para ADC foi substituído por dois novos drivers:
                        //esp_adc/adc_oneshot.h para leitura pontual.
                        //esp_adc/adc_continuous.h para leituras contínuas.

void app_main(void)
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11); // A constante ADC_ATTEN_DB_11 foi marcada como obsoleta e redirecionada
                                                                // para ADC_ATTEN_DB_12. Ambas têm o mesmo comportamento agora.

    adc2_config_channel_atten(ADC2_CHANNEL_0, ADC_ATTEN_DB_11);

    while (1)
    {
        int val1 = 0;
        int val2 = 0;

        val1 = adc1_get_raw(ADC1_CHANNEL_4);
        adc2_get_raw(ADC2_CHANNEL_0, ADC_WIDTH_BIT_12, &val2);

        printf("ADC1: %.1FV ADC2: %.1Fv \n", val1 * (3.3 / 4095), val2 * (3.3 / 4095));
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
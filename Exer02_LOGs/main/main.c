#include <stdio.h>
#include "esp_log.h"

void app_main(void)
{
    int var = 0;
    ESP_LOGE("LOG 1","LOG DE ERRO %d", var++); 
    ESP_LOGW("LOG 2","LOG DE WARNING / AVISO %d", var++);
    ESP_LOGI("LOG 3","LOG DE INFORMAÇÃO %d", var++);
    ESP_LOGD("LOG 4","LOG DE DEBUG %d", var++);
    ESP_LOGV("LOG 5","LOG DE TEXTO COMUM/VERBOSE %d", var++); 

    esp_log_level_set("LOG2", ESP_LOG_DEBUG);
    ESP_LOGE("LOG 1","LOG DE ERRO"); 
    ESP_LOGW("LOG 2","LOG DE WARNING / AVISO");
    ESP_LOGI("LOG 3","LOG DE INFORMAÇÃO");
    ESP_LOGD("LOG 4","LOG DE DEBUG");
    ESP_LOGV("LOG 5","LOG DE TEXTO COMUM/VERBOSE"); 
}
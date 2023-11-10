#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t semaforoLed_1;
SemaphoreHandle_t semaforoLed_2;
SemaphoreHandle_t semaforoSerial;

void enviarGantt(const char *item, unsigned int tInicio, unsigned int tFim) 
{
    if (xSemaphoreTake(semaforoSerial, portMAX_DELAY) == pdTRUE) 
    {
        Serial.print("\t\t");
        Serial.print(item);
        Serial.print(": ");
        Serial.print(tInicio);
        Serial.print(", ");
        Serial.println(tFim);
        xSemaphoreGive(semaforoSerial);
    }
}

void tarefaVermelho(void *parametros)
{
    unsigned int tInicio;
    const int pinoLed = 13;
    const int atraso = 5 * 1000;

    pinMode(pinoLed, OUTPUT);

    while (true)
    {
        if (xSemaphoreTake(semaforoLed_1, (TickType_t) 5) == pdTRUE)
        {
            tInicio = millis();
            digitalWrite(pinoLed, HIGH);
            vTaskDelay(atraso / portTICK_PERIOD_MS);
            digitalWrite(pinoLed, LOW);
            xSemaphoreGive(semaforoLed_1);
            enviarGantt("Led Vermelho", tInicio, millis());
            vTaskDelay(atraso / portTICK_PERIOD_MS);
        }
    }
}

void tarefaAmarelo(void *parametros)
{
    unsigned int tInicio;
    const int pinoLed = 12;
    const int atraso = 2 * 1000;

    pinMode(pinoLed, OUTPUT);

    while (true)
    {
        if (xSemaphoreTake(semaforoLed_1, (TickType_t) 5) == pdTRUE)
        {
            tInicio = millis();
            digitalWrite(pinoLed, HIGH);
            vTaskDelay(atraso / portTICK_PERIOD_MS);
            digitalWrite(pinoLed, LOW);
            xSemaphoreGive(semaforoLed_1);
            enviarGantt("Led Amarelo", tInicio, millis());
            vTaskDelay(atraso / portTICK_PERIOD_MS);
        }
    }
}

void tarefaVerde(void *parametros)
{
    unsigned int tInicio;
    const int pinoLed = 11;
    const int atraso = 4 * 1000;

    pinMode(pinoLed, OUTPUT);

    while (true)
    {
        if (xSemaphoreTake(semaforoLed_2, (TickType_t) 5) == pdTRUE)
        {
            tInicio = millis();
            digitalWrite(pinoLed, HIGH);
            vTaskDelay(atraso / portTICK_PERIOD_MS);
            digitalWrite(pinoLed, LOW);
            xSemaphoreGive(semaforoLed_2);
            enviarGantt("Led Verde", tInicio, millis());
            vTaskDelay(atraso / portTICK_PERIOD_MS);
        }
    }
}

void tarefaAzul(void *parametros)
{
    unsigned int tInicio;
    const int pinoLed = 10;
    const int atraso = 1 * 1000;

    pinMode(pinoLed, OUTPUT);

    while (true)
    {
        if (xSemaphoreTake(semaforoLed_2, (TickType_t) 5) == pdTRUE)
        {
            tInicio = millis();
            digitalWrite(pinoLed, HIGH);
            vTaskDelay(atraso / portTICK_PERIOD_MS);
            digitalWrite(pinoLed, LOW);
            xSemaphoreGive(semaforoLed_2);
            enviarGantt("Led Azul", tInicio, millis());
            vTaskDelay(atraso / portTICK_PERIOD_MS);
        }
    }
}

void setup() 
{
    Serial.begin(9600);
    Serial.println("gantt\n\tdateFormat X\n\taxisFormat %s\n\ttitle Diagrama de GANTT");

    semaforoSerial = xSemaphoreCreateMutex();
    xSemaphoreGive(semaforoSerial);

    semaforoLed_1 = xSemaphoreCreateMutex();
    xSemaphoreGive(semaforoLed_1);
    
    semaforoLed_2 = xSemaphoreCreateMutex();
    xSemaphoreGive(semaforoLed_2);

    xTaskCreate(tarefaVermelho, "Vermelho", 128, NULL, 1, NULL);
    xTaskCreate(tarefaAmarelo, "Amarelo", 128, NULL, 1, NULL);
    xTaskCreate(tarefaVerde, "Verde", 128, NULL, 1, NULL);
    xTaskCreate(tarefaAzul, "Azul", 128, NULL, 1, NULL);
}

void loop() {}
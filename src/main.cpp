#include <Arduino.h>

//Tarea de encender
void encenderTask(void * parameter)
{
    for(;;)
    {
        digitalWrite(23,HIGH);
        delay(1000);
    }
}
//Tarea de apagar
void apagarTask(void * parameter)
{
    delay(500);
    for(;;)
    {
        digitalWrite(23,LOW);
        delay(1000);
    }
}

void setup()
{
    Serial.begin(112500);
    xTaskCreate(encenderTask,"Encender Led",10000,NULL,0,NULL);
    xTaskCreate(apagarTask,"Apagar Led",10000,NULL,0,NULL);
}

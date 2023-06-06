# Práctica 3: SISTEMAS OPERATIVOS EN TIEMPO REAL (Guillem Pérez, Vadym Lakymchuk)

## Ejercicio Práctico 1

Script:

```cpp
/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter )
{
    /* loop forever */
    for(;;)
    {
        Serial.println("this is another Task");
        delay(1000);
    }
    /* delete a task when finish, this will never happen because this is infinity loop */
    vTaskDelete( NULL );
}

void setup()
{
    Serial.begin(112500);
    /* we create a new task here */
    xTaskCreate(
    anotherTask, /* Task function. */
    "another Task", /* name of task. */
    10000, /* Stack size of task */
    NULL, /* parameter of the task */
    1, /* priority of the task */
    NULL); /* Task handle to keep track of created task */
}
 
/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
    Serial.println("this is ESP32 Task");
    delay(1000);
}
```

Explicación: Crea una tarea independiente de FreeRTOS donde realiza un loop de "this is another Task" (puerto Serie) cada segundo, ademas, el loop() actua de la misma manera en paralelo de la tarea independiente.

## Ejercicio Práctico 2

```cpp
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
```

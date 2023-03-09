#include <Arduino.h>

void ledoff(void * parameter)
  {
    bool t=false;
  /* loop forever */
  for(;;){
    //if(t){
    digitalWrite(14,LOW);
    Serial.println("apagado");
    delay (500);
    }
  //  else t=true;
  //}
}

void setup()
{
  Serial.begin(112500);
  pinMode(14,OUTPUT);
  xTaskCreate(
  ledoff, 
  "apaga el led",
  10000, /* Stack size of task */
  NULL, /* parameter of the task */
  1, /* priority of the task */
  NULL); /* Task handle to keep track of created task */
}
void loop()
{
  digitalWrite(14,HIGH);
    Serial.println("encendido");

  delay(1000);

}

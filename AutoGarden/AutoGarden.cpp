#include <Arduino.h>

int relayPins[] = {5, 6, 7};
int pump = 8;
int sensorPins[] = {A0, A1, A2};
int pincount = 3;

void setup()
{
  for (int pinInit = 0; pinInit < pincount; pinInit ++)
  {
	pinMode(relayPins[pinInit], OUTPUT);
  }
  pinMode(pump, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < pincount; i ++)			//Loop runs through the array of sensors set up previously
  {
    if (analogRead(sensorPins[i]) >= 500)
    {
      digitalWrite(relayPins[i], HIGH);
      digitalWrite(pump, HIGH);
      delay(2000);
      digitalWrite(relayPins[i], LOW);
      digitalWrite(pump, LOW);
      delay(5000);
    }
    else
    {
    	digitalWrite(relayPins[i], LOW);
    	digitalWrite(pump, LOW);
    	delay(5000);
    }
  }
  //delay(6*60*60*1000ul); 					DON'T FORGET TO PUT THIS BACK TO NORMAL IN THE FINAL COPY
}

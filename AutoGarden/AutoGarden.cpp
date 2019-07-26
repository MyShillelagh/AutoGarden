#include <Arduino.h>

int relayPins[] = {5, 6, 7};
int pump = 8;
int sensorPins[] = {A0, A1, A2};
int pinCount = 3;

void setup()
{
	for (int pinInit = 0; pinInit < pinCount; pinInit ++)
	{
		pinMode(relayPins[pinInit], OUTPUT);
	}
	pinMode(pump, OUTPUT);

	Serial.begin(9600);
}

void loop()
{
	for (int i = 0; i < pinCount; i ++)			//Loop runs through the array of sensors set up previously
	{
		Serial.print("Sensor ");
		Serial.print(i+1);
		Serial.print(": ");
		Serial.println(analogRead(sensorPins[i]));
		if (analogRead(sensorPins[i]) >= 400)
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

#include <Arduino.h>

int relayPins[] = {5, 6, 7};									//Pins used to activate the valves
int pump = 8;													//Pin for water pump
int sensorPins[] = {A0, A1, A2};								//Pins used to measure moisture sensors
int pinCount = 3;												//Number of valve-sensor pairs in the system

void setup()
{
	for (int pinInit = 0; pinInit < pinCount; pinInit ++)		//Loop to designate relay pins as outputs, done to help future scaling
	{
		pinMode(relayPins[pinInit], OUTPUT);
	}
	pinMode(pump, OUTPUT);

	Serial.begin(9600);
}

void loop()
{
	for (int i = 0; i < pinCount; i ++)							//Loop runs through the array of sensors set up previously
	{
		Serial.print("Sensor ");								//Displays the current reading of each sensor in the serial monitor
		Serial.print(i+1);
		Serial.print(": ");
		Serial.println(analogRead(sensorPins[i]));
		if (analogRead(sensorPins[i]) >= 400)					//Checks moisture of soil (higher = drier), range of 285-581
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
	//delay(6*60*60*1000ul); 									//DON'T FORGET TO PUT THIS BACK TO NORMAL IN THE FINAL COPY
}

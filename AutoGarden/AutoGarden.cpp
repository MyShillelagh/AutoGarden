#include <Arduino.h>

int relay_pins[] = {5, 6, 7};
int pump = 8;
int sensor_pins[] = {A0, A1, A2};

void setup()
{
  pinMode(relay_pins[0,1,2], OUTPUT);
  pinMode(pump, OUTPUT);

  Serial.begin(9600);

  pinMode(sensor_pins[0,1,2], INPUT);
}

void loop()
{
  for (int i = 0; i <= 2; i + 1)			//Loop runs through the array of sensors set up previously
  {
    if (analogRead(sensor_pins[i]) >= 500)
    {
      digitalWrite(relay_pins[i], HIGH);
      digitalWrite(pump, HIGH);
      delay(2000);
      digitalWrite(relay_pins[i], LOW);
      digitalWrite(pump, LOW);
    }
    else
    {
    	digitalWrite(relay_pins[i], LOW);
    	digitalWrite(pump, LOW);
    }
  }
  //delay(6*60*60*1000ul); 					DON'T FORGET TO PUT THIS BACK TO NORMAL IN THE FINAL COPY
  delay(1000);
}

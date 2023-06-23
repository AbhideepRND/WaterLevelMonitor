#include <Filters.h>

float testFrequency = 50;
float windowLenght = 40.0/testFrequency;

int sensor = 0;

float intercept = -0.04;
float slope = 0.0405;
float current_volts;

unsigned long printPeriod = 1000;
unsigned long previousMills = 0;




void setup() {
Serial.begin(9600);
delay(5000);
}

void loop() 
{
RunningStatistics inputStats;
inputStats.setWindowSecs(windowLenght);

  while(true){

      sensor = analogRead(A0);
      inputStats.input(sensor);

      if((unsigned long) (millis() - previousMills) >= printPeriod){
          previousMills = millis();

          current_volts = intercept + slope * inputStats.sigma();
          current_volts = current_volts*(40.3231);

          Serial.println(current_volts);
    }
  }

}
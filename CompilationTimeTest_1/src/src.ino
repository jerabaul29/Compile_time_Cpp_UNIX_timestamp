#include <Arduino.h>


/*
  NOTE: to make a unix timestamp in Python:

  import time
  import datetime
  s = "29/03/2018 00:09:15"
  time.mktime(datetime.datetime.strptime(s, "%d/%m/%Y %H:%M:%S").timetuple())

*/

#define UNIX_TIME_OBJECTIVE 1522278000UL


void setup() {
    delay(1000);

    Serial.begin(9600);
    delay(100);
    Serial.println(F(__DATE__));
    Serial.println(F(__TIME__));

    // just to check that the right type
    const static unsigned long compile_time = COMPILE_TIME;

    Serial.print(F("Compile time: "));
    Serial.println(COMPILE_TIME);

    Serial.print(F("Objective time: "));
    Serial.println(UNIX_TIME_OBJECTIVE);  

    Serial.print(F("Seconds to objective: "));
    Serial.println(UNIX_TIME_OBJECTIVE - COMPILE_TIME);  
}

void loop() {
    // put your main code here, to run repeatedly:
}
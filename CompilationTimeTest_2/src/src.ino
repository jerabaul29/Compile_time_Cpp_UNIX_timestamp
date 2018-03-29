#include <Arduino.h>
#include "CompilationTime_original.h"
#include "GetUNIXTimestamp.h"
#include "CompilationTime.h"

void setup() {
    delay(5000);

    Serial.begin(9600);

    Serial.println();
    Serial.println(F("Summary information from __TIME__ and __DATE__"));
    Serial.println(F("Raw __DATE__"));
    Serial.println(F(__DATE__));
    Serial.println(F("Raw __TIME__"));
    Serial.println(F(__TIME__));

    Serial.println();
    Serial.println(F("Information extraction using CompilationTime.h"));
    Serial.print(F("YEAR "));
    Serial.println(__TIME_YEARS__);
    Serial.print(F("MONTH "));
    Serial.println(__TIME_MONTH__);
    Serial.print(F("DAY "));
    Serial.println(__TIME_DAYS__);
    Serial.print(F("HOUR "));
    Serial.println(__TIME_HOURS__);
    Serial.print(F("MINUTE "));
    Serial.println(__TIME_MINUTES__);
    Serial.print(F("SECOND "));
    Serial.println(__TIME_SECONDS__);
    
    Serial.println();
    Serial.println(F("UNIX timestamp from the 'broken' macro"));
    Serial.println(__TIME_UNIX__);

    Serial.println();
    Serial.println(F("UNIX timestamp from the 'fixed' macro"));
    Serial.println(UNIX_TIMESTAMP);
}

void loop() {
    
}

// __TIME_YEARS__, __TIME_MONTH__, __TIME_DAYS__, __TIME_HOURS__, __TIME_MINUTES__, __TIME_SECONDS__
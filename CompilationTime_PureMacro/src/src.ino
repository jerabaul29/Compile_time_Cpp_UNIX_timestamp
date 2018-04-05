/*
 *
 * Created: 28.03.2018
 * Author: Jean Rabault
 * 
 * Getting the UNIX timestamp in a program, using purely macros and the
 * __TIME__ compiler defined macro. CAREFUL, __TIME__ is using the
 * timezone of your computer; if your computer is not on UTC, then the
 * UNIX timestamp will not be UTC either (but in time zone of your computer).
 * To my knowledge, there is no way to get the time zone from a macro in the
 * file. Contact me if you know of a way (open an issue on the repo).
 * 
 * NOTE START: ----------------------------------------------------------
 * 
 * To make a unix timestamp in Python:
 *
 * import time
 * import datetime
 * s = "29/09/2034 00:09:15"
 * time.mktime(datetime.datetime.strptime(s, "%d/%m/%Y %H:%M:%S").timetuple())
 *
 * prints: 2043101355
 * 
 * To get the current UTC UNIX timestamp in terminal:
 * 
 * date +%s
 *
 * NOTE END : ----------------------------------------------------------
 * 
 * 
 * NOTE START: ----------------------------------------------------------
 * 
 * When I executed this code (March 29th 2018 at 20:54:14 UTC) I got the
 * serial output:
 * 
 * Raw __DATE__
 * Mar 29 2018
 * Raw __TIME__
 * 20:54:14
 * 
 * YEAR 2018
 * MONTH 3
 * DAY 29
 * HOUR 20
 * MINUTE 54
 * SECOND 14
 * 
 * UNIX timestamp 'broken'
 * 1522356854
 * 
 * UNIX timestamp 'fixed'
 * 1522356854
 *
 * NOTE END : ----------------------------------------------------------
 *
 */

#include <Arduino.h>
#include "CompilationTime_original.h"
// #include "GetUNIXTimestamp.h"
#include "CompilationTime.h"

void setup() {
    delay(500);

    Serial.begin(9600);

    Serial.println();
    Serial.println(F("Raw __DATE__"));
    Serial.println(F(__DATE__));
    Serial.println(F("Raw __TIME__"));
    Serial.println(F(__TIME__));

    Serial.println();
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
    Serial.println(F("UNIX timestamp 'broken'"));
    Serial.println(__TIME_UNIX__);

    Serial.println();
    Serial.println(F("UNIX timestamp 'fixed'"));
    Serial.println(UNIX_TIMESTAMP);
}

void loop() {
    // pass
}

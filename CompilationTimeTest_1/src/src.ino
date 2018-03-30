/*
 *
 * Created: 28.03.2018
 * Author: Jean Rabault
 * 
 * Getting the UNIX timestamp in a program using compile flag.
 * 
 * This is to be compiled with platformio, or other tool, using the following compilation
 * flag (in platformio convention, or equivalent) to define the UNIX timestamp macro:
 * 
 * build_flags = !echo "-D COMPILE_TIME="$(date +%s)"UL"
 * 
 * The build flag is set in the ../platformio.ini platformio configuration file.
 * 
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
 * NOTE END : ----------------------------------------------------------
 * 
 * 
 * NOTE START: ----------------------------------------------------------
 * 
 * When I executed this code (March 29th 2018 at 20:35:24 UTC) I got the
 * serial output:
 * 
 * __DATE__ Mar 29 2018
 * __TIME__ 20:35:24
 * 
 * Compile time        : 1522355724
 * Objective time      : 2043101355
 * Seconds to objective: 520745631
 * Years to objective (approx): 16.50
 *
 * NOTE END : ----------------------------------------------------------
 *
 */

#include <Arduino.h>

#define UNIX_TIME_OBJECTIVE 2043101355UL


void setup() {
    delay(500);

    Serial.begin(9600);
    delay(100);

    Serial.println();
    Serial.print(F("__DATE__ "));
    Serial.println(F(__DATE__));
    Serial.print(F("__TIME__ "));
    Serial.println(F(__TIME__));

    // just to check that the right type; if not, the compiler will warn about implicit cast
    const static unsigned long compile_time = COMPILE_TIME;

    Serial.println();
    Serial.print(F("Compile time        : "));
    Serial.println(COMPILE_TIME);
    Serial.print(F("Objective time      : "));
    Serial.println(UNIX_TIME_OBJECTIVE);  
    Serial.print(F("Seconds to objective: "));
    Serial.println(UNIX_TIME_OBJECTIVE - COMPILE_TIME);
    Serial.print(F("Years to objective (approx): "));
    Serial.println(((float)(UNIX_TIME_OBJECTIVE - COMPILE_TIME)) / (60.0 * 60.0 * 24.0 * 365.25));
}

void loop() {
    // pass
}
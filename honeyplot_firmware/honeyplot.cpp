#include "Arduino.h"

#include <SPI.h>
#include <SparkFunAutoDriver.h>

#include "constants.h"

AutoDriver motorAlpha(10, 6);
AutoDriver motorBeta(9, 6);

#include "support.ino"

void setup() {
    Serial.begin(9600);

    #ifdef DEBUG
        Serial.println("init");
    #endif

    dSPINConfig();
}

void loop() {
    
}
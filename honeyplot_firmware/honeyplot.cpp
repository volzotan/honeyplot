#include "Arduino.h"

#include <SPI.h>
#include <SparkFunAutoDriver.h>

#define DEBUG

#include "constants.h"

AutoDriver motorAlpha(dSPIN_ALPHA_ENABLE, dSPIN_ALPHA_RESET, dSPIN_ALPHA_BUSYN);
AutoDriver motorBeta(dSPIN_BETA_ENABLE, dSPIN_BETA_RESET, dSPIN_BETA_BUSYN);

// serial
String serialCommand = "";  

#include "support.ino"
#include "serialComm.ino"

void setup() {
    Serial.begin(9600);

    serialCommand.reserve(100);

    #ifdef DEBUG
        Serial.println(F("# init"));
    #endif

    dSPINConfig();

    //motorAlpha.run(FWD, 1000);
    //delay(300);
    //motorAlpha.hardStop();
}

void loop() {
    serialEvent();
}
#include "Arduino.h"

#include <SPI.h>
#include <SparkFunAutoDriver.h>

#define DEBUG

#include "constants.h"

AutoDriver motorAlpha(dSPIN_ALPHA_ENABLE, dSPIN_ALPHA_RESET, dSPIN_ALPHA_BUSYN);
AutoDriver motorBeta(dSPIN_BETA_ENABLE, dSPIN_BETA_RESET, dSPIN_BETA_BUSYN);

// serial
String serialCommand = "";  

// everything else
int baseline = 0;

#include "support.ino"
#include "serialComm.ino"

void setup() {
    Serial.begin(9600);

    serialCommand.reserve(100);

    #ifdef DEBUG
        Serial.println("# init");
    #endif

    dSPINConfig();

    motorAlpha.run(FWD, 200);
    delay(500);
    motorAlpha.hardStop();

    delay(10);

    motorBeta.run(REV, 200);
    delay(500);
    motorBeta.hardStop();
}

void loop() {
    serialEvent();
}
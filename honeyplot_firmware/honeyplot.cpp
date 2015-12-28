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
int millimeterToStep = 0;

int baseline    = 0;
int beltLeft    = 0;
int beltRight   = 0;

#include "support.ino"
#include "serialComm.ino"

void configure() {
    // DEBUG
    int height = 770;

    beltLeft = computeLeft(baseline/2, height);
    beltRight = computeLeft(baseline/2, height);

    baseline = 370;
    millimeterToStep = 125;
}

void setup() {
    Serial.begin(9600);

    serialCommand.reserve(100);

    #ifdef DEBUG
        Serial.println("# init");
    #endif

    dSPINConfig();
    configure();
}

void loop() {
    serialEvent();
}
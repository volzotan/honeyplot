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
int height      = 0;
int beltLeft    = 0;
int beltRight   = 0;

int homeLeft    = 0;
int homeRight   = 0;

#include "support.ino"
#include "serialComm.ino"

void configure() {
    baseline = 1000;
    height = 600 - 125; // height - height gondola

    int x = baseline/2;
    int y = height;

    beltLeft = computeLeft(x, y);
    beltRight = computeLeft(x, y);

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
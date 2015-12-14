// -------------------- Pinout -------------------- //

#define dSPIN_ALPHA_ENABLE      12  // ALPHA-CSN pin   slave-select
#define dSPIN_ALPHA_RESET       13  // STBY line         reset
#define dSPIN_ALPHA_BUSYN       14  // BSYN line         busy
#define dSPIN_ALPHA_FLAG        15  // FLAG line         flag

#define dSPIN_BETA_ENABLE       20  // BETA-CSN pin  slave-select
#define dSPIN_BETA_RESET        21  // STBY line         reset
#define dSPIN_BETA_BUSYN        22  // BSYN line         busy
#define dSPIN_BETA_FLAG         23  // FLAG line         flag

#define dSPIN_SDI                5  // SDI pin           data
#define dSPIN_SDO                6  // SDO pin           data
#define dSPIN_CLOCK              7  // CK pin            clock

#define WIZNET_ENABLE            2
#define WIZNET_INT               1
#define WIZNET_RESET             0

#define BUTTON_BACK             27 
#define BUTTON_FRONT            26

#define DISPLAY_SUPPLY          25
#define PIEZO                    3

#define BTN_ONE                 29
#define BTN_TWO                 28
#define BTN_THREE               31
#define BTN_FOUR                30

#define POTENTIOMETER_PIN       A2
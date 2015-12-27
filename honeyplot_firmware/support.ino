#define DSPIN_SPEED_MIN         330 // not used yet
#define DSPIN_SPEED_MAX         400
#define DSPIN_ACC               370
#define DSPIN_DEC               1900
#define DSPIN_KVAL_ACC          100
#define DSPIN_KVAL_DEC          100
#define DSPIN_KVAL_RUN          100
#define DSPIN_KVAL_HOLD         50

void dSPINConfig(void) {

  motorAlpha.configSyncPin(BUSY_PIN, 0);            // BUSY pin low during operations;
                                                    //  second paramter ignored.
  motorAlpha.configStepMode(STEP_SEL_1_128);        // 0 microsteps per step
  motorAlpha.setMaxSpeed(DSPIN_SPEED_MAX);          // 10000 steps/s max
  motorAlpha.setFullSpeed(700);                     // microstep below 10000 steps/s
  motorAlpha.setAcc(DSPIN_ACC);                     // accelerate at 10000 steps/s/s
  motorAlpha.setDec(DSPIN_DEC);
  motorAlpha.setSlewRate(SR_530V_us);               // Upping the edge speed increases torque.
  motorAlpha.setOCThreshold(OC_750mA);              // OC threshold 750mA
  motorAlpha.setPWMFreq(PWM_DIV_2, PWM_MUL_2);      // 31.25kHz PWM freq
  motorAlpha.setOCShutdown(OC_SD_DISABLE);          // don't shutdown on OC
  motorAlpha.setVoltageComp(VS_COMP_DISABLE);       // don't compensate for motor V
  motorAlpha.setSwitchMode(SW_USER);                // Switch is not hard stop
  motorAlpha.setOscMode(INT_16MHZ_OSCOUT_16MHZ);    // for motorAlpha, we want 16MHz
                                                    //  internal osc, 16MHz out. motorBeta and
                                                    //  boardC will be the same in all respects
                                                    //  but this, as they will bring in and
                                                    //  output the clock to keep them
                                                    //  all in phase.
  motorAlpha.setAccKVAL(DSPIN_KVAL_ACC);            // We'll tinker with these later, if needed.
  motorAlpha.setDecKVAL(DSPIN_KVAL_DEC);
  motorAlpha.setRunKVAL(DSPIN_KVAL_RUN);
  motorAlpha.setHoldKVAL(DSPIN_KVAL_HOLD);          // This controls the holding current; keep it low.
  
  
  motorBeta.configSyncPin(BUSY_PIN, 0);             // BUSY pin low during operations;
                                                    //  second paramter ignored.
  motorBeta.configStepMode(STEP_SEL_1_128);         // 0 microsteps per step
  motorBeta.setMaxSpeed(DSPIN_SPEED_MAX);           // 10000 steps/s max
  motorBeta.setFullSpeed(700);                      // microstep below 10000 steps/s
  motorBeta.setAcc(DSPIN_ACC);                      // accelerate at 10000 steps/s/s
  motorBeta.setDec(DSPIN_DEC);
  motorBeta.setSlewRate(SR_530V_us);                // Upping the edge speed increases torque.
  motorBeta.setOCThreshold(OC_750mA);               // OC threshold 750mA
  motorBeta.setPWMFreq(PWM_DIV_2, PWM_MUL_2);       // 31.25kHz PWM freq
  motorBeta.setOCShutdown(OC_SD_DISABLE);           // don't shutdown on OC
  motorBeta.setVoltageComp(VS_COMP_DISABLE);        // don't compensate for motor V
  motorBeta.setSwitchMode(SW_USER);                 // Switch is not hard stop
  motorBeta.setOscMode(INT_16MHZ_OSCOUT_16MHZ);     // for motorAlpha, we want 16MHz
                                                    //  internal osc, 16MHz out. motorBeta and
                                                    //  boardC will be the same in all respects
                                                    //  but this, as they will bring in and
                                                    //  output the clock to keep them
                                                    //  all in phase.
  motorBeta.setAccKVAL(DSPIN_KVAL_ACC);             // We'll tinker with these later, if needed.
  motorBeta.setDecKVAL(DSPIN_KVAL_DEC);
  motorBeta.setRunKVAL(DSPIN_KVAL_RUN);
  motorBeta.setHoldKVAL(DSPIN_KVAL_HOLD);           // This controls the holding current; keep it low.
}
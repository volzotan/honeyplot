void dSPINConfig(void) {

  motorAlpha.configSyncPin(BUSY_PIN, 0);            // BUSY pin low during operations;
                                                    //  second paramter ignored.
  motorAlpha.configStepMode(STEP_FS);               // 0 microsteps per step
  motorAlpha.setMaxSpeed(10000);                    // 10000 steps/s max
  motorAlpha.setFullSpeed(10000);                   // microstep below 10000 steps/s
  motorAlpha.setAcc(10000);                         // accelerate at 10000 steps/s/s
  motorAlpha.setDec(10000);
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
  motorAlpha.setAccKVAL(255);                       // We'll tinker with these later, if needed.
  motorAlpha.setDecKVAL(255);
  motorAlpha.setRunKVAL(255);
  motorAlpha.setHoldKVAL(32);                       // This controls the holding current; keep it low.
  
  
  motorBeta.configSyncPin(BUSY_PIN, 0);             // BUSY pin low during operations;
                                                    //  second paramter ignored.
  motorBeta.configStepMode(STEP_FS);                // 0 microsteps per step
  motorBeta.setMaxSpeed(10000);                     // 10000 steps/s max
  motorBeta.setFullSpeed(10000);                    // microstep below 10000 steps/s
  motorBeta.setAcc(10000);                          // accelerate at 10000 steps/s/s
  motorBeta.setDec(10000);
  motorBeta.setSlewRate(SR_530V_us);                // Upping the edge speed increases torque.
  motorBeta.setOCThreshold(OC_750mA);               // OC threshold 750mA
  motorBeta.setPWMFreq(PWM_DIV_2, PWM_MUL_2);       // 31.25kHz PWM freq
  motorBeta.setOCShutdown(OC_SD_DISABLE);           // don't shutdown on OC
  motorBeta.setVoltageComp(VS_COMP_DISABLE);        // don't compensate for motor V
  motorBeta.setSwitchMode(SW_USER);                 // Switch is not hard stop
  motorBeta.setOscMode(EXT_16MHZ_OSCOUT_INVERT);    // for motorAlpha, we want 16MHz
                                                    //  internal osc, 16MHz out. motorBeta and
                                                    //  boardC will be the same in all respects
                                                    //  but this, as they will bring in and
                                                    //  output the clock to keep them
                                                    //  all in phase.
  motorBeta.setAccKVAL(255);                        // We'll tinker with these later, if needed.
  motorBeta.setDecKVAL(255);
  motorBeta.setRunKVAL(255);
  motorBeta.setHoldKVAL(32);                        // This controls the holding current; keep it low.
}
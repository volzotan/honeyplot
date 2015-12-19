#define LINE_ENDING '\r'

void evaluateCommand() {
    if (serialCommand.length() < 1) {
        #ifdef DEBUG
            Serial.println("# error: malformed cmd");
        #endif
        return;
    }

    switch(serialCommand[0]) {
        case 'M':
            
            break;
        default:
            #ifdef DEBUG
                Serial.println("# error: unknown cmd");
            #endif
            break;
    }
}

void serialEvent() {
    char recv;

    while (Serial.available()) {
        recv = (char) Serial.read();

        Serial.println(serialCommand.length());

        if (serialCommand.length() >= 100) {
            serialCommand = "";

            #ifdef DEBUG
                Serial.println("# error: command length exceeded");
            #endif

            return;
        }

        if (recv == LINE_ENDING) {
            evaluateCommand(); 
            serialCommand = "";
        } else {
            serialCommand += recv;
        }
    }
}
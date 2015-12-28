/*

commands:

m 1234 5678         move absolute
M 1234 5678         move relative

H                   move to home
Z                   move to zero

B                   set home
N                   set zero

s                   stop
c                   check if busy

// debug commands   motor a/b 1k steps FWD/REV

q                   motor a FWD
w                   motor a REV
e                   motor b FWD
r                   motor b REV

p                   print configuration

*/

#define LINE_ENDING '\r'

long extractParam(String inp, int number) {
    // TODO: replace this function

    int first = inp.indexOf(" ");

    if (first < 0) {
        return NULL;
    }

    int second = inp.indexOf(" ", first+1);

    if (second <= first) {
        if (number == 1) {
            return inp.substring(first+1).toInt(); 
        }

        return NULL;
    }

    if (number == 1) {
        return inp.substring(first+1, second).toInt(); // to Long ...
    } else {
        return inp.substring(second+1).toInt();
    }
}

void evaluateCommand() {
    if (serialCommand.length() < 1) {
        #ifdef DEBUG
            Serial.println("# error: malformed cmd");
        #endif
        return;
    }

    switch(serialCommand[0]) {
        case 'm':
            moveAbsolute(extractParam(serialCommand, 1), extractParam(serialCommand, 2));
            break;

        case 's':
            fullStop();
            break;

        case 'q':
            Serial.println(extractParam(serialCommand, 1));
            motorAlpha.move(FWD, (extractParam(serialCommand, 1) * millimeterToStep));
            break;
        case 'w':
            motorAlpha.move(REV, (extractParam(serialCommand, 1) * millimeterToStep));
            break;
        case 'e':
            motorBeta.move(FWD, (extractParam(serialCommand, 1) * millimeterToStep));
            break;
        case 'r':
            motorBeta.move(REV, (extractParam(serialCommand, 1) * millimeterToStep));
            break;
        case 'p':
            Serial.print("# beltLeft:  "); Serial.println(beltLeft);
            Serial.print("# beltRight: "); Serial.println(beltRight);
            Serial.print("# baseline:  "); Serial.println(baseline);
            //Serial.println("# height:    " + height);
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
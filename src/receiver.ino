#include "receiver.h"

Receiver receiver;

void setup() {
    receiver.setupReceiver();
    analogWrite(9, 128); 
}

void loop() {
    
   int32_t receivedValue = receiver.readi32Receiver();  
   int pwmValue = map(receivedValue, -1000, 1000, 0, 255);
   pwmValue = constrain(pwmValue, 0, 255);
   analogWrite(9, pwmValue);
}


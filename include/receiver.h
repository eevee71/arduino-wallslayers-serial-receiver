#ifndef RECEIVER_H
#define RECEIVER_H

#include <Arduino.h>
#include "order.h"
#include "parameters.h"
#include "slave.h"

class Receiver {
public:
    Receiver();
    void setupReceiver(); 
    void getMessagesFromSerialReceiver();
    void writeOrderReceiver(enum Order order);
    void write16Receiver(int16_t num);
    void writei32Receiver(int32_t num);
    int32_t readi32Receiver();
    int16_t readi16Receiver();

private:
    bool ifConnected;
    void waitForBytesReceiver(int num_bytes, unsigned long timeout);
};

#endif // RECEIVER_H

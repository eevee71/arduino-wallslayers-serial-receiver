#include "receiver.h"

Receiver::Receiver() : ifConnected(false) {}

void Receiver::setupReceiver() {
    Serial.begin(SERIAL_BAUD); 
    ifConnected = false;
    int i = 0;
    
    while(!ifConnected || i < 30) {
        getMessagesFromSerialReceiver();
        i++;
        delay(900);
    }
 }

void Receiver::getMessagesFromSerialReceiver() {
    if(Serial.available() > 0)
    {
      Order order_received = read_order();
  
      if(order_received == HELLO) {
        if(!ifConnected) {
            ifConnected = true;
          write_order(HELLO);
        }
        else {
          write_order(ALREADY_CONNECTED);
        }
      }
      else if(order_received == ALREADY_CONNECTED) {
        ifConnected = true;
      }
      
      writeOrderReceiver(RECEIVED); 
    }
}

void Receiver::writeOrderReceiver(enum Order order) {
    write_order(order);
}

void Receiver::write16Receiver(int16_t num) {
    write_i16(num);
}

void Receiver::writei32Receiver(int32_t num) {
    write_i32(num);
}

int32_t Receiver::readi32Receiver() {
    if(ifConnected)
        return read_i32();
    return 0;
}

int16_t Receiver::readi16Receiver() {
    return read_i16();

}

void Receiver::waitForBytesReceiver(int num_bytes, unsigned long timeout) {
    wait_for_bytes(num_bytes, timeout);
}

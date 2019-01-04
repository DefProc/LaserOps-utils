/* hashDecode.ino Example sketch for IRLib2
 * Instead of decoding using a standard encoding scheme
 * (e.g. Sony, NEC, RC5), the code is hashed to a 32-bit value.
 * This should produce a unique 32-bit number however that number 
 * cannot be used to retransmit the same code. This is just a quick 
 * and dirty way to detect a unique code for controlling a device 
 * when you don't really care what protocol or values are being sent.
 * 
 *  This is an almost exact copy of the libary example original: 
 *    https://github.com/cyborg5/IRLib2/blob/master/IRLib2/examples/hashDecode/hashDecode.ino
 */

#define CPLAY_IR_RECEIVER 26 ///< IR receiver pin

//First create a decoder that just returns a 32 bit hash.
#include <IRLibDecodeBase.h> 
#include <IRLib_HashRaw.h>  //Must be last protocol
#include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal decoder
// class called "IRdecode" containing only the protocols you want.
// Now declare an instance of that decoder.
IRdecode myDecoder;

// Include a receiver either this or IRLibRecvPCI or IRLibRecvLoop
#include <IRLibRecv.h> 
IRrecv myReceiver(CPLAY_IR_RECEIVER);    //create a receiver on the CPLAY IR IN pin

void setup() {
  Serial.begin(115200);
  while (!Serial); //delay to wait for serial port to be opened
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
}

void loop() {
  if(myReceiver.getResults()) {
    myDecoder.decode();
    if(myDecoder.protocolNum==UNKNOWN) {
      Serial.print(F("IR recieved. Hash value is: 0x"));
      Serial.println(myDecoder.value,HEX);
    } else {
      myDecoder.dumpResults(false);
    };
    myReceiver.enableIRIn(); 
  }
}


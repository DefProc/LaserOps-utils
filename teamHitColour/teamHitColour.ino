/* Decode Nerf LaserOps signals and display on the Circuitplayground LEDs
 *
 * Display the team colour that "hit" the circuit playground reciver by matching
 * to a known IRLib Hash of the signal.
 */

#define CPLAY_NEOPIXELPIN 8 // neopixel pin
#define CPLAY_IR_RECEIVER 26 // IR receiver pin

// Use only HashRaw to return a 32 bit hash.
#include <IRLibDecodeBase.h>
#include <IRLib_HashRaw.h>  //Must be last protocol
#include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal decoder
// class called "IRdecode" containing only the protocols you want.
// Now declare an instance of that decoder.
IRdecode myDecoder;

// Include a receiver
#include <IRLibRecv.h>
IRrecv myReceiver(CPLAY_IR_RECEIVER);

// include the adafruit neopixel library
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, CPLAY_NEOPIXELPIN, NEO_GRB + NEO_KHZ800);

static const unsigned long ANIMATION_DELAY = 5; //ms
static const unsigned long HOLD_DELAY = 250; //ms

/* IR hashes for Nerf LaserOps standard game */
static const long PURPLE = 0x67228B44;
static const long RED = 0x78653B0E;
static const long BLUE = 0x2FFEA610;

void setup() {
  Serial.begin(115200);
  //while (!Serial); //delay to wait for serial port
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
  strip.begin();
  strip.setBrightness(64);
  strip.clear();
  strip.show();
}

void loop() {
  if(myReceiver.getResults()) {
    myDecoder.decode();
    if(myDecoder.protocolNum==UNKNOWN) {
      if (myDecoder.value == PURPLE) {
        // turn the lights purple
        Serial.println("PURPLE");
        for (int i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, 0xFF, 0x00, 0xFF);
          strip.show();
          delay(ANIMATION_DELAY);
        }
      } else if (myDecoder.value == RED ) {
        // turn the lights red
        Serial.println("RED");
        for (int i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, 0xFF, 0x00, 0x00);
          strip.show();
          delay(ANIMATION_DELAY);
        }
      } else if (myDecoder.value == BLUE) {
        // turn the lights blue
        Serial.println("BLUE");
        for (int i=0; i<strip.numPixels(); i++) {
          strip.setPixelColor(i, 0x00, 0x00, 0xFF);
          strip.show();
          delay(ANIMATION_DELAY);
        }
      }
    }
    delay(HOLD_DELAY);
    strip.clear();
    strip.show();
    myReceiver.enableIRIn();
  }
}

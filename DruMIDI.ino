/** Project Title: DruMIDI
@author Nathan Blanchard
@date 1/9/2025
@Version 1.0.0
@brief This program takes the hardware trigger and converts it into MIDI data based on the pad triggered, and the velocity of which it was triggered
at.
*/

//Import libraries
#include <MIDI.h>

// Setup variables & constants
int drumPins[8] = {A0,A1,A2,A3,A4,A5,A6,A7};
int ledPins[8];
//Map notes to pins

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  //Setup input and output pins
  for (int i=0; i<8; i++) {
    pinMode(drumPins[i],INPUT);
  }

  for (int i=0; i<8; i++) {
    ledPins[i] = i+2;
    pinMode(ledPins[i], OUTPUT);
  }

  MIDI.begin(5);
}

void loop() {
  //Check if any pads are struck
  for (int i=0; i<8; i++) {
    int val = analogRead(i);
    val = map(val,0,1024,0,12);

    if (val > 3) {
      digitalWrite(13,HIGH);
      delay(60);
      digitalWrite(13,LOW);
      
      //Send MIDI out according to note mapping
    }
  }
}

//Internal functions go here
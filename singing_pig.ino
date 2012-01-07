/*
  Singing Pig
  by Becky Stewart
  December 2011
*/

#include "pitches.h"

// pins
int ledsPin = 3;
int blackWigPin = 5;
int mohawkPin = 6;
int beehivePin = 7;
int speakerPin = 8;

// Bad Romance - 29
int brNotes[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_B3,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_D4, NOTE_C4,
  
  NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, NOTE_F4,
  NOTE_E4, NOTE_A3, NOTE_A3, NOTE_E4, NOTE_E4, 
  NOTE_F4,NOTE_E4
};

int brDurations[] = {
  8, 8, 8, 8, 3, 
  8, 8, 8, 2, 8, 
  4, 4, 3, 8, 8,
  4, 2,
  
  4, 4, 8, 8, 8,
  8, 8, 4, 8, 8, 
  8, 8
};

int brRests[] = {
  0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 
  0, 550,
  
  0, 0, 0, 0, 0,
  120, 0, 0, 0, 0,
  0, 0
};

// Super Bass - 42
int sbNotes[] = {
  NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_CS4,NOTE_DS4, 
  NOTE_CS4, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_GS3,
  NOTE_FS3,
  
  NOTE_FS3, NOTE_GS3, NOTE_B3, NOTE_CS4,NOTE_DS4, 
  NOTE_CS4, NOTE_B3, NOTE_B3, NOTE_CS4, NOTE_GS3,
  NOTE_FS3,
  
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_GS3, NOTE_FS3,
  
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_GS3, NOTE_FS3
};

int sbDurations[] = {
  8, 8, 8, 8, 4,
  4, 8, 8, 8, 4,
  4,
  
  8, 8, 8, 8, 4,
  4, 8, 8, 8, 4,
  4,
  
  8, 16, 8, 8, 8, 
  16, 8, 8, 8, 4,
  
  8, 16, 8, 8, 8, 
  16, 8, 8, 8, 4
};

int sbRests[] = {
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  300, 
  
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  200,
  
  10, 10, 10, 10, 10,
  10, 10, 10, 10, 400,
  
  10, 10, 10, 10, 10,
  10, 10, 10, 10, 0
};


// Tik Tok - 43
int ttNotes[] = {
  NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_F4, NOTE_F4, 
  
  NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, 
  NOTE_D4,
  
  NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, 
  NOTE_F4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, 
  NOTE_A4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_A4
};

int ttDurations[] = {
  4, 4, 8, 8, 4,
  8, 8, 8, 8, 8,
  8, 4, 
  
  4, 4, 8, 8, 4,
  8, 8, 8, 8, 4, 
  4,
  
  4, 4, 8, 8, 4,
  8, 8, 8, 8, 4, 
  4, 4, 6, 6, 6, 
  4, 6, 6, 6, 4
};

int ttRests[] = {
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  0, 50, 
  
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  0,
  
  0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,
  50, 50, 50, 0, 110, 
  50, 50, 50, 0, 0
};

void setup() {
 pinMode(ledsPin, OUTPUT);
 pinMode(blackWigPin, INPUT);
 pinMode(beehivePin, INPUT);
 pinMode(mohawkPin, INPUT);
 
 // startup tune
 tone(speakerPin, NOTE_C3, 300);
 delay(300);
 tone(speakerPin, NOTE_E3, 300);
 delay(300);
 tone(speakerPin, NOTE_G3, 300);
 delay(300);
 tone(speakerPin, NOTE_C4, 500);
 delay(1000);
}


void loop() {
  int blackWigValue = digitalRead(blackWigPin);
  int beehiveValue = digitalRead(beehivePin);
  int mohawkValue = digitalRead(mohawkPin);
  
  if (beehiveValue) {
    // play Tik Tok song
    for(int i=0; i<43; i++){
      digitalWrite(ledsPin, HIGH);
      int noteDuration = 2000/ttDurations[i];
      tone(speakerPin, ttNotes[i], noteDuration);
      delay(noteDuration + ttRests[i]);
    }
    // turn off eyes
    digitalWrite(ledsPin, LOW);
    // wait 4 seconds before playing again
    delay(4000);
  }
  if (mohawkValue) {
    // play Super Bass song
    for(int i=0; i<42; i++){
      digitalWrite(ledsPin, HIGH);
      int noteDuration = 2000/sbDurations[i];
      tone(speakerPin, sbNotes[i], noteDuration);
      delay(noteDuration + sbRests[i]);
    }
    // turn off eyes
    digitalWrite(ledsPin, LOW);
    // wait 4 seconds before playing again
    delay(4000);
  }
  if (blackWigValue) {
    // play Bad Romance song
    for(int i=0; i<29; i++){
      digitalWrite(ledsPin, HIGH);
      int noteDuration = 2000/brDurations[i];
      tone(speakerPin, brNotes[i], noteDuration);
      delay(noteDuration + brRests[i]);
    }
    // turn off eyes
    digitalWrite(ledsPin, LOW);
    // wait 4 seconds before playing again
    delay(4000);
  }
  
  // no wigs on
  else {
   for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
      // sets the value (range from 0 to 255):
      analogWrite(ledsPin, fadeValue);         
      // wait for 30 milliseconds to see the dimming effect    
      delay(30);                            
    } 

    // fade out from max to min in increments of 5 points:
    for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
      // sets the value (range from 0 to 255):
      analogWrite(ledsPin, fadeValue);         
      // wait for 30 milliseconds to see the dimming effect    
      delay(30);   
    }
  }
}

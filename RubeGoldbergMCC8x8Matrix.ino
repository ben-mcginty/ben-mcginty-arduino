#include "LedControl.h"

LedControl lc=LedControl(12,10,11,2);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=500;  // Delay between Frames
int triggerProbe = 3;

// Put values in arrays
byte invader1a[] =
{
   B10000001,  // M
   B11000011,
   B10100101,
   B10011001,
   B10000001,
   B10000001,
   B10000001,
   B10000001
};

byte invader1b[] =
{
  B00111111, // C
  B01000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B01000000,
  B00111111
};
byte clearPre[] =
{
   B00000000,  //clear
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};
byte fill[] =
{
  B11111111, //all on
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B11111111
};
void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  pinMode(triggerProbe, INPUT);
}


//  Take values in Arrays and Display them
void sinvader1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,invader1a[i]);
  }
}

void sinvader1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,invader1b[i]);
  }
}
void clearFinal()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,clearPre[i]);
  }
}
void filled()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,fill[i]);
  }
}

void loop()
{
  if (digitalRead(triggerProbe) == HIGH){
      // Put #1 frame on both Display
    sinvader1a();
    delay(delayTime);

// Put #2 frame on both Display
    sinvader1b();
    delay(delayTime);
    delay(delayTime);
    filled();
    delay(delayTime);
  }
  else {
    
  }
}

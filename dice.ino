int segmentPins [] = {3, 2, A5, A2, A4, 4, 5, A3};
int displayPins[] = {A1};

int buttonPin = A0;

byte digets [10] [8] = {
  { 1, 1, 1, 1, 1, 1, 0, 0}, 
  { 0, 1, 1, 0, 0, 0, 0, 0},
  { 1, 1, 0, 1, 1, 0, 1, 0},
  { 1, 1, 1, 1, 0, 0, 1, 0},
  { 0, 1, 1, 0, 0, 1, 1, 0},
  { 1, 0, 1, 1, 0, 1, 1, 0},
  { 1, 0, 1, 1, 1, 1, 1, 0},
  { 1, 1, 1, 0, 0, 0, 0, 0},
  { 1, 1, 1, 1, 1, 1, 1, 0},
  { 1, 1, 1, 1, 0, 1, 1, 0},
};

void setup() 
{
  for (int i=0; i < 8; i++)
  {
    pinMode (segmentPins [i], OUTPUT); 
  }
    pinMode(displayPins [0], OUTPUT);
    pinMode(displayPins [0], OUTPUT);
    pinMode(buttonPin,  INPUT_PULLUP);
}

 
 void loop()
{
  static int dice1;
  static int dice2;
  if (digitalRead(buttonPin) == LOW)
  {
    dice1 = random (1,7);
    dice2 = random (1,7);
  }
  updateDisplay(dice1, dice2);
}
  
void updateDisplay(int value1, int value2)
{
  digitalWrite(displayPins[0], HIGH);
  digitalWrite(displayPins[1], LOW);
  setSegments(value1);

  delay(1000);
  digitalWrite(displayPins[0],LOW);
  digitalWrite(displayPins[1],HIGH);
  setSegments (int n)
  {
    for (int i=0; i <9; i++)
    {
      digitalWrite(segmentPins[i], ! digets[n][i]);
    }
  }
}


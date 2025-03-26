#include <LedControl.h>

const int SWITCH_PIN_1 = 2;
const int SWITCH_PIN_2 = 3;
const int SWITCH_PIN_3 = 4;
const int SWITCH_PIN_4 = 5;
// Define the pins for the MAX7219 module
const int DIN_PIN = 11;
const int CS_PIN = 10;
const int CLK_PIN = 13;

// Create an instance of the LedControl library
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

void setup() {;
  // Configure the DIP switch pins as inputs
  pinMode(SWITCH_PIN_1, INPUT_PULLUP);
  pinMode(SWITCH_PIN_2, INPUT_PULLUP);
  pinMode(SWITCH_PIN_3, INPUT_PULLUP);
  pinMode(SWITCH_PIN_4, INPUT_PULLUP);

  // Set the number of devices to 1
  lc.shutdown(0, false);
  // Set the brightness to maximum
  lc.setIntensity(0, 15);
  // Clear the display
  lc.clearDisplay(0);
}

void loop() {
  int switchState1 = !digitalRead(SWITCH_PIN_1);
  int switchState2 = !digitalRead(SWITCH_PIN_2);
  int switchState3 = !digitalRead(SWITCH_PIN_3);
  int switchState4 = !digitalRead(SWITCH_PIN_4);

  // Concatenate the switch states into a binary string
  String binaryValue = String(switchState1) + String(switchState2) + String(switchState3) + String(switchState4);

  // Define the byte array

  byte char0[] = {B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110};
  byte char1[] = {B00110000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00100000};
  byte char2 [] = {B01111100,
    B01000100,
    B01000000,
    B01000000,
    B01111100,
    B00000100,
    B00000100,
    B01111100};
  byte char3 [] = {B01111100,
    B01000000,
    B01000000,
    B01111100,
    B01000000,
    B01000000,
    B01000000,
    B01111100};
  byte char4[] = {B00000100,
    B00000100,
    B01000100,
    B01000100,
    B01111100,
    B01000000,
    B01000000,
    B01000000};
  byte char5[] = {B01111100,
    B01000100,
    B00000100,
    B00000100,
    B01111100,
    B01000000,
    B01000000,
    B01111100};
  byte char6[] = {B00111110,
    B00100010,
    B00000010,
    B00000010,
    B01111110,
    B01000010,
    B01000010,
    B01111110};
  byte char7[] = {B01111110,
    B00100010,
    B00010000,
    B00001000,
    B00000100,
    B00000010,
    B00000010,
    B00000000};
  byte char8[] = {B01111110,
    B01000010,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01111110};
  byte char9[] = {B01111110,
    B01000010,
    B01000010,
    B01111110,
    B01000000,
    B01000000,
    B01000010,
    B01111110};
  byte letterA[] = {
    B00011000,
    B00100100,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B00000000};
  byte letterB[] = {B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01111110};
  byte letterC[] = {B01111110,
    B01100010,
    B00000010,
    B00000010,
    B00000010,
    B00000010,
    B01000010,
    B01111110};
  byte letterD [] = {B00111110,
    B00100010,
    B00100010,
    B00100010,
    B00100010,
    B00100010,
    B00100010,
    B00111110};
  byte letterE [] = {B01111110,
    B01000010,
    B00000010,
    B00000010,
    B01111110,
    B00000010,
    B01000010,
    B01111110};
  byte letterF[] = {B01111110,
    B01000010,
    B00000010,
    B00000010,
    B01111110,
    B00000010,
    B00000010,
    B00000010};

  if(binaryValue == "0000")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char0[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "0001")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char1[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "0010")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char2[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "0011")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char3[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "0100")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char4[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "0101")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char5[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "0110")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char6[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "0111")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char7[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1000")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char8[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1001")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, char9[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1010")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, letterA[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1011")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, letterB[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1100")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, letterC[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1101")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, letterD[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1110")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, letterE[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
  else if(binaryValue == "1111")
  {
    for (int i = 0; i < 8; i++) 
    {
      lc.setRow(0, i, letterF[i]);
    }

  // Wait for 1 second
    delay(1000);

  // Clear the display
    lc.clearDisplay(0);
  }
}
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// Define pushbutton pin
const int buttonPin = 2;
// Set up the interrupt flag and symbol index
volatile bool interruptFlag = false;
int symbolIndex = 0;

// Define the symbols to display
const byte symbols[] = {
  179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 
  189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 
  199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 
  209, 210, 211, 212, 213, 214, 215, 216, 217
};

void setup() {
  // Set up the LCD
  lcd.begin(16, 2);
  
  // Set up the pushbutton as an input
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Attach the interrupt handler to the pushbutton
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING);
}

void loop() {
  // If the interrupt flag is set, update the LCD display
  if (interruptFlag) {
    // Clear the interrupt flag
    interruptFlag = false;
    
    // Display the symbol at the current index
    lcd.clear();
    lcd.print((char)symbols[symbolIndex]);
    
    // Increment the index, wrapping around if necessary
    symbolIndex = (symbolIndex + 1) % sizeof(symbols);
  }
}

void handleInterrupt() {
  // Set the interrupt flag
  interruptFlag = true;
}
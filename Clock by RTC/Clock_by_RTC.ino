#include <Wire.h>
#include <LiquidCrystal.h>
#include <RTClib.h>

// Define the RTC and LCD objects
RTC_DS1307 rtc;
LiquidCrystal lcd(12, 11,10,9,8,7);


// Define the variables for the clock and calendar
int hour, minute, second;
int day, month, year;

void setup() 
{
  // Start the RTC and LCD
  rtc.begin();
  lcd.begin(16, 2);

  // Set the cursor position on the LCD
  lcd.setCursor(0, 0);

  // Turn on the backlight and set the brightness
  pinMode(6, OUTPUT);
  analogWrite(6, 200);
}

void loop() 
{
  // Get the current time from the RTC
  DateTime now = rtc.now();
  hour = now.hour();
  minute = now.minute();
  second = now.second();

  // Get the current date from the RTC
  day = now.day();
  month = now.month();
  year = now.year() ; 

  // Display the time and date on the LCD
  lcd.print(hour);
  lcd.print(":");
  lcd.print(minute);
  lcd.print(":");
  lcd.print(second);
  lcd.setCursor(0, 1); // Set the cursor to the second row
  lcd.print(month);
  lcd.print("/");
  lcd.print(day);
  lcd.print("/");
  lcd.print(year);

  // Wait for one second
  delay(1000);

  // Clear the LCD screen
  lcd.clear();

  // Set the cursor position on the LCD
  lcd.setCursor(0, 0);
}
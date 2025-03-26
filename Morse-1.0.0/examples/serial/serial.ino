#include <Arduino.h>
#include <string.h>

String alphabetMorseCodes[26] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

String digitMorseCodes[10] = {
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----."  // 9
};

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
    char ch = char(Serial.read());
    ch =  toupper(ch);

    if(ch >= 65 && ch <=90)
    {
      for(int i = 0; i < alphabetMorseCodes[int(ch) - 65].length(); i++)
      {
        if(alphabetMorseCodes[int(ch) - 65][i] == '-')
        {
          Serial.println("- executed");
          digitalWrite(13, 1);
          delay(1500);
          digitalWrite(13, 0);
          delay(500);
        }
        else if(alphabetMorseCodes[int(ch) - 65][i] == '.')
        {
          Serial.println(". executed");
          digitalWrite(13,1);
          delay(900);
          digitalWrite(13, 0);
          delay(500);
        }
      }
    }
    else if(ch >= 48 && ch <=57)
    {
      for(int i = 0; i < digitMorseCodes[int(ch) - 48].length(); i++)
      {
        if(digitMorseCodes[int(ch) - 48][i] == '-')
        {
          Serial.println("- executed");
          digitalWrite(13, 1);
          delay(1500);
          digitalWrite(13, 0);
          delay(500);
        }
        else if(digitMorseCodes[int(ch) - 48][i] == '.')
        {
          Serial.println(". executed");
          digitalWrite(13,1);
          delay(900);
          digitalWrite(13, 0);
          delay(500);
        }
      }
    }
  }

}
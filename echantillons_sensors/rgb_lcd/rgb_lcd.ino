#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();   
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("  Hello, world! ");
//  lcd.autoscroll();
}


void loop()
{
  for (int i = 0; i < 16; i++){
  lcd.scrollDisplayLeft();
  delay(800);
  }
  for (int i = 0; i < 16; i++){
  lcd.scrollDisplayRight();
  delay(800);
  }
}

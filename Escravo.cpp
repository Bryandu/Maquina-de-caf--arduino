#include <LiquidCrystal.h>
#include <Wire.h>

#define SRCADDR 0x02

byte cafe = 0;
LiquidCrystal lcd(
  12, 11, 10, 7, 6, 5, 4
);

void setup()
{
  Wire.begin(SRCADDR);
  Wire.onReceive(Console);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Aceita um cafe?");
}

void Console(int lendo){
  cafe = Wire.read();
  switch(cafe){
    case 1 :
    	lcd.clear();
      	lcd.print("Preparando o seu");
      	lcd.setCursor(0, 1);
      	lcd.print("cafe...");
    	break;
    case 2 :
    	lcd.clear();
    	lcd.print("Misturando...");
    	break;
    case 3 :
    	lcd.clear();
   		lcd.print("O seu cafe esta");
    	lcd.setCursor(0, 1);
    	lcd.print("pronto.");
    	break;
    case 4 :
    	lcd.clear();
    	lcd.print("Cafe acabou.");
    	break;
    case 5 :
    	setup();
    	break;
    case 6 : 
    	lcd.clear();
   		lcd.print("Coloque um copo");
    	lcd.setCursor(0, 1);
    	lcd.print("e aperte de novo");
    default : 
    	false;
  }
  
}
  

void loop()
{
  delay(100);
}

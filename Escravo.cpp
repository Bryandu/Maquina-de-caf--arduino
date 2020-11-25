#include <LiquidCrystal.h>
#include <Wire.h>


#define SRCADDR 0x02

int cafe = 0;
bool cafeOff = false;
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
  if(cafe == 1){
    lcd.clear();
    lcd.print("Preparando o seu");
    lcd.setCursor(0, 1);
    lcd.print("cafe...");
  }
  if(cafe == 2){
    lcd.clear();
    lcd.print("Misturando...");
  }
  if(cafe == 3){
    lcd.clear();
    lcd.print("O seu cafe esta");
    lcd.setCursor(0, 1);
    lcd.print("pronto.");
  }if(cafe == 4){
    lcd.clear();
    lcd.print("Cafe acabou.");
  }if(cafe == 5){
    setup();
  }
  
}
  

void loop()
{
  delay(100);
}
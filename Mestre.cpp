#include <Wire.h>

#define LED 2
#define BTN 4
#define BIP 8
#define SRCADDR 0x01
#define DSTADDR 0x02

int CONT = 0;
int FREQ = 4000;


void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  pinMode(BIP, OUTPUT);
  Serial.begin(9600);
  Wire.begin(SRCADDR);
  attachInterrupt(digitalPinToInterrupt(LED), Vazio, RISING);
}

void Vazio(){
   Wire.beginTransmission(DSTADDR);
   Wire.write(4);
   Wire.endTransmission();
   Serial.println("Tanque de agua vazio");
}

void CafeLeite()
{
  Serial.println("Colocando po de cafe");
  delay(1000);
  Serial.println("Colocando leite em po");
  delay(1000);
}
void Agua()
{
  Serial.println("Colocando agua quente");
  delay(3000);
}

void loop()
{
  while(CONT < 2){
    if(digitalRead(BTN) == HIGH){
        Wire.beginTransmission(DSTADDR);
        Wire.write(1);
      	Wire.endTransmission();
      	delay(500);
    	CONT++;
      	CafeLeite();
      	Wire.beginTransmission(DSTADDR);
        Wire.write(2);
      	Wire.endTransmission();
      	Agua();
        Wire.beginTransmission(DSTADDR);
   		Wire.write(3);
      	Wire.endTransmission();
      	tone(BIP, FREQ, 3);
      	Serial.println("Cafe com leite pronto.");
      if(CONT < 2){
        delay(1000);
        Wire.beginTransmission(DSTADDR);
        Wire.write(5);
        Wire.endTransmission();
      }
      if(CONT == 2){
         delay(1000);
         Vazio();
      }
      	delay(500);
  	}
  }
  digitalWrite(LED, HIGH);
}
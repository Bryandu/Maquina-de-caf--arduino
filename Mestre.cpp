#include <Wire.h>

#define LED 2
#define BTNC 4
#define BTNL 3
#define BIP 8
#define SRCADDR 0x01
#define DSTADDR 0x02
#define TRIG 7
#define ECHO 6

byte CONT = 0;
int FREQ = 4000;
int DISTANCIA = 0;
float TEMPO = 0.000340;
float TEMPOECHO = 0;
bool COPO = false;
bool STADEBTN = false;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BTNC, INPUT);
  pinMode(BTNL, INPUT);
  pinMode(BIP, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
  Wire.begin(SRCADDR);
}

void Distancia()
{
  TEMPOECHO = pulseIn(ECHO, HIGH);
  DISTANCIA = (((TEMPOECHO * TEMPO) / 2) * 100);
  Serial.println(COPO);
  if (DISTANCIA < 6)
  {
    COPO = true;
  }
  else
  {
    COPO = false;
  }
  delay(100);
}

void Disparo()
{
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}

void Vazio()
{
  Wire.beginTransmission(DSTADDR);
  Wire.write(4);
  Wire.endTransmission();
  Serial.println("Tanque de agua vazio");
}

void CafeLeite()
{
  Wire.beginTransmission(DSTADDR);
  Wire.write(7);
  Wire.endTransmission();
  Serial.println("Colocando po de cafe");
  delay(2000);
  Serial.println("Colocando leite em po");
  delay(2000);
}

void Cafe()
{
  Wire.beginTransmission(DSTADDR);
  Wire.write(1);
  Wire.endTransmission();
  Serial.println("Colocando po de cafe");
  delay(2000);
}

void Agua()
{
  Wire.beginTransmission(DSTADDR);
  Wire.write(2);
  Wire.endTransmission();
  Serial.println("Colocando agua quente");
  delay(5000);
}

void Pronto()
{
  Wire.beginTransmission(DSTADDR);
  Wire.write(3);
  Wire.endTransmission();
  tone(BIP, FREQ, 3);
  Serial.println("Cafe com leite pronto.");
  while (COPO)
  {
    Disparo();
    Distancia();
    delay(100);
  }
  if (!COPO)
  {
    Wire.beginTransmission(DSTADDR);
    Wire.write(5);
    Wire.endTransmission();
  }
}

void Cont()
{
  if (CONT < 2)
  {
    delay(1000);
    Wire.beginTransmission(DSTADDR);
    Wire.write(5);
    Wire.endTransmission();
  }

  if (CONT == 2)
  {
    delay(1000);
    Vazio();
  }

  delay(500);
}

void loop()
{

  while (CONT < 2)
  {
    if (digitalRead(BTNC) == HIGH)
    {
      delay(100);
      Disparo();
      Distancia();
      if (!COPO)
      {
        Wire.beginTransmission(DSTADDR);
        Wire.write(6);
        Wire.endTransmission();
      }
      if (COPO)
      {
        CONT++;
        Cafe();
        Agua();
        Pronto();
        Cont();
      }
    }

    if (digitalRead(BTNL) == HIGH)
    {
      delay(100);
      Disparo();
      Distancia();
      if (!COPO)
      {
        Wire.beginTransmission(DSTADDR);
        Wire.write(6);
        Wire.endTransmission();
      }
      if (COPO)
      {
        CONT++;
        CafeLeite();
        Agua();
        Pronto();
        Cont();
      }
    }
  }

  digitalWrite(LED, HIGH);
}
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16, 2);

int g_sw = 3;

void setup() {
  pinMode(g_sw, OUTPUT);

  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  int h = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);

  if(h > 55) {
    digitalWrite(3, HIGH);
    lcd.print("sw on");
  }
  else {
    digitalWrite(3, LOW);
    lcd.print("sw off"); 
  }
  delay(500);
}

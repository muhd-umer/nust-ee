#include "DHT.h"
#include "LiquidCrystal.h"

#define DHTPIN 28     // Pin connected to DHT11
#define DHTTYPE DHT11 // DHT 11
#define BUZZER 29

const int rs = 22, en = 23, d4 = 24, d5 = 25, d6 = 26, d7 = 27;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPIN, DHTTYPE);

float temperature = 0;

void clearLCDLine(int line)
{
    pinMode(DHTPIN, INPUT);
    pinMode(BUZZER, OUTPUT);
    lcd.setCursor(0, line);
    for (int n = 0; n < 16; n++)
    {
        lcd.print(" ");
    }
}

void setup()
{
    Serial.begin(9600);
    Serial.println("DHT11 Temperature Sensor");
    lcd.begin(16, 2);
    lcd.print("DHT11 Sensor");
    dht.begin();
}

void loop()
{
    delay(2000);
    digitalWrite(BUZZER, LOW);
    clearLCDLine(1);
    temperature = dht.readTemperature();
    if (temperature >= 35)
    {
        digitalWrite(BUZZER, HIGH);
    }
    lcd.setCursor(0, 1);
    String temperature_str = "Value: ";
    String lcd_str = temperature_str + temperature + " C";
    lcd.print(lcd_str);
    lcd.print((char)223);
    Serial.println(lcd_str);
}
# 1 "d:\\NUST\\Semester 5\\Instrumentation and Measurements\\Labs\\Lab 4\\main_sensor.ino"
# 2 "d:\\NUST\\Semester 5\\Instrumentation and Measurements\\Labs\\Lab 4\\main_sensor.ino" 2
# 3 "d:\\NUST\\Semester 5\\Instrumentation and Measurements\\Labs\\Lab 4\\main_sensor.ino" 2





const int rs = 22, en = 23, d4 = 24, d5 = 25, d6 = 26, d7 = 27;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(28 /* Pin connected to DHT11*/, DHT11 /* DHT 11*/);

float temperature = 0;

void clearLCDLine(int line)
{
    pinMode(28 /* Pin connected to DHT11*/, 0x0);
    pinMode(29, 0x1);
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
    digitalWrite(29, 0x0);
    clearLCDLine(1);
    temperature = dht.readTemperature();
    if (temperature >= 35)
    {
        digitalWrite(29, 0x1);
    }
    lcd.setCursor(0, 1);
    String temperature_str = "Value: ";
    String lcd_str = temperature_str + temperature + " C";
    lcd.print(lcd_str);
    lcd.print((char)223);
    Serial.println(lcd_str);
}

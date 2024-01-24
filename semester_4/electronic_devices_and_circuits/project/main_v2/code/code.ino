// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int m;
int g;
int s;

void setup()
{
    lcd.begin(20,4);
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(9, INPUT);
    pinMode(8, INPUT);
    pinMode(7, INPUT);
    lcd.setCursor(0,0);
    lcd.print("  Security System");
}

void loop()
{
    // put your main code here, to run repeatedly:
    m = digitalRead(9);
    g = digitalRead(8);
    s = digitalRead(7);

    if (m == 0 && g == 0 && s == 0){
        lcd.setCursor(0,1);  
        lcd.print("Motion not detected.");
        lcd.setCursor(0,2);  
        lcd.print("Gas not detected.   ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke not detected. ");
    }
    else if (m == 1 && g == 0 && s == 0){
        lcd.setCursor(0,1);  
        lcd.print("Motion detected.    ");
        lcd.setCursor(0,2);  
        lcd.print("Gas not detected.   ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke not detected. ");
    }
    else if (m == 0 && g == 1 && s == 0){
        lcd.setCursor(0,1);  
        lcd.print("Motion not detected.");
        lcd.setCursor(0,2);  
        lcd.print("Gas detected.       ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke not detected. ");
    }
    else if (m == 0 && g == 0 && s == 1){
        lcd.setCursor(0,1);  
        lcd.print("Motion not detected.");
        lcd.setCursor(0,2);  
        lcd.print("Gas not detected.   ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke detected.     ");
    }
    else if (m == 1 && g == 1 && s == 0){
        lcd.setCursor(0,1);  
        lcd.print("Motion detected.    ");
        lcd.setCursor(0,2);  
        lcd.print("Gas detected.       ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke not detected. ");
    }
    else if (m == 1 && g == 0 && s == 1){
        lcd.setCursor(0,1);  
        lcd.print("Motion detected.    ");
        lcd.setCursor(0,2);  
        lcd.print("Gas not detected.   ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke detected.     ");
    }
    else if (m == 0 && g == 1 && s == 1){
        lcd.setCursor(0,1);  
        lcd.print("Motion not detected.");
        lcd.setCursor(0,2);  
        lcd.print("Gas detected.       ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke detected.     ");
    }
    else if (m == 1 && g == 1 && s == 1){
        lcd.setCursor(0,1);  
        lcd.print("Motion detected.    ");
        lcd.setCursor(0,2);  
        lcd.print("Gas detected.       ");
        lcd.setCursor(0,3);  
        lcd.print("Smoke detected.     ");
    }
}

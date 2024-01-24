int a;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(7, INPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    a = digitalRead(7);

    if (a == 1) {
        Serial.println("Motion detected.");
    }

    else {
        Serial.println("Motion not detected.");
    }
}

#define sensorPin A0
#define ledPin A1
int gasIntensity; // analog reading (0-5V) from the sensor
int threshold = 470;

void setup()
{
    pinMode(sensorPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600); // sets the serial port to 9600
    Serial.println("Initializing gas sensor!");
}

void loop()
{
    gasIntensity = analogRead(sensorPin); // read analog input pin 0

    Serial.print("Sensor Value: ");
    Serial.print(gasIntensity);

    if (gasIntensity > threshold)
    {
        Serial.print("  Smoke detected!");
        analogWrite(ledPin, 255); // turns LED on
    }

    Serial.println(""); // print null and move to next line
    delay(200);
    analogWrite(ledPin, 0); // turns LED off
}
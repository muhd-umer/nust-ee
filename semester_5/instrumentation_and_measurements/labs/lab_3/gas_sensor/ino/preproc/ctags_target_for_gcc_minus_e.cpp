# 1 "d:\\NUST\\Semester 5\\Instrumentation and Measurements\\Labs\\Lab 3\\gas_sensor.ino"


int gasIntensity; // analog reading (0-5V) from the sensor
int threshold = 470;

void setup()
{
    pinMode(A0, 0x0);
    pinMode(A1, 0x1);
    Serial.begin(9600); // sets the serial port to 9600
    Serial.println("Initializing gas sensor!");
}

void loop()
{
    gasIntensity = analogRead(A0); // read analog input pin 0

    Serial.print("Sensor Value: ");
    Serial.print(gasIntensity);

    if (gasIntensity > threshold)
    {
        Serial.print("  Smoke detected!");
        analogWrite(A1, 255); // turns LED on
    }

    Serial.println(""); // print null and move to next line
    delay(200);
    analogWrite(A1, 0); // turns LED off
}

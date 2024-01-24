void setup() {
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);

  digitalWrite(22, HIGH); // LSB
  digitalWrite(23, HIGH);
  digitalWrite(24, LOW);
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);  // MSB

  digitalWrite(48, HIGH);  // LSB
  digitalWrite(49, LOW);
  digitalWrite(50, LOW);
  digitalWrite(51, LOW);
  digitalWrite(52, LOW);
  digitalWrite(53, LOW);  // MSB

  pinMode(37, OUTPUT); // Add or Subtract
  digitalWrite(37, HIGH);  // 0 for ADD and 1 for SUB
  
}

void loop() 
{
}

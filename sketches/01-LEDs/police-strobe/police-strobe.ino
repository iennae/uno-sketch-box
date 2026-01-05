void setup() {
  pinMode(8, OUTPUT);  // Red
  pinMode(12, OUTPUT); // Blue
  pinMode(10, OUTPUT); // Green
  pinMode(11, OUTPUT); // Green
}

void loop() {
  // Rapid Red flash
  for(int i=0; i<3; i++) {
    digitalWrite(8, HIGH); delay(40); digitalWrite(8, LOW); delay(40);
  }
  // Rapid Blue flash
  for(int i=0; i<3; i++) {
    digitalWrite(12, HIGH); delay(40); digitalWrite(12, LOW); delay(40);
  }
}

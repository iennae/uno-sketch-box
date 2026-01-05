int pins[] = {8, 12, 11, 10}; // Order: Red, Blue, Green, Green

void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  for(int i = 0; i < 4; i++) {
    digitalWrite(pins[i], HIGH);
    delay(300); // Slower so you can see it move
    digitalWrite(pins[i], LOW);
  }
  for(int i = 2; i > 0; i--) { // Bounces back
    digitalWrite(pins[i], HIGH);
    delay(300);
    digitalWrite(pins[i], LOW);
  }
}

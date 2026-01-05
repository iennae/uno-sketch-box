int pins[] = {8, 10, 11, 12};

void setup() {
  for(int i = 0; i < 4; i++) pinMode(pins[i], OUTPUT);
}

void loop() {
  for (int count = 0; count < 16; count++) {
    for (int bit = 0; bit < 4; bit++) {
      digitalWrite(pins[bit], (count >> bit) & 0x01);
    }
    delay(1000); // Wait 1 second before the next number
  }
}

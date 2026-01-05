int pins[] = {8, 10, 11, 12};

void setup() {
  // This reads static noise from Pin A0 to randomize the list
  randomSeed(analogRead(0)); 
  
  for(int i = 0; i < 4; i++) pinMode(pins[i], OUTPUT);
  
  // Visual "Spin" effect
  for(int i = 0; i < 25; i++) {
    digitalWrite(pins[i % 4], HIGH);
    delay(40 + (i * 7)); // Gets slower and slower
    digitalWrite(pins[i % 4], LOW);
  }
  
  // Pick the random winner
  int winner = pins[random(0, 4)];
  digitalWrite(winner, HIGH); 
}

void loop() {
  // Winner stays lit!
}

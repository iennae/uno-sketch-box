int redValue, greenValue, blueValue;
unsigned long lastPrintTime = 0;

#define RED 8
#define GREEN 11
#define BLUE 9
#define YELLOW 10
#define delayTime 15

void setup() {
  Serial.begin(115200);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop() {
  // Red to Green (YELLOW ZONE)
  for (int i = 0; i <= 255; i++) {
    redValue = 255 - i;
    greenValue = i;
    blueValue = 0;
    updateLEDs();
    delay(delayTime);
  }
  // Green to Blue
  for (int i = 0; i <= 255; i++) {
    greenValue = 255 - i;
    blueValue = i;
    redValue = 0;
    updateLEDs();
    delay(delayTime);
  }
  // Blue to Red
  for (int i = 0; i <= 255; i++) {
    blueValue = 255 - i;
    redValue = i;
    greenValue = 0;
    updateLEDs();
    delay(delayTime);
  }
}

void updateLEDs() {
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);

  // Simplified Yellow: If both R and G are above 0, Yellow glows.
  int yellowBright = (redValue < greenValue) ? redValue : greenValue;
  analogWrite(YELLOW, yellowBright);

  if (millis() - lastPrintTime > 30) {
    Serial.print("Red");
    Serial.print(redValue);
    Serial.print(",");
    Serial.print("Green");
    Serial.print(greenValue);
    Serial.print(",");
    Serial.print("Blue");
    Serial.print(blueValue);
    Serial.print(",");

    // Add +5 to Yellow so the line is visible
    Serial.print("Yellow LED:");
    Serial.println(yellowBright + 5);

    lastPrintTime = millis();
  }
}

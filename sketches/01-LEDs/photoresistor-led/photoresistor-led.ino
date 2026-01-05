int redValue, greenValue, blueValue;
#define RED 8
#define GREEN 11  
#define BLUE 9    
#define YELLOW 10
#define SENSOR_PIN A0

void setup() {
  Serial.begin(115200); 
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop() {
  int lightLevel = analogRead(SENSOR_PIN);

  // MAP the light level to a color transition
  // Bright (1023) -> Blue
  // Medium -> Green/Yellow
  // Dark (0) -> Red
  
  if (lightLevel > 600) {
    // Bright: Fade from Green to Blue
    blueValue = map(lightLevel, 600, 1023, 0, 255);
    greenValue = 255 - blueValue;
    redValue = 0;
  } 
  else {
    // Dark: Fade from Red to Green (This is our Yellow Zone!)
    greenValue = map(lightLevel, 0, 600, 0, 255);
    redValue = 255 - greenValue;
    blueValue = 0;
  }

  updateLEDs();
  delay(20); 
}

void updateLEDs() {
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);

  int yellowBright = (redValue < greenValue) ? redValue : greenValue;
  if (blueValue > 50) yellowBright = 0; // Keep yellow for dark/warm tones only
  
  analogWrite(YELLOW, yellowBright);

  Serial.print("Light_Sensor:"); Serial.print(analogRead(SENSOR_PIN) / 4); // Scaled for graph
  Serial.print(",Red:");         Serial.print(redValue);
  Serial.print(",Green:");       Serial.print(greenValue);
  Serial.print(",Blue:");        Serial.print(blueValue);
  Serial.print(",Yellow:");      Serial.println(yellowBright + 5);
}

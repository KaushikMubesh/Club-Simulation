int red = 2;
int yellow = 3;
int green = 4;
int pedestrian = 5;   // Pedestrian light
int switchPin = 6;    // Switch pin

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pedestrian, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {
    // Pedestrian mode
    digitalWrite(red, HIGH);      // Red ON during pedestrian crossing
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);

    // Blink pedestrian light 5 times
    for (int i = 0; i < 5; i++) {
      digitalWrite(pedestrian, HIGH);
      delay(500);
      digitalWrite(pedestrian, LOW);
      delay(500);
    }
  } else {
    // Normal traffic cycle
    digitalWrite(red, HIGH);
    delay(3000);
    digitalWrite(red, LOW);

    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);

    digitalWrite(green, HIGH);
    delay(3000);
    digitalWrite(green, LOW);
  }
}

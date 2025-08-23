int ledPin = 13; // LED connected to pin 13

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn LED ON
  delay(1000);                // Wait 1 second
  digitalWrite(ledPin, LOW);  // Turn LED OFF
  delay(1000);                // Wait 1 second
}

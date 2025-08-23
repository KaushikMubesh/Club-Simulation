#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // R1 -> 9, R2 -> 8, R3 -> 7, R4 -> 6
byte colPins[COLS] = {5, 4, 3, 2}; // C1 -> 5, C2 -> 4, C3 -> 3, C4 -> 2

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";  // Correct password
String input = "";

const int greenLED = 10;
const int redLED = 11;

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.println("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Pressed: ");
    Serial.println(key);

    if (key == '#') {  // # to submit password
      if (input == password) {
        Serial.println("ACCESS GRANTED");
        blinkLED(greenLED);
      } else {
        Serial.println("ACCESS DENIED");
        blinkLED(redLED);
      }
      input = "";  // Reset input
    } else if (key == '*') {
      input = "";  // Clear input
      Serial.println("Input Cleared");
    } else {
      input += key;
    }
  }
}

void blinkLED(int ledPin) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}

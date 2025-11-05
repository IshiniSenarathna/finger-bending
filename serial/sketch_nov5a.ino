#define THUMB_LED 2
#define INDEX_LED 4
#define MIDDLE_LED 13 
#define RING_LED 18
#define PINKY_LED 19

void setup() {
  Serial.begin(115200);
  pinMode(THUMB_LED, OUTPUT);
  pinMode(INDEX_LED, OUTPUT);
  pinMode(MIDDLE_LED, OUTPUT);
  pinMode(RING_LED, OUTPUT);
  pinMode(PINKY_LED, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    if (input.length() == 5) {
      digitalWrite(THUMB_LED, input.charAt(0) == '1' ? HIGH : LOW);
      digitalWrite(INDEX_LED, input.charAt(1) == '1' ? HIGH : LOW);
      digitalWrite(MIDDLE_LED, input.charAt(2) == '1' ? HIGH : LOW);
      digitalWrite(RING_LED, input.charAt(3) == '1' ? HIGH : LOW);
      digitalWrite(PINKY_LED, input.charAt(4) == '1' ? HIGH : LOW);
    }
  }
}
#include <WiFi.h>

const char* ssid = "SLT_FIBRE518";
const char* password = "2261518RK";


WiFiServer server(12345);

// Define GPIO pins for LEDs
#define THUMB_LED 2
#define INDEX_LED 4
#define MIDDLE_LED 13
#define RING_LED 18
#define PINKY_LED 19

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start TCP server
  server.begin();
  Serial.println("TCP server started on port 12345");

  // Initialize LED pins
  pinMode(THUMB_LED, OUTPUT);
  pinMode(INDEX_LED, OUTPUT);
  pinMode(MIDDLE_LED, OUTPUT);
  pinMode(RING_LED, OUTPUT);
  pinMode(PINKY_LED, OUTPUT);
}

void loop() {
  WiFiClient client = server.available(); // Check for incoming clients

  if (client) {
    Serial.println("Client connected");
    while (client.connected()) {
      if (client.available()) {
        String input = client.readStringUntil('\n');
        input.trim();  
        Serial.print("Received: ");
        Serial.println(input);
        if (input.length() == 5) {
          digitalWrite(THUMB_LED, input.charAt(0) == '1' ? HIGH : LOW);
          digitalWrite(INDEX_LED, input.charAt(1) == '1' ? HIGH : LOW);
          digitalWrite(MIDDLE_LED, input.charAt(2) == '1' ? HIGH : LOW);
          digitalWrite(RING_LED, input.charAt(3) == '1' ? HIGH : LOW);
          digitalWrite(PINKY_LED, input.charAt(4) == '1' ? HIGH : LOW);
        }
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}

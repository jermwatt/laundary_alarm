
// #include <Arduino.h>
// const int vibrationPin = 5; // digital input pin connected to the vibration sensor

// void setup() {
//   Serial.begin(9600);
//   pinMode(vibrationPin, INPUT);
//   pinMode(LED_BUILTIN, OUTPUT);
// }

// void loop() {
//   int vibrationValue = digitalRead(vibrationPin);
//   Serial.println("Vibration value: ");
//   Serial.println(vibrationValue);
//   digitalWrite(LED_BUILTIN, HIGH); // turn the LED off by making the voltage LOW
//   delay(2000);
//   digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
// }


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <LedFeedback.h>
#include <Secrets.h>

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
const char* serverName = "www.icanhazip.com"; // replace with your server's hostname
const int serverPort = 80; // HTTP port is usually 80
LedFeedback ledFeedback(LED_BUILTIN); // initialize LedFeedback object with builtin LED pin

void setup() {
  // initialize digital pin led builtin as output
  pinMode(LED_BUILTIN, OUTPUT);

  // connect Serial Monitor
  Serial.begin(9600);
  Serial.println("Starting...");

  // connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  ledFeedback.flashLedSuccess();
}

void loop() {
  WiFiClient client;
  if (client.connect(serverName, serverPort)) {
    Serial.println("Connected to server");
    client.println("GET / HTTP/1.1");
    client.print("Host: ");
    client.println(serverName);
    client.println("Connection: close");
    client.println();
    delay(1000); // wait for server to respond
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }
    client.stop();
    Serial.println("Disconnected from server");
    ledFeedback.flashLedSuccess();
  } else {
    Serial.println("Connection failed");
    ledFeedback.flashLedFailure();
  }
  // turn off LED
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000); // wait 5 seconds before sending next request
}
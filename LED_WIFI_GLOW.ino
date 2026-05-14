#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Mahesh_EXT";
const char* password = "shiva@123";

WebServer server(80);

int ledPin = 2;

void setup() {

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println(WiFi.localIP());

  server.on("/on", []() {
    digitalWrite(ledPin, HIGH);
    server.send(200, "text/plain", "LED ON");
  });

  server.on("/off", []() {
    digitalWrite(ledPin, LOW);
    server.send(200, "text/plain", "LED OFF");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
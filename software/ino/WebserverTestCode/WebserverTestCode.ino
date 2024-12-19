#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>ESP32 Access Point Web Server is Online!</h1>");
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Set up the ESP32 as an Access Point
  Serial.println("Setting up Access Point...");
  WiFi.softAP("ESP32_AP", "12345678"); // SSID: ESP32_AP, Password: 12345678
  IPAddress IP = WiFi.softAPIP();      // Get the Access Point IP address
  Serial.print("AP IP Address: ");
  Serial.println(IP);

  // Start Web Server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started on Access Point");
}

void loop() {
  server.handleClient();
}

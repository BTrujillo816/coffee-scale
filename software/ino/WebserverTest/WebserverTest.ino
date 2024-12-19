#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "HX711.h"
#include "driver/rtc_io.h"
#include "esp_sleep.h"
#include <WiFi.h>
#include <WebServer.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_MOSI  11
#define OLED_CLK   10
#define OLED_DC    9
#define OLED_CS    5
#define OLED_RESET 6

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 17;
const int LOADCELL_SCK_PIN = 18;

HX711 scale;

// Button pins
const int buttonTarePin = 16;
const int buttonTimerPin = 15;
const int buzzerPin = 14;
const int wakeUpPin = 12;

// WiFi credentials
#define WIFI_SSID "Fios-2ykMB"
#define WIFI_PASSWORD "fig75noted22sew"

WebServer server(80);

// Variables
unsigned long previousMillis = 0;
unsigned long interval = 1000;
bool timerRunning = false;
unsigned long timerStartMillis = 0;
unsigned long lastActivityMillis = 0;
const unsigned long sleepTimeout = 30000;
bool wifiConnected = false;

RTC_DATA_ATTR int bootCount = 0;

// Flow rate variables
float lastWeight = 0.0;
float flowRate = 0.0;
unsigned long lastFlowTime = 0;
float lastDisplayWeight = 0.0;

// Function to print the reason for wake-up
void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  switch (wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0: Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_TIMER: Serial.println("Wakeup caused by timer"); break;
    default: Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason); break;
  }
}

// Function to initialize the OLED display
void initializeDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Stop if OLED initialization fails
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.display(); // Show initial buffer
}

// Function to initialize the scale
void initializeScale() {
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(25924 / 60.2);  // Set scale factor (adjust to your scale)
  scale.tare();  // Reset the scale to 0
}

// Function to display a short message on the OLED
void displayMessage(String message) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print(message);
  display.display();
}

// Function to play a beep sound using the active buzzer
void beep() {
  digitalWrite(buzzerPin, HIGH);  // Turn the buzzer ON
  delay(100);                     // Wait for 100 milliseconds
  digitalWrite(buzzerPin, LOW);   // Turn the buzzer OFF
}

// Function to go to deep sleep
void goToSleep() {
  Serial.println("Going to sleep now");
  delay(100);  // Allow serial output to complete

  // Enter deep sleep
  esp_deep_sleep_start();
}

// Handle the root web page
void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>Scale Data</title></head><body>";
  html += "<h1>Scale Data</h1>";
  html += "<p>Weight: " + String(lastDisplayWeight, 1) + " g</p>";
  html += "<p>Flow Rate: " + String(flowRate, 1) + " g/s</p>";
  if (timerRunning) {
    unsigned long elapsedTime = millis() - timerStartMillis;
    unsigned long seconds = elapsedTime / 1000;
    html += "<p>Timer: " + String(seconds) + " s</p>";
  } else {
    html += "<p>Timer: Stopped</p>";
  }
  html += "</body></html>";
  server.send(200, "text/html", html);
}

// Attempt to connect to WiFi with a timeout
void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  unsigned long startAttemptTime = millis();

  // Try connecting for 10 seconds
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    wifiConnected = true;
    Serial.println("\nConnected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP server started");
  } else {
    wifiConnected = false;
    Serial.println("\nFailed to connect to WiFi. Running offline.");
  }
}

void setup() {
  Serial.begin(57600);
  delay(1000);
  Serial.println("HX711 Demo");

  print_wakeup_reason();

  initializeDisplay();
  initializeScale();

  pinMode(buttonTarePin, INPUT_PULLUP);
  pinMode(buttonTimerPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_12, 1);

  lastActivityMillis = millis();

  // Attempt to connect to WiFi
  connectToWiFi();
}

void loop() {
  float weight = scale.get_units(10);

  unsigned long currentMillis = millis();
  if (currentMillis - lastFlowTime >= 1000) {
    flowRate = abs(weight - lastWeight);
    lastWeight = weight;
    lastFlowTime = currentMillis;
  }

  if ((weight > 1 || timerRunning)) {
    lastActivityMillis = millis();
  }

  if (digitalRead(buttonTarePin) == LOW) {
    scale.tare();
    beep();
    displayMessage("Scale Tared");
    delay(500);
    lastActivityMillis = millis();
  }

  if (digitalRead(buttonTimerPin) == LOW) {
    if (!timerRunning) {
      timerRunning = true;
      timerStartMillis = millis();
      beep();
      displayMessage("Timer Started");
    } else {
      timerRunning = false;
      beep();
      displayMessage("Timer Stopped");
    }
    delay(500);
    lastActivityMillis = millis();
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Weight: ");
  if (weight > 1.0) {
    if (flowRate > 0.3) {
      display.print(weight, 1);
      lastDisplayWeight = weight;
    } else {
      display.print(lastDisplayWeight, 1);
    }
  } else {
    display.print(0.0, 1);
  }
  display.print(" g");

  display.setCursor(0, 16);
  display.print("Flow Rate: ");
  if (flowRate > 0.5) {
    display.print(flowRate, 1);
  } else {
    display.print(0.0, 1);
  }
  display.print(" g/s");

  if (timerRunning) {
    unsigned long elapsedTime = millis() - timerStartMillis;
    unsigned long seconds = elapsedTime / 1000;
    display.setCursor(0, 24);
    display.print("Timer: ");
    display.print(seconds);
    display.print(" s");
  }

  display.display();
  delay(100);

  if (weight <= 1 && !timerRunning && millis() - lastActivityMillis > sleepTimeout) {
    goToSleep();
  }

  // Handle Web Server if connected to WiFi
  if (wifiConnected) {
    server.handleClient();
  }
}

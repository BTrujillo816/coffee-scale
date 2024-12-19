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
const int buttonTarePin = 16;  // Button 1: Tare
const int buttonTimerPin = 15; // Button 2: Timer Start/Stop
const int buzzerPin = 14;      // Active buzzer pin
const int wakeUpPin = 12;      // GPIO 12 for wake-up

// WiFi credentials
#define WIFI_SSID "ESP32_AP"
#define WIFI_PASSWORD "12345678"

WebServer server(80);

// Variables
unsigned long previousMillis = 0;  // Timer
unsigned long interval = 1000;      // 1 second interval for the timer
bool timerRunning = false;          // Timer state
unsigned long timerStartMillis = 0; // Timer start time
unsigned long lastActivityMillis = 0; // Last activity time
const unsigned long sleepTimeout = 30000; // 30 seconds timeout for sleep

RTC_DATA_ATTR int bootCount = 0; // Keep track of reboots during deep sleep

// Flow rate variables
float lastWeight = 0.0;
float flowRate = 0.0;
unsigned long lastFlowTime = 0;
float lastDisplayWeight = 0.0;

void handleRoot() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 Scale Data</title>
      <style>
        body {
          font-family: Arial, sans-serif;
          text-align: center;
          margin: 0;
          padding: 0;
          background-color: #f4f4f9;
        }
        h1 {
          font-size: 2em;
          margin-top: 20px;
        }
        p {
          font-size: 1.5em;
          margin: 20px 0;
        }
        .data {
          font-size: 2em;
          font-weight: bold;
          color: #333;
        }
      </style>
      <script>
        async function fetchData() {
          const response = await fetch('/data');
          const data = await response.json();
          document.getElementById('weight').textContent = data.weight + ' g';
          document.getElementById('flowRate').textContent = data.flowRate + ' g/s';
          document.getElementById('timer').textContent = data.timer !== null ? data.timer : 'N/A';
        }
        setInterval(fetchData, 1000); // Fetch data every second
      </script>
    </head>
    <body onload="fetchData()">
      <h1>ESP32 Scale Data</h1>
      <p>Weight: <span id="weight" class="data">-- g</span></p>
      <p>Flow Rate: <span id="flowRate" class="data">-- g/s</span></p>
      <p>Timer: <span id="timer" class="data">Stopped</span></p>
    </body>
    </html>
  )rawliteral";
  server.send(200, "text/html", html);
}



void setup() {
  // Initialize Serial Monitor
  Serial.begin(57600);
  delay(1000);
  Serial.println("HX711 Demo");

  // Wake-up cause check
  print_wakeup_reason();

  // Initialize the display and scale
  initializeDisplay();
  initializeScale();

  // Initialize buttons and buzzer
  pinMode(buttonTarePin, INPUT_PULLUP);
  pinMode(buttonTimerPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  // Configure wakeup source on GPIO 12
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_12, 1); // Wake up when GPIO 12 is HIGH

  // Set up the ESP32 as an Access Point
  Serial.println("Setting up Access Point...");
  WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP Address: ");
  Serial.println(IP);

  // Start Web Server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started on Access Point");

  // Track activity start
  lastActivityMillis = millis();

  server.on("/data", handleData);

}

void loop() {
  unsigned long currentMillis = millis();

  // Read weight from scale
  float weight = scale.get_units(10);

  // Flow rate calculation (grams per second)
  if (currentMillis - lastFlowTime >= 1000) {  // Update every second
    flowRate = weight - lastWeight;  // Flow rate is the difference in weight over 1 second
    lastWeight = weight;  // Save the current weight for the next calculation
    lastFlowTime = currentMillis;
  }

  // Don't go to sleep if the weight is above 1 gram or if the timer is running
  if ((weight > 1 || timerRunning)) {
    lastActivityMillis = millis(); // Reset activity timer when weight is detected or timer is running
  }

  // Check if Tare button is pressed
  if (digitalRead(buttonTarePin) == LOW) {
    scale.tare();  // Reset the scale to 0
    beep();
    displayMessage("Scale Tared");
    delay(500); // Debounce time to prevent multiple readings
    lastActivityMillis = millis(); // Reset activity timer
  }

  // Check if Timer button is pressed
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
    delay(500); // Debounce time to prevent multiple readings
    lastActivityMillis = millis(); // Reset activity timer
  }

  // OLED and Web Server updates (non-blocking)
  if (currentMillis - previousMillis >= 100) { // Update display every 100ms
    previousMillis = currentMillis;

    // Display the weight
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Weight: ");
    if (weight > 1.0) {
      if (flowRate > 0.3) {
        display.print(weight, 1);  // Display weight with 1 decimal place
        lastDisplayWeight = weight;
      } else {
        display.print(lastDisplayWeight, 1);
      }
    } else {
      display.print(0.0, 1);
    }
    display.print(" g");

    // Display flow rate (grams per second)
    display.setCursor(0, 16);
    display.print("Flow Rate: ");
    if (flowRate > 0.5) {
      display.print(flowRate, 1);  // Display flow rate with 2 decimal places
    } else {
      display.print(0.0, 1);
    }
    display.print(" g/s");

    // Display the timer if running
  if (timerRunning) {
    unsigned long elapsedTime = millis() - timerStartMillis;
    unsigned long minutes = elapsedTime / 60000;
    unsigned long seconds = (elapsedTime % 60000) / 1000;

    display.setCursor(0, 24);
    display.print("Timer: ");
    if (minutes < 10) display.print("0");
    display.print(minutes);
    display.print(":");
    if (seconds < 10) display.print("0");
    display.print(seconds);
  }

    // Show the display buffer on the screen
    display.display();
  }

  // Check for sleep timeout if no weight or activity is detected
  if (weight <= 1 && !timerRunning && millis() - lastActivityMillis > sleepTimeout) {
    goToSleep();
  }

  // Handle Web Server
  server.handleClient();
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

// Function to print the reason for wake-up
void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  switch (wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0: Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_TIMER: Serial.println("Wakeup caused by timer"); break;
    default: Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason); break;
  }
}

void handleData() {
  float weight = scale.get_units(10); // Get the current weight
  float displayWeight = 0.0;          // To hold the final weight value to display
  float displayFlowRate = 0.0;        // To hold the final flow rate value to display

  // Apply the same logic as used for the OLED display
  if (weight > 1.0) {
    if (abs(flowRate) > 0.3) {
      displayWeight = weight;         // Use the current weight
      lastDisplayWeight = weight;    // Update last displayed weight
    } else {
      displayWeight = lastDisplayWeight; // Use the last known valid weight
    }
  }

  if (flowRate > 0.5) {
    displayFlowRate = flowRate;       // Use the current flow rate
  }

  String timerDisplay = "Stopped";
  
  if (timerRunning) {
    unsigned long elapsedTime = millis() - timerStartMillis;
    unsigned long minutes = elapsedTime / 60000;
    unsigned long seconds = (elapsedTime % 60000) / 1000;
    timerDisplay = (minutes < 10 ? "0" : "") + String(minutes) + ":" +
                   (seconds < 10 ? "0" : "") + String(seconds);
  }

  // Construct JSON response
  String json = "{";
  json += "\"weight\":" + String(displayWeight, 1) + ",";
  json += "\"flowRate\":" + String(displayFlowRate, 1) + ",";
  json += "\"timer\":\"" + timerDisplay + "\"";
  json += "}";

  // Send JSON response
  server.send(200, "application/json", json);
}





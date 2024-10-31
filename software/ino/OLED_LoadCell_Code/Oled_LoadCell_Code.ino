#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "HX711.h"

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

void setup() {
  Serial.begin(57600);
  Serial.println("HX711 Demo");
  
  // Initialize the scale
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(25924/60.2); // Set the scale factor (change this value based on your calibration)
  scale.tare(); // Reset the scale to 0

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.display(); // Show initial buffer
}

void loop() {
  // Get the weight
  float weight = scale.get_units(10); // Average of 10 readings

  // Clear the display
  display.clearDisplay();

  // Display the weight on the OLED
  display.setCursor(0, 0);
  display.print("Weight: ");
  display.print(weight, 1); // Display weight with 1 decimal place
  display.print(" g"); // Assuming you are measuring in grams

  // Show the display buffer on the screen
  display.display();

  // Print to Serial for debugging
  Serial.print("Weight: ");
  Serial.println(weight);

  delay(1000); // Update every second
}
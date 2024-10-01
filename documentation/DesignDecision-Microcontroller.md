Write up which microcontrollers you considered, and which you chose [30].

- ESP32-S3
- Arduino

Show pros and cons [10].

- ESP32-S3

  - Pros
    - WiFi
    - Bluetooth
    - Arduino IDE compatible
    - Greater processing speed
  - Cons
    - More expensive than ATMEGA328PB-MU
    - Smaller operational voltage range (2.2 to 3.6V)

- ATMEGA328PB-MU

  - Pros
    - Greater operational voltage range (1.8 to 5.5V)
    - Easier to work with (prior experience)
    - Lower power draw

  - Cons
    - No WiFi without external module
    - No Bluetooth capability without external module

Describe what lead you to this decision [10]

- We decided to use an ESP32-S3 primarily because of its IoT capabilities (WiFi and Bluetooth compatibility) and its compatibility with the Arduino IDE.

  

Show a plan of the resources you are going to use from your microcontroller, and how [30].	

- Connectivity
  - SPI
    - eInk Display
  - PWM
    - eInk Display
  - RTC
    - Sleep mode
  - GPIO
    - Pushbuttons
    - LEDs
    - HX711

Show parameters you already know or have to determine, for instance duty/cycle and frequency settings for a timer that generates a PWM signal [20]

eInk Display (UC8151d)

- Clock rate for SPI interface
- Display resolution
- Frame rate

HX711

- Sampling rate

- Gain selection

​            

​          
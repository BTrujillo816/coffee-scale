### Microcontroller Options

- ESP32-S3
- Arduino

### Pros and Cons

- ESP32-S3

  - Pros
    - IoT Capability (Bluetooth and Wi-Fi)
    - Arduino IDE compatible
    - Greater processing speed
    - Sleep modes
  - Cons
    - More expensive than ATMEGA328PB-MU
    - Smaller operational voltage range (2.2 to 3.6V)
- ATMEGA328PB-MU

  - Pros
    - Greater operational voltage range (1.8 to 5.5V)
    - Easier to work with (prior experience)
    - Lower power draw

  - Cons
    - No Wi-Fi without external module
    - No Bluetooth capability without external module

### Decision Factors

We decided to use an ESP32-S3 primarily because of its IoT capabilities (Wi-Fi and Bluetooth compatibility) and its compatibility with the Arduino IDE.

### Microcontroller Resources

Built-in Peripherals

- PWM
  - eInk Display
- RTC
  - External Wakeup

Connectivity	

- SPI
  - eInk Display
- BLE
  - App connectivity/data collection
- Wi-Fi
  - App connectivity/data collection

Memory Planning

- Calibration settings

GPIO

- Pushbuttons

- LEDs

- HX711

Power supply plan

- Sleep modes

### Parameters

eInk Display (UC8151d)

- Clock rate for SPI interface
- Display resolution
- Frame rate

HX711

- Sampling rate
- Gain selection

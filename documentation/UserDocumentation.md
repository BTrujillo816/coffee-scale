# Digital Coffee Scale User Manual

## Product Purpose
- The Coffee Scale Project is designed to replicate a professional coffee scale, providing precise measurements for brewing coffee. The scale automatically weighs objects, shows brewing parameters, and interacts with the user through physical controls and oled display. The product is powered by a LiPo battery and built around the ESP32 microcontroller for versatile connectivity and functionality.

## Operation
### Initial Setup
1. Power
- Make sure battery is charged. Connect to USB-C if needs charging. 
- Press wake up button to turn product on.

2. Calibration
- Ensure the scale is on a flat surface.
- Press the Tare Button to reset the weight to zero.

### Button Functions

1. Tare Button
- Action: Press to reset the scale reading to zero.
- Feedback: The buzzer will emit a short beep, and the display will show "Scale Tared"
- Use Case: Use this when the scale is loaded with a container and you want to measure the contents only.

2. Timer Button
- Action:
    - Press once to start the timer.
    - Press again to stop the timer.
- Feedback: The buzzer will emit a short beep for each action.
- Display:
    - When running, the timer shows elapsed time in seconds (e.g., "Timer: 10 s").
    - When stopped, the timer display freezes.
- Use Case: Use this to track brewing time or other timed processes.

## Weight and Flow Rate Display

1. Weight
- Displayed as: "Weight: X.X g"
    - Updates continuously as items are added or removed.
    - Minimum detectable weight is 1 gram.

2. Flow Rate
    - Displayed as: "Flow Rate: X.X g/s"
    - Calculates the rate of weight change every second.
    - Updates if the flow rate exceeds 0.5 g/s.

## Sleep Mode

1. Activation
- The device enters deep sleep mode after 30 seconds of inactivity.
- Inactivity is defined as:
    - Weight below 1 gram.
    - Timer is not running.

2. Wake-Up
- Press the wake-up button to reactivate the device.

## Maintenance
1. Clean the scale surface regularly to ensure accurate readings
2. Avoid overloading the strain gauge to prevent damage
3. Recharge the battery periodically to maintain portability
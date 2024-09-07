# Client
- Roles
  - Consumer
- Budget
  - $ 50

# Communication
- Repository: GitHub
- Logbook: GitHub

# Objectives
- Descriptions
  - Triangular
  - LED display
  - Make sounds
  - Pressure sensor

# Scenario
# # User Interaction Stories
- Unboxing
  - wrap to protect product
- Using
  - slide switch to turn on product
- Display
  - Turns off automatically after 1 hour of no usage
- Power
  - Rechargeable battery

# # User Interface
- Display
  - LEDs
- Switches
  - SPDT Slide Switch
- Indicators
  - Beeps when system first turns on

# User Acceptance
- Given-When-Then criteria
  - Given: Cup and product
  - When: product detects weight change
  - Then: Red LED lights up
- Quantifiable Goals
  - Pressure sensor can detect weigh change when ball goes inside cup
  - RED led will light up when pressure sensor detect weight change
  - Slide switch will turn on system
  - Batteries are rechargeable
- On/off switch works as intended

# Parameters
## Technical
- Protection
  - Waterproof

## Functions
- Uses infrared sensor to detect ball
- Emits a sound whenever infrared detect ball

## Integration
- Protocols
  - I2C

## Operational
- Don't put underwater
- Long-battery life
- Carrying case to protect product

## Regulatory
- None

## Life Cycle
- Manufacturing
  - Makerspace
- Programming
  - C or C++
- Service
  - No
- Associated Services
  - Also no

## Environment
- Temperatures
  - Can operate with exposure to elements
- Hazards
  - Cannot withstand large weights/pressure on product
- Ingress
  - Water resistance (IPX4)
    - Charging port cap
    - Silicone/water resistant outershell

## Starting Point
- Existing IP
  - None

## Key Concerns
- Most Important
  - Product cannot be sumberged in liquids
- Set-in-stone Parameters
  - Must turn red when sensor is triggered
  - Must reset back to green after a few seconds game is over

## Future
- Open-source
- DIY capable
  - Order a kit and assemble it easily with/without a soldering iron

## Glossary
- LED pong
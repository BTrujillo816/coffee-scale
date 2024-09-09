# Client
- Roles
  - Consumer
- Budget
  - $40

# Communication
- Repository: GitHub
- Logbook: GitHub

# Objectives
- Descriptions
  - Triangular shaped PCB
  - LED display around the perimeter
  - Piezo buzzer to make sounds
  - Pressure sensor to detect weight change

# Scenario
## User Interaction Stories
- Unboxing
  - Wrapping to protect product
- Using
  - Slide switch to turn on product
- Display
  - Turns off automatically after 1 hour of no usage
- Power
  - Rechargeable battery

## User Interface
- Display
  - LEDs
- Switches
  - SPDT Slide Switch
- Indicators
  - Beeps when system first turns on

# User Acceptance
- Given-When-Then criteria
  - Given: Cup and product
  - When: Product detects weight change
  - Then: Red LED lights up
- Quantifiable Goals
  - Pressure sensor can detect weight change when ball goes inside cup
  - Accompanying sound will go off when the pressure sensor detects the weight change
  - RED led will light up when pressure sensor detect weight change
  - Slide switch will turn on system
  - Batteries are rechargeable
  - On/off switch works as intended

# Parameters
## Technical
- Protection
  - Waterproof

## Functions
- Uses pressure sensor to detect weight change when ball goes in a cup filled with water
- Emits a sound whenever weight change is detected

## Integration
- Protocols
  - I2C

## Operational
- Do not submerge in water
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
  - Product cannot be submerged in liquids
- Set-in-stone Parameters
  - Must turn red when sensor is triggered
  - LEDs must reset back to green after a few seconds to signify game is over
  - Sound must be audible when product is being used

## Future
- Open-source
- DIY capable
  - PCB design can be downloaded/edited and ordered for individual use
    - PCB has the potential to be used in single-use cups  

## Glossary
- LEDs
- Piezo Buzzer
- Pressure Sensor
# Client
- Roles
- - Consumer
- Budget
- - $ 500

# Communication
- Repository: GitHub
- Logbook: GitHub

# Objectives
- Descriptions
- - Rectangular
- - Displays numbers
- - Physical interaction
- - Makes sounds

# Scenario
# # User Interaction Stories
- Unboxing
- - Foam to protect pressure sensor
- Using
- - Press button to turn on
- - Press button to zero
- - Automatically weighs objects
- - Stores coffee weight data, flow rata data, water weight data, timing data
- - Timer
- - -  Reset
- - Modes
- - - Configurable modes for different coffee brewing methods
- - - - Aeropress
- - - - Pour over
- - - - Espresso
- Display
- - Turns off automatically after 30s of no usage
- - Shows current mode
- Power
- - Battery
- - - Rechargeable
- Modes
- - Standard
- - - Basic kitchen scale functionality
- - - - Manual timer
- - - - Manual tare
- - - - Automatic weighing
- - - - Brew parameters storeable at any stage
- - Espresso
- - - Automatic detection of brewing vessel
- - - Automatic timer when coffee flow starts/stops
- - - Automatically stores brew parameters
- - Pour-over
- - - Manual start
- - - Automatic timer
- - - - Starts when weight is above a certain amount
- - - Automatically stores brew parameters

# # User Interface
- Display
- - LCD
- Buttons
- - Pushbuttons with 3D printed button caps
- Switches
- - SPDT Slide Switch
- Indicators
- - Beeps for pushbuttons

# User Acceptance
- Given-When-Then criteria
- - Given: Weigh coffee
- - When: When coffee is on the scale
- - Then: Coffee weight is displayed
- Quantifiable Goals
- - Objects are weighed accurately
- - Flow-rate is displayed continuously
- - Pushbuttons work as intended to tare, power on, and start/stop timer
- - Display is accurate and fast
- - Batteries are easily swapped
- - - Alternatively, battery is chargeable
- On/off switch works as intended
- Modes are easily switched betwen

# Parameters
## Technical
- Dimensions
- - 115 mm x 100.8 mm x 16 mm
- Weight
- - 192 g
- Protection
- - Waterproof

## Functions
- Uses pressure sensor to weigh coffee
- Uses gyroscope to detect level surface and calibrate sensor
- Displays brewing parameters from memory to LCD display
- Emits a sound whenever a button is pressed
- Starts and stops timer based on input or mode

## Integration
- Protocols
- - SPI
- - I2C
- - Serial

## Operational
- Don't put underwater
- Long-battery life
- Carrying case to protect pressure sensor

## Regulatory
- None

## Life Cycle
- Manufacturing
- - Makerspace
- Programming
- - C or C++
- Service
- - No
- Associated Services
- - Also no

## Environment
- Temperatures
- - Room temp optimal operation
- Hazards
- - Cannot withstand large weights/pressure on pressure sensor
- Ingress
- - Water resistance (IPX3)
- - - Charging port cap
- - - Silicone/water resistant cover
- Power
- - Rechargeable battery

## Starting Point
- Existing IP
- - Timemore Coffee Scale Basic Mini

## Key Concerns
- Most Important
- - If the scale is not leveled, the weight calculation will be inaccurate
- Set-in-stone Parameters
- - Must weigh coffee accurately
- - Must display weigh and time
- - Must be resetable

## Future
- Open-source
- DIY capable
- - Order a kit and assemble it easily with/without a soldering iron

## Glossary
- Grounds
- Flow rate
- Pour Over
- Espresso
- Brewing parameters
- Brewing vessel
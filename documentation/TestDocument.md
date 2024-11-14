# Test Document

## Precision Testing

### Test 1 - Does it show the same value for a given object?

- Given: An object of known weight
- When: The object is removed and placed again
- Then: The scale should display the same value each time
- Acceptable Range: $\pm10$% error

### Test 2

#### Equipment Used

- Coffee scoop (light weight)
- Metal bottle (medium weight)
- Coffee Grinder (heavy weight)
- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black)

#### Criteria

- Does it show the same value over a long period of time?
  - Given: An object of known weight
  - When: The object remains on the scale for an extended period of time
  - Then: The scale should continuously show the same weight for the same period of time

## Accuracy Testing

### Test 1 - Benchmark weight against existing products

#### Equipment Used

- Coffee scoop (light weight)
- Metal bottle (medium weight)
- Coffee Grinder (heavy weight)
- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black)

#### Criteria

Benchmark weight against existing products

- Acceptable Range: Within $\pm 10%$% error

#### Result

| Object         | Control (g)                                                  | Weight (g)                                                   | Percent Error (%) |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| Coffee Scoop   | [16.3](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Small_weight_test_control.jpg) | [16.3](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Small_weight_test_result.jpg) | 0                 |
| Metal Bottle   | [299.7](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Medium_weight_test_control.jpg) | [299.3](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Medium_weight_test_result.jpg) | 0.13              |
| Coffee Grinder | [380.8](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Large_weight_test_control.jpg) | [380.2](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Large_weight_test_result.jpg) | 0.15              |

### Test 2 - Benchmark time against computer/phone clock

- Benchmark flow-rate calculation against existing products

## Manual Testing

Power and Auto-off Functionality

- Test Type: Manual
- Objective: Check the power functions and auto-off function after inactivity
- Test Steps:
  - Wake up the scale by pressing the wakeup button
  - Place weight on scale and wait 30 seconds
  - Observe if the scale remains on after 30 seconds
  - Remove weight and leave the scale idle for 30 seconds
  - Observe if the scale automatically powers off after 30 seconds
- Pass Criteria: The scale turns on when power button is pressed and turns off after 30 seconds of no activity


# Test Document

## Precision Testing

### Test 1 - Does it show the same value for a given object?

#### Equipment Used

- Coffee Grinder
- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black)
- [Breadboard prototype](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Current_prototype_11-13-24.jpg)

#### Criteria

- Given: An object of known weight
- When: The object is removed and placed again
- Then: The scale should display the same value each time
- Acceptable Range: $\pm10$%

#### Results

| Placement | Control (g) | Test (g) | Percent Error (%) |
| --------- | ----------- | -------- | ----------------- |
| 1         | 380.4       | 380.3    | 0.02              |
| 2         | 380.4       | 380.4    | 0                 |
| 3         | 380.4       | 380.5    | 0.05              |

The object was picked up and placed three times after the initial placement, as seen in the [video](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Test_Precision.mp4). The results of this test fall within the acceptable range, therefore the system is precise. However, the weight output tends to fluctuate, likely due to noise.

### Test 2 - Does it show the same value over a long period of time?

#### Equipment Used

- Coffee Grinder
- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black)
- [Breadboard prototype](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Current_prototype_11-13-24.jpg)

#### Criteria

- Given: An object of known weight
- When: The object remains on the scale for an extended period of time
- Then: The scale should continuously show the same weight for the same period of time
- Acceptable Range: $\pm 5$%

#### Results

| Time (s) | Control (g) | Test (g) | Percent Error (%) |
| -------- | ----------- | -------- | ----------------- |
| 5        | 298.7       | 298.4    | 0.10              |
| 15       | 298.7       | 298.5    | 0.07              |
| 30       | 298.7       | 298.9    | 0.07              |

When an object remains on the scale, the weight display tends to fluctuate; however, because the fluctuations are within an acceptable range below 5%, the system is still precise. The weight fluctuation could be potentially be solved through noise reduction measures and a redesign the load cell chassis.

## Accuracy Testing

### Test 1 - Benchmark weight against existing products

#### Equipment Used

- Coffee scoop (light weight)
- Metal bottle (medium weight)
- Coffee Grinder (heavy weight)
- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black)
- [Breadboard prototype](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Current_prototype_11-13-24.jpg)

#### Criteria

- Acceptable Range: $\pm 10%$%

#### Results

| Object         | Control (g)                                                  | Test (g)                                                     | Percent Error (%) |
| -------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| Coffee Scoop   | [16.3](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Small_weight_test_control.jpg) | [16.3](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Small_weight_test_result.jpg) | 0                 |
| Metal Bottle   | [299.7](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Medium_weight_test_control.jpg) | [299.3](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Medium_weight_test_result.jpg) | 0.13              |
| Coffee Grinder | [380.8](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Large_weight_test_control.jpg) | [380.2](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Large_weight_test_result.jpg) | 0.15              |

All tests were within an acceptable range, therefore, our system is accurate.

### Test 2 - Benchmark time against computer/phone clock

#### Equipment Used

- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black)
- Breadboard prototype

#### Criteria

- Acceptable Range: $\pm 5$%

#### Results

As shown in the [video](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Test_Timer.mp4), both timers seem to increment at the same rate. Therefore, we can say that our system is accurate in its timing.

### Test 3 - Benchmark flow-rate calculation against existing products

#### Equipment Used

- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black)
- [Breadboard](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Current_prototype_11-13-24.jpg) prototype
- Metal cup
- Paper cup

#### Criteria

- Given: Water flows from a container at a known flow rate
- When: Water flows onto the scale
- Then: The scale should display an accurate flow rate measurement

#### Result

We have determined from our [test](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Functionality_Flow_Rate.mp4) that a more consistent, controllable method should be used to measure flow rate. In the future, we'll use an object that provides a consistent flow rate (such as a funnel) and benchmark the scale against the Timemore scale.

## Manual Testing

#### Equipment Used

- Timemore [Black Mirror Nano Scale](https://www.timemore.com/products/timemore-black-mirror-nano-espresso-coffee-weighing-timing-black) (or any timer)
- [Breadboard](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Current_prototype_11-13-24.jpg) prototype
- Any weight

#### Test 1 - Check sleep timer functionality after inactivity

#### Procedure

- Wake up the scale by pressing the wakeup button
- Place weight on scale and wait 30 seconds
- Observe if the scale remains on after 30 seconds
- Remove weight and leave the scale idle for 30 seconds
- Observe if the scale automatically powers off after 30 seconds

- Pass Criteria: The scale turns on when power button is pressed and turns off after 30 seconds of no activity

#### Result

In the [video](https://github.com/BTrujillo816/coffee-scale/blob/main/documentation/TestDocument.assets/Test_Timer.mp4), an object is placed on the scale to prevent the system from going to sleep. At 32 seconds, the object is removed and the system shuts off 30 seconds later at 1:02. This accurate shows the sleep timer is functioning properly.








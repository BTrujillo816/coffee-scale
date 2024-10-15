# Test Criterias by Miguel Takinan

## Guides
1. [Automatic vs Manual Testing](https://www.geeksforgeeks.org/software-engineering-differences-between-manual-and-automation-testing/)
2. [Given-When-Then](https://martinfowler.com/bliki/GivenWhenThen.html)

## Test
1. Power and Auto-off Functionality
    - Test Type: Manual
    - Objective: Check the power functions and auto-off function after inactivity
    - Test Steps:
        - Turn the scale on by pressing the power button
        - Leave the scale idle for 30 seconds
        - Observe if the scale automatically powers off after 30 seconds
    - Pass Criteria: The scale turns on when power button is pressed and turns off after 30 seconds of no activity

2. Accuracy of Weight Measurement
    - Test Type: Manual, Given-When-Then
    - Objective: Ensure the scale measures weight accurately
    - Test Steps:
        - Given an accurate weight of 100g
        - When the weight is placed on the scale
        - Then the scale should display the correct weight of 100g
    - Pass Criteria: The displayed weight is correct within a small margin of error

3. Display Accuracy and Speed
    - Test Type: Manual, Given-When-Then
    - Objective: Ensure the display shows weight measurements accurately and updates in real-time without noticeable delay
    - Test Steps:
        - Given the scale is powered on
        - When a series of weights starting from 0g, 50g and 100g are placed on the scale one at a time
        - Then the display should show the correct weight for each measurement immediately
    - Pass Criteria: The display shows the correct weight for each tested weight within one second

4. Flow Rate Detection
    - Test Type: Manual
    - Objective: Ensure the scale accurately detects and displays flow rate
    - Test Steps:
        - Start pouring water slowly onto a container placed on the scale
        - Observe if the scale continuously displays the flow rate in grams per second
        - Compare flow rate readings against a stopwatch and a graduated cylinder for accuracy
    - Pass Criteria: The scale’s flow rate closely matches the manual measurements
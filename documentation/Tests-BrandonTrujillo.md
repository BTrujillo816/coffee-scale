# Tests - Brandon Trujillo

## Performance Testing

![Types-of-Performance-testing-1024](C:\Repositories\coffee-scale\documentation\Tests-BrandonTrujillo.assets\Types-of-Performance-testing-1024.webp)

### Load Testing

What happens when a weight that exceeds the Load Cell's rating is placed on the scale?

- Test different types of loads
  - Anticipated loads
  - Excessive loads

### Endurance Testing

**Precision**

- Does it show the same value for a given object?
  - Given: An object of known weight
  - When: The object is removed and placed again
  - Then: The scale should display the same value each time
- Does it show the same value over a long period of time?
  - Given: An object of known weight
  - When: The object remains on the scale for an extended period of time
  - Then: The scale should continuously show the same weight for the same period of time

### Benchmark Testing

**Accuracy**

- Benchmark weight against existing products
- Benchmark time against computer/phone clock
- Benchmark flow-rate calculation against existing products

### Speed Testing

- Measure execution time of each section of code
  - Print time of execution to serial monitor
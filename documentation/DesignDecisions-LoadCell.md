# Load Cell + HX711 Design Decisions

## Calculations

### Load Cell

#### Voltage Output

$$V_{OUT}=V_{S}\times V_{E}$$

- $V_{OUT}$: Output from Load Cell
- $V_S$: Voltage Sensitivity
- $V_E$ = Excitation Voltage

### HX711

#### Full Scale Input Differential Voltage (FSR)

- Gain of 128: $\pm 20mV$
- Gain of 64: $\pm 40mV$
- Gain of 32: $\pm 80mV$

#### ADC Step Size

The data output from the ADC is a 24-bit 2's complement value.

ADC Step Size $= \frac{FSR\times2}{2^{24}}$

#### Saturation

[In Progress]

## Example Situation

Given a 1 kg Load Cell with $V_{S}=20 \space mV/V$ sensitivity and an excitation voltage of $V_E=5 \space V$

Max Output Voltage: 

$V_{OUT}=20\space mV/V\times5 \space V=100\space mV$

If an object weighs 500 g, then the output voltage (input into HX711) would be

$V_{OUT}=\frac{500}{1000}\times100=50\space mV$

If the input signal into the HX711 were to exceed these the Full Scale Input Differential Voltage, the output from the HX711 would be saturated.

$50 \space mV$ is beyond the range of $\pm 20mV$ and $\pm 40mV$; therefore, the only appropriate gain value to use is 32, which gives a range of $\pm 80mV$








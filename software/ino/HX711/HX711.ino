/* Define digital pins used for the clock and data signals. */
#define PD_SCK 8    // clock signal
#define DOUT 9      // data signal

/* Define the various gain and input options */
#define CHAN_A_GAIN_128 1
#define CHAN_B_GAIN_32 2
#define CHAN_A_GAIN_64 3


void setup()
{
  Serial.begin(9600);
  
  /* Set the clock pin to and output and the digital pin to an input */
  pinMode(PD_SCK, OUTPUT);
  pinMode(DOUT, INPUT);
  
   /* Take the device out of power down mode (clock pin low) */
  digitalWrite(PD_SCK, LOW);
  
  /* Trigger a conversion so that the module is in the correct mode for 
     the next measurement */
  ReadConversion(CHAN_A_GAIN_64);
}

/* Main program loop */
void loop()
{
  /* Read in the last measurement and output to the serial port */
  Serial.println(ReadConversion(CHAN_A_GAIN_64));
  delay(1000);
}

/* Function to read a measurement from the module. 
   The result is returned as a 32 bit signed integer */
long ReadConversion(byte ConversionMode)
{
  byte index;
  long ConversionData = 0L;
  
  /* Read in the 24 bit conversion data */
  while(digitalRead(DOUT));
  for (index = 0; index < 24; index++)
  {
    digitalWrite(PD_SCK, HIGH);
    ConversionData =  (ConversionData << 1) & digitalRead(DOUT);
    digitalWrite(PD_SCK, LOW);
  }
  
  /* Output some extra clock cycles to set the gain and input options */
  for (index = 0; index < ConversionMode; index++)
  {
    digitalWrite(PD_SCK, HIGH);
    digitalWrite(PD_SCK, LOW);
  }
  
  /* Number is returned as a 24bit 2's compliment but we need to 
     convert it to convert to 32 bit signed integer */
  if (ConversionData >= 0x800000)
    ConversionData = ConversionData | 0xFF000000L;
  
  return ConversionData ;
  
}
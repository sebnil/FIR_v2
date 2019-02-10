#include <FIR_v2.h> // https://github.com/sebnil/FIR_v2

#define NUMBER_OF_TAPS 4
float coefficients[NUMBER_OF_TAPS] = {0.25, 0.25, 0.25, 0.25}; // the sum should equal 1.00
FIR_v2 movingAvarageFilter(coefficients, NUMBER_OF_TAPS);

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("setup");
  
  // the coefficients can also be set later like this
  //movingAvarageFilter.setCoefficients(coefficients, NUMBER_OF_TAPS);

  Serial.println("setup done");
}

void loop()
{

  // declare input and output variables
  float input = 1; // without a real input, looking at the step response (input at unity, 1)
  float output = 0;

  for (int n = 0; n < 20; n++)
  {
    // change the input after a few samples
    if (n >= 10)
    {
      input = 2;
    }

    output = movingAvarageFilter.process(input);
    Serial.print("n: "); // print the sample number
    Serial.print(n, DEC);
    Serial.print(", input: "); // print the sample number
    Serial.print(input, DEC);
    Serial.print(", output: "); // print the sample number
    Serial.println(output, DEC);
  }

  while (true)
  {
  }; // endless loop
}

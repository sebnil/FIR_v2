# Finite impulse response (FIR) library
Simple signal processing [FIR filter](https://en.wikipedia.org/wiki/Finite_impulse_response).
This library is typically used for making a noisy signal less noisy.


## How to use
Init the filter:
```cpp
#define NUMBER_OF_TAPS 4
float coefficients[NUMBER_OF_TAPS] = {0.25, 0.25, 0.25, 0.25}; // the sum should equal 1.00
FIR_v2 movingAvarageFilter(coefficients, NUMBER_OF_TAPS);
```

Input the signal value and get processed output:
```cpp
float input = readSomeSensor();
float output = movingAvarageFilter.process(input);
```

## More complete example
```cpp
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
```
### Output:
```javascript
n: 0, input: 1.0000000000, output: 0.2500000000
n: 1, input: 1.0000000000, output: 0.5000000000
n: 2, input: 1.0000000000, output: 0.7500000000
n: 3, input: 1.0000000000, output: 1.0000000000
n: 4, input: 1.0000000000, output: 1.0000000000
n: 5, input: 1.0000000000, output: 1.0000000000
n: 6, input: 1.0000000000, output: 1.0000000000
n: 7, input: 1.0000000000, output: 1.0000000000
n: 8, input: 1.0000000000, output: 1.0000000000
n: 9, input: 1.0000000000, output: 1.0000000000
n: 10, input: 2.0000000000, output: 1.2500000000
n: 11, input: 2.0000000000, output: 1.5000000000
n: 12, input: 2.0000000000, output: 1.7500000000
n: 13, input: 2.0000000000, output: 2.0000000000
n: 14, input: 2.0000000000, output: 2.0000000000
n: 15, input: 2.0000000000, output: 2.0000000000
n: 16, input: 2.0000000000, output: 2.0000000000
n: 17, input: 2.0000000000, output: 2.0000000000
n: 18, input: 2.0000000000, output: 2.0000000000
n: 19, input: 2.0000000000, output: 2.0000000000
```


### Support my creation of open source software:
[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=sebnil&url=https://github.com/sebnil/FIR_v2)

<a href='https://ko-fi.com/A0A2HYRH' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi2.png?v=0' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>
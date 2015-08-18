/*
TODO https://github.com/sebnil/...
*/
#include "FIR_v2.h"
FIR_v2::FIR_v2() {
	float newCoefficients[] = {
		0.5,
		0.5
	};
	init(newCoefficients, 1, sizeof(newCoefficients));
}
FIR_v2::FIR_v2(float *newCoefficients) {
	float newGain = 0;
	for (int i=0; i<sizeof(newCoefficients); i++) {
		newGain += newCoefficients[i];
	}
	newGain = newGain / sizeof(newCoefficients);
	init(newCoefficients, newGain, sizeof(newCoefficients));
}
FIR_v2::FIR_v2(float *newCoefficients, float newGain) {
	init(newCoefficients, newGain, sizeof(newCoefficients));
}
FIR_v2::FIR_v2(float *newCoefficients, float newGain, unsigned int newNumberOfTaps) {
	init(newCoefficients, newGain, newNumberOfTaps);
}
void FIR_v2::init(float *newCoefficients, float newGain, unsigned int newNumberOfTaps) {
	setNumberOfTaps(newNumberOfTaps);
	setCoefficients(newCoefficients);
	gain = newGain;
	resetFilter();
}
void FIR_v2::resetFilter() {
  k = 0; //initialize so that we start to write at index 0
  for (i=0; i<numberOfTaps; i++) {
    values[i] = 0; // fill the array with 0's
  }
}
void FIR_v2::setCoefficients(float *newCoefficients) {
  for (int i=0; i<numberOfTaps; i++) {
    coefficients[i] = newCoefficients[i];
  }
  //setNumberOfTaps(sizeof(newCoefficients));
}
void FIR_v2::setNumberOfTaps(unsigned int newNumberOfTaps) {
  if (newNumberOfTaps < MAX_NUMBER_OF_TAPS)
	numberOfTaps = newNumberOfTaps;
  else
	numberOfTaps = MAX_NUMBER_OF_TAPS;
}

void FIR_v2::setGain(float newGain) {
	gain = newGain;
}

float FIR_v2::process(float in) {
  out = 0;
  values[k] = in;

  for (int i=0; i<numberOfTaps; i++) { // we step through the array
    out += coefficients[i] * values[k];
  }
  k = (k+1) % numberOfTaps;
  
  out *= gain;

  return out;
}



/*
TODO https://github.com/sebnil/...
*/
#ifndef FIR_v2_h
#define FIR_v2_h

#define MAX_NUMBER_OF_TAPS 40

class FIR_v2 {
public:
	FIR_v2();
	FIR_v2(float*);
	FIR_v2(float*, float);
	FIR_v2(float*, float, unsigned int);

  	float process(float in);
	void init(float*, float, unsigned int);
	void setNumberOfTaps(unsigned int);
	void setCoefficients(float*);
	void setGain(float);
	void resetFilter();
private:
  float values[MAX_NUMBER_OF_TAPS];
  float coefficients[MAX_NUMBER_OF_TAPS];
  float gain;
  int k; // k stores the index of the current array read to create a circular memory through the array
  unsigned int numberOfTaps;
  float out;
  int i; // just a loop counter
};
#endif



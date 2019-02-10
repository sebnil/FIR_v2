/*
TODO https://github.com/sebnil/...
*/
#ifndef FIR_v2_h
#define FIR_v2_h

#define MAX_NUMBER_OF_TAPS 40

class FIR_v2
{
public:
	FIR_v2();
	FIR_v2(float *newCoefficients, unsigned int newNumberOfTaps);

	float process(float in);
	void setCoefficients(float *, unsigned int);
	void resetFilter();

private:
	void setNumberOfTaps(unsigned int newNumberOfTaps);
	float values[MAX_NUMBER_OF_TAPS];
	float coefficients[MAX_NUMBER_OF_TAPS];
	int k; // k stores the index of the current array read to create a circular memory through the array
	unsigned int numberOfTaps;
	float out;
};
#endif

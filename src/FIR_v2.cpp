/*
https://github.com/sebnil/FIR_v2
*/
#include "FIR_v2.h"

// constructors
FIR_v2::FIR_v2()
{
	float newCoefficients[] = {
		0.5,
		0.5};
	setCoefficients(newCoefficients, 2);
}

FIR_v2::FIR_v2(float *newCoefficients, unsigned int newNumberOfTaps)
{
	setCoefficients(newCoefficients, newNumberOfTaps);
	resetFilter();
}

// public methods
void FIR_v2::resetFilter()
{
	k = 0; // initialize so that we start to write at index 0
	for (int i = 0; i < numberOfTaps; i++)
	{
		values[i] = 0; // fill the array with 0's
	}
}

void FIR_v2::setCoefficients(float *newCoefficients, unsigned int newNumberOfTaps)
{
	setNumberOfTaps(newNumberOfTaps);
	for (int i = 0; i < numberOfTaps; i++)
	{
		coefficients[i] = newCoefficients[i];
	}
}

float FIR_v2::process(float in)
{
	out = 0;
	values[k] = in;

	for (int i = 0; i < numberOfTaps; i++)
	{ // we step through the array
		out += coefficients[i] * values[i];
	}
	k = (k + 1) % numberOfTaps;

	return out;
}

// private methods
void FIR_v2::setNumberOfTaps(unsigned int newNumberOfTaps)
{
	if (newNumberOfTaps < MAX_NUMBER_OF_TAPS)
	{
		numberOfTaps = newNumberOfTaps;
	}
	else
	{
		numberOfTaps = MAX_NUMBER_OF_TAPS;
	}
}

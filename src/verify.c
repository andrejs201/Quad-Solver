#include <stdio.h>
#include <math.h>

#include "verify.h"

//returns a double with d number of decimal places
double verifyDecimalPlacement(double x, int d) {
	double new = (int)(x * pow(10, d) + 0.5); //+.5 for rounding
	return (double)new / pow(10, d);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "constants.h"

int main (void) {

	double span = 10;
	double root_chord = 0.4;
	
	// 0 is false in C
	int report = 1;
	
	FUNC_init_run(span, root_chord, report);

	return 0;
}
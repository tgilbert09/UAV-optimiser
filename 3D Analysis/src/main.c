#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

int main (void) {

	double *moment, *z, *ib_dim;
	int i;

	double weight = 100*9.81;
	double span = 6;

	printf("\nTotal span: %fm\tCurrent Weight %fN\n", span, weight);

	// Pre processing of useful/repetitive variables
	int number_of_points = (int)(((span/2)*POINTS_PER_METRE)+1);
	// Displays how many points (understanding purposes)
	printf("Numer of points (including zero): %i \n", number_of_points);
	// Calculates step incremen
	double dz = 1/(double)POINTS_PER_METRE;

	z = FUNC_spanLocations(dz, number_of_points);
	moment = FUNC_moment_distribution(weight, span, number_of_points, z);
	ib_dim = FUNC_ibeam_dimension(number_of_points, moment);
	
	printf("Total I-Beam height is currently set at (and should not exceed): %f\n", C);

	printf("\nSpan Loc(m)\tMoment(Nm)\tWeb height(m)\n");
	for( i = 0; i < number_of_points; ++i ){
		printf("%f\t%f\t%f\n", z[i], moment[i], ib_dim[i]);
	}



	// Testing new function
	printf("\nTesting that.. hi %f\n", FUNC_ibeam_dimension(moment));

	// Free memory n that
	free(ib_dim);
	free(moment);
	free(z);

	return 0;
}
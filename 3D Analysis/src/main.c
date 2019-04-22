#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

int main (void) {

	double *moment, *z, *ib_dim_B, *chord, *ib_dim_C, *ib_dim_D;
	
	int i;

	double weight = 100*9.81;
	double span = 6;
	double root_chord = 0.4;
	double thick_over_chord = 0.08;
	int ib_cutoff;

	printf("\nTotal span: %fm\tCurrent Weight %fN\n", span, weight);

	// Pre processing of useful/repetitive variables
	int number_of_points = (int)(((span/2)*POINTS_PER_METRE)+1);
	// Displays how many points (understanding purposes)
	printf("Numer of points (including zero): %i \n", number_of_points);
	// Calculates step incremen
	double dz = 1/(double)POINTS_PER_METRE;
	
	ib_cutoff = (int)(number_of_points -CAP_LENGTH*POINTS_PER_METRE);
	printf("i beam cut %i\n",ib_cutoff);

	z = FUNC_spanLocations(dz, number_of_points);
	moment = FUNC_moment_distribution(weight, span, number_of_points, z);
	chord = FUNC_chord(root_chord, number_of_points, z);
	ib_dim_C = FUNC_ibeam_C(number_of_points, z, chord, thick_over_chord, ib_cutoff);
	ib_dim_D = FUNC_ibeam_D(number_of_points, z, chord, ib_cutoff);
	ib_dim_B = FUNC_ibeam_B(number_of_points, moment, z, ib_dim_C, ib_dim_D, ib_cutoff);

	
	
	printf("Total I-Beam height is currently set at (and should not exceed): %f\n", C);

	printf("\nSpan Loc(m)\tChord(m)\tIB Height(m)\tIB Width(m)\tMoment(Nm)\tWeb height(m)\n");
	for( i = 0; i < number_of_points; ++i ){
		printf("%f\t%f\t%f\t%f\t%f\t%f\n", z[i], chord[i], ib_dim_C[i], ib_dim_D[i], moment[i], ib_dim_B[i]);
	}

	

	// Testing new function
	//printf("\nTesting that.. hi %f\n", FUNC_ibeam_dimension(moment));

	// Free memory n tha
	free(ib_dim_B);
	free(ib_dim_D);
	free(ib_dim_C);
	free(chord);
	free(moment);
	free(z);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

int main (void) {

   double *moment, *z;
   int i;

   double weight = 100*9.81;
   double span = 10;
   
   printf("\nTotal span: %fm\tCurrent Weight %fN\n", span, weight);
   
   // Pre processing of useful/repetitive variables
   int number_of_points = (int)(((span/2)*POINTS_PER_METRE)+1);
   // Displays how many points (understanding purposes)
   printf("Numer of points (including zero): %i \n", number_of_points);
   // Calculates step incremen
   double dz = 1/(double)POINTS_PER_METRE;
	
   z = FUNC_spanLocations(dz, number_of_points);
   moment = FUNC_moment_distribution(weight, span, number_of_points, z);
   
   printf("\nSpan Loc(m)\tMoment(Nm)\n");
	for( i = 0; i < number_of_points; ++i ){
	   printf("%f\t%f \n", z[i], moment[i]);
	}
	
   // Testing new function
   printf("\nTesting that.. hi %f\n", FUNC_ibeam_dimension(moment));

   free(moment);
   free(z);

   return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

/* main function to call above defined function */
int main (void) {

   
   double *moment_distribution, *z;
   int i;

   double weight = 100;
   double chord = 0.3;
   double span = 10;
   
   // Pre processing of useful/repetitive variables
   int number_of_points = (int)(((span/2)*POINTS_PER_METRE)+1);
   double dz = 1/(double)POINTS_PER_METRE;
	
   z = FUNC_spanning(number_of_points);
   moment_distribution = FUNC_moment_distribution(weight, chord, span, dz, number_of_points);
   

	
   for ( i = 0; i < number_of_points; i++ ) {
      printf( "Location ID: %i, z: %f, Moment: %f\n", i, *(z+i), *(moment_distribution + i));
   }
   
   free(moment_distribution);

   return 0;
}
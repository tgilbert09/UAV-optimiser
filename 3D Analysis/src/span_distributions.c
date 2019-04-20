#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"


double *FUNC_spanLocations(double dz,
					  int number_of_points){

	// Program required
	int i;
	
	// Create spanwise distances array
	double *z = malloc(number_of_points*sizeof(double));
		
	// Fill spanwise distances array
	// The matrix (from 0 to whatever) represents root to tip
	for( i = 0; i < number_of_points; ++i ){
		// z - spanwise locations
		z[i] = dz * i;
	}
	
	return z;
}


double *FUNC_moment_distribution(double weight,
								 double span,
								 int number_of_points,
								 double *z){	
	
	// Program required
	int i;
	
	// Calculates the required central sectional lift coefficient to attain the desired global CL
	double centre_lift_2d = CL * 4/(span*M_PI/2);
	printf("Centre sectional lift coefficient: %f\n", centre_lift_2d);
	
	// Creates memory space for distributed_moment array to be returned
	double *distributed_moment = malloc(number_of_points*sizeof(double));
	  
	// Raises exception incase something goes horribly wrong
	if(!distributed_moment)
      return NULL;
	
	for( i = 0; i < number_of_points; ++i ){
	  distributed_moment[i] = (3*weight*(pow((span/2 - z[i]),2) - pow((span/2 - z[i]),4)/(3*pow(span,2))))/(2*pow(span,2));
	}
	
	// Return the gold..
	return distributed_moment;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

double *FUNC_spanning(double dz,
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
								 double chord,
								 double span,
								 double dz,
								 int number_of_points,
								 double *z){	
	
	// Program required
	int i;
	
	// Calculates the required central sectional lift coefficient to attain the desired global CL
	double centre_lift_2d = CL * 4/(span*M_PI/2);
	//printf("Centre sectional lift coefficient: %f\n", centre_lift_2d);

	// The matrix (from 0 to whatever) represents root to tip
	double load[number_of_points],
		   distributed_shear_force[number_of_points];
	
	// Creates memory space for distributed_moment array to be returned
	double *distributed_moment = malloc(number_of_points*sizeof(double));
	  
	// Raises exception incase something goes horribly wrong
	if(!distributed_moment)
      return NULL;
	
	
	
	
	/* Easier to understand but uses more memory?
	// cl - sectional lift coefficients at given z
	// load - force given a cl at given z
	for( i = 0; i < number_of_points; ++i ){
		cl[i] = centre_lift_2d * pow(1-pow(2*(*(z+i))/span, 2), 0.5);
		load[i] = cl[i]*0.5*AIR_DENSITY*pow(VELOCITY, 2)*chord;
		//printf("value of i: %i , %f, %f, %f\n", i, z[i], cl[i], load[i]);
	}
	*/
	
	
	/* Explanation
		Calculates load (newtons/metre) distributed along span at given z location
		centre_lift_2d * pow(1-pow(2*(*(z+i))/span, 2), 0.5) represents the local lift coefficient
		This is then multiplied by 0.5*AIR_DENSITY*pow(VELOCITY, 2)*chord to get the local load at a given z	
	*/
	for( i = 0; i < number_of_points; ++i ){
		load[i] = (centre_lift_2d * pow(1-pow(2*(*(z+i))/span, 2), 0.5))*0.5*AIR_DENSITY*pow(VELOCITY, 2)*chord;
	}
	
	/* Initialises for loop
	   Moment distribution requires calc from tip to root not root to tip
	*/
	distributed_shear_force[number_of_points-1] = load[number_of_points-1];
	distributed_moment[number_of_points-1] = z[number_of_points-1] * load[number_of_points-1];
	
	
	/*
	// Understanding purposes
	printf("i: %i, location: %f, distributed shear: %f, distributed moment: %f\n", 
	number_of_points-1, z[number_of_points-1], distributed_shear_force[number_of_points-1], 
	distributed_moment[number_of_points-1]);
	*/
	
	
	// Continue with above in for loop
	for( i = number_of_points-1; i > 0; --i ){
		distributed_shear_force[i-1] = distributed_shear_force[i] + load[i-1] * dz;
		distributed_moment[i-1] = distributed_moment[i] + (span/2 - *(z+i-1)) * load[i-1] * dz;
		//printf("i: %i, location: %f, distributed shear: %f, distributed moment: %f\n", i-1, z[i-1], 
		//distributed_shear_force[i-1], distributed_moment[i-1]);
	}
	
	// Return the gold..
	return distributed_moment;
}
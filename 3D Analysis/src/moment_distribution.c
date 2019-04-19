#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

double *FUNC_moment_distribution(double weight, double chord, double span, double dz, int number_of_points){	

	// Program required
	int i;
	
	// Behind the scenes maths requirements
	// Value of centre local lift coefficient to achieve required global lift coefficent
	double centre_lift_2d;

	
	// The matrix (from 0 to whatever) represents root to tip
	double z[number_of_points],
		   cl[number_of_points],
		   load[number_of_points],
		   distributed_shear_force[number_of_points];
	
	// Special matrix which can be returned
	double *distributed_moment = malloc(number_of_points*sizeof(double));
	  
	  // Raises exception incase something goes horribly wrong
	  if(!distributed_moment)
        return NULL;
	
	
	// Calculates the required central sectional lift coefficient to attain the desired global CL
	centre_lift_2d = CL * 4/(span*M_PI/2);
	//printf("Centre sectional lift coefficient: %f\n", centre_lift_2d);
	
	// Displays how many points working with for understanding
	//printf("Numer of points (including zero): %i \n", number_of_points);

	// z - spanwise locations
	// cl - sectional lift coefficients at given z
	// load - force given a cl at given z
	for( i = 0; i < number_of_points; ++i ){
		z[i] = dz * i;
		cl[i] = centre_lift_2d * pow(1-pow(2*z[i]/span, 2), 0.5);
		load[i] = cl[i]*0.5*AIR_DENSITY*pow(VELOCITY, 2)*chord;
		//printf("value of i: %i , %f, %f, %f\n", i, z[i], cl[i], load[i]);
	}
	
	// Strange setup required before for loop as I couldn't think of how to initiate it
	// Only additionally complex due to reversing nature of these shear force and moment distributions
	// (requires calc from tip to root not root to tip)
	distributed_shear_force[number_of_points-1] = load[number_of_points-1];
	distributed_moment[number_of_points-1] = z[number_of_points-1] * load[number_of_points-1];
	
	// Start the first line of display
	//printf("i: %i, location: %f, distributed shear: %f, distributed moment: %f\n", 
	//number_of_points-1, z[number_of_points-1], distributed_shear_force[number_of_points-1], 
	//distributed_moment[number_of_points-1]);
	
	// Continue with above in for loop!
	for( i = number_of_points-1; i > 0; --i ){
		distributed_shear_force[i-1] = distributed_shear_force[i] + load[i-1] * dz;
		distributed_moment[i-1] = distributed_moment[i] + (span/2 - z[i-1]) * load[i-1] * dz;
		//printf("i: %i, location: %f, distributed shear: %f, distributed moment: %f\n", i-1, z[i-1], 
		//distributed_shear_force[i-1], distributed_moment[i-1]);
	}
	
	// Return the gold..
	return distributed_moment;
}
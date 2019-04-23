#include <stdlib.h>
#include "constants.h"

double *FUNC_wing_weight_initial(int number_of_points){
	
	// Program required
	int i;
	
	// Create spanwise weight array
	double *weight = malloc(number_of_points*sizeof(double));
	
	// Raises exception incase something goes horribly wrong
	if(!weight)
      return NULL;
		
	for( i = 0; i < number_of_points-1; ++i ){
		weight[i] = 0;
	}
	
	return weight;
}

double *FUNC_wing_weight(int number_of_points, double *ib_area, double dz){
	
	// Program required
	int i;
	
	// Create spanwise weight array
	double *weight = malloc(number_of_points*sizeof(double));
	
	// Raises exception incase something goes horribly wrong
	if(!weight)
      return NULL;
		
	for( i = 0; i < number_of_points-1; ++i ){
		weight[i] = ib_area[i]*IB_MATERIAL_DENSITY*9.91;
	}
	
	return weight;
}

double FUNC_total_wing_weight(int number_of_points, double *wing_weight, double dz){
	
	// Program required
	int i;
	
	double total_weight = 0;
				
	for( i = 0; i < number_of_points-1; ++i ){
		total_weight = total_weight + ((wing_weight[i]+wing_weight[i+1])/2)*dz;
	}
	
	return total_weight;
}
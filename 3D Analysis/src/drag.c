#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"
#include "constants.h"

double FUNC_weight(int number_of_points, double *ib_area, double dz){
	
	// Program required
	int i;
	
	// Create sectional chord array
	double weight = 0;
		
	for( i = 0; i < number_of_points-1; ++i ){
		weight = weight + ((ib_area[i]+ib_area[i+1])/2)*dz*IB_MATERIAL_DENSITY;
	}
	
	return weight;
}
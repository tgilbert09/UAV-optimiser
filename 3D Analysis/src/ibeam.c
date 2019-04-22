#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "functions.h"

double *FUNC_ibeam_C(int number_of_points, double *z, double *chord, double thick_over_chord, int ib_cutoff){
	
	// Program required
	int i;	
	
	//ib_dim stands for I-Beam Dimension (the one we are optimising)
	// Creates memory space for distributed_moment array to be returned
	double *ib_dim_C = malloc(number_of_points*sizeof(double));
	  
	// Raises exception incase something goes horribly wrong
	if(!ib_dim_C)
		return NULL;
	

	for( i = 0; i < ib_cutoff; ++i ){
		ib_dim_C[i] = chord[i]* thick_over_chord * C;	
	}
	return ib_dim_C;
}

double *FUNC_ibeam_D(int number_of_points, double *z, double *chord, int ib_cutoff){
	
	// Program required
	int i;	
	
	//ib_dim stands for I-Beam Dimension (the one we are optimising)
	// Creates memory space for distributed_moment array to be returned
	double *ib_dim_D = malloc(number_of_points*sizeof(double));
	  
	// Raises exception incase something goes horribly wrong
	if(!ib_dim_D)
		return NULL;

	for( i = 0; i < ib_cutoff; ++i ){
		ib_dim_D[i] = chord[i] * D;	
	}
	return ib_dim_D;
}



double *FUNC_ibeam_B(int number_of_points, double *M, double *z, double *ib_dim_C, double *ib_dim_D, int ib_cutoff){
	
	// Program required
	int i;	
	
	//ib_dim stands for I-Beam Dimension (the one we are optimising)
	// Creates memory space for distributed_moment array to be returned
	double *ib_dim_B = malloc(number_of_points*sizeof(double));
	  
	// Raises exception incase something goes horribly wrong
	if(!ib_dim_B)
		return NULL;


	double sig;
	sig = SIGMA_MAX * SAFTEY_FACTOR;

	for( i = 0; i < ib_cutoff; ++i ){
	  //ib_dim[i] = pow(sqrt((C*C)*1.0/(sig*sig)*1.0/pow(A*4.0-D*7.0,4.0)*((A*A)*(M[i]*M[i])*5.76E2+(D*D)*(M[i]*M[i])*1.764E3+(C*C*C*C)*(D*D*D*D)*(sig*sig)*6.4E1-A*D*(M[i]*M[i])*2.016E3+(A*A)*(C*C*C*C)*(D*D)*(sig*sig)*4.9E1-(C*C)*(D*D*D)*M[i]*sig*6.24E2-A*(C*C*C*C)*(D*D*D)*(sig*sig)*1.04E2+A*(C*C)*(D*D)*M[i]*sig*8.52E2-(A*A)*(C*C)*D*M[i]*sig*3.36E2))*2.0+(C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)/(sig*(A*4.0-D*7.0)*2.0)-(C*C*C)*(D*D)*1.0/pow(A*4.0-D*7.0,2.0)*(2.7E1/2.0)-(C*C*C)*(D*D*D)*1.0/pow(A*4.0-D*7.0,3.0)*2.7E1,1.0/3.0)-(C*D*3.0)/(A*4.0-D*7.0)+(C*C)*D*(A-D)*1.0/pow(A*4.0-D*7.0,2.0)*1.0/pow(sqrt((C*C)*1.0/(sig*sig)*1.0/pow(A*4.0-D*7.0,4.0)*((A*A)*(M[i]*M[i])*5.76E2+(D*D)*(M[i]*M[i])*1.764E3+(C*C*C*C)*(D*D*D*D)*(sig*sig)*6.4E1-A*D*(M[i]*M[i])*2.016E3+(A*A)*(C*C*C*C)*(D*D)*(sig*sig)*4.9E1-(C*C)*(D*D*D)*M[i]*sig*6.24E2-A*(C*C*C*C)*(D*D*D)*(sig*sig)*1.04E2+A*(C*C)*(D*D)*M[i]*sig*8.52E2-(A*A)*(C*C)*D*M[i]*sig*3.36E2))*2.0+(C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)/(sig*(A*4.0-D*7.0)*2.0)-(C*C*C)*(D*D)*1.0/pow(A*4.0-D*7.0,2.0)*(2.7E1/2.0)-(C*C*C)*(D*D*D)*1.0/pow(A*4.0-D*7.0,3.0)*2.7E1,1.0/3.0)*1.2E1;
	  //ib_dim[i] = C*(3.0/7.0)+((C*C)*(9.0/4.9E1)+(M[i]*2.4E1-(C*C)*D*sig*9.0)/(D*sig*2.1E1))*1.0/pow((C*C*C)*(2.7E1/3.43E2)+sqrt(pow((C*C*C)*(2.7E1/3.43E2)-(A*(C*C*C)*sig*4.0-(C*C*C)*D*sig*7.0)/(D*sig*1.4E1)+(C*(M[i]*2.4E1-(C*C)*D*sig*9.0)*(3.0/9.8E1))/(D*sig),2.0)-pow((C*C)*(9.0/4.9E1)+(M[i]*2.4E1-(C*C)*D*sig*9.0)/(D*sig*2.1E1),3.0))-(A*(C*C*C)*sig*4.0-(C*C*C)*D*sig*7.0)/(D*sig*1.4E1)+(C*(M[i]*2.4E1-(C*C)*D*sig*9.0)*(3.0/9.8E1))/(D*sig),1.0/3.0)+pow((C*C*C)*(2.7E1/3.43E2)+sqrt(pow((C*C*C)*(2.7E1/3.43E2)-(A*(C*C*C)*sig*4.0-(C*C*C)*D*sig*7.0)/(D*sig*1.4E1)+(C*(M[i]*2.4E1-(C*C)*D*sig*9.0)*(3.0/9.8E1))/(D*sig),2.0)-pow((C*C)*(9.0/4.9E1)+(M[i]*2.4E1-(C*C)*D*sig*9.0)/(D*sig*2.1E1),3.0))-(A*(C*C*C)*sig*4.0-(C*C*C)*D*sig*7.0)/(D*sig*1.4E1)+(C*(M[i]*2.4E1-(C*C)*D*sig*9.0)*(3.0/9.8E1))/(D*sig),1.0/3.0);
	  //ib_dim[i] = pow(C,1.0/3.0)*1.0/pow(sig,1.0/3.0)*1.0/pow(A-D,1.0/3.0)*pow(M[i]*6.0-(C*C)*D*sig,1.0/3.0);
	  
	  // MATLAB rearranged for B, parallel axis theorem
	  //ib_dim[i] = ((C*C)*(D*D)*(sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,2.0)*9.0+((C*C)*D*sig*3.0)/(A*sig*4.0-D*sig*7.0))*1.0/pow((C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)/(A*sig*8.0-D*sig*1.4E1)+sqrt(-pow((C*C)*(D*D)*(sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,2.0)*9.0+((C*C)*D*sig*3.0)/(A*sig*4.0-D*sig*7.0),3.0)+pow(((C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)*(-1.0/2.0))/(A*sig*4.0-D*sig*7.0)+(C*C*C)*(D*D)*(sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,2.0)*(2.7E1/2.0)+(C*C*C)*(D*D*D)*(sig*sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,3.0)*2.7E1,2.0))-(C*C*C)*(D*D)*(sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,2.0)*(2.7E1/2.0)-(C*C*C)*(D*D*D)*(sig*sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,3.0)*2.7E1,1.0/3.0)+pow((C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)/(A*sig*8.0-D*sig*1.4E1)+sqrt(-pow((C*C)*(D*D)*(sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,2.0)*9.0+((C*C)*D*sig*3.0)/(A*sig*4.0-D*sig*7.0),3.0)+pow(((C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)*(-1.0/2.0))/(A*sig*4.0-D*sig*7.0)+(C*C*C)*(D*D)*(sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,2.0)*(2.7E1/2.0)+(C*C*C)*(D*D*D)*(sig*sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,3.0)*2.7E1,2.0))-(C*C*C)*(D*D)*(sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,2.0)*(2.7E1/2.0)-(C*C*C)*(D*D*D)*(sig*sig*sig)*1.0/pow(A*sig*4.0-D*sig*7.0,3.0)*2.7E1,1.0/3.0)-(C*D*sig*3.0)/(A*sig*4.0-D*sig*7.0);
	  // Equation shown above run through MATLAB's simplify().. above and below eqns give same results
	  //ib_dim_B[i] = pow(sqrt((C*C)*1.0/(sig*sig)*1.0/pow(A*4.0-D*7.0,4.0)*((A*A)*(M[i]*M[i])*5.76E2+(D*D)*(M[i]*M[i])*1.764E3+(C*C*C*C)*(D*D*D*D)*(sig*sig)*6.4E1-A*D*(M[i]*M[i])*2.016E3+(A*A)*(C*C*C*C)*(D*D)*(sig*sig)*4.9E1-(C*C)*(D*D*D)*M[i]*sig*6.24E2-A*(C*C*C*C)*(D*D*D)*(sig*sig)*1.04E2+A*(C*C)*(D*D)*M[i]*sig*8.52E2-(A*A)*(C*C)*D*M[i]*sig*3.36E2))*2.0+(C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)/(sig*(A*4.0-D*7.0)*2.0)-(C*C*C)*(D*D)*1.0/pow(A*4.0-D*7.0,2.0)*(2.7E1/2.0)-(C*C*C)*(D*D*D)*1.0/pow(A*4.0-D*7.0,3.0)*2.7E1,1.0/3.0)-(C*D*3.0)/(A*4.0-D*7.0)+(C*C)*D*(A-D)*1.0/pow(A*4.0-D*7.0,2.0)*1.0/pow(sqrt((C*C)*1.0/(sig*sig)*1.0/pow(A*4.0-D*7.0,4.0)*((A*A)*(M[i]*M[i])*5.76E2+(D*D)*(M[i]*M[i])*1.764E3+(C*C*C*C)*(D*D*D*D)*(sig*sig)*6.4E1-A*D*(M[i]*M[i])*2.016E3+(A*A)*(C*C*C*C)*(D*D)*(sig*sig)*4.9E1-(C*C)*(D*D*D)*M[i]*sig*6.24E2-A*(C*C*C*C)*(D*D*D)*(sig*sig)*1.04E2+A*(C*C)*(D*D)*M[i]*sig*8.52E2-(A*A)*(C*C)*D*M[i]*sig*3.36E2))*2.0+(C*M[i]*2.4E1-(C*C*C)*D*sig*7.0)/(sig*(A*4.0-D*7.0)*2.0)-(C*C*C)*(D*D)*1.0/pow(A*4.0-D*7.0,2.0)*(2.7E1/2.0)-(C*C*C)*(D*D*D)*1.0/pow(A*4.0-D*7.0,3.0)*2.7E1,1.0/3.0)*1.2E1;
	  ib_dim_B[i] = pow(sqrt((ib_dim_C[i]*ib_dim_C[i])*1.0/(sig*sig)*1.0/pow(A*4.0-ib_dim_D[i]*7.0,4.0)*((A*A)*(M[i]*M[i])*5.76E2+(ib_dim_D[i]*ib_dim_D[i])*(M[i]*M[i])*1.764E3+(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*(sig*sig)*6.4E1-A*ib_dim_D[i]*(M[i]*M[i])*2.016E3+(A*A)*(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i])*(sig*sig)*4.9E1-(ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*M[i]*sig*6.24E2-A*(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*(sig*sig)*1.04E2+A*(ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i])*M[i]*sig*8.52E2-(A*A)*(ib_dim_C[i]*ib_dim_C[i])*ib_dim_D[i]*M[i]*sig*3.36E2))*2.0+(ib_dim_C[i]*M[i]*2.4E1-(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*ib_dim_D[i]*sig*7.0)/(sig*(A*4.0-ib_dim_D[i]*7.0)*2.0)-(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i])*1.0/pow(A*4.0-ib_dim_D[i]*7.0,2.0)*(2.7E1/2.0)-(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*1.0/pow(A*4.0-ib_dim_D[i]*7.0,3.0)*2.7E1,1.0/3.0)-(ib_dim_C[i]*ib_dim_D[i]*3.0)/(A*4.0-ib_dim_D[i]*7.0)+(ib_dim_C[i]*ib_dim_C[i])*ib_dim_D[i]*(A-ib_dim_D[i])*1.0/pow(A*4.0-ib_dim_D[i]*7.0,2.0)*1.0/pow(sqrt((ib_dim_C[i]*ib_dim_C[i])*1.0/(sig*sig)*1.0/pow(A*4.0-ib_dim_D[i]*7.0,4.0)*((A*A)*(M[i]*M[i])*5.76E2+(ib_dim_D[i]*ib_dim_D[i])*(M[i]*M[i])*1.764E3+(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*(sig*sig)*6.4E1-A*ib_dim_D[i]*(M[i]*M[i])*2.016E3+(A*A)*(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i])*(sig*sig)*4.9E1-(ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*M[i]*sig*6.24E2-A*(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*(sig*sig)*1.04E2+A*(ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i])*M[i]*sig*8.52E2-(A*A)*(ib_dim_C[i]*ib_dim_C[i])*ib_dim_D[i]*M[i]*sig*3.36E2))*2.0+(ib_dim_C[i]*M[i]*2.4E1-(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*ib_dim_D[i]*sig*7.0)/(sig*(A*4.0-ib_dim_D[i]*7.0)*2.0)-(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i])*1.0/pow(A*4.0-ib_dim_D[i]*7.0,2.0)*(2.7E1/2.0)-(ib_dim_C[i]*ib_dim_C[i]*ib_dim_C[i])*(ib_dim_D[i]*ib_dim_D[i]*ib_dim_D[i])*1.0/pow(A*4.0-ib_dim_D[i]*7.0,3.0)*2.7E1,1.0/3.0)*1.2E1;
	}
	return ib_dim_B;
}


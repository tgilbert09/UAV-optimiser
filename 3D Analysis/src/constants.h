// Constants used throughout the analysis

// Aerodynamics
#define VELOCITY 41.6667       // m/s
#define AIR_DENSITY 1.1685     // kg/m^3
// Target 3D global lift coefficient
#define CL 0.5

// Materials
#define SIGMA_MAX 210e6        // N/m^2
#define IB_MATERIAL_DENSITY 2800    // kg/m^3
// Allowable stress saftey factor (percentage of SIGMA_MAX allowable)
#define SAFTEY_FACTOR 0.035      // unitless // supposed to be 0.19 

// Structures
// I-Beam dimensions - see latex report for diagram
// A is web thickness
#define A 0.001
// C*(t/c)*c is height (where c is aerofoil chord, t is aerofoil thickness)
#define C 0.9375
// D*c is width (where c is aerofoil chord)
#define D 0.133
// Cap length is the amount shorter the I-beam is than the wing
// Special cap structure used for the rest of the wing
#define CAP_LENGTH 0.6         // m

/* How many spanwise "points" are used for the calculation,
   defines "dz" size, a higher POINTS_PER_METRE gives lower dz thus greater accuracy
   100 gives ~ 1 d.p. accuracy		5.205173kg
   1000 gives ~ 2 d.p. accuracy 	5.186109
   10,000 gives ~ 3.d.p accuracy	5.184190
   100,000 gives 					5.184004
   Getting numberical errors when POINTS_PER_METRE < span*10 - 2
   38 for 4m span
   30 for 5m span
   25 for 6m span*/
#define POINTS_PER_METRE 25   // 
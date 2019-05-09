// Constants used throughout the analysis

// Aerodynamics
#define VELOCITY 41.6667       // m/s
#define AIR_DENSITY 1.1685     // kg/m^3

// Materials - Al 6061
#define SIGMA_MAX 290e6        // N/m^2
#define IB_MATERIAL_DENSITY 2700    // kg/m^3
// Allowable stress saftey factor (percentage of SIGMA_MAX allowable)
#define SAFTEY_FACTOR 0.5      // unitless // supposed to be 0.19   0.035

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
// Wing skin properties
#define SKIN_DENSITY 1780		// kg/m3
#define SKIN_THICKNESS 0.0005
// These coeffients estimate the aerofoil perimeter in terms of (SKIN_COEFFICIENT_1)chord + SKIN_COEFFICIENT_2
#define SKIN_COEFFICIENT_1 2.123
#define SKIN_COEFFICIENT_2 -0.039525


/* How many spanwise "points" are used for the calculation,
   defines "dz" size, a higher POINTS_PER_METRE --> lower dz --> greater accuracy
   Getting numberical errors when POINTS_PER_METRE is too small, minimum value examples shown below
   38 for 4m span
   30 for 5m span
   25 for 6m span*/
#define POINTS_PER_METRE 500   // 


// Wing setup
// Chord variable testing
#define START_CHORD 0.4
#define END_CHORD 1
#define CHORD_POINTS_PER_METRE 100
// Span variable testing
#define START_SPAN 8
#define END_SPAN 10
#define SPAN_POINTS_PER_METRE 1







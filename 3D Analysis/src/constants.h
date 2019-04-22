// Constants used throughout the analysis

// Aerodynamics
#define VELOCITY 41.6667       // m/s
#define AIR_DENSITY 1.1685     // kg/m^3
// Target 3D global lift coefficient
#define CL 0.5

// Materials
#define SIGMA_MAX 210e6        // N/m^2
#define MATERIAL_DENSITY 15    // kg/m^3

// Structure
#define CAP_LENGTH 0.1         // m

// --- Fine tunning required here ---
// Allowable stress saftey factor (percentage of SIGMA_MAX allowable)
#define SAFTEY_FACTOR 0.19      // unitless
/* How many spanwise "points" are used for the calculation,
   defines "dz" size, a higher POINTS_PER_METRE gives lower dz thus greater accuracy */
#define POINTS_PER_METRE 100   // 
// I-Beam dimensions - see latex report for diagram
// A is web thickness
#define A 0.001
// C*(t/c)*c is height (where c is aerofoil chord, t is aerofoil thickness)
#define C 0.9375
// D*c is width (where c is aerofoil chord)
#define D 0.133
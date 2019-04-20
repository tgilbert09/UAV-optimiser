// Constants used throughout the analysis

// Aerodynamics
#define VELOCITY 41.6667       // m/s
#define AIR_DENSITY 1.1685     // kg/m^3
// Target 3D global lift coefficient
#define CL 0.5

// Materials
#define SIGMA_MAX 210e6         // N/m^2
#define MATERIAL_DENSITY 15    // kg/m^3

// --- Fine tunning required here ---
// Allowable stress saftey factor (percentage of SIGMA_MAX allowable)
#define SAFTEY_FACTOR 0.3      // unitless
/* How many spanwise "points" are used for the calculation,
   defines "dz" size, a higher POINTS_PER_METRE gives lower dz thus greater accuracy */
#define POINTS_PER_METRE 1   // 
// I-Beam dimensions - see latex report for diagram
// A is web thickness
#define A 0.015
// C is height
#define C 0.2
// D is width
#define D 0.15
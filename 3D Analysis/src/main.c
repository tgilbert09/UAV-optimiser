#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "constants.h"

int main (void) {
	
	int span_points;
	double min_span = 7;
	double max_span = 10;
	double span_increment = 0.1;
	
	int chord_points;
	double min_root_chord = 0.3;
	double max_root_chord = 0.5;
	double chord_increment = 0.01;
	double drag, span, root_chord;


	// 0 is false in C, 1 for true
	int report = 0;
	int i, j;
	
	printf("Root Chord(m)\tSpan(m)\t\tDrag(N)\n");
	
	span_points = (int)((max_span+span_increment)-min_span)/span_increment;
	chord_points = (int)(((max_root_chord+chord_increment)-min_root_chord)/chord_increment);	
	
	FILE *fp;
	fp = fopen("induced_drag_landscape_results.csv", "w");
	
	for( j = 0; j < chord_points; ++j ){
		root_chord = min_root_chord + j*chord_increment;
		for( i = 0; i <= span_points; ++i ){
			span = min_span + i*span_increment;
			drag = FUNC_init_run(span, root_chord, report);
			printf("%f\t%f\t%f\n", root_chord, span, drag);
			fprintf(fp, "%f,%f,%f\n", span, root_chord, drag);
		}
	}
	
	fclose(fp);
	
	return 0;
}
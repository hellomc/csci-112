/*
*/

#include <stdio.h>

int main() {
	float distance, time, speed_miph, speed_mps;

	distance = 425.0;
	time = 7.5;
	
	speed_miph = distance / time;
	speed_mps = speed_miph * 1600.0 / 3600;

	printf("The Speed in Miles per Hour: %f, The Speed in Meters per Second: %f\n", speed_miph, speed_mps);
	//printf("The Speed in Meters per Second: %f\n", speed_mps);

	getchar();
	return 0;
}

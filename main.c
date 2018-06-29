/*
*/

#include <stdio.h>
#define TIME 7.5
#define DISTANCE 425.5

int main() {
	float speed_miph, speed_mps;

	speed_miph = DISTANCE / TIME;
	speed_mps = speed_miph * 1600.0 / 3600;

	printf("The Speed in Miles per Hour: %f, The Speed in Meters per Second: %f\n", speed_miph, speed_mps);
	//printf("The Speed in Meters per Second: %f\n", speed_mps);

	getchar();
	return 0; 
}

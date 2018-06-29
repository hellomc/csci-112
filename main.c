#include <stdio.h>

/* Author Michelle Adea
Date: 2018 June 26
Purpose: Write a program that converts miles per hour to meters per second.
*/

int main()
{
	float distance;
	float time;
	float speed_miph;
	float speed_mps;

	distance = 425.5; // Value for distance traveled by car.
	time = 7.5; // Value for the number of hours for traveling above distance.

	speed_miph = distance / time; // Expression solves for speed in miles per hour.
	printf("Speed in Miles per Hour = %f\n", speed_miph);

	speed_mps = speed_miph * 1600.0 / 3600; // Expression converts miph to meters per second.
	printf("speed in Meters per Second = %f\n", speed_mps);

	getchar();
	return 0;
}
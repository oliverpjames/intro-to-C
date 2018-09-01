#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi()
{
	double i, x, y;
	int n = 1e7;
	double pi;
	float count = 0;
	
	for(i = 0; i < n; i = i + 1)
	{
		x = rand()/(double)RAND_MAX;
		y = rand()/(double)RAND_MAX;		
		if (pow((pow(x, 2) + pow(y, 2)), 0.5) < 1)
			count++;
	}
	pi = 4*count/n;	
	return pi;
}
/*void main()
{
	printf("\n\tpi is: %f\n\n", pi());
}*/

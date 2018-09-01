/* prog8 - reading from a text file */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXVALS 100

int main()
{
	float value[MAXVALS], sum, mean, stddev;
	int i, count;
	FILE *fh;

/* Open the data file */
	fh = fopen("file.dat", "r");
	if ( fh == NULL ) 
	{
		printf("Cannot open data file\n");
		exit(EXIT_FAILURE);
	}

/* Initialise counter */
	count = 0;
/* Read all the values in the file */
	while ( ! feof(fh) && count < MAXVALS ) 
	{
		if ( fscanf(fh, "%f", &value[count]) > 0 ) 
			{ count = count + 1; }
	}

/* Close the file */
	fclose(fh);

/* Check the file contains data */
	if ( count == 0 )
	{
		printf("Data file contains no values\n");
		exit(EXIT_FAILURE);
	} else 
	{
		printf("Read %d values from file\n", count);
	}

/* Calculate the mean */
	sum = 0.0;
	for ( i = 0; i < count; i = i + 1 )
		{ sum = sum + value[i]; }

	mean = sum / count;
	printf("Mean value is %f\n", mean);

/* Calculate the standard deviation */
	sum = 0.0;
	for ( i = 0; i < count; i = i + 1 )
		sum = sum + powf(value[i] - mean, 2.0);
	stddev = sqrt(sum) / count;
	printf("Standard deviation is %f\n", stddev);
	fh = fopen("results.dat","w");
	fprintf(fh,"Mean value is %f\n", mean);
	fprintf(fh,"Standard deviation is %f\n", stddev);
	fclose(fh);
}


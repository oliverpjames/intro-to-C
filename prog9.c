/* prog9 - reading a tabulation file and performing linear regression */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXCLUNAMLEN 10
#define MAXCLU 100
#define MAXHEAD 60

struct clusterinfo {
	char name[MAXCLUNAMLEN];
	int nneb;
	float rvel,pmag;
};

int main() {
	struct clusterinfo clist[MAXCLU];
	char header[MAXHEAD];
	int i, count;
	FILE *fh;
	float sumx=0.0, sumy=0.0, sumxx=0.0, sumxy=0.0;
	float del, gradient, intercept;

/* Open the data file */
	fh = fopen("hubble.dat", "r");
	if ( fh == NULL ) {
		printf("Cannot open data file hubble.dat\n");
	exit(EXIT_FAILURE);
	}

/* read header line from file */
	fgets(header,MAXHEAD,fh);

/* Initialise counter */
	count = 0;

/* Read all cluster info from the file */
	while ( ! feof(fh) && count < MAXCLU ) {
		if ( fscanf(fh, "%s %d %f %f",
			&clist[count].name,&clist[count].nneb,&clist[count].rvel,
			&clist[count].pmag) > 0 ) count = count + 1;
	}

/* Close the file */
	fclose(fh);

/* Check the file contains data */
	if ( count == 0 ) {
		printf("Data file hubble.dat contains no data\n");
		exit(EXIT_FAILURE);
	} else {
		printf("Read info for %d clusters from file hubble.dat\n", count);
	}

/* List data and perform linear regression on log(rvel) vs. pmag */
	printf("%s",header);
	for (i = 0; i < count; i = i + 1) {
		printf("%s %d %f %f \n",clist[i].name,clist[i].nneb,
		clist[i].rvel,clist[i].pmag);
		sumy = sumy + log10(clist[i].rvel);
		sumx = sumx + clist[i].pmag;
		sumxx = sumxx + clist[i].pmag * clist[i].pmag;
		sumxy = sumxy + clist[i].pmag * log10(clist[i].rvel);
	}

	del=count*sumxx-sumx*sumx;
	gradient=(count*sumxy-sumx*sumy)/del;
	intercept=(sumxx*sumy-sumx*sumxy)/del;

/* print results */
	printf("log10(rvel) = %f * pmag + %f\n", gradient,intercept);
}

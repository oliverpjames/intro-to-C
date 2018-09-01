/* prog10 - tabulation of sawtooth function */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXT 1000
double sawtooth_amp(double tr, double tf, double tc, double tz, double t);
int main()
{
double tmin=-14.,tmax=14.,tsam;
double trise=1.0,tfall=5.0,tcons=4.0,tzero=3.0;
int nt=MAXT,i;
double t[MAXT],ft[MAXT];
FILE *fh;
/* Set up time samples and calculate function */
tsam=(tmax-tmin)/(nt-1);
for(i=0; i<nt; i=i+1) {
t[i]=tmin+tsam*i;
ft[i]=sawtooth_amp(trise,tfall,tcons,tzero,t[i]);
}
/* Produce a tabulation of function on file */
fh = fopen("sawtooth.dat","w");
fprintf(fh,"i t amp\n");
for(i=0; i<nt; i=i+1) {
fprintf(fh,"%d %f %f\n",i,t[i],ft[i]);
}
fclose(fh);
}

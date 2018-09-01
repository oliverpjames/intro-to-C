/* prog11 - tabulation of sawtooth function amplitude and phase */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXT 1000
void sawtooth_amp_pha(double tr, double tf, double tc, double tz,
double t, double *amp, double *pha);
int main()
{
double tmin=-14.,tmax=14.,tsam;
double trise=1.0,tfall=5.0,tcons=4.0,tzero=3.0;
int nt=MAXT,i;
double t[MAXT],amp[MAXT],pha[MAXT];
FILE *fh;
/* Set up time samples and calculate function */
tsam=(tmax-tmin)/(nt-1);
for(i=0; i<nt; i=i+1) {
t[i]=tmin+tsam*i;
}
sawtooth(&trise,&tfall,&tcons,&tzero,&nt,t,amp,pha);
/* Produce a tabulation of function on file */
fh = fopen("sawtooth.dat","w");
fprintf(fh,"i t amp pha\n");
for(i=0; i<nt; i=i+1) {
fprintf(fh,"%d %f %f %f\n",i,t[i],amp[i],pha[i]);
}
fclose(fh);
}

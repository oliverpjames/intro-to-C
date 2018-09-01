/* function to return sawtooth amplitude for a given time */
#include <tgmath.h>
#define PI 3.1415926535898
double sawtooth_amp(double trise, double tfall, double tcons,
double tzero, double t)
{
double tperiod, tphase, trf, ft;
tperiod=trise+tfall+tcons;
tphase=t-tzero;
tphase=fmod(tphase,tperiod);
if(tphase<0.0) {
tphase=tperiod+tphase;
}
trf=trise+tfall;
if(tphase<trise) {
ft=tphase/trise;
} else if(tphase<trf) {
ft=(trf-tphase)/tfall;
} else {
ft=0.0;
}
return ft;
}




/* function to return both amplitude and phase for a given time */
void sawtooth_amp_pha(double trise, double tfall, double tcons,
double tzero, double t, double *amp, double *pha)
{
double tperiod, tphase, trf;
tperiod=trise+tfall+tcons;
tphase=t-tzero;
tphase=fmod(tphase,tperiod);
if(tphase<0.0) {
tphase=tperiod+tphase;
}
trf=trise+tfall;
if(tphase<trise) {
*amp=tphase/trise;
} else if(tphase<trf) {
*amp=(trf-tphase)/tfall;
} else {
*amp=0.0;
}
*pha=(tphase/tperiod)*PI*2.0;
}


/* function to return amplitude and phase for a series of times */
void sawtooth(double *tr, double *tf, double *tc, double *tz,
int *nt, double *t, double *amp, double *pha)
{
int i;
for(i = 0; i < *nt; i=i+1) {
sawtooth_amp_pha(*tr,*tf,*tc,*tz,t[i],&amp[i],&pha[i]);
}
}

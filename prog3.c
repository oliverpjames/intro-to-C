/* prog1 - a simple first program in C */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 2*asin(1)
float main()
{
/* Declare variables */
int piint;
float pifloat;
double pidouble;
piint = pi;
pifloat = pi;
pidouble = pi;
int b, c;
float a;
b=1;
c=3;
a=b/c;
printf("The pi is %d, %f, %f\n", piint, pifloat, pidouble);
printf("the sum is %f\n", a);
}

/* prog4 - calculate a factorial in C */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
/* Declare variables */
int num, i;
float fact;
/* what number to calc factorial of */
i = 10;
num = 10;
/* initailize factorial */
fact = 1.0;
/* Count down from num to 1, multiply factby counter each time */
for ( i=1; i <= num; i = i + 1){
fact = fact * i;
}
printf("The factorial of %d is %f\n", (i-1), fact);
}

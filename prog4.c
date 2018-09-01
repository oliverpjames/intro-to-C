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
while ( 1 <= num){
fact = fact* num;
num = num - 1;
}
printf("The factorial of %d is %f\n", i, fact);
}


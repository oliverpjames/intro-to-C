/* prog6 - using scanf to read values from user input */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
float a, b, sum;
/* Read two numbers */
printf("Enter two real numbers:");
scanf("%f %f", &a, &b);
/* Calculate the sum, print it out */
sum = a + b;
printf("The sum is %f\n", sum);
}

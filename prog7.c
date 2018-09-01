/* prog7 - defining and using arrays */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
int i;
float value[10], sum, mean, stddev;
/* Read ten values from the keyboard into the array */
for ( i = 0; i < 10; i = i + 1 ) {
printf("Enter value %d: ", i);
scanf("%f", &value[i]);
}
/* Calculate the mean */
sum = 0.0;
for ( i = 0; i < 10; i = i + 1 )
sum = sum + value[i];
mean = sum / 10.0;
printf("Mean value is %f\n", mean);
/* Calculate the standard deviation */
sum = 0.0;
for ( i = 0; i < 10; i = i + 1 )
sum = sum + powf(value[i] - mean, 2.0);
stddev = sqrt(sum) / 10;
printf("Standard deviation is %f\n", stddev);
}

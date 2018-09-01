#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int x = 1, y = 2;
	int *p;
	
/* Point p at address x:							p = &x, *p = x	*/	
	p = &x;
	

/* Set value of y to the value pointed to by p:		y = x			*/
	y = *p;

/* Change value of x to the address stored by p:	x = &x			*/
	x = p;
	
/* Change value pointed to by p to 3:				x = 3			*/
	*p = 3;
	
	printf(" *p = %d\n", *p);
	printf(" p = %d\n", p);
	
	

	return;
}

/*int main()
{
	int *px;
	int *py;
	int temp;
	
	temp = *px;
	*px = *py;
	*py = temp;
	return *px, *py;
}
	*/

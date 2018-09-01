#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	int n, i , j;
	n = 14;
	int x[n][n];
	
	
	for (j=0; j<n; j++)
	{
		for(i=0; i<n; i++)
		{
			if (i == 0)
			{
				x[i][j] = 1;
			}
			else
			{
				x[i][j] = 0;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		if(x[i][j]!=0)
		{
			printf("%d	", x[i][0]);
		}
	}
			
	for(j = 1; j < n; j++)
	{
		for(i = 0; i < (n); i++)
		{
			if (i==0)
			{
				if(x[i][j]!=0)
				{
					printf("\n%d	", x[i][j]);
				}
			}
			else
			{
				x[i][j] = x[i-1][j-1] + x[i][j-1];
				if(x[i][j]!=0)
				{
					printf("%d	", x[i ][j ]);
				}
			}
		}
	}
	printf("\n");
	
	return;
}
	




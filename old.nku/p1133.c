#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int k,n,i;
	double l,r,m;
	if(scanf("%d\n",&k)!= EOF && k)
	{
		for(i=0;i<k;i++)
		{
			scanf("%d\n",&n);
			l=0;
			r=sqrt(500.0/3.0/3.14159);
			if(3.14159*pow(r,3.0)-500*r+n>0)
				printf("NO\n");
			else
			{
				while(r-l>=0.1)
				{
					m=0.5*(r+l);
					if(3.14159*pow(m,3.0)-500*m+n>0) 
						l=m;
					else
						r=m;
				}
				printf("%.1lf\n",m);}
		}
	}
	return 0;
}

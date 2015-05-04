#include <stdio.h>
int main( )
{
	long n,sum,max;
	int x,flag;
	while( scanf("%ld",&n)!=EOF)
   {
		for(flag = 0,sum = max = -1000001; n--; )
		{
			scanf("%d",&x);
			if(flag==0&&x<=0)
			{
				if(sum<x)
					sum=max=x;
			}
			else if(flag==0&&x>0)
			{
				sum=max=x;
				flag=1;
			}
			else if(flag&&x<0)
			{
				if(sum>0)
				{
					sum+=x;
					if(sum<0)
						sum=0;
				}
			}
			else if(flag&&x>0)
			{
				if(sum>0)
					sum+=x;
				else
                   sum=x;
				if(sum>max)
					max=sum;
			}
		}
			printf("%ld\n",max);
   }
    return 0;
}

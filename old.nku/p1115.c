#include <stdio.h>

int main(void)
{
	int n, i;
	long long int last2,  last1, sum;
	while(scanf("%d", &n)!=EOF)
	{
		sum = 1;
		last2 =1;
		last1 =1;
		if(n > 2)
		{
			for(i = 3; i <= n; i ++)
			{
				last2 = last1;
				last1 = sum;
				sum = last2 + last1;
			}
			printf("%lld\n", sum);
			
		}
		else
		{
			printf("1\n");
		}
	}
	return 1;
}

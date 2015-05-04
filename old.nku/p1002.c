#include <stdio.h>
int main(void)
{
	long long int n, res;
	long long int temp;
	while(scanf("%lld", &n) != EOF)
	{
		if(n >= 50025002)
		{
			res = n - 5;
		}
		else
		{
			temp = (50025002 - n)/2000;
			res = (temp + 1) * 2000 + n - 5;
		}
		printf("%lld\n", res);
	}
}

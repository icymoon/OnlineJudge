#include <stdio.h>
int main(void)
{
	long long int n;
	while(scanf("%lld", &n) != EOF)
	{
		printf("%lld\n", (n*(n-1)+2));
	}
	return 1;
}

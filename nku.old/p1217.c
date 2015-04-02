#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, i;
	double count;
	while(scanf("%d", &n) != EOF)
	{
		count = 0.00;
		for(i = 1; i <= n ; i ++)
		{
			count += log10(i);
		}
		printf("%d\n", (int)(count+1));
	}
	return 1;
}

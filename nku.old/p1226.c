#include <stdio.h>
#include <math.h>

int main(void)
{
	int i, j, k = 0;
	while(scanf("%ld", &k) != EOF && k)
	{
		printf("%d\n", (int)(sqrt((double)k)));
	}
	return 1;
}

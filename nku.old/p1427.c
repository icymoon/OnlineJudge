#include <stdio.h>

int main(void)
{
	int n, k, temp;
	while(scanf("%d", &n) != EOF)
	{
		temp = 1;
		k = 0;
		while(temp < n)
		{
			temp = temp * 2;
			k ++;
		}
		printf("%d\n", k);
	}
	return 1;
}

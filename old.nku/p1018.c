#include <stdio.h>
int main(void)
{
	int res = 0;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		res += n;
	}
	printf("%d\n", res);
}

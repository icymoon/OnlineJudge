#include <stdio.h>
int main(void)
{
	int e,v;
	while(scanf("%d %d", &e, &v) != EOF)
		printf("%d\n", e-v+2);
	return 0;
}

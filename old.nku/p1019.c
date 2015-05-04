#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[100], b[100];
	int c[100];
	int i, j, flag = 0, max_len;

	for(i = 0; i < 100; i ++)
	{
		a[i] = b[i] = '0';
	}
	
	if(scanf("%s %s", &a, &b) != EOF)
	{
		int len_a = strlen(a);
		int len_b = strlen(b);

		if(len_a < len_b)
		{
			for(i = 0; i < len_a; i ++)
			{
				a[len_b -i -1] = a[len_a -i -1];
				a[len_a -i -1] = '0';
			}
			a[len_a] = '0';
			max_len = len_b;
		}
		else if(len_a > len_b)
		{
			for(i = 0; i < len_b; i ++)
			{
				b[len_a -i -1] = b[len_b -i -1];
				b[len_b -i -1] = '0';
			}
			b[len_b] = '0';
			max_len = len_a;
		}
		else
			max_len = len_a;

		for(i = max_len - 1; i >= 0; i --)
		{
			c[i] = a[i] + b[i] - 96 + flag;
			if(c[i] > 9)
			{
				c[i] -= 10;
				flag = 1;
			}
			else
				flag = 0;
		}
		if(flag)
			printf("1");
		for(i = 0; i < max_len; i ++)
		{
			printf("%d", c[i]);
		}
		printf("\n");
	}
	return 1;
}

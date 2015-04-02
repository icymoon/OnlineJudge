#include <stdio.h>

int main(void)
{
	long int sum = 0, temp = 0;
	char ch;
	while((ch = getchar()) != EOF)
	{
		if(ch >= '0' && ch <= '9')
		{
			temp = temp*10 + ch - 48;
			continue;
		}
		else
		{
			sum += temp;
			if(ch == '\n')
			{
				printf("%ld\n", sum);
				sum = 0;
			}
			temp = 0;
		}
	}
	return 0;
}

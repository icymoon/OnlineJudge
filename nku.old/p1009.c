#include <stdio.h>
#include <string.h>

int main(void)
{
	char A[9], B[9];
	int C[9];
	int i, flag;
	int max_len, len_a, len_b;

	
	while(scanf("%s %s", &A, &B) != EOF)
	{
		len_a = strlen(A);
		len_b = strlen(B);
		max_len = len_a > len_b? len_a: len_b;
		flag = 0;
		
		for(i = len_a; i < 9; i ++)	A[i] = '0';
		for(i = len_b; i < 9; i ++) B[i] = '0';
		for(i = 0; i < max_len; i ++)
		{
			C[i] = A[i] + B[i] - 96 + flag;
			if(C[i] > 9)
			{
				C[i] = C[i] - 10;
				flag = 1;
			}
			else
				flag = 0;
		}
		i = 0;
		while(C[i] == 0) i ++;
		while(max_len > i && C[max_len - 1] == 0)
		{
			max_len --;
		}

		while(i < max_len)
		{
			printf("%d", C[i]);
			i ++;
		}
		if(flag)
			printf("1");
		printf("\n");

		for(i = 0; i < 9; i ++)
		{
			A[i] = B[i] = '0';
			C[i] = 0;
		}

	}
}

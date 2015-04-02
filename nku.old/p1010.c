#include <stdio.h>

int main(void)
{
	int n, mid, offset, flag;
	char seat[51];

	while(scanf("%d", &n) != EOF)
	{
		scanf("%s", &seat);
		mid = (n-1)/2;
		offset = 0;
		flag = 0;
		if(n == 2)
		{
			if(seat[0] == 'E' && seat[1] == 'E')
			{
				printf("0\n");
				continue;
			}
		}
		while((mid + offset < n-1) && (mid - offset > 0))
		{
			if(seat[mid + offset] == 'P' && seat[mid - offset] == 'P') 
			{
				offset ++;
				continue;
			}	
			if((seat[mid-offset] == 'E') && (seat[mid-offset-1] == 'E' || seat[mid-offset+1] == 'E'))
			{
				printf("%d\n", mid - offset);
				flag =1;
				break;
			}


			if((seat[mid + offset] == 'E') && (seat[mid + offset -1] == 'E' || seat[mid + offset + 1] == 'E'))
			{
				printf("%d\n", mid + offset);
				flag =1;
				break;
			}
					offset ++;
		}
		if(!flag)
			printf("-1\n");
	}
	return 1;
}

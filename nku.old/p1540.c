#include<stdio.h>
int main(void)
{
	int a[10],t,i,j;
	while(scanf("%d %d %d %d %d %d %d %d %d %d\n",&(a[0]),&(a[1]),&(a[2]),&(a[3]),&(a[4]),&(a[5]),&(a[6]),&(a[7]),&(a[8]),&(a[9]))!=EOF)
	{
		scanf("%d",&t);
		t=t+30;
		j=0;
		for(i=0;i<10;i++)
		{
			if(a[i]<=t) j++;
		}
		printf("%d\n",j);
		getchar();
	}
}

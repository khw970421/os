//32161269 kimhyoungwook fifo.c//
#include<stdio.h>
int main()
{
	int fnum,i,j,min,searchnum,temp;
	printf("select number of process: ");
	scanf("%d",&fnum);
	int a[fnum],b[fnum];

	printf("select process of arrival time\n");
	for(i=0;i<fnum;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("select process of service time\n");
	for(i=0;i<fnum;i++)
	{
		scanf("%d",&b[i]);
	}

	for(i=0;i<fnum;i++)
	{
		min=10000000;
		for(j=0;j<fnum;j++)
		{
			if(a[j]<min)
			{
			min=a[j];
			searchnum=j;
			}
		}
		a[searchnum]=10000000;
		printf("%c is scheduling\n",searchnum+65);
	}
}


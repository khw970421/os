//32161269 kimhyoungwook stride//
#include<stdio.h>

int main()
{	int pnum,i;
	printf("select number of process ");
	scanf("%d",&pnum);
	int a[pnum],b[pnum],c[pnum],num=1,min,cnum,searchnum;
	printf("select process of size\n");

	for(i=0;i<pnum;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<pnum;i++)
	{
		c[i]=0;
		num*=a[i];
	}
	for(i=0;i<pnum;i++)
	{
		b[i]=num/a[i];
	}
	printf("-------------------\n");
	while(1)
	{
		for(i=0;i<pnum;i++)
		{
			printf("%d\t",c[i]);
		}
		min=num;
		for(cnum=0;cnum<pnum;cnum++)
		{
			if(c[cnum]<min)
			{
				min=c[cnum];
				searchnum=cnum;
			}
		}
		printf("%c is processing\n",searchnum+65);
		c[searchnum]+=b[searchnum];
		if(min>=num)
			break;
	}
}


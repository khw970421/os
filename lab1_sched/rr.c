//32161269 kimhyoungwook rr//
#include<stdio.h>
int main()
{
	int rnum,i,j,s,p=0,q=0;
	int realtime=0,sum=0,rr,sum_service=0;
	printf("select number of process ");
	scanf("%d",&rnum);
	int a[rnum],b[rnum],queue[1000000];

	printf("select process of arrval time\n");
	for(i=0;i<rnum;i++)
	{scanf("%d",&a[i]);}

	printf("select process of service time\n");
	for(i=0;i<rnum;i++)
	{scanf("%d",&b[i]);
	sum+=b[i];}

	printf("select rounde-robin q\n");
	scanf("%d",&rr);

	for(i=0;i<=rnum;i++)
	{
		if(a[i]==realtime)
		{queue[p++]=i;}
	}
	
	while(sum!=sum_service)
	{
		s=queue[q];
		printf("%c is processing\n",queue[q]+65);

		for(j=0;j<rr;j++)
		{
			if(b[queue[q]]==0)
			{break;}
			else
			{
				b[queue[q]]=b[queue[q]]-1;
				sum_service++;
				realtime++;

				for(i=0;i<rnum;i++)
				{if(a[i]==realtime)
					queue[p++]=i;
				}
			}
		}
		printf("service time=>%d\n",sum_service);
		q++;

		if(b[s]!=0)
			queue[p++]=s;
	}
}	

//32161269 kimhyoungwook nolock.c//
#include<stdio.h>
#include<pthread.h>
#include<time.h>
int counter =0;
int global = 0;
pthread_mutex_t mutex_lock;
void *worker(int *data){
	int local[4];			//4cpu
	int p=0;
	int threshold=5; 		//5size reset
	float result;

	for(int i=0;i<*data;i++){
		local[p]++;
		if(local[p]>=threshold)
		{
		global+=local[p];
		local[p]=local[p]-threshold;	//local -> global 
		}
	}
	p++;
	return NULL;
}
int main(int argc,char *argv[])
{
	int size;
	int a[4];
	for(int i=0;i<4;i++)
	{
		printf("p%d thread size\n",i);
		scanf("%d",&size);		//enter thread size
		a[i]=size;
	}	
	pthread_t p4;
	pthread_t p3;
	pthread_t p2;
	pthread_t p1;

	pthread_create(&p1,NULL,worker,&a[0]);
	pthread_create(&p2,NULL,worker,&a[1]);
	pthread_create(&p3,NULL,worker,&a[2]);
	pthread_create(&p4,NULL,worker,&a[3]);

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(p3,NULL);
	pthread_join(p4,NULL);
	printf("global : %d\n",global);		//global print
}


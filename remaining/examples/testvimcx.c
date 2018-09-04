#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define SETTIMES  10

int prtTimeA = SETTIMES;
int prtTimeB = SETTIMES;
int prtTimeC = SETTIMES;

void prtA(void *ptr);
void prtB(void *ptr);
void prtC(void *ptr);

pthread_mutex_t mutexA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexB = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexC = PTHREAD_MUTEX_INITIALIZER;


int main()
{
	int tmp1,tmp2,tmp3;
	void *retval;
	pthread_t thread1,thread2,thread3;
	char *message1="thread1";
	char *message2="thread2";
	char *message3="thread3";
	
	int ret_thrd1,ret_thrd2,ret_thrd3;

	if (pthread_mutex_lock(&mutexA) != 0)
	{
		printf("Main lock mutexA fail!\n");
		perror("pthread_mute_lock");
		exit(EXIT_FAILURE);
	}
	if (pthread_mutex_lock(&mutexB) != 0)
	{
		printf("Main lock mutexB fail!\n");
		perror("pthread_mute_lock");
		exit(EXIT_FAILURE);
	}
	if (pthread_mutex_lock(&mutexC) != 0)
	{
		printf("Main lock mutexC fail!\n");
		perror("pthread_mute_lock");
		exit(EXIT_FAILURE);
	}

	if(prtTimeA == SETTIMES)
		if (pthread_mutex_unlock(&mutexA) != 0)
		{
			printf("Main unlock mutexA fail!\n");
			perror("pthread_mute_unlock");
			exit(EXIT_FAILURE);
		}
		
	
	ret_thrd1 = pthread_create(&thread1,NULL,(void *)&prtA,(void *)message1);
	ret_thrd2 = pthread_create(&thread2,NULL,(void *)&prtB,(void *)message2);
	ret_thrd3 = pthread_create(&thread3,NULL,(void *)&prtC,(void *)message3);
	
	//thread create successful return 0, or return thread num
	if (ret_thrd1 != 0)
	{
		printf("fail to create th1!\n");
	}
	else
	{
		printf("th1 has created\n");
	}
	if (ret_thrd2 != 0)
	{
		printf("fail to create th2!\n");
	}
	else
	{
		printf("th2 has created\n");
	}
	if (ret_thrd3 != 0)
	{
		printf("fail to create th3!\n");
	}
	else
	{
		printf("th3 has created\n");
	}
	
			
	//thread join  successful return 0
	tmp1 = pthread_join(thread1,&retval);
//	printf("thread1 return value(retval) is %d\n",(int)retval);
//	printf("thread1 return value(tmp) is %d\n",(int)tmp1);
	if(tmp1 != 0)
	{
		printf("cannot join with th1\n");
	}	
		printf("th1 end\n");
	
	tmp2 = pthread_join(thread2,&retval);
//	printf("thread2 return value(retval) is %d\n",(int)retval);
//	printf("thread2 return value(tmp) is %d\n",(int)tmp2);
	if(tmp2 != 0)
	{
		printf("cannot join with th2\n");
	}	
		printf("th2 end\n");

	tmp3 = pthread_join(thread3,&retval);
//	printf("thread3 return value(retval) is %d\n",(int)retval);
//	printf("thread3 return value(tmp) is %d\n",(int)tmp1);
	if(tmp3 != 0)
	{
		printf("cannot join with th3\n");
	}	
		printf("th3 end\n");
	return 0;
}

void prtA(void *ptr)
{
	while(prtTimeA>0)
	{
		if (pthread_mutex_lock(&mutexA) != 0)
		{
			printf("th1 lock mutexA fail!\n");
			perror("pthread_mute_lock");
			exit(EXIT_FAILURE);
		}
		printf("%s:A\n",(char *)ptr);
		--prtTimeA;
		if (pthread_mutex_unlock(&mutexB) != 0)
		{
			printf("th1 unlock mutexB fail!\n");
			perror("pthread_mute_unlock");
			exit(EXIT_FAILURE);
		}
	}
}

void prtB(void *ptr)
{
	while(prtTimeB>0)
	{
		if (pthread_mutex_lock(&mutexB) != 0)
		{
			printf("th1 lock mutexB fail!\n");
			perror("pthread_mute_lock");
			exit(EXIT_FAILURE);
		}
		printf("%s:B\n",(char *)ptr);
		--prtTimeB;
		if (pthread_mutex_unlock(&mutexC) != 0)
		{
			printf("th1 unlock mutexC fail!\n");
			perror("pthread_mute_unlock");
			exit(EXIT_FAILURE);
		}
	}
}

void prtC(void *ptr)
{
	while(prtTimeC>0)
	{
		if (pthread_mutex_lock(&mutexC) != 0)
		{
			printf("th1 lock mutexC fail!\n");
			perror("pthread_mute_lock");
			exit(EXIT_FAILURE);
		}
		printf("%s:C\n",(char *)ptr);
		--prtTimeC;
		if (prtTimeC > 0)
			if (pthread_mutex_unlock(&mutexA) != 0)
			{
				printf("th1 unlock mutexC fail!\n");
				perror("pthread_mute_unlock");
				exit(EXIT_FAILURE);
			}
	}
}


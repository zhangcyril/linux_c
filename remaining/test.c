#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <errno.h>  
#include <pthread.h>
  
#define LP_TIMES    10  
  
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
  
pthread_cond_t cond_AB = PTHREAD_COND_INITIALIZER;  
pthread_cond_t cond_BC = PTHREAD_COND_INITIALIZER;  
pthread_cond_t cond_CA = PTHREAD_COND_INITIALIZER;  
  
//标记  
int flag_AB,flag_BC,flag_CA;  
  
//标记检查的线程等待  
void th_condflag_wait(int *flag,pthread_cond_t *cond,pthread_mutex_t *mutex)  
{  
    (*flag) = 1;  
    pthread_cond_wait(cond,mutex);  
    (*flag) = 0;  
}  
  
//标记检查的线程通知  	
void th_condflag_broadcast(int *flag,pthread_cond_t *cond,pthread_mutex_t *mutex)  
{  
    while(!(*flag))  
    {  
        pthread_mutex_unlock(mutex);  
        usleep(50);  
        pthread_mutex_lock(mutex);  
    }  
    pthread_cond_broadcast(cond);  
}  
  
void *th_fun_A(void *arg)  
{  
    int i = LP_TIMES;  
    while(i--)  
    {  
        pthread_mutex_lock(&mutex);  
        //A wait C  
        th_condflag_wait(&flag_CA,&cond_CA,&mutex);  
          
        printf("A%d: %lx\n",10-i,pthread_self());  
          
        //A cond B  
        th_condflag_broadcast(&flag_AB,&cond_AB,&mutex);  
        pthread_mutex_unlock(&mutex);  
          
        usleep(50);  
    }  
    //防止C线程最后一次等待A线程时死锁  
    flag_CA = 1;  
}  
  
void *th_fun_B(void *arg)  
{  
    int i = LP_TIMES;  
    while(i--)  
    {  
        pthread_mutex_lock(&mutex);  
        //B wait A  
        th_condflag_wait(&flag_AB,&cond_AB,&mutex);  
  
        printf("B%d: %lx\n",10-i,pthread_self());  
          
        //B cond C  
        th_condflag_broadcast(&flag_BC,&cond_BC,&mutex);  
        pthread_mutex_unlock(&mutex);  
  
        usleep(50);  
    }  
}  
  
void *th_fun_C(void *arg)  
{  
    int i = LP_TIMES;  
    while(i--)  
    {  
        pthread_mutex_lock(&mutex);  
        //C wait B  
        th_condflag_wait(&flag_BC,&cond_BC,&mutex);  
  
        printf("C%d: %lx\n",10-i,pthread_self());  
          
        //C cond A  
        th_condflag_broadcast(&flag_CA,&cond_CA,&mutex);  
        pthread_mutex_unlock(&mutex);  
        usleep(50);  
    }  
}  
  
int main(void)  
{  
    printf("main: %lx\n",pthread_self());  
  
    //保存3个线程的处理函数  
    void *(*th_funs[])(void *) =   
    {  
        th_fun_A,  
        th_fun_B,  
        th_fun_C  
    };  
  
    int th_count = sizeof(th_funs)/sizeof(th_funs[0]);  
  
    pthread_t th[th_count];  
    int i;  
    for(i = 0;i < th_count;i++)  
    {  
        //通过线程函数数组记录的函数来创建线程  
        if(pthread_create(th+i,NULL,th_funs[i],(void *)i) < 0)  
        {  
            fprintf(stderr,"th_create: %s\n",  
                    strerror(errno));  
            exit(1);  
        }  
        printf("th[%d]: %lx\n",i,th[i]);  
    }  
  
    //起始给A线程发出通知，防止A和C死锁  
    pthread_mutex_lock(&mutex);  
    th_condflag_broadcast(&flag_CA,&cond_CA,&mutex);  
    pthread_mutex_unlock(&mutex);  
  
    //回收线程  
    for(i = 0;i < th_count;i++)  
    {  
        pthread_join(th[i],NULL);  
        printf("i: %d finished!\n",i);  
    }  
  
    return 0;  
}  
  

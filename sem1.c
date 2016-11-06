#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
void* f1(void* v);
void* f2(void* v);
volatile int x;
volatile int y;
sem_t s1;
sem_t s2;
void main()
{
pthread_t t1;
pthread_t t2;
sem_init(&s1,0,0);
sem_init(&s2,0,0);
srand(time(NULL));
pthread_create(&t1,NULL,f1,NULL);
pthread_create(&t2,NULL,f2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
sem_destroy(&s1);
sem_destroy(&s2);
}
void* f1(void* v)
{ 
while(1){
x=rand()%1000;
printf("\nx after modified by f1 %d",x);
sem_post(&s1);
sem_wait(&s2);
printf("\ny after read by f1 %d",y);
sleep(3);
}

}
void* f2(void* v)
{
while(1){
sem_wait(&s1);
printf("\nx after read by f1 %d",x);
y=rand()%1000;
printf("\ny after modified by f1 %d",y);
sem_post(&s2);
sleep(3);
}}

#include<stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <iostream>
using namespace std;
void*dpp(void*);
void multilevel_queue_scheduling();
sem_t fok[5];
int main()
{
    //cout << "\n\t Welcome to CPU Scheduling Simulator \n\n";
    //multilevel_queue_scheduling();
pthread_t p[5];
int n[5];
for (int i=0;i<5;i++)
{
    sem_init(&fok[i],0,1);
}
for (int i=0;i<5;i++)
{
    n[i]=i;
    pthread_create(&p[i],NULL,dpp,&n[i]);
    sleep(1);
}
for (int i=0;i<5;i++)
{
    pthread_join(p[i],NULL);
}

    return 0;
}
void * dpp(void * n)
{
    //sleep(1);
    int x=*(int*)n;
    cout<<endl;
    cout<<"philosopher "<<x<<" is thinking"<<endl;
    //cout<<"philosopher "<<x<<" wants to eat"<<endl;
    sem_wait(&fok[x]);
    //cout<<"philosopher "<<x<<" has picked its left fork"<<endl;
    sem_wait(&fok[(x+1)%5]);
   //cout<<"philosopher "<<x<<" has picked its right fork"<<endl;
   cout<<"philosopher "<<x<<" is now eating"<<endl;
   sleep(2);
   sem_post(&fok[(x+1)%5]);
   //cout<<"philosopher "<<x<<" has left its right fork"<<endl;
    sem_post(&fok[x]);
    //cout<<"philosopher "<<x<<" has left its left fork"<<endl;
    pthread_exit(NULL);
   return 0;
}
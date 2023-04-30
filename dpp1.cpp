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
    int n1;
   cout<<"enter the number of processes for dining philosophers problem"<<endl;
   cin>>n1;
pthread_t p[n1];
int n[n1];
for (int i=1;i<=n1;i++)
{
    sem_init(&fok[i],0,1);
}
for (int i=1;i<=n1;i++)
{
    n[i]=i;
    pthread_create(&p[i],NULL,dpp,&n[i]);
    //sleep(1);
}
for (int i=1;i<=n1;i++)
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
   //sleep(2);
   sem_post(&fok[(x+1)%5]);
   //cout<<"philosopher "<<x<<" has left its right fork"<<endl;
    sem_post(&fok[x]);
    //cout<<"philosopher "<<x<<" has left its left fork"<<endl;
    pthread_exit(NULL);
   return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <iostream>
using namespace std;

void* dpp(void*);
void multilevel_queue_scheduling();

sem_t fok[100];  // create semaphores for forks for up to 10 philosophers
sem_t T;
sem_t typing;

int total_philosophers = 5;

int main()
{
    int n1;
    cout<<"Enter the number of philosophers for dining philosophers problem: "<<endl;
    cin>>n1;

    if (n1 < 1)
    {
        cout << "Invalid number of philosophers" << endl;
        return 0;
    }
    total_philosophers = n1;
    sem_init(&T,0,n1-1);
    sem_init(&typing,0,1);
    pthread_t p[n1];
    int n[n1];
    for (int i=0;i<n1;i++)
    {
        sem_init(&fok[i],0,1);
    }
    for (int i=0;i<n1;i++)
    {
        n[i]=i;
        pthread_create(&p[i],NULL,dpp,&n[i]);
    }
    for (int i=0;i<n1;i++)
    {
        pthread_join(p[i],NULL);
    }
    for (int i=0;i<n1;i++)
    {
        sem_destroy(&fok[i]);
    }
    return 0;
}

void* dpp(void * n)
{
    int x=*(int*)n;
    sem_wait(&typing);
    cout<<"Philosopher "<<x + 1<<" is thinking"<<endl;
    sem_post(&typing);
    sem_wait(&T);
    sem_wait(&fok[x]);
    sem_wait(&fok[(x+1)%total_philosophers]);
    sem_wait(&typing);
    cout<<"Philosopher "<<x + 1<<" is now eating"<<endl;
    sem_post(&typing);
    sem_post(&fok[(x+1)%total_philosophers]);
    sem_post(&fok[x]);
    sem_post(&T);
    pthread_exit(NULL);
    return 0;
}

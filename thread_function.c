#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    pthread_t a_thread;

    pthread_create(&a_thread, NULL, thread_function, NULL);

    printf("Thread Created\n");

    pthread_join(a_)
}
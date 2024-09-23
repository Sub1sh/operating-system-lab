#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int shared = 1; 

void* fun1() {
    int x = shared; 
    printf("Thread 1 reads: %d\n", x);
    x++;
    sleep(1); 
    shared = x; 
    printf("Thread 1 updates shared to: %d\n", shared);
}

void* fun2() {
    int y = shared;
    printf("Thread 2 reads: %d\n", y);
    y--; 
    sleep(1); 
    shared = y; 
    printf("Thread 2 updates shared to: %d\n", shared);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared: %d\n", shared);
    return 0;
}

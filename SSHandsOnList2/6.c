// Roll Num : MT2024137
// Name : Shah Mohit P
// 6. Write a simple program to create three threads.
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void thread1(void){
    printf("Hii! Myself Thread 1\n");
    printf("Thread 1: %d\n", getpid());  //pid of the thread and the parent process is same because the kernel does not know about the user threads.
    printf("Thread 1 thread id : %ld\n", pthread_self());
}

void thread2(void){
    printf("Hii! Myself Thread 2\n");
}

void* thread3(void){
    printf("Hii! Myself Thread 3\n");
    return NULL;
}

int main(){

    pthread_t first;
    pthread_create(&first, NULL, (void *)thread1, NULL);

    pthread_t second;
    pthread_create(&second, NULL, (void *)thread2, NULL);

    pthread_t third;
    pthread_create(&third, NULL, (void *)thread3, NULL);

    printf("Parent : %d\n", getpid());
    printf("thread iD for parent : %ld\n", pthread_self());// Every process also has thread id
    
    pthread_join(third, NULL); //THis will wait for the third thread to return NULL

}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 6.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Hii! Myself Thread 1
// Thread 1: 15341
// Thread 1 thread id : 140217610667712
// Hii! Myself Thread 2
// Hii! Myself Thread 3
// Parent : 15341
// thread iD for parent : 140217615861568
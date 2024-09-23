// Roll Num : MT2024137
// Name : Shah Mohit P
//7. Write a simple program to print the created thread ids.
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void thread1(void){
    printf("Hii! Myself Thread 1\n"); //pthread_self() return the thread id of the thread which can be used also
}

int main(){

    pthread_t first;
    pthread_create(&first, NULL, (void *)thread1, NULL);
    sleep(1); //without this the thread1 was not getting time to execute
    printf("Thread ID of 1st thread is : %ld\n", first);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 7.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Hii! Myself Thread 1
// Thread ID of 1st thread is : 133904851797696

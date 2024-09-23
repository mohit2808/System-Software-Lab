// Roll Num : MT2024137
// Name : Shah Mohit P
// 8. Write a separate program using signal system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE
// d. SIGALRM (use alarm system call)
// e. SIGALRM (use setitimer system call)
// f. SIGVTALRM (use setitimer system call)
// g. SIGPROF (use setitimer system call)
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void SigHandler(int sig){
    printf("You are terminating\n");
    exit(1);
}

int main(){
    signal(SIGINT, SigHandler);//SIGINT generates signal on getting any interrupt

    printf("Enter here to complete\n");
    getchar();
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 8b.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Enter here to complete
// ^CYou are terminating
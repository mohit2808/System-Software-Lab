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

#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void SigHandler(int sig){
    printf("Segmentation fault signal generated\n");
    exit(1);
}

int main(){
    signal(SIGSEGV, SigHandler);//SIGSEGV generates signal on Segmentation fault

    int *ptr = NULL;
    *ptr = 100;
    return 0;
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 8a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Segmentation fault signal generated
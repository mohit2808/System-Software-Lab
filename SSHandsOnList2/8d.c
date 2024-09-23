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
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void SigHandler(int sig){
    printf("You Got alarm signal\n");
    exit(0);
}

int main(){
    signal(SIGALRM, SigHandler);

    alarm(3);//This wil generate alarm signal in 3 secs
    pause();
}

//PUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 8d.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// You Got alarm signal
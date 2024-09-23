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
    printf("You got an mathematical expression error\n");
    exit(0);
}

int main(){
    signal(SIGFPE, SigHandler);

    int a = 12;
    int b = a/0;
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// You got an mathematical expression error
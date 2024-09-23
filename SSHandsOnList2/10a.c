// Roll Num : MT2024137
// Name : Shah Mohit P
// 10. Write a separate program using sigaction system call to catch the following signals.
// a. SIGSEGV
// b. SIGINTc. 
// c. SIGFPE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void SigHandler(int sig, siginfo_t *info, void *context){
    printf("You got an updated response to SIGSEGV signal\n");
    exit(0);
}

int main(){
    struct sigaction act;

    act.sa_sigaction = &SigHandler;
    sigaction(SIGSEGV, &act, NULL);

    raise(SIGSEGV);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 10a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// You got an updated response to SIGSEGV signal
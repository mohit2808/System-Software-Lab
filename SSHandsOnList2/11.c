// Roll Num : MT2024137
// // Name : Shah Mohit P
// 11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
// use sigaction system call.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void SigHandler(int sig, siginfo_t *info, void *context){
    printf("You got an updated response to the SIGINT signal\n");
    exit(0);
}

int main(){
    
    signal(SIGINT, SIG_IGN);//will ignore the SIGINT
    printf("Your termination request will be accepted after 10 secs\n");
    sleep(10);

    struct sigaction act;
    act.sa_sigaction = &SigHandler;

    sigaction(SIGINT, &act, NULL);
    printf("Press crntl+c to terminate now\n");
    sleep(6);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 11.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Your termination request will be accepted after 10 secs
// ^C^C^CPress crntl+c to terminate now
// ^CYou got an updated response to the SIGINT signal
// Roll Num : MT2024137
// Name : Shah Mohit P
// 1. Write a separate program (for each time domain) to set a interval timer in 10sec and
// 10micro second
// a. ITIMER_REAL
// b. ITIMER_VIRTUAL
// c. ITIMER_PROF

#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void signal_output(int sig){
    printf("Signal Received\n");
}

int main(){
    
    struct itimerval timer;

    signal(SIGALRM, signal_output);

    timer.it_interval.tv_sec = 10; //After first every signal would come in 10 sec
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10; //First Signal in 10 sec
    timer.it_value.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL); //here as per real time the signal is sent

    while(1){
        printf("Hello\n");
        sleep(1);
    }
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 1a.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Hello
// Hello
// Hello
// Hello
// Hello
// Hello
// Hello
// Hello
// Hello
// Hello
// Signal Received
// Hello
// Hello
// Hello
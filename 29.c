/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
 
*/


#include<stdio.h>
#include<sched.h>
#include<unistd.h>

int main(){

    pid_t pid = getpid();

    struct sched_param param;

    int currentpolicy = sched_getscheduler(pid);
    
    switch(currentpolicy){
        case SCHED_OTHER:   printf("Current Policy : Other Scheduling process\n"); break;
        case SCHED_FIFO:    printf("Current Policy : FIFO\n"); break;
        case SCHED_RR:      printf("Current Policy : Round Robin\n"); break;
    }
    sched_setscheduler(pid, SCHED_RR, &param);

    printf("New Scheduling policy is Round Robin\n");
}

// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 29.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// Current Policy : Other Scheduling process
// New Scheduling policy is Round Robin
// mohit@mohit-14IRL8:~/SSHandsOnList1$ 
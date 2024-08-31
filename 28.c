/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *28. Write a program to get maximum and minimum real time priority.
 
*/

#include<stdio.h>
#include<sched.h>

int main(){

    printf("For FIFO : \n");
    printf("Max Priority : %d \nMin Priority : %d\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));

    printf("For Round Robin : \n");
    printf("Max Priority : %d \nMin Priority : %d \n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
}

// OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList1$ cc 28.c
// mohit@mohit-14IRL8:~/SSHandsOnList1$ ./a.out
// For FIFO : 
// Max Priority : 99 
// Min Priority : 1
// For Round Robin : 
// Max Priority : 99 
// Min Priority : 1 

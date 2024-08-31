/* Name: Shah Mohit P
 * Reg. No: MT2024137
 *
 *19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
 
*/

#include<stdio.h>
#include<unistd.h>
//#include<c7x.h>

// unsigned long long rdtsc() {
//     unsigned int low, high;
//     __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
//     return ((unsigned long long)high << 32) | low;
// }

int main(){
    unsigned long start_time = __rdtsc();

    printf("PID : %d\n", getpid());

    unsigned long end_time = __rdtsc();

    printf("Time Taken : %lu\n", start_time-end_time);
}
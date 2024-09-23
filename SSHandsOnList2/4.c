// Roll Num : MT2024137
// Name : Shah Mohit P
//4. Write a program to measure how much time is taken to execute 100 getppid ( )
// system call. Use time stamp counter.

#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

unsigned long long rdtsc() //For Time Stamp Counter this structure is to be used
{
     unsigned long long dst;
     __asm__   __volatile__ ("rdtsc":"=A" (dst));
     return dst;  
 }


int main(){
    long long int start, end;

    start = rdtsc(); //Start time

    for(int i = 0; i<100; i++){ 
            getppid();
    }
    
    end = rdtsc(); //end time

    printf("Time Taken = %llu\n", end - start);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 4.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Time Taken = 63538

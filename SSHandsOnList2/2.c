// Roll Num : MT2024137
// Name : Shah Mohit P
//2. Write a program to print the system resource limits. Use getrlimit system call.
#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 

int main(){
    struct rlimit lt;

    if(getrlimit(RLIMIT_STACK, &lt) == 0){

        printf("Stack Limits of system is: \n");
        printf("Soft Limit : %ld\n", lt.rlim_cur);
        printf("Hard Limit : %ld\n", lt.rlim_max); //This will we -1 cause it is unlimited
    }

}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 2.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Stack Limits of system is: 
// Soft Limit : 8388608
// Hard Limit : -1

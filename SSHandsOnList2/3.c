// Roll Num : MT2024137
// Name : Shah Mohit P
//3. Write a program to set (any one) system resource limit. Use setrlimit system call.
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

    struct rlimit st;
    struct rlimit new;

    st.rlim_cur = 3;
    st.rlim_max = 1024;

    setrlimit(RLIMIT_STACK, &st);

    if(getrlimit(RLIMIT_STACK, &new) == 0){

        printf("Virtual memory Limits of system is: \n");
        printf("Soft Limit : %ld\n", new.rlim_cur);
        printf("Hard Limit : %ld\n", new.rlim_max);
    }
    else perror("Status");
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 3.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Stack Limits of system is: 
// Soft Limit : 8388608
// Hard Limit : -1
// Virtual memory Limits of system is: 
// Soft Limit : 3
// Hard Limit : 1024

// Roll Num : MT2024137
// Name : Shah Mohit P
// 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
// signal - Use signal system call.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

int main(){
    signal(SIGINT, SIG_IGN);
    printf("I will Ignore terminating signal for 10 secs\n");
    sleep(10);//SIGINT will be ignored for 10 secs

    signal(SIGINT, SIG_DFL);//SIGINT will will be automatically treated as it should be
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 9.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// I will Ignore terminating signal for 10 secs
// ^C^C^C
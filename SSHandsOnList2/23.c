// Roll Num : MT2024137
// Name : Shah Mohit P
// 23. Write a program to print the maximum number of files can be opened within a process and
// size of a pipe (circular buffer).
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    long pipe_buff, open_max;

    pipe_buff = pathconf("fifotest4", _PC_PIPE_BUF);
    open_max = sysconf(_SC_OPEN_MAX);
    printf("Limit of Pipe buffer: %ld\n", pipe_buff);
    printf("Maximum Files that can be opened by any process: %ld\n", open_max);
}

//OUTPUT
// mohit@mohit-14IRL8:~/SSHandsOnList2$ man pathconf
// mohit@mohit-14IRL8:~/SSHandsOnList2$ cc 23.c
// mohit@mohit-14IRL8:~/SSHandsOnList2$ ./a.out
// Limit of Pipe buffer: 4096
// Maximum Files that can be opened by any process: 1048576